// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vf1_tick__Syms.h"


void Vf1_tick___024root__trace_chg_sub_0(Vf1_tick___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vf1_tick___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_tick___024root__trace_chg_top_0\n"); );
    // Init
    Vf1_tick___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vf1_tick___024root*>(voidSelf);
    Vf1_tick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vf1_tick___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vf1_tick___024root__trace_chg_sub_0(Vf1_tick___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_tick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_tick___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(vlSelf->f1_tick__DOT__counter__DOT__count),16);
        bufp->chgIData(oldp+1,(vlSelf->f1_tick__DOT__lights_display__DOT__current_state),32);
        bufp->chgIData(oldp+2,(vlSelf->f1_tick__DOT__lights_display__DOT__next_state),32);
    }
    bufp->chgBit(oldp+3,(vlSelf->clk));
    bufp->chgBit(oldp+4,(vlSelf->rst));
    bufp->chgBit(oldp+5,(vlSelf->en));
    bufp->chgSData(oldp+6,(vlSelf->N),16);
    bufp->chgBit(oldp+7,(vlSelf->tick));
    bufp->chgCData(oldp+8,(vlSelf->lights),8);
}

void Vf1_tick___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_tick___024root__trace_cleanup\n"); );
    // Init
    Vf1_tick___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vf1_tick___024root*>(voidSelf);
    Vf1_tick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
