// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vstarting_light.h for the primary calling header

#ifndef VERILATED_VSTARTING_LIGHT___024ROOT_H_
#define VERILATED_VSTARTING_LIGHT___024ROOT_H_  // guard

#include "verilated.h"

class Vstarting_light__Syms;

class Vstarting_light___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(trigger,0,0);
    VL_OUT8(lights,7,0);
    CData/*0:0*/ starting_light__DOT__tick;
    CData/*0:0*/ starting_light__DOT__cmd_delay;
    CData/*0:0*/ starting_light__DOT__cmd_seq;
    CData/*0:0*/ starting_light__DOT____Vcellinp__F1__en;
    CData/*6:0*/ starting_light__DOT__lfsr7__DOT__sreg;
    CData/*6:0*/ starting_light__DOT__delayer__DOT__count;
    CData/*6:0*/ __Vdly__starting_light__DOT__lfsr7__DOT__sreg;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    CData/*0:0*/ __Vchglast__TOP__starting_light__DOT__cmd_delay;
    CData/*0:0*/ __Vchglast__TOP__starting_light__DOT__cmd_seq;
    SData/*15:0*/ starting_light__DOT__one_second__DOT__count;
    IData/*31:0*/ starting_light__DOT__delayer__DOT__current_state;
    IData/*31:0*/ starting_light__DOT__delayer__DOT__next_state;
    IData/*31:0*/ starting_light__DOT__F1__DOT__current_state;
    IData/*31:0*/ starting_light__DOT__F1__DOT__next_state;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vstarting_light__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vstarting_light___024root(Vstarting_light__Syms* symsp, const char* name);
    ~Vstarting_light___024root();
    VL_UNCOPYABLE(Vstarting_light___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
