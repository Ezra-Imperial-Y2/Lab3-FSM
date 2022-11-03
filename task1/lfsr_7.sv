module lfsr7 (
    input logic         clk,
    input logic         rst,
    input logic         en,
    output logic [7:0]  data_out
);

logic [7:0] sreg; 

always_ff @(posedge clk, posedge rst) begin
    if (en)
     sreg <= {sreg[6:0], sreg[7] ^ sreg[3]};
    else if(rst)
        sreg <= 8'b1;
    else 
        sreg <= sreg;
end

assign data_out = sreg;
endmodule 

