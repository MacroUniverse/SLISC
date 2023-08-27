#include "../global.h"
#ifdef SLS_USE_EIGEN
#include "Eigen/Dense"
#include "Eigen/Sparse"
#include "Eigen/LU"

// extension for Eigen library
// note that NumTraits<long double> and NumTraits<complex<long double>> are already defined
#ifdef SLS_USE_QUAD_MATH

namespace Eigen {
	using slisc::Qdoub; using slisc::Qcomp;
	
	template<> struct NumTraits<Qdoub> : GenericNumTraits<Qdoub>
	{
		typedef Qdoub Real;
		typedef Qdoub NonInteger;
		typedef Qdoub Nested;

		static inline Real epsilon() { return FLT128_EPSILON; }
		static inline Real dummy_precision() { return 0; }
		static inline int digits10() { return FLT128_DIG; }

		enum {
			IsInteger = 0,
			IsSigned = 1,
			IsComplex = 0,
			RequireInitialization = 0,
			ReadCost = 2,
			AddCost = 2,
			MulCost = 6
		};
	};

	template<> struct NumTraits<Qcomp> : GenericNumTraits<Qcomp>
	{
		typedef Qdoub Real;
		typedef Qdoub NonInteger;
		typedef Qdoub Nested;

		static inline Real epsilon() { return FLT128_EPSILON; }
		static inline Real dummy_precision() { return 0; }
		static inline int digits10() { return FLT128_DIG; }

		enum {
			IsInteger = 0,
			IsSigned = 0,
			IsComplex = 1,
			RequireInitialization = 0,
			ReadCost = 4,
			AddCost = 4,
			MulCost = 12
		};
	};

	typedef Matrix<Qdoub, Dynamic, Dynamic> MatrixXq;
	typedef Matrix<Qcomp, Dynamic, Dynamic> MatrixXqc;
	typedef Matrix<Qdoub, Dynamic, 1> VectorXq;
	typedef Matrix<Qcomp, Dynamic, 1> VectorXqc;
} // namespace Eigen

#endif
#endif
