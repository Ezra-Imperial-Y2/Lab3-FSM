// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstarting_light.h for the primary calling header

#include "verilated.h"

#include "Vstarting_light___024root.h"

VL_INLINE_OPT void Vstarting_light___024root___sequent__TOP__0(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__starting_light__DOT__lfsr7__DOT__sreg 
        = vlSelf->starting_light__DOT__lfsr7__DOT__sreg;
    vlSelf->__Vdly__starting_light__DOT__lfsr7__DOT__sreg 
        = ((IData)(vlSelf->rst) ? 1U : ((0x7eU & ((IData)(vlSelf->starting_light__DOT__lfsr7__DOT__sreg) 
                                                  << 1U)) 
                                        | (1U & VL_REDXOR_8(
                                                            (0x44U 
                                                             & (IData)(vlSelf->starting_light__DOT__lfsr7__DOT__sreg))))));
}

VL_INLINE_OPT void Vstarting_light___024root___sequent__TOP__1(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___sequent__TOP__1\n"); );
    // Init
    SData/*15:0*/ __Vdly__starting_light__DOT__one_second__DOT__count;
    // Body
    __Vdly__starting_light__DOT__one_second__DOT__count 
        = vlSelf->starting_light__DOT__one_second__DOT__count;
    vlSelf->starting_light__DOT__delayer__DOT__count 
        = (0x7fU & ((((IData)(vlSelf->rst) | (IData)(vlSelf->starting_light__DOT__cmd_delay)) 
                     | (0U == (IData)(vlSelf->starting_light__DOT__delayer__DOT__count)))
                     ? ((IData)(vlSelf->starting_light__DOT__lfsr7__DOT__sreg) 
                        - (IData)(1U)) : ((IData)(vlSelf->starting_light__DOT__delayer__DOT__count) 
                                          - (IData)(1U))));
    if (vlSelf->rst) {
        vlSelf->starting_light__DOT__F1__DOT__current_state = 8U;
        vlSelf->starting_light__DOT__tick = 0U;
        __Vdly__starting_light__DOT__one_second__DOT__count = 0x2eU;
        vlSelf->starting_light__DOT__delayer__DOT__current_state = 0U;
    } else {
        vlSelf->starting_light__DOT__F1__DOT__current_state 
            = vlSelf->starting_light__DOT__F1__DOT__next_state;
        if (vlSelf->starting_light__DOT__cmd_seq) {
            if ((0U == (IData)(vlSelf->starting_light__DOT__one_second__DOT__count))) {
                vlSelf->starting_light__DOT__tick = 1U;
                __Vdly__starting_light__DOT__one_second__DOT__count = 0x2eU;
            } else {
                __Vdly__starting_light__DOT__one_second__DOT__count 
                    = (0xffffU & ((IData)(vlSelf->starting_light__DOT__one_second__DOT__count) 
                                  - (IData)(1U)));
                vlSelf->starting_light__DOT__tick = 0U;
            }
        }
        vlSelf->starting_light__DOT__delayer__DOT__current_state 
            = vlSelf->starting_light__DOT__delayer__DOT__next_state;
    }
    vlSelf->starting_light__DOT__one_second__DOT__count 
        = __Vdly__starting_light__DOT__one_second__DOT__count;
}

VL_INLINE_OPT void Vstarting_light___024root___sequent__TOP__2(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___sequent__TOP__2\n"); );
    // Body
    vlSelf->starting_light__DOT__lfsr7__DOT__sreg = vlSelf->__Vdly__starting_light__DOT__lfsr7__DOT__sreg;
}

VL_INLINE_OPT void Vstarting_light___024root___combo__TOP__0(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___combo__TOP__0\n"); );
    // Body
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
    vlSelf->starting_light__DOT____Vcellinp__F1__en 
        = ((IData)(vlSelf->starting_light__DOT__cmd_seq)
            ? (IData)(vlSelf->starting_light__DOT__tick)
            : ((0U != vlSelf->starting_light__DOT__delayer__DOT__current_state) 
               & ((1U != vlSelf->starting_light__DOT__delayer__DOT__current_state) 
                  & (2U == vlSelf->starting_light__DOT__delayer__DOT__current_state))));
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

void Vstarting_light___024root___eval(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vstarting_light___024root___sequent__TOP__0(vlSelf);
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vstarting_light___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vstarting_light___024root___sequent__TOP__2(vlSelf);
    }
    Vstarting_light___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

QData Vstarting_light___024root___change_request_1(Vstarting_light___024root* vlSelf);

VL_INLINE_OPT QData Vstarting_light___024root___change_request(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___change_request\n"); );
    // Body
    return (Vstarting_light___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vstarting_light___024root___change_request_1(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSelf->starting_light__DOT__cmd_delay ^ vlSelf->__Vchglast__TOP__starting_light__DOT__cmd_delay)
         | (vlSelf->starting_light__DOT__cmd_seq ^ vlSelf->__Vchglast__TOP__starting_light__DOT__cmd_seq));
    VL_DEBUG_IF( if(__req && ((vlSelf->starting_light__DOT__cmd_delay ^ vlSelf->__Vchglast__TOP__starting_light__DOT__cmd_delay))) VL_DBG_MSGF("        CHANGE: starting_light.sv:13: starting_light.cmd_delay\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->starting_light__DOT__cmd_seq ^ vlSelf->__Vchglast__TOP__starting_light__DOT__cmd_seq))) VL_DBG_MSGF("        CHANGE: starting_light.sv:14: starting_light.cmd_seq\n"); );
    // Final
    vlSelf->__Vchglast__TOP__starting_light__DOT__cmd_delay 
        = vlSelf->starting_light__DOT__cmd_delay;
    vlSelf->__Vchglast__TOP__starting_light__DOT__cmd_seq 
        = vlSelf->starting_light__DOT__cmd_seq;
    return __req;
}

#ifdef VL_DEBUG
void Vstarting_light___024root___eval_debug_assertions(Vstarting_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
}
#endif  // VL_DEBUG
