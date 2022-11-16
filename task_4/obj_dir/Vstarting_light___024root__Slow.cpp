// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstarting_light.h for the primary calling header

#include "verilated.h"

#include "Vstarting_light__Syms.h"
#include "Vstarting_light___024root.h"

void Vstarting_light___024root___ctor_var_reset(Vstarting_light___024root* vlSelf);

Vstarting_light___024root::Vstarting_light___024root(Vstarting_light__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vstarting_light___024root___ctor_var_reset(this);
}

void Vstarting_light___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vstarting_light___024root::~Vstarting_light___024root() {
}
