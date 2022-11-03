#!/bin/sh

#cleanup
rm -rf obj_dir
rm -f lfsr_7.vcd

#run Verilator to translate Verilog into C++ testbench
verilator -Wall --cc --trace lfsr_7.sv --exe lfsr_7_tb.cpp

#build c++ project via make automatically generated by Verilator 
make -j -C obj_dir/ -f Vlfsr_7.mk Vlfsr_7

#run executable simulation file
obj_dir/Vlfsr_7
