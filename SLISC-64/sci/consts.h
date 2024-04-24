#pragma once
// constants and conversion functions
// ref: wuli.wiki/online/Consts.html, AU.html

#include "../global.h"

namespace slisc {

namespace c {
	// exact
	constexpr Doub
	c0 = 299792458,                   // speed of light
	h = 6.62607015e-34,               // Plank constant
	hbar = h/(2*PI),                  // reduced Plank constant
	qe = 1.602176634e-19,             // elementary charge
	Na = 6.02214076e23,               // Avogadro constant
	kb = 1.380649e-23,                // Boltzmann constant
	R = Na*kb,                        // gas constant
	u = 0.9999999996530e-3/Na,        // atomic mass unit
	AU = 149597870700,                // astronomical unit
	ly = c0*3600*24*365.25,           // light-year

	// measured
	mu0 = 1.25663706212e-6,                // vacuum permeability
	epsilon0 = 1/(mu0*c0*c0),              // vacuum permittivity
	k = 1/(4*PI*epsilon0),                 // Coulomb's constant
	G = 6.67430e-11,                       // gravitational constant
	alpha = qe*qe/(4*PI*epsilon0*hbar*c0), // fine structure constant
	me = 9.1093837015e-31,                 // electron mass
	mp = 1.67262192369e-27,                // proton mass
	Rh = 1.0973731568160e7,                // Rydberg constant
	a0 = 5.29177210903e-11,                // Bohr radius

	// conversion constants
	inch = 2.54e-2,                   // length
	gauss = 1e-4,                     // electric field
	mile = 6.09e+2,                   // length
	lb = 0.454, pound=0.454,          // mass
	au_x = a0,                        // 1 a.u. distance
	au_t = me*a0*a0/hbar,             // 1 a.u. time
	au_E = hbar*hbar/(me*a0*a0),      // 1 a.u. energy
	au_Ef = qe/(4*PI*epsilon0*a0*a0); // 1 a.u. electric field
}

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
