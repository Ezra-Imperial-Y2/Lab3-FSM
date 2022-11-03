module lfsr4 (
    input logic         clk,
    input logic         rst,
    input logic         en,
    output logic [3:0]  data_out
);

logic [3:0] sreg; 

always_ff @(posedge clk, posedge rst) begin
    if (en)
     sreg <= {sreg[2:0], sreg[3] ^ sreg[2]};
    else if(rst)
        sreg <= 4'b1;
    else 
        sreg <= sreg;
end

assign data_out = sreg;
endmodule 

