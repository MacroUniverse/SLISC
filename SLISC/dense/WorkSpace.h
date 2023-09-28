#pragma once
// workspace
// each allocation must start at a memory address at the multiple of SLS_WSP_ALIGN, for possible SIMD optimization

#include "Scmat.h"
#include "Scmat3.h"
#ifndef SLS_WSP_ALIGN
#define SLS_WSP_ALIGN 64
#endif

namespace slisc {

class WorkSpace : protected SvecUchar {

private:
	Long m_used; // start of free space

	// modify m_used so that `m_p + m_used` is aligned
	// will not check bound
	void do_align() {
		Long rem = (size_t(m_p) + m_used) % SLS_WSP_ALIGN;
		if (rem)
			m_used += SLS_WSP_ALIGN - rem;
	}

public:
	using SvecUchar::size;
	using SvecUchar::p;

	WorkSpace() {};

	// allocate all space ever needed, won't allow resize
	WorkSpace(void *ptr, Long_I Nbyte) :
		SvecUchar((Uchar*)ptr, Nbyte), m_used(0) {}

	// initialize from STL and SLISC containers (continuous memory)
	template <class Tv>
	WorkSpace(Tv &v) : WorkSpace(ptr(v), (Long)v.size()) {}

	WorkSpace &operator=(const WorkSpace &rhs) {
		m_p = rhs.m_p; m_N = rhs.m_N;
		m_used = rhs.m_used;
		return *this;
	}
	
	Long used() const { return m_used; }

	Long free() const { return m_N-m_used; }

	constexpr Long align() const { return SLS_WSP_ALIGN; }

	void set(void *ptr, Long_I Nbyte) {
		SvecUchar::set((Uchar*)ptr, Nbyte);
	};

	template <class Tv>
	void set(Tv &v) { set(v.p(), v.size()); }

	// get a sub WorkSpace
	WorkSpace get(Long_I Nbyte) {
#ifdef SLS_CHECK_BOUNDS
		if (Nbyte > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nbyte;
		return WorkSpace(m_p+start, Nbyte);
	}

	// danger! make sure no one is using the workspace!
	void reset() { m_used = 0; }

	// ======= allocate WorkSpace for different containers =========

	Char *pChar(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Char);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return (Char *)(m_p+start);
	}

	slisc::SvecChar SvecChar(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Char);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecChar((Char *)(m_p+start), N);
	}

	slisc::ScmatChar ScmatChar(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Char);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatChar((Char *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Char Scmat3Char(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Char);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Char((Char *)(m_p+start), N1, N2, N3);
	}


	Int *pInt(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Int);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return (Int *)(m_p+start);
	}

	slisc::SvecInt SvecInt(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Int);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecInt((Int *)(m_p+start), N);
	}

	slisc::ScmatInt ScmatInt(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Int);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatInt((Int *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Int Scmat3Int(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Int);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Int((Int *)(m_p+start), N1, N2, N3);
	}

	Long *pLong(Long_I N) {	return pInt(N); }

	slisc::SvecLong SvecLong(Long_I N) { return SvecInt(N); }

	slisc::ScmatLong ScmatLong(Long_I N1, Long_I N2) { return ScmatInt(N1, N2); }

	slisc::Scmat3Long Scmat3Long(Long_I N1, Long_I N2, Long_I N3) { return Scmat3Int(N1, N2, N3); }

	Llong *pLlong(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Llong);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return (Llong *)(m_p+start);
	}

	slisc::SvecLlong SvecLlong(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Llong);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecLlong((Llong *)(m_p+start), N);
	}

	slisc::ScmatLlong ScmatLlong(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Llong);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatLlong((Llong *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Llong Scmat3Llong(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Llong);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Llong((Llong *)(m_p+start), N1, N2, N3);
	}


	Float *pFloat(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Float);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return (Float *)(m_p+start);
	}

	slisc::SvecFloat SvecFloat(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Float);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecFloat((Float *)(m_p+start), N);
	}

	slisc::ScmatFloat ScmatFloat(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Float);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatFloat((Float *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Float Scmat3Float(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Float);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Float((Float *)(m_p+start), N1, N2, N3);
	}


	Doub *pDoub(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Doub);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return (Doub *)(m_p+start);
	}

	slisc::SvecDoub SvecDoub(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Doub);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecDoub((Doub *)(m_p+start), N);
	}

	slisc::ScmatDoub ScmatDoub(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Doub);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatDoub((Doub *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Doub Scmat3Doub(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Doub);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Doub((Doub *)(m_p+start), N1, N2, N3);
	}



	Fcomp *pFcomp(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Fcomp);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return (Fcomp *)(m_p+start);
	}

	slisc::SvecFcomp SvecFcomp(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Fcomp);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecFcomp((Fcomp *)(m_p+start), N);
	}

	slisc::ScmatFcomp ScmatFcomp(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Fcomp);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatFcomp((Fcomp *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Fcomp Scmat3Fcomp(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Fcomp);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Fcomp((Fcomp *)(m_p+start), N1, N2, N3);
	}


	Comp *pComp(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Comp);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return (Comp *)(m_p+start);
	}

	slisc::SvecComp SvecComp(Long_I N) {
		do_align();
		Long Nb = N*sizeof(Comp);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::SvecComp((Comp *)(m_p+start), N);
	}

	slisc::ScmatComp ScmatComp(Long_I N1, Long_I N2) {
		do_align();
		Long Nb = N1*N2*sizeof(Comp);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::ScmatComp((Comp *)(m_p+start), N1, N2);
	}

	slisc::Scmat3Comp Scmat3Comp(Long_I N1, Long_I N2, Long_I N3) {
		do_align();
		Long Nb = N1*N2*N3*sizeof(Comp);
#ifdef SLS_CHECK_BOUNDS
		if (Nb > size() - m_used)
			SLS_ERR("WorkSpace: out of space!");
#endif
		Long start = m_used;
		m_used += Nb;
		return slisc::Scmat3Comp((Comp *)(m_p+start), N1, N2, N3);
	}



};

}; // namespace slisc

