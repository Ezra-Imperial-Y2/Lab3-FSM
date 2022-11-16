module starting_light  (
    input logic clk,
    input logic rst,
    input logic trigger, 
    output logic [7:0] lights
);


logic tick;
logic time_out;
logic [6:0] data_out;
/* verilator lint_off UNOPTFLAT */
logic cmd_delay;
logic cmd_seq;



lfsr_7 lfsr7 (
    .clk (clk),
    .en (1),
    .rst (rst),
    .data_out (data_out)
);

delay delayer (
    .clk (clk),
    .rst (rst),
    .trigger_delay(cmd_delay),
    .n (data_out),
    .time_out (time_out)

);

clktick one_second (
    .N (46),
    .en (cmd_seq),
    .rst (rst),
    .clk (clk),
    .tick (tick)
);

f1_fsm F1 (
    .clk (clk),
    .trigger (trigger),
    .en (cmd_seq ? tick : time_out),
    .rst (rst),
    .cmd_delay (cmd_delay),
    .cmd_seq (cmd_seq),
    .lights (lights)
);

endmodule  

