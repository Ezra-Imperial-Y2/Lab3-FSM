#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vf1_fsm.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env){
    int i;
    int clk; 

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vf1_fsm* top = new Vf1_fsm;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("f1_fsm.vcd");

    //init Vbuddy 
    if(vbdOpen()!=1) return(-1);
    vbdHeader("L3T2: F1 Lights");
    vbdSetMode(1);

    // initialize simulation inputs 
    top->clk = 1;
    top->rst = 0;
    top->en = 0;

    for(i=0; i<700; i++){

         for (clk=0; clk<2; clk++) {
                tfp->dump (2*i+clk);
                top->clk = !top->clk;
                top->eval();
            }

        //Send count values to Vbuddy
        //vbdHex(1, top->data_out & 0xF);
        //Display neopixels
        vbdBar(top->lights & 0xFF);

        vbdCycle(i+1);

        if (i < 2){
            top->rst = 1;
        } else {
            top->rst = 0;
        }

        if(vbdFlag() == 1){
            top->en = 1;
        } else {
            top->en = 0;
        }

        if (Verilated::gotFinish()) exit(0);

    }
    vbdClose();
    tfp->close();
    exit(0);
   
}