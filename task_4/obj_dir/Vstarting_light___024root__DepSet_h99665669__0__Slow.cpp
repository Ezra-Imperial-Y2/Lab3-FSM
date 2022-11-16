// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstarting_light.h for the primary calling header

#include "verilated.h"

#include "Vstarting_light___024root.h"

VL_ATTR_COLD void Vstarting_light___024root___initial__TOP__0(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___initial__TOP__0\n"); );
    // Body
    vlSelf->starting_light__DOT__F1__DOT__current_state = 8U;
    vlSelf->starting_light__DOT__delayer__DOT__count = 0U;
}

VL_ATTR_COLD void Vstarting_light___024root___settle__TOP__0(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->starting_light__DOT____Vcellinp__F1__en 
        = ((IData)(vlSelf->starting_light__DOT__cmd_seq)
            ? (IData)(vlSelf->starting_light__DOT__tick)
            : ((0U != vlSelf->starting_light__DOT__delayer__DOT__current_state) 
               & ((1U != vlSelf->starting_light__DOT__delayer__DOT__current_state) 
                  & (2U == vlSelf->starting_light__DOT__delayer__DOT__current_state))));
    vlSelf->starting_light__DOT__delayer__DOT__next_state 
        = ((0U == vlSelf->starting_light__DOT__delayer__DOT__current_state)
            ? ((IData)(vlSelf->starting_light__DOT__cmd_delay)
                ? 1U : vlSelf->starting_light__DOT__delayer__DOT__current_state)
            : ((1U == vlSelf->starting_light__DOT__delayer__DOT__current_state)
                ? ((0U == (IData)(vlSelf->starting_light__DOT__delayer__DOT__count))
                    ? 2U : vlSelf->starting_light__DOT__delayer__DOT__current_state)
                : ((2U == vlSelf->starting_light__DOT__delayer__DOT__current_state)
                    ? ((IData)(vlSelf->starting_light__DOT__cmd_delay)
                        ? 3U : 0U) : ((3U == vlSelf->starting_light__DOT__delayer__DOT__current_state)
                                       ? ((IData)(vlSelf->starting_light__DOT__cmd_delay)
                                           ? vlSelf->starting_light__DOT__delayer__DOT__current_state
                                           : 0U) : 0U))));
    if (((IData)(vlSelf->trigger) & (~ (IData)(vlSelf->starting_light__DOT__cmd_delay)))) {
        vlSelf->starting_light__DOT__cmd_seq = 1U;
    }
    if (vlSelf->starting_light__DOT____Vcellinp__F1__en) {
        if (((((((((8U == vlSelf->starting_light__DOT__F1__DOT__current_state) 
                   | (0U == vlSelf->starting_light__DOT__F1__DOT__current_state)) 
                  | (1U == vlSelf->starting_light__DOT__F1__DOT__current_state)) 
                 | (2U == vlSelf->starting_light__DOT__F1__DOT__current_state)) 
                | (3U == vlSelf->starting_light__DOT__F1__DOT__current_state)) 
               | (4U == vlSelf->starting_light__DOT__F1__DOT__current_state)) 
              | (5U == vlSelf->starting_light__DOT__F1__DOT__current_state)) 
             | (6U == vlSelf->starting_light__DOT__F1__DOT__current_state))) {
            if ((8U == vlSelf->starting_light__DOT__F1__DOT__current_state)) {
                vlSelf->starting_light__DOT__F1__DOT__next_state = 0U;
                vlSelf->lights = 0U;
                vlSelf->starting_light__DOT__cmd_seq = 0U;
                vlSelf->starting_light__DOT__cmd_delay = 0U;
            } else if ((0U == vlSelf->starting_light__DOT__F1__DOT__current_state)) {
                vlSelf->starting_light__DOT__F1__DOT__next_state = 1U;
                vlSelf->lights = 1U;
                vlSelf->starting_light__DOT__cmd_seq = 1U;
                vlSelf->starting_light__DOT__cmd_delay = 0U;
            } else if ((1U == vlSelf->starting_light__DOT__F1__DOT__current_state)) {
                vlSelf->starting_light__DOT__F1__DOT__next_state = 2U;
                vlSelf->lights = 3U;
            } else if ((2U == vlSelf->starting_light__DOT__F1__DOT__current_state)) {
                vlSelf->starting_light__DOT__F1__DOT__next_state = 3U;
                vlSelf->lights = 7U;
            } else if ((3U == vlSelf->starting_light__DOT__F1__DOT__current_state)) {
                vlSelf->starting_light__DOT__F1__DOT__next_state = 4U;
                vlSelf->lights = 0xfU;
            } else if ((4U == vlSelf->starting_light__DOT__F1__DOT__current_state)) {
                vlSelf->starting_light__DOT__F1__DOT__next_state = 5U;
                vlSelf->lights = 0x1fU;
            } else if ((5U == vlSelf->starting_light__DOT__F1__DOT__current_state)) {
                vlSelf->starting_light__DOT__F1__DOT__next_state = 6U;
                vlSelf->lights = 0x3fU;
            } else {
                vlSelf->starting_light__DOT__F1__DOT__next_state = 7U;
                vlSelf->lights = 0x7fU;
            }
        } else {
            vlSelf->starting_light__DOT__F1__DOT__next_state = 8U;
            if ((7U == vlSelf->starting_light__DOT__F1__DOT__current_state)) {
                vlSelf->lights = 0xffU;
                vlSelf->starting_light__DOT__cmd_seq = 0U;
                vlSelf->starting_light__DOT__cmd_delay = 1U;
            } else {
                vlSelf->lights = 0U;
            }
        }
    }
}

VL_ATTR_COLD void Vstarting_light___024root___eval_initial(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___eval_initial\n"); );
    // Body
    Vstarting_light___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vstarting_light___024root___eval_settle(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___eval_settle\n"); );
    // Body
    Vstarting_light___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vstarting_light___024root___final(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___final\n"); );
}

VL_ATTR_COLD void Vstarting_light___024root___ctor_var_reset(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->trigger = VL_RAND_RESET_I(1);
    vlSelf->lights = VL_RAND_RESET_I(8);
    vlSelf->starting_light__DOT__tick = VL_RAND_RESET_I(1);
    vlSelf->starting_light__DOT__cmd_delay = VL_RAND_RESET_I(1);
    vlSelf->starting_light__DOT__cmd_seq = VL_RAND_RESET_I(1);
    vlSelf->starting_light__DOT____Vcellinp__F1__en = VL_RAND_RESET_I(1);
    vlSelf->starting_light__DOT__lfsr7__DOT__sreg = VL_RAND_RESET_I(7);
    vlSelf->starting_light__DOT__delayer__DOT__count = VL_RAND_RESET_I(7);
    vlSelf->starting_light__DOT__delayer__DOT__current_state = 0;
    vlSelf->starting_light__DOT__delayer__DOT__next_state = 0;
    vlSelf->starting_light__DOT__one_second__DOT__count = VL_RAND_RESET_I(16);
    vlSelf->starting_light__DOT__F1__DOT__current_state = 0;
    vlSelf->starting_light__DOT__F1__DOT__next_state = 0;
    vlSelf->__Vdly__starting_light__DOT__lfsr7__DOT__sreg = VL_RAND_RESET_I(7);
    vlSelf->__Vchglast__TOP__starting_light__DOT__cmd_delay = VL_RAND_RESET_I(1);
    vlSelf->__Vchglast__TOP__starting_light__DOT__cmd_seq = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
