module conv(
    input rst,
    input clk, 
    output reg M0_R_req, 
    output reg [31:0]M0_addr, 
    input [31:0]M0_R_data, 
    output reg [3:0]M0_W_req, 
    output reg [31:0]M0_W_data,

    output reg M1_R_req, 
    output reg [31:0]M1_addr, 
    input [31:0]M1_R_data, 
    output reg [3:0]M1_W_req, 
    output reg [31:0]M1_W_data,
    
    input start,
    output reg finish
);
    reg [31:0]window[8:0];
    reg [31:0]weight[8:0];
    reg [31:0]bias;
    reg [3:0]state;
    reg [4:0]weight_index;
    reg [5:0]window_index;
    reg [2:0]array_index;
    reg [9:0]window_head;
    reg [2:0]move_state;
    reg [2:0]cal_state;
    reg [63:0]product[8:0];
    reg [31:0]ans;
    reg [9:0]write_back_index;
    reg stall;
    reg send;
    integer i;
    initial begin
        state = 0;
    end
    always@(posedge clk)begin
        /*if(rst)begin
            state <= 0;
            window_index <= 0;
            weight_index <= 0;
            window_head <= 0;
            move_state <= 0;
            cal_state <= 0;
            write_back_index <= 0;
            send <= 1;
        end else */
        if(start==1&&state==0)begin
            state <= 1;
            array_index <= 0;
            window_index <= 0;
            weight_index <= 0;
            window_head <= 0;
            move_state <= 0;
            cal_state <= 0;
            write_back_index <= 0;
            send <= 1;
            stall <= 1;
        end 

        if(state==1&&start==0)begin
        // initial weight
            if(weight_index>=10)begin
                state <= 2;
                send <= 1;
            end else if(send)begin
                M0_R_req <= 1;
                M0_W_req <= 0;
                M0_addr <= (784+weight_index)*4;
                send <= 0;
            end else begin
            // use data which read previous cycle
                M0_R_req <= 0;
                M0_W_req <= 0;
                weight_index <= weight_index + 1;
                weight[weight_index-1] <= M0_R_data;
                send <= 1;
            end
        end else if(state==2)begin
        // initial bias
            if(send)begin
                M0_R_req <= 1;
                M0_W_req <= 0;
                M0_addr <= 793*4;
                send <= 0;
            end else begin
                bias <= M0_R_data;
                send <= 1;
                state <= 3;
            end
        end else if(state==3)begin
        // initial window's left six element
            if(window_index>=58)begin
                send <= 1;
                state <= 4;
                window_index <= 0;
            end else if(send)begin
                M0_R_req <= 1;
                M0_W_req <= 0;
                M0_addr <= window_index*4;
                send <= 0;
            end else begin
                if(stall)begin
                    stall <= 0;
                end else begin
                if(window_index==1)begin
                    window_index <= 28;
                    array_index <= 3;
                end else if(window_index==29)begin
                    window_index <= 56;
                    array_index <= 6;
                end else begin
                    window_index <= window_index + 1;
                    array_index <= array_index + 1;
                end
                M0_R_req <= 0;
                window[array_index] = M0_R_data;
                send <= 1;
                stall <= 1;
                end
            end
        end else if(state==4)begin
        // take three new element in window and move six elememnt in left
            if(send==1)begin
                if(move_state==0)begin
                    M0_addr <= (window_head+2)*4;
                end else if(move_state==1)begin
                    M0_addr <= (window_head+30)*4;
                end else begin
                    M0_addr <= (window_head+58)*4;
                end               
                M0_R_req <= 1;
                M0_W_req <= 0;
                send <= 0;
            end else begin 
                if(stall)begin
                    stall <= 0;
                end else begin
                if(move_state==0)begin
                    window[2] <= M0_R_data;
                    move_state <= move_state + 1;
                end else if(move_state==1)begin
                    window[5] <= M0_R_data;
                    move_state <= move_state + 1;
                end else begin
                    window[8] <= M0_R_data;
                    move_state <= 0;
                    state <= 5;
                end
                send <= 1;
                stall <= 1;
                end
            end
            
        end else if(state==5)begin
        // calculate
            if(cal_state==0)begin
                // product
                for(i=0; i<9; i=i+1)begin
                    product[i] <= $signed(window[i])*$signed(weight[i]);
                end
                cal_state <= 1;
            end else if(cal_state==1)begin
                // rounding
                for(i=0; i<9; i=i+1)begin
                    product[i][31:0] <= (product[i][15:0]>=16'h8000)?product[i][47:16]+1:product[i][47:16];
                end
                cal_state <= 2;
            end else begin
                // summing them
                ans <= $signed(product[0][31:0])+$signed(product[1][31:0])+
                        $signed(product[2][31:0])+$signed(product[3][31:0])+
                        $signed(product[4][31:0])+$signed(product[5][31:0])+
                        $signed(product[6][31:0])+$signed(product[7][31:0])+
                        $signed(product[8][31:0])+bias;
                cal_state <= 0;
                state <= 6;
            end
        end else if(state==6)begin
        // write ans back to output
            M1_R_req <= 1;
            M1_W_req <= 4'b1111;
            M1_addr <= write_back_index*4;
            M1_W_data <= ans;
            state <= 7;
            write_back_index <= write_back_index + 1;
        end else if(state==7)begin
        // shift window's left six element
            if(write_back_index>=676)begin
            // finish
                finish <= 1;
            end else begin
                window[0] <= window[1];
                window[1] <= window[2];
                window[3] <= window[4];
                window[4] <= window[5];
                window[6] <= window[7];
                window[7] <= window[8];
                if(window_head%28>=25)begin
                    window_head <= window_head + 3;
                    state <= 8;
                end else begin 
                    window_head <= window_head + 1;
                    state <= 4;
                end
            end
        end else if(state==8)begin
        // reset new six element
            if(window_index>=8)begin
                state <= 4;
                window_index <= 0;
            end else begin
                if(send)begin
                    M0_R_req <= 1;
                    M0_W_req <= 0;
                    M0_addr <= (window_head+window_index)*4;
                    send <= 0;
                end else begin
                    if(stall)begin
                        stall <= 0;
                    end else begin
                    if(window_index==1)begin
                        window_index <= 28;
                    end else if(window_index==29)begin
                        window_index <= 56;
                        
                    end else begin
                        window_index <= window_index + 1;
                    end
                    window[window_index] <= M0_R_data;
                    send <= 1;
                    stall <= 1;
                    end
                end
            end
        end
    end

endmodule