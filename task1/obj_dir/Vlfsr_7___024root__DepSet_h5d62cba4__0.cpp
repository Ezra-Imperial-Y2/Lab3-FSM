// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlfsr_7.h for the primary calling header

#include "verilated.h"

#include "Vlfsr_7___024root.h"

VL_INLINE_OPT void Vlfsr_7___024root___sequent__TOP__0(Vlfsr_7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlfsr_7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr_7___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->lfsr7__DOT__sreg = ((IData)(vlSelf->en)
                                 ? ((0xfeU & ((IData)(vlSelf->lfsr7__DOT__sreg) 
                                              << 1U)) 
                                    | (1U & VL_REDXOR_8(
                                                        (0x88U 
                                                         & (IData)(vlSelf->lfsr7__DOT__sreg)))))
                                 : ((IData)(vlSelf->rst)
                                     ? 1U : (IData)(vlSelf->lfsr7__DOT__sreg)));
    vlSelf->data_out = vlSelf->lfsr7__DOT__sreg;
}

void Vlfsr_7___024root___eval(Vlfsr_7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlfsr_7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr_7___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vlfsr_7___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vlfsr_7___024root___eval_debug_assertions(Vlfsr_7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlfsr_7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr_7___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
