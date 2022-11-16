// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vstarting_light__Syms.h"


void Vstarting_light___024root__trace_chg_sub_0(Vstarting_light___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vstarting_light___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root__trace_chg_top_0\n"); );
    // Init
    Vstarting_light___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vstarting_light___024root*>(voidSelf);
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vstarting_light___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vstarting_light___024root__trace_chg_sub_0(Vstarting_light___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->starting_light__DOT__tick));
        bufp->chgBit(oldp+1,(((0U != vlSelf->starting_light__DOT__delayer__DOT__current_state) 
                              & ((1U != vlSelf->starting_light__DOT__delayer__DOT__current_state) 
                                 & (2U == vlSelf->starting_light__DOT__delayer__DOT__current_state)))));
        bufp->chgIData(oldp+2,(vlSelf->starting_light__DOT__F1__DOT__current_state),32);
        bufp->chgCData(oldp+3,(vlSelf->starting_light__DOT__delayer__DOT__count),7);
        bufp->chgIData(oldp+4,(vlSelf->starting_light__DOT__delayer__DOT__current_state),32);
        bufp->chgSData(oldp+5,(vlSelf->starting_light__DOT__one_second__DOT__count),16);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+6,(vlSelf->starting_light__DOT__cmd_delay));
        bufp->chgBit(oldp+7,(vlSelf->starting_light__DOT__cmd_seq));
        bufp->chgBit(oldp+8,(vlSelf->starting_light__DOT____Vcellinp__F1__en));
        bufp->chgIData(oldp+9,(vlSelf->starting_light__DOT__F1__DOT__next_state),32);
    }
    bufp->chgBit(oldp+10,(vlSelf->clk));
    bufp->chgBit(oldp+11,(vlSelf->rst));
    bufp->chgBit(oldp+12,(vlSelf->trigger));
    bufp->chgCData(oldp+13,(vlSelf->lights),8);
    bufp->chgCData(oldp+14,(vlSelf->starting_light__DOT__lfsr7__DOT__sreg),7);
    bufp->chgIData(oldp+15,(((0U == vlSelf->starting_light__DOT__delayer__DOT__current_state)
                              ? ((IData)(vlSelf->starting_light__DOT__cmd_delay)
                                  ? 1U : vlSelf->starting_light__DOT__delayer__DOT__current_state)
                              : ((1U == vlSelf->starting_light__DOT__delayer__DOT__current_state)
                                  ? ((0U == (IData)(vlSelf->starting_light__DOT__delayer__DOT__count))
                                      ? 2U : vlSelf->starting_light__DOT__delayer__DOT__current_state)
                                  : ((2U == vlSelf->starting_light__DOT__delayer__DOT__current_state)
                                      ? ((IData)(vlSelf->starting_light__DOT__cmd_delay)
                                          ? 3U : 0U)
                                      : ((3U == vlSelf->starting_light__DOT__delayer__DOT__current_state)
                                          ? ((IData)(vlSelf->starting_light__DOT__cmd_delay)
                                              ? vlSelf->starting_light__DOT__delayer__DOT__current_state
                                              : 0U)
                                          : 0U))))),32);
}

void Vstarting_light___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root__trace_cleanup\n"); );
    // Init
    Vstarting_light___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vstarting_light___024root*>(voidSelf);
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
