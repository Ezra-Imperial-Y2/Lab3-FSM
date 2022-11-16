// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vstarting_light.h"
#include "Vstarting_light__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vstarting_light::Vstarting_light(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vstarting_light__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , trigger{vlSymsp->TOP.trigger}
    , lights{vlSymsp->TOP.lights}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vstarting_light::Vstarting_light(const char* _vcname__)
    : Vstarting_light(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vstarting_light::~Vstarting_light() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vstarting_light___024root___eval_initial(Vstarting_light___024root* vlSelf);
void Vstarting_light___024root___eval_settle(Vstarting_light___024root* vlSelf);
void Vstarting_light___024root___eval(Vstarting_light___024root* vlSelf);
QData Vstarting_light___024root___change_request(Vstarting_light___024root* vlSelf);
#ifdef VL_DEBUG
void Vstarting_light___024root___eval_debug_assertions(Vstarting_light___024root* vlSelf);
#endif  // VL_DEBUG
void Vstarting_light___024root___final(Vstarting_light___024root* vlSelf);

static void _eval_initial_loop(Vstarting_light__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vstarting_light___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vstarting_light___024root___eval_settle(&(vlSymsp->TOP));
        Vstarting_light___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vstarting_light___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("starting_light.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vstarting_light___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vstarting_light::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vstarting_light::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vstarting_light___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vstarting_light___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vstarting_light___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("starting_light.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vstarting_light___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vstarting_light::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vstarting_light::final() {
    Vstarting_light___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vstarting_light::hierName() const { return vlSymsp->name(); }
const char* Vstarting_light::modelName() const { return "Vstarting_light"; }
unsigned Vstarting_light::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vstarting_light::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vstarting_light___024root__trace_init_top(Vstarting_light___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vstarting_light___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vstarting_light___024root*>(voidSelf);
    Vstarting_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vstarting_light___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vstarting_light___024root__trace_register(Vstarting_light___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vstarting_light::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vstarting_light___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
