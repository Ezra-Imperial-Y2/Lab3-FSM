module f1_tick #(
    parameter WIDTH = 16
)(
    input logic clk,
    input logic rst,
    input logic en, 
    input  logic [WIDTH-1:0] N,     	 // clock divided by N+1
    output logic  		       tick,      // tick output
    output logic [7:0] lights

);

f1_fsm lights_display (
    .clk (clk),
    .rst (rst),
    .en (tick),
    .lights (lights)
);

clktick counter (
    .clk (clk),
    .rst (rst),
    .en (en),
    .N (N),
    .tick (tick)

);

endmodule



