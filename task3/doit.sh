#!/bin/sh

#cleanup
rm -rf obj_dir
rm -f f1_tick.vcd

#run Verilator to translate Verilog into C++ testbench
verilator -Wall --cc --trace f1_tick.sv --exe f1_tick_tb.cpp

#build c++ project via make automatically generated by Verilator 
make -j -C obj_dir/ -f Vf1_tick.mk Vf1_tick

#run executable simulation file
obj_dir/Vf1_tick
