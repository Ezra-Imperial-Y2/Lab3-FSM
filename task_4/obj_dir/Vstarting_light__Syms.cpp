// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vstarting_light__Syms.h"
#include "Vstarting_light.h"
#include "Vstarting_light___024root.h"

// FUNCTIONS
Vstarting_light__Syms::~Vstarting_light__Syms()
{
}

Vstarting_light__Syms::Vstarting_light__Syms(VerilatedContext* contextp, const char* namep, Vstarting_light* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
