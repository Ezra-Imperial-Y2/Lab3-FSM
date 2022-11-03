#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vlfsr_7.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env){
    int i;
    int clk; 

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vlfsr_7* top = new Vlfsr_7;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("lfsr_7.vcd");

    //init Vbuddy 
    if(vbdOpen()!=1) return(-1);
    vbdHeader("L3T1: PRBS");
    vbdSetMode(1);

    // initialize simulation inputs 
    top->clk = 1;
    top->rst = 0;
    top->en = 0;

    for(i=0; i<1000; i++){

         for (clk=0; clk<2; clk++) {
                tfp->dump (2*i+clk);
                top->clk = !top->clk;
                top->eval();
            }

        //Send count values to Vbuddy
        vbdHex(2, (int(top->data_out) >> 4) & 0xF);
        vbdHex(1, (int(top->data_out) & 0xF));

        //Display neopixels
        vbdBar(top->data_out & 0xFF);

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