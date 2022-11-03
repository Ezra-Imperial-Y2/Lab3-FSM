// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlfsr_7.h for the primary calling header

#include "verilated.h"

#include "Vlfsr_7__Syms.h"
#include "Vlfsr_7___024root.h"

void Vlfsr_7___024root___ctor_var_reset(Vlfsr_7___024root* vlSelf);

Vlfsr_7___024root::Vlfsr_7___024root(Vlfsr_7__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vlfsr_7___024root___ctor_var_reset(this);
}

void Vlfsr_7___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vlfsr_7___024root::~Vlfsr_7___024root() {
}
