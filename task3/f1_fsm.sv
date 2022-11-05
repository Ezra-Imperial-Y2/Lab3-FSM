module f1_fsm (
    input logic clk,
    input logic rst,
    input logic en,
    output logic [7:0] lights
);

// Define the states 
typedef enum {S_0, S_1, S_2, S_3, S_4, S_5, S_6, S_7, S_8} my_state;
my_state current_state, next_state;

// Next state logic 
always_comb 
    case (current_state)
        S_0: if(en==1'b1)  next_state = S_1;
            else           next_state = current_state;
        S_1: if(en==1'b1)  next_state = S_2;
            else           next_state = current_state;
        S_2: if(en==1'b1)  next_state = S_3;
            else           next_state = current_state;
        S_3: if(en==1'b1)  next_state = S_4;
            else           next_state = current_state;
        S_4: if(en==1'b1)  next_state = S_5;
            else           next_state = current_state;
        S_5: if(en==1'b1)  next_state = S_6;
            else           next_state = current_state;
        S_6: if(en==1'b1)  next_state = S_7;
            else           next_state = current_state;
        S_7: if(en==1'b1)  next_state = S_8;
            else           next_state = current_state;
        S_8: if(en==1'b1)   next_state = S_0;
            else           next_state = current_state;
        default: next_state = S_0;
    endcase 

// State transition
always_ff @(posedge clk) begin
    if (rst)    current_state <= S_0;
    else        current_state <= next_state;
end

// Output logic 

always_comb
    case (current_state)
        S_0:    lights = 8'b0;
        S_1:    lights = 8'b1;
        S_2:    lights = 8'b11;
        S_3:    lights = 8'b111;
        S_4:    lights = 8'b1111;
        S_5:    lights = 8'b11111;
        S_6:    lights = 8'b111111;
        S_7:    lights = 8'b1111111;
        S_8:    lights = 8'b11111111;
    endcase

endmodule 
    




    
