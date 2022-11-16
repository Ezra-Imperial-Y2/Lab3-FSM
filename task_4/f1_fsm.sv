module f1_fsm (
    input logic clk,
    input logic rst,
    input logic en,
    input logic trigger,
    output logic [7:0] lights,
    output logic cmd_seq,
    output logic cmd_delay
);



// Define the states 
typedef enum {S_1, S_2, S_3, S_4, S_5, S_6, S_7, S_8, S_0} my_state;
my_state current_state = S_0, next_state;

always_ff @(posedge clk)
    if (rst) current_state <= S_0;
    else     current_state <= next_state;


always_comb begin
    if (trigger && !cmd_delay) begin 
        cmd_seq = 1;
    end 
    
    if (en) begin
        case (current_state)
        S_0:             next_state = S_1;
        S_1:             next_state = S_2;
        S_2:             next_state = S_3;
        S_3:             next_state = S_4;
        S_4:             next_state = S_5;
        S_5:             next_state = S_6;
        S_6:             next_state = S_7;
        S_7:             next_state = S_8;
        S_8:             next_state = S_0;
        default:         next_state = S_0;
        endcase

        case (current_state)
        S_0: 
        begin 
            lights = 8'b0;
            cmd_seq = 0;
            cmd_delay = 0;
        end 
        S_1:
        begin
            lights = 8'b1;
            cmd_seq = 1;
            cmd_delay = 0;
        end 
        S_2: lights = 8'b11;
        S_3: lights = 8'b111;
        S_4: lights = 8'b1111;
        S_5: lights = 8'b11111;
        S_6: lights = 8'b111111;
        S_7: lights = 8'b1111111;
        S_8:
        begin 
            lights = 8'b11111111;
            cmd_seq = 0;
            cmd_delay = 1;
        end 
        default: lights = 8'b0;
    endcase 
    end
end

    
endmodule

















// // Next state logic 
// always_comb 
//     if (trigger && !cmd_delay) cmd_seq = 1;
//     if (en) begin
//     case (current_state)
//         S_0: if  next_state = S_1;
//         
//         S_1:                next_state = S_2;
//         
//         S_2:                next_state = S_3;
//         
//         S_3:                next_state = S_4;
//         
//         S_4:                next_state = S_5;
//         
//         S_5:                next_state = S_6;
//         
//         S_6:                next_state = S_7;
//         
//         S_7:                next_state = S_8;
//         
//         S_8:                next_state = S_0;
//         
//         default: next_state = S_0;
//     endcase 

// // State transition
// always_ff @(posedge clk) begin
//     if (rst)    current_state <= S_0;
//     else        current_state <= next_state;
// end

// // Output logic 

// always_comb
//     case (current_state)
//         S_0:    lights = 8'b0;
//         S_1:    lights = 8'b1;
//                 cmd_seq = 1;
//         S_2:    lights = 8'b11;
//                 cmd_seq = 1;
//         S_3:    lights = 8'b111;
//                 cmd_seq = 1;
//         S_4:    lights = 8'b1111;
//                 cmd_seq = 1;
//         S_5:    lights = 8'b11111;
//                 cmd_seq = 1;
//         S_6:    lights = 8'b111111;
//                 cmd_seq = 1;
//         S_7:    lights = 8'b1111111;
//                 cmd_seq = 1;
//         S_8:    lights = 8'b11111111;
//                 cmd_seq = 0;
//                 cmd_delay = 1;
//     endcase

// endmodule 
    




    
