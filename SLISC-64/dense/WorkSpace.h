#pragma once
// workspace

#include "Scmat.h"
#include "Scmat3.h"

namespace slisc {

class WorkSpace : protected VecUchar {

private:
	Long m_used; // start of free space
	const Long m_align; // each allocation must start at a memory address at the multiple of m_align

	// modify m_used so that `m_p + m_used` is aligned
	// will not check bound
	void do_align() {
		Long rem = (size_t(m_p) + m_used) % m_align;
		if (rem)
			m_used += m_align - rem;
	}

public:
	// allocate all space ever needed, won't allow resize
	WorkSpace(Long_I Nbyte, Long_I align = 64) : VecUchar(Nbyte), m_used(0), m_align(align) {}
	
	Long used() const { return m_used; }

	Long align() const { return m_align; }

	using VecUchar::size;
	using VecUchar::p;

	// ======= allocate WorkSpace for different containers =========

	Char *pChar(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Char);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return (Char *)(m_p+start);
	}

	slisc::SvecChar SvecChar(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Char);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecChar((Char *)(m_p+start), N);
	}

	slisc::ScmatChar ScmatChar(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Char);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatChar((Char *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Char Scmat3Char(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Char);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Char((Char *)(m_p+start), N1, N2, N3);
	}

	Int *pInt(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Int);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return (Int *)(m_p+start);
	}

	slisc::SvecInt SvecInt(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Int);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecInt((Int *)(m_p+start), N);
	}

	slisc::ScmatInt ScmatInt(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Int);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatInt((Int *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Int Scmat3Int(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Int);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Int((Int *)(m_p+start), N1, N2, N3);
	}

	Llong *pLlong(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Llong);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return (Llong *)(m_p+start);
	}

	slisc::SvecLlong SvecLlong(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Llong);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecLlong((Llong *)(m_p+start), N);
	}

	slisc::ScmatLlong ScmatLlong(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Llong);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatLlong((Llong *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Llong Scmat3Llong(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Llong);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Llong((Llong *)(m_p+start), N1, N2, N3);
	}

	Float *pFloat(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Float);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return (Float *)(m_p+start);
	}

	slisc::SvecFloat SvecFloat(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Float);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecFloat((Float *)(m_p+start), N);
	}

	slisc::ScmatFloat ScmatFloat(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Float);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatFloat((Float *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Float Scmat3Float(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Float);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Float((Float *)(m_p+start), N1, N2, N3);
	}

	Doub *pDoub(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Doub);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return (Doub *)(m_p+start);
	}

	slisc::SvecDoub SvecDoub(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Doub);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecDoub((Doub *)(m_p+start), N);
	}

	slisc::ScmatDoub ScmatDoub(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Doub);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatDoub((Doub *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Doub Scmat3Doub(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Doub);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Doub((Doub *)(m_p+start), N1, N2, N3);
	}


	Fcomp *pFcomp(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Fcomp);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return (Fcomp *)(m_p+start);
	}

	slisc::SvecFcomp SvecFcomp(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Fcomp);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecFcomp((Fcomp *)(m_p+start), N);
	}

	slisc::ScmatFcomp ScmatFcomp(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Fcomp);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatFcomp((Fcomp *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Fcomp Scmat3Fcomp(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Fcomp);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Fcomp((Fcomp *)(m_p+start), N1, N2, N3);
	}

	Comp *pComp(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Comp);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return (Comp *)(m_p+start);
	}

	slisc::SvecComp SvecComp(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Comp);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecComp((Comp *)(m_p+start), N);
	}

	slisc::ScmatComp ScmatComp(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Comp);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatComp((Comp *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Comp Scmat3Comp(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Comp);
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Comp((Comp *)(m_p+start), N1, N2, N3);
	}


};

}; // namespace slisc
