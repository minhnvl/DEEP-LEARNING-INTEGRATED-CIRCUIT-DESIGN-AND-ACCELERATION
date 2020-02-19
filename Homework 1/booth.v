`timescale 1ns / 10ps
module booth(out, in1, in2);

	parameter width = 6;
	input  	[width-1:0]   in1; //multiplicand
	input  	[width-1:0]   in2; //multiplier
	output  [2*width-1:0] out; //product
	reg [2*width-1:0] out; 
	reg Q; // Storing last value of in2 after output shift_bit
	integer i; // Number for loop
	reg [1:0] combine; // The rightmost 2 bits used for the selection of different executions.
	
	always @(in1,in2) begin
		out[width-1 : 0] = in2[width-1:0];
		// out[2*width-1: width] = 6'b0;
		Q = 1'b0;
		for(i = 0; i < width; i = i+1) begin
		
			combine = {in2[i],Q};
			if(combine == 2'd2) begin
				out[2*width-1: width] = out[2*width-1: width] - in1;
			end
			else if (combine == 2'd1) begin
				out[2*width-1: width] = out[2*width-1: width] + in1;
			end

			out = out >> 1;
			
			out[2*width-1] = out[2*width-2];
			/* $display("Case %d ==> Out[12:6] = %b ==> Out[5:0] = %b ==> Out = %b ==> In1 = %b ==> In2 = %b ==> combine %d ==> in[0] = %b ==> Q = %b", i, out[2*width-1: width],out[width-1: 0],out,in1,in2,combine,in2[i],Q); */
			Q = in2[i];
		end
		
	end
	
endmodule
