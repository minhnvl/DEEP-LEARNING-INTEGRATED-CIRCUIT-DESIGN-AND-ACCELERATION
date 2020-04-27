`timescale 1ns/10ps
module CS(Y, X, reset, clk);

    input clk, reset; 
    input 	[7:0] X;

    reg     [71:0] ValX;
    reg     [11:0]   sum;
    reg     [7:0]  Xavg;
    reg     [7:0]   Xapp;
    reg     [7:0]   Xapp_temporary;
    reg     [7:0]   Xapp_compare1;
    reg     [7:0]   Xapp_compare2;
    output 	[9:0] Y;
    reg 	[9:0] Y;
    reg     [71:0] A;
    integer counter;
    integer i;
    always @(posedge clk) begin
        if (reset == 1) begin
            Xavg <= 0;
            Xapp <= 0;
            ValX  <= 0;
            sum <=0;
            counter <= 0;
            Y <= 0;
            Xapp_compare1 <= 0;
            Xapp_compare2 <= 0;
        end
        else begin
            
            if (counter < 8) begin
                ValX = ValX << 8;
                ValX[7:0] = X[7:0];
                sum = sum + X;
                
                
            end
            else begin
                sum = sum + X[7:0] - ValX[71:64];
                ValX = ValX << 8;
                ValX[7:0] = X[7:0];
                
                Xavg = sum/9;
                Xapp = 0;
                for(i=0; i<9; i = i+1) begin
                    A = ValX >> 8*i;
                    Xapp_temporary[7:0] = A[7:0];
                    if (Xavg >= Xapp_temporary) 
                        Xapp_compare1 = Xavg  - Xapp_temporary;
                        Xapp_compare2 = Xavg  - Xapp;
                        Xapp = (Xapp_compare1 < Xapp_compare2) ? Xapp_temporary:Xapp;
                    
                end

                Y = (sum + 9*Xapp)/8;
                
            end
            counter = counter + 1;

        end
    end

endmodule
