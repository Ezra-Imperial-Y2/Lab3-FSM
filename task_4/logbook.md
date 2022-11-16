

# Logbook: Lab 3
## Task 4: Full implementation of F1 starting light (OPTIONAL)



- [Logbook: Lab 3](#logbook-lab-3)
  - [Task 4: Full implementation of F1 starting light (OPTIONAL)](#task-4-full-implementation-of-f1-starting-light-optional)
    - [What I did:](#what-i-did)
    - [Problems encountered:](#problems-encountered)

    - [Other reflexions:](#other-reflexions)

![schematic](./logbook_images/F1_complete%20L3T4.png)



### What I did: 
* Created a full desgin for the F1 starting lights by combining previously designed modules, using provided modules and creating new ones: 

* *Previously desgined* : 
  * <ins>__clktick__</ins>: This module sends a pulse at every 1 sec delay &rarr; changing the state of the FSM so that 1 extra light turns on every second. It is enabled by cmd_seq signal.
 ![schematic](./logbook_images/L3T4%20clktick.png)
  * <ins>__delay__</ins>: This module has a trigger input and when it is asserted (goes from low to high), it starts counting K clock cycles. As it is connected to the LFSR module, the number of K cycles before it releases the input time_out is pseudo-random
 ![schematic](./logbook_images/L3T4%20delay%20.png)
  * <ins>__lfsr_7__</ins>: This module imitates a pseudo-random 7 bits sequence.
 ![schematic](./logbook_images/L3T4%20time_out-start.png) 
  * We can see that when cmd_delay goes high; the countdown starts in S_8. The values of data_out (delay) are passed to K (= delay - 1)
  ![schematic](./logbook_images/L3T4%20time_out-end.png)
  * The countdown continues until K reaches 0. Then, time_out goes high &rarr; S_8 changes to S_0, all the lights are off. The user needs to press the trigger. 
 
* *New modules*: 
  * <ins>**f1_fsm**</ins>: This module is very similar to the FSM created in Task 2. Except that it include: 
    * A trigger input: It kicks off the whole sequence and is controlled by vbdFlag()
    * A cmd_seq output: Which is high during the sequencing of data_out[7:0] from 8'b1 to 8'b11111111. (See diagram above)
    * A cmd_delay: Which triggers the start of the delay.sv component.
  
* These changes made me redesign the module quite a bit: 

1. I needed to make the sequence start IF enable = 1, (enable is controlled by the MUX). 
2. Added new output specifications in the ``` always_comb ```  block:   
    * If trigger is on and cmd_delay is off then we are starting the sequencing of the F1 lights THUS cmd_seq has to be high
      ![schematic](./logbook_images/L3T4%20start_sequence.png) 
    * If we are in S_8, the lights sequencing is over (cmd_seq = 0) and we are waiting for the time_out impulse to turn all the lights off (cmd_delay = 1)
     ![schematic](./logbook_images/L3T4%20end_sequence.png)
   * If we are in S_0 but no trigger has been pressed, we should wait for it and nothing has to happen (cmd_seq & cmd_delay = 0)
     ![schematic](./logbook_images/L3T4%20S_0.png)
   * If we are in S_1 then it means a trigger has been pressed; we entered the lights sequencing THUS (cmd_seq = 1)
    ![schematic](./logbook_images/L3T4%20pressed_trigger.png)
  
    * <ins> **starting_light** </ins>: This is the top-layer module, it connects everything together. To do it I simply had to look at the diagram depicted above. **HOWEVER** I added a feature to it; instead of creating a module for the MUX component (controlling the enable pin of the FSM) I simply implemented it that way: 
```sv
.en (cmd_seq ? tick : time_out),
```
**TRANSLATION**: 
```cpp
if (cmd_seq == 1){
    .en(tick);
} else {
    .en(time_out);
}

```

* <ins> **Testbench** </ins>: The testbench simulates the whole design. 
1. Once all the lights are OFF after a random delay, the testbench calls vbdInitWatch() function to start Vbuddy's stop watch.
2. User reacts to the lights going OFF and presses the switch as quickly as possible. Vbuddy automatically records the elapsed time since the stop watch started.
3. The testbench calls vbdElapsed() function to read the reaction time in milliseconds.
4. The testbench reports by sending it to Vbuddy as a message on the TFT screen.

To implement this I am checking different conditons: 
1. Are all the lights on?
1. Have all the lights turned off after being on?
1. Has the rotary switch been pressed after the all the lights turned off? If so, how much time has elapsed between these 2 events?
1. If none of these events happened, wait for the user to press the rotary switch to start the sequencing. 

I am wrapping these questions in different If/Else statements and asserting or not internal flags for my program to know on which step the user currently is. 

---
### Problems encountered:

* I needed to change my design for lfrs_7. As I struggled to find that if my _if (en)_ condtion was checked before my _if (rst)_ condition then no signal would be sent to the delay module and thus the design would not work 
    /!\ Ask for clarification /!\ 
* I needed to change my state enumeration in my FSM (starting with S_1 instead of S_0) otherwise I would need to press the trigger twice to start the sequencing. This action would make my cmd_seq and cmd_delay signals act weirdly. 
---
### Other reflexions: 

_None_

