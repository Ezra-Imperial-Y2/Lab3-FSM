

# Logbook: Lab 3
## Task 1: 4-bit LFSR and Pseudo Random Binary Sequence

- [Logbook: Lab 3](#logbook-lab-3)
  - [Task 1: 4-bit LFSR and Pseudo Random Binary Sequence](#task-1-4-bit-lfsr-and-pseudo-random-binary-sequence)
    - [What I did:](#what-i-did)
    - [Challenge:](#challenge)
    - [Problems encountered:](#problems-encountered)
    - [Other reflexions:](#other-reflexions)


### What I did: 
*  Programmed a 4-bit Linear Feedback Shift Register (LFSR: 
   *  **(1)** : Created the _lfsr.sv_ module from scratch. 
   *  This module is a 4-bit LFSR of the primitive polynomial _1 + X<sup>3</sup> + X<sup>4</sup>_
   *  It is a **shift register** with data_in feed in from an XOR gate with _0b3 xor 0b4_ 
   *  **. /!\ .** I needed to initialize the shift register to a value other than 4'b0000 otherwise the primitive polynomial would never increase. 
   *  **. /!\ .** No parameters because for different WIDTH, I need different primitive polynomial
   *  I added an _enable_ input to the module: 

```sv 
always_ff @(posedge clk, posedge rst) begin
    if (en)
     sreg <= {sreg[2:0], sreg[3] ^ sreg[2]}; //Concatenation of 4 bits: the 2 LSB are shifted and become MSB and the new two LSB are 0b'0 XOR 0b'1
    else if(rst)
        sreg <= 4'b1;
    else 
        sreg <= sreg;
end
```
* **(2)** In the *testbench*: 
  * Created a testbench from scratch to test the LFSR
  * Displaying the bits to the neopixels and the 7-segments display
  * Adding input stimuli for the digit only to implement when _vbdFlag()_ is pressed and resetting when the clock cycle < 2: 
* 
```cpp
if (i < 2) {
    top->rst = 1;
} else {
    top->rst = 0;
}

if(vbdFlag() == 1){
    top->en = 1;
} else {
    top->en = 0;
}
```

**EXPLANATION**:
* This piece of code checks if the value of *vbdFlag()* has been set to 1 (has been armed) ; if this condition evaluates to true, the enable is set to the 1. Else, nothing happens 

![schematic](./logbook_images/lfsr%20L3T1.png)

In the image above it can clearly be seen that when the rotary switch is pressed the value changes according to the pseudo-random sequence. 

++ In the testbench I had to change the TFT display to fit 8 bits instead of 4: 

```cpp
vbdHex(2, (int(top->data_out) >> 4) & 0xF);
        vbdHex(1, (int(top->data_out) & 0xF));
```

---
### Challenge:

The goal of this challenge is to change the LFSR to a 7-bit pseudorandom binary sequence (PRBS) : **primitive polynomial**: _1 + X<sup>3</sup> + X<sup>7</sup>_. As the primitive polynomial is changing from 4-bit to 7-bit I could not add parameters to my previous model. **THUS** I had to recreate a module *lfsr_7.sv* and a new testbench *lfsr_7_tb.cpp* to tailor the new design. The process is exactly the same as with 4-bit but instead of shifting the 2 LSB to the 2 MSB, I am now shifting the 6 LSB to the 6 MSB; and Xoring 0b7 with 0b3. 

![schematic](./logbook_images/lfsr_7%20L3T1.png)

In the image above it can clearly be seen that when the rotary switch is pressed the value changes according to the pseudo-random sequence.


---
### Problems encountered:

_None_

---
### Other reflexions: 

  **. /!\ .** No parameters because for different WIDTH, I need different circuits. 

