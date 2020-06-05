// ############ Nguyen Vu Le Minh #############
// ############### Homework 5 #################
// ############### CAID-NCKU  #################
module conv(
    input               rst,
    input               clk, 
    input       [31:0]  M0_R_data, 
    input       [31:0]  M1_R_data, 
    input               start,

    output  reg         M0_R_req, 
    output  reg [31:0]  M0_addr, 

    output  reg [3:0]   M0_W_req, 
    output  reg [31:0]  M0_W_data,

    output  reg         M1_R_req, 
    output  reg [31:0]  M1_addr, 

    output  reg [3:0]   M1_W_req, 
    output  reg [31:0]  M1_W_data,
    
    output  reg         finish
);
    reg         [31:0]   Weight_arr[8:0];
    reg         [31:0]   Weight_data;
    reg         [31:0]   Input_data;
    reg         [31:0]   biased;
    reg         [31:0]   Result;
    reg         [63:0]   Ans;
    reg         [63:0]   Conv1,Conv2,Conv3,Conv4,Conv5,Conv6,Conv7,Conv8,Conv9;
    reg         [31:0]   A_Conv1,A_Conv2,A_Conv3,A_Conv4,A_Conv5,A_Conv6,A_Conv7,A_Conv8,A_Conv9;
    reg         [31:0]   Databuffer1, Databuffer2;
    reg                  weight,write;
    reg         [12:0]   CountWeight, CountInput, CountWrite,CountPre;
    reg         [895:0]  Linebuffer_3;
    reg         [895:0]  Linebuffer_2;
    reg         [95:0]   Linebuffer_1;

    parameter   first_weight = 784;
    parameter   last_weight  = 795 ;

    always @(posedge clk) begin
        if(start==1) begin
            CountWeight <= 0;
            CountInput  <= 0;
            CountWrite  <= 0;
            CountPre    <= 0;
            Weight_data <= 0;
            Input_data  <= 0;
            weight      <= 1;
            M0_addr     <= 0;

        end
        else begin // Set up counter to get Weight and Input
            case (weight)
                1: CountWeight <= CountWeight + 1;
                0: CountInput  <= CountInput  + 1;
            endcase  
            if (write) begin
                CountPre       <= CountPre    + 1;
                if (CountPre > 0 && CountPre%28==0) begin 
                    CountWrite <= CountWrite - 1;
                    
                end
                else begin
                    CountWrite     <= CountWrite  + 1;
                    
                end
               
            end      
        end
    end
    // First cycle, we excecute to get Weight, put it on array
    always @(*) begin
        if (weight) begin
            M0_R_req <= 1'b1;
            M0_W_req <= 4'b0;
            M0_addr <= (first_weight+CountWeight)*4;
            Weight_data <= M0_R_data;
            
            if (CountWeight < 10) begin
                Weight_arr[CountWeight-1] <= Weight_data;
            end
            else if (CountWeight >= 11) begin
                biased <= Weight_data;
                weight <= 0;
            end
        end
    end    
    // Second cycle, we get Input data and execute convolution
    always @(*) begin
        if (!weight) begin
            M0_R_req <= 1'b1;
            M0_W_req <= 4'b0;
            M0_addr <= (CountInput)*4;
            Input_data <= M0_R_data;
            Linebuffer_1 [31:0] <=  M0_R_data;
            Linebuffer_2 [31:0] <=  Databuffer1[31:0];
            // if (CountInput % 32 == 0)
            Linebuffer_3 [31:0] <=  Databuffer2[31:0];
           
        end
        
    end  
    // In progress, using many shift register to shift input data
    always @(CountInput) begin
        Databuffer1  <= Linebuffer_1[95:64];
        Databuffer2  <= Linebuffer_2[895:864];
        Linebuffer_1 = Linebuffer_1 << 32;
        Linebuffer_2 = Linebuffer_2 << 32;
        Linebuffer_3 = Linebuffer_3 << 32;

    end

    // After 58 cycle, It's mean that The shift register contain enough Input data
    // We start calculate
    always @(*) begin
        if (CountInput >= 58)  begin
            write        <= 1 ;
            Conv1        <= $signed(Linebuffer_3[895:864]) * $signed(Weight_arr[0]);
            Conv2        <= $signed(Linebuffer_3[863:832]) * $signed(Weight_arr[1]);
            Conv3        <= $signed(Linebuffer_3[831:800]) * $signed(Weight_arr[2]);
            Conv4        <= $signed(Linebuffer_2[895:864]) * $signed(Weight_arr[3]);
            Conv5        <= $signed(Linebuffer_2[863:832]) * $signed(Weight_arr[4]);
            Conv6        <= $signed(Linebuffer_2[831:800]) * $signed(Weight_arr[5]);
            Conv7        <= $signed(Linebuffer_1[95:64])   * $signed(Weight_arr[6]);
            Conv8        <= $signed(Linebuffer_1[63:32])   * $signed(Weight_arr[7]);
            Conv9        <= $signed(Linebuffer_1[31:0])    * $signed(Weight_arr[8]);
     

            A_Conv1[31:0] <= (Conv1[15:0]>=16'h8000)?Conv1[47:16]+1:Conv1[47:16];
            A_Conv2[31:0] <= (Conv2[15:0]>=16'h8000)?Conv2[47:16]+1:Conv2[47:16];
            A_Conv3[31:0] <= (Conv3[15:0]>=16'h8000)?Conv3[47:16]+1:Conv3[47:16];
            A_Conv4[31:0] <= (Conv4[15:0]>=16'h8000)?Conv4[47:16]+1:Conv4[47:16];
            A_Conv5[31:0] <= (Conv5[15:0]>=16'h8000)?Conv5[47:16]+1:Conv5[47:16];
            A_Conv6[31:0] <= (Conv6[15:0]>=16'h8000)?Conv6[47:16]+1:Conv6[47:16];
            A_Conv7[31:0] <= (Conv7[15:0]>=16'h8000)?Conv7[47:16]+1:Conv7[47:16];
            A_Conv8[31:0] <= (Conv8[15:0]>=16'h8000)?Conv8[47:16]+1:Conv8[47:16];
            A_Conv9[31:0] <= (Conv9[15:0]>=16'h8000)?Conv9[47:16]+1:Conv9[47:16];
    
            Result       <= $signed(A_Conv1[31:0]) + $signed(A_Conv2[31:0]) + $signed(A_Conv3[31:0]) +
                            $signed(A_Conv4[31:0]) + $signed(A_Conv5[31:0]) + $signed(A_Conv6[31:0]) +
                            $signed(A_Conv7[31:0]) + $signed(A_Conv8[31:0]) + $signed(A_Conv9[31:0]) +
                            $signed(biased);
           
        end
        
    end

    // After convolution , we write result on Bram via available address
    always @(*) begin
      
        if (write) begin
            M1_R_req    <= 1'b1;
            M1_W_req    <= 4'b1111;
            M1_addr     <= (CountWrite-1)*4;
            M1_W_data   <= Result;
        end
        finish = (CountInput>=first_weight)?1:0;
    end
endmodule

// ################ Finish ####################
// ############ Nguyen Vu Le Minh #############
// ############### Homework 5 #################
// ############### CAID-NCKU  #################