

# Logbook: Lab 3
## Task 3: Exploring the clktick.sv and the delay.sv modules

- [Logbook: Lab 3](#logbook-lab-3)
  - [Task 3: Exploring the clktick.sv and the delay.sv modules](#task-3-exploring-the-clkticksv-and-the-delaysv-modules)
    - [What I did:](#what-i-did)
    - [Challenge:](#challenge)
    - [Problems encountered:](#problems-encountered)
    - [Other reflexions:](#other-reflexions)

### What I did: 
* Calibrated the *clktick.sv* module  to find what value of N gives us a tick period of 1 sec.
  * It has an internal counter whose output is not visible external to this module 
  * The circuit generates a ***single clock pulse*** every **N+1 rising edge** of the clock input signal clock
  * The enable signal is always set to 1 
  * The internal parameter is used to define the number of bits of the internal counter &rarr; adaptable to different counter size
  * The output tick has to be declared as *reg* because its value is updated inside the *always* block
  * **Warning** Instead of adding 1 on each positive edge of the clock, this design uses a **down counter**. The counter counts from N to 0 (N+1 clock cycles). What then happens, it is reset to N and the tick output is high for the next clock cycle. 
  * **RESULT OF CALIBRATION**: vbdValue() = **54** for a 1 second tick delay

![schematic](./logbook_images/clktick%20%20L3T3.png)

    This waveform shows how the rotary switch changes the value of N and this the time elapsed between each tick delay (flash rate of the neopixels).  

    The reason that we need to do this calibration is that the Verilator simulation of your design is NOT in real time. Every computer will work at different rate and therefore takes different amount of time to simulate one cycle of the clock signal clk.

---
### Challenge: 

* Implemented the following design y combining clkctick.sv with f1_fsm.sv so that the F1 light sequence is cycle through automatically with 1 second delay per state transition: 

![schematic](./logbook_images/f1_sequence%20L3Tchallenge.jpg)

* To do that I had to create a top-layer module called *f1_tick.sv*: 
  * This module combines clkctick.sv with f1_fsm.sv

    ``` sv
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
    ```
* I also had to create a *testbench*:
  * This testbench is very similar to the one already provided in the repo. However there are some differences: 
  * The neopixel display is done 1 by 1 so the way to do it is: 

    ```cpp
    // Display toggle neopixel
        if (top->tick) {
        vbdBar(top->lights & 0xFF);
        }
    ```
  * **EXPLANATION**: $\newline$
  This code will only display the value of the neopixels (provided by the FSM done in task 2) one by one when a tick occurs

  * Another difference is that instead of using vbdValue() to change the flash rate of the neopixel I hard-coded it using the result of my calibration done in task 3: 

    ```cpp
    top->N = int(77);
    ```
![schematic](./logbook_images/f1_tick%20challenge%20L3T3.png)

The image above shows that the increment of the FSM only occurs at every tick (every 1 second). The implementation is working correctly! The 3rd waveform is the value of N. 

---
### Problems encountered:

My calibration value of N in *clktick_tb.cpp* did not match when I used it in *f1_tick_tb.cpp*. I suspect that my computer did not work at the same rate when simultating the two different testbenches. 
* **FIX**: I recalibrated my value of N in the challenge and found **74** 

---
### Other reflexions: 

_None_

