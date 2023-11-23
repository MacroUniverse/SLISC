#pragma once
// constants and conversion functions
// ref: wuli.wiki/online/Consts.html, AU.html

#include "../global.h"

namespace slisc {

// ======= conversion for atomic unit =============

// (verified)
inline Doub eV2au_E(Doub_I eV) { return (c::qe/c::au_E) * eV; }

// (verified)
inline Doub nm2au_E(Doub_I nm) { return (c::h*c::c0*1e9/c::au_E) / nm; }

// (verified)
inline Doub as2au_t(Doub_I as) { return as / (c::au_t*1e18); }

// (verified)
inline Doub w_cm22au_Ef(Doub_I w_cm2) { return sqrt(w_cm2/(0.5e-4*c::epsilon0*c::c0))/c::au_Ef; }

// (verified)
inline Doub nm2au_t(Doub_I nm) { return nm / (1e9*c::c0*c::au_t); }



} // namespace slisc
