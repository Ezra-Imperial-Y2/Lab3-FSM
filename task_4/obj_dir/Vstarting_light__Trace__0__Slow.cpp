// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vstarting_light__Syms.h"


VL_ATTR_COLD void Vstarting_light___024root__trace_init_sub__TOP__0(Vstarting_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+11,"clk", false,-1);
    tracep->declBit(c+12,"rst", false,-1);
    tracep->declBit(c+13,"trigger", false,-1);
    tracep->declBus(c+14,"lights", false,-1, 7,0);
    tracep->pushNamePrefix("starting_light ");
    tracep->declBit(c+11,"clk", false,-1);
    tracep->declBit(c+12,"rst", false,-1);
    tracep->declBit(c+13,"trigger", false,-1);
    tracep->declBus(c+14,"lights", false,-1, 7,0);
    tracep->declBit(c+1,"tick", false,-1);
    tracep->declBit(c+2,"time_out", false,-1);
    tracep->declBus(c+15,"data_out", false,-1, 6,0);
    tracep->declBit(c+7,"cmd_delay", false,-1);
    tracep->declBit(c+8,"cmd_seq", false,-1);
    tracep->pushNamePrefix("F1 ");
    tracep->declBit(c+11,"clk", false,-1);
    tracep->declBit(c+12,"rst", false,-1);
    tracep->declBit(c+9,"en", false,-1);
    tracep->declBit(c+13,"trigger", false,-1);
    tracep->declBus(c+14,"lights", false,-1, 7,0);
    tracep->declBit(c+8,"cmd_seq", false,-1);
    tracep->declBit(c+7,"cmd_delay", false,-1);
    tracep->declBus(c+3,"current_state", false,-1, 31,0);
    tracep->declBus(c+10,"next_state", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("delayer ");
    tracep->declBus(c+17,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+11,"clk", false,-1);
    tracep->declBit(c+12,"rst", false,-1);
    tracep->declBit(c+7,"trigger_delay", false,-1);
    tracep->declBus(c+15,"n", false,-1, 6,0);
    tracep->declBit(c+2,"time_out", false,-1);
    tracep->declBus(c+4,"count", false,-1, 6,0);
    tracep->declBus(c+5,"current_state", false,-1, 31,0);
    tracep->declBus(c+16,"next_state", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("lfsr7 ");
    tracep->declBit(c+11,"clk", false,-1);
    tracep->declBit(c+12,"rst", false,-1);
    tracep->declBit(c+18,"en", false,-1);
    tracep->declBus(c+15,"data_out", false,-1, 6,0);
    tracep->declBus(c+15,"sreg", false,-1, 7,1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("one_second ");
    tracep->declBus(c+19,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+11,"clk", false,-1);
    tracep->declBit(c+12,"rst", false,-1);
    tracep->declBit(c+8,"en", false,-1);
    tracep->declBus(c+20,"N", false,-1, 15,0);
    tracep->declBit(c+1,"tick", false,-1);
    tracep->declBus(c+6,"count", false,-1, 15,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vstarting_light___024root__trace_init_top(Vstarting_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root__trace_init_top\n"); );
    // Body
    Vstarting_light___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vstarting_light___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vstarting_light___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vstarting_light___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vstarting_light___024root__trace_register(Vstarting_light___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vstarting_light___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vstarting_light___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vstarting_light___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vstarting_light___024root__trace_full_sub_0(Vstarting_light___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vstarting_light___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root__trace_full_top_0\n"); );
    // Init
    Vstarting_light___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vstarting_light___024root*>(voidSelf);
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vstarting_light___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vstarting_light___024root__trace_full_sub_0(Vstarting_light___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstarting_light___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->starting_light__DOT__tick));
    bufp->fullBit(oldp+2,(((0U != vlSelf->starting_light__DOT__delayer__DOT__current_state) 
                           & ((1U != vlSelf->starting_light__DOT__delayer__DOT__current_state) 
                              & (2U == vlSelf->starting_light__DOT__delayer__DOT__current_state)))));
    bufp->fullIData(oldp+3,(vlSelf->starting_light__DOT__F1__DOT__current_state),32);
    bufp->fullCData(oldp+4,(vlSelf->starting_light__DOT__delayer__DOT__count),7);
    bufp->fullIData(oldp+5,(vlSelf->starting_light__DOT__delayer__DOT__current_state),32);
    bufp->fullSData(oldp+6,(vlSelf->starting_light__DOT__one_second__DOT__count),16);
    bufp->fullBit(oldp+7,(vlSelf->starting_light__DOT__cmd_delay));
    bufp->fullBit(oldp+8,(vlSelf->starting_light__DOT__cmd_seq));
    bufp->fullBit(oldp+9,(vlSelf->starting_light__DOT____Vcellinp__F1__en));
    bufp->fullIData(oldp+10,(vlSelf->starting_light__DOT__F1__DOT__next_state),32);
    bufp->fullBit(oldp+11,(vlSelf->clk));
    bufp->fullBit(oldp+12,(vlSelf->rst));
    bufp->fullBit(oldp+13,(vlSelf->trigger));
    bufp->fullCData(oldp+14,(vlSelf->lights),8);
    bufp->fullCData(oldp+15,(vlSelf->starting_light__DOT__lfsr7__DOT__sreg),7);
    bufp->fullIData(oldp+16,(((0U == vlSelf->starting_light__DOT__delayer__DOT__current_state)
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
    bufp->fullIData(oldp+17,(7U),32);
    bufp->fullBit(oldp+18,(1U));
    bufp->fullIData(oldp+19,(0x10U),32);
    bufp->fullSData(oldp+20,(0x2eU),16);
}
