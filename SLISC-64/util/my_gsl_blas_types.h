// this is a modified version of gsl_blas_types.h to prevent error due to `typedef enum`
// ref: https://wuli.wiki/online/CNote.html

#ifndef __MY_GSL_BLAS_TYPES_H__
#define __MY_GSL_BLAS_TYPES_H__

#include <gsl/gsl_cblas.h>

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

__BEGIN_DECLS

typedef  CBLAS_INDEX  CBLAS_INDEX_t;
typedef  CBLAS_ORDER       CBLAS_ORDER_t;
typedef  CBLAS_TRANSPOSE   CBLAS_TRANSPOSE_t;
typedef  CBLAS_UPLO        CBLAS_UPLO_t;
typedef  CBLAS_DIAG        CBLAS_DIAG_t;
typedef  CBLAS_SIDE        CBLAS_SIDE_t;

/* typedef  gsl_complex  COMPLEX; */

__END_DECLS


#endif /* __MY_GSL_BLAS_TYPES_H__ */
