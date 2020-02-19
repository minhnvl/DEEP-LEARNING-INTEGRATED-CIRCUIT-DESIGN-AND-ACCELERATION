`timescale 1ns/10ps
module CS(Y, X, reset, clk);

input 			clk, reset; 
input 	[7:0] 	X;
output 	[9:0] 	Y;
reg		[71:0] 	ValX;
reg		[11:0]	r_sumX;
wire	[7:0]	appr_out;
wire 	[11:0] 	sumX;
wire	[7:0] 	avgX;
wire  	[9:0]	Y;

parameter z = 0;

//--------------------------------------
//  \^o^/   Write your code here~  \^o^/
//--------------------------------------
always @(posedge clk or posedge reset) begin
	if(reset) begin
		ValX <= 72'b0;
		r_sumX <= 8'b0;

	end
	else begin
		ValX <= {ValX[63:0],X};
		r_sumX <= sumX;
	end	
end

assign sumX = r_sumX - {4'b0, ValX[71:64]} + {4'b0, X};
assign avgX = r_sumX/9;

Calculation cal(avgX,ValX,appr_out);

assign Y = (appr_out*9 + r_sumX)/8;
endmodule

/* ################ */
module Calculation(id_avgX,id_ValX,id_appr_out);

input	[71:0]	id_ValX;
input	[7:0]	id_avgX;
output 	[7:0]	id_appr_out;

reg		[7:0]	id_appr_out;
reg 	[7:0]	appr_cal1[0:8];
reg 	[7:0]	appr_cal2[0:8];
reg		[71:0]	ValShiftX[0:8];
reg		[7:0]	id_tranfer[0:8];
integer i;

always @(id_ValX,id_avgX) begin
	id_appr_out = 8'b0;
	for(i=0;i<9;i=i+1) begin
	
		case(i) 
			0: begin
				id_tranfer[i] = id_ValX[7:0];
			end
			1: begin
				id_tranfer[i] = id_ValX[15:8];
			end
			2: begin
				id_tranfer[i] = id_ValX[23:16];
			end
			3: begin
				id_tranfer[i] = id_ValX[31:24];
			end
			4: begin
				id_tranfer[i] = id_ValX[39:32];
			end
			5: begin
				id_tranfer[i] = id_ValX[47:40];
			end
			6: begin
				id_tranfer[i] = id_ValX[55:48];
			end
			7: begin
				id_tranfer[i] = id_ValX[63:56];
			end
			8: begin
				id_tranfer[i] = id_ValX[71:64];
			end
		
		endcase
		if (id_tranfer[i] <= id_avgX)  begin
			appr_cal1[i] = id_avgX - id_tranfer[i];
			appr_cal2[i] = id_avgX - id_appr_out;
			if(appr_cal1[i][7:0] < appr_cal2[i][7:0]) begin
				id_appr_out[7:0] = id_tranfer[i];
			end
		end
		else begin
			appr_cal1[i][7:0] = 0;
			appr_cal2[i][7:0] = 0;
		end
	end	
end
endmodule
