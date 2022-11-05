

# Logbook: Lab 3
## Task 2: Formula 1 Light Sequence 

- [Logbook: Lab 3](#logbook-lab-3)
  - [Task 2: Formula 1 Light Sequence](#task-2-formula-1-light-sequence)
    - [What I did:](#what-i-did)
    - [Problems encountered:](#problems-encountered)
    - [Other reflexions:](#other-reflexions)


### What I did: 
* Designed a FSM that cycles through the sequence according to the following FSM: 
![schematic](./logbook_images/FSM%20sequence%20L3T2.png)

    This is a Formula 1 Racing starting light sequence. They turn on whenever the enable button is pressed 
* The enable signal is driven by the rotary switch set to mode 1. Whenever the button is pressed a light turns on. When it reaches 8 it automatically resets to 0 and waits for an enable signal. 
* In *f1_fsm.sv* : 
  * Create a FSM module with 9 states; each corresponding to 0 to 8 neopixels turned on:

    ```sv
    typedef enum {S_0, S_1, S_2, S_3, S_4, S_5, S_6, S_7, S_8} my_state;

    ```
   * To manage the **next state logic** I am adding the condition that if the enable button is not pressed then *next_state = current_state*. When enable is pressed an additional light turns on. 
   * To manage the **state transition** I am setting that if reset happens, the lights go back to state 0, otherwise *current_state = next_state*. 
   * To manage the **output logic** I am setting state 0-9 to 0-9 ones respectively. This assings the number to the output that will be displayed on the neopixels in the testbench. 

* In the *testbench*: 
  * Displaying the neopixels using the onboard method: 
    ```cpp
    //Display neopixels
    vbdBar(top->lights & 0xFF);
    ```
  * Adding the **control logic** of the enable input: 
    ```cpp
      if(vbdFlag() == 1){
            top->en = 1;
            usleep(1000);
        } else {
            top->en = 0;
        }
    ```
  * **EXPLANATION**: $\newline$
  This piece of code checks if the value of *vbdFlag()* has been set to 1 (has been armed) ; if this condition evaluates to true, the enable is set to the 1. Else, nothing happens 

    $\newline$
  

![schematic](./logbook_images/f1_lights%20L3T2.png)

In the image above it can clearly be seen that when the rotary switch is pressed the light value changes. When it reaches 0'b11111111 it automatically resets to 0.  

---
### Problems encountered:

_None_

---
### Other reflexions: 

_None_

