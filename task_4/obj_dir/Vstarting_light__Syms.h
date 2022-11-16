// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSTARTING_LIGHT__SYMS_H_
#define VERILATED_VSTARTING_LIGHT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vstarting_light.h"

// INCLUDE MODULE CLASSES
#include "Vstarting_light___024root.h"

// SYMS CLASS (contains all model state)
class Vstarting_light__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vstarting_light* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vstarting_light___024root      TOP;

    // CONSTRUCTORS
    Vstarting_light__Syms(VerilatedContext* contextp, const char* namep, Vstarting_light* modelp);
    ~Vstarting_light__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
