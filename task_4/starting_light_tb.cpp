#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vstarting_light.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 100000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int lights = 0; // state to toggle LED lights

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vstarting_light *top = new Vstarting_light;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("starting_light.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T4: F1");
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation inputs
  top->clk = 1;
  top->rst = 0;
 
  bool ReadyToTime = false;
  bool TimingMode = false;
  bool Flag = false;
  
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    // Reset for 1st cycle 
    if (simcyc < 2){
      top->rst = 1;
    } else {
      top->rst = 0;
    };    

    //Displaying output lights on the Neopixels
    vbdBar(top->lights & 0xFF);

    if (top->lights == 0b11111111){
      ReadyToTime = true; // Making sure that the FSM has finished its sequence 
    } 

    if (ReadyToTime && top->lights == 0) {
    
       //  If FSM finished successfully and time_out turned all the lights off THEN start stopwatch 
      
      TimingMode = true;
      ReadyToTime = false;
      vbdInitWatch();
    }
    
    // set up input signals of testbench
    Flag = vbdFlag();

    if (TimingMode && Flag) {

      // If stopwatch has been started and the rotary switch has been pressed THEN stop stopwatch and display the result and the TFT displa
      
      int result = vbdElapsed();

      vbdHex(1, (int)(result % 10) & 0xFF); // print just digits
      vbdHex(2, (int)(result / 10 % 10) & 0xFF);
      vbdHex(3, (int)(result / 100 % 10) & 0xFF);
      vbdHex(4, (int)(result / 1000 % 10) & 0xFF);
      vbdHex(5, (int)(result / 10000 % 10) & 0xFF);
      
      TimingMode = false;

    } else {
      top->trigger = Flag;
    }

    vbdCycle(simcyc);

    if (Verilated::gotFinish() || (vbdGetkey()=='q')) {
      vbdClose();
      tfp->close();
      exit(0);
    } 
  }

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}
