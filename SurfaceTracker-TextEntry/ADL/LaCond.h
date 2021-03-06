#ifndef LACON_HDR
#define LACON_HDR
/*******************************************************************************
This header file contains the C/C++ prototypes for the LAPACK routines.
Routines in this file are specific for RCOND of a matrix.

Abed M. Hammoud
17Nov94-Stealth
Copyright 1993-1995
*******************************************************************************/
// NOMANPAGE
/*
*  -- LAPACK routine (version 1.1) --
*     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
*     Courant Institute, Argonne National Lab, and Rice University
*     February 29, 1992
*
*     .. Scalar Arguments ..
      CHARACTER          NORM
      INTEGER            INFO, LDA, N
      REAL               ANORM, RCOND
*     ..
*     .. Array Arguments ..
      INTEGER            IWORK( * )
      REAL               A( LDA, * ), WORK( * )
*     ..
*
*  Purpose
*  =======
*
*  SGECON estimates the reciprocal of the condition number of a general
*  real matrix A, in either the 1-norm or the infinity-norm, using
*  the LU factorization computed by SGETRF.
*
*  An estimate is obtained for norm(inv(A)), and the reciprocal of the
*  condition number is computed as
*     RCOND = 1 / ( norm(A) * norm(inv(A)) ).
*
*  Arguments
*  =========
*
*  NORM    (input) CHARACTER*1
*          Specifies whether the 1-norm condition number or the
*          infinity-norm condition number is required:
*          = '1' or 'O':  1-norm;
*          = 'I':         Infinity-norm.
*
*  N       (input) INTEGER
*          The order of the matrix A.  N >= 0.
*
*  A       (input) REAL array, dimension (LDA,N)
*          The factors L and U from the factorization A = P*L*U
*          as computed by SGETRF.
*
*  LDA     (input) INTEGER
*          The leading dimension of the array A.  LDA >= max(1,N).
*
*  ANORM   (input) REAL
*          If NORM = '1' or 'O', the 1-norm of the original matrix A.
*          If NORM = 'I', the infinity-norm of the original matrix A.
*
*  RCOND   (output) REAL
*          The reciprocal of the condition number of the matrix A,
*          computed as RCOND = 1/(norm(A) * norm(inv(A))).
*
*  WORK    (workspace) REAL array, dimension (4*N)
*
*  IWORK   (workspace) INTEGER array, dimension (N)
*
*  INFO    (output) INTEGER
*          = 0:  successful exit
*          < 0:  if INFO = -i, the i-th argument had an illegal value
*
*  =====================================================================
*/
#ifdef __cplusplus

extern "C" {

// Single precision.
   extern void F77CALL(sgecon)(const char& NORM, const int& N, 
	const float A[], const int& LDA, const float& ANORM, 
	float *RCOND, float WORK[], int IWORK[], int *INFO); 

// Double precision.
   extern void F77CALL(dgecon)(const char& NORM, const int& N, 
	const double A[], const int& LDA, const double& ANORM, 
	double *RCOND, double WORK[], int IWORK[], int *INFO); 

}

#else

/* Single precision */
   void F77CALL(sgecon)(char const *NORM, int const *N, const float A[], 
	int const *LDA, float const *ANORM, float *RCOND, 
	float WORK[], int IWORK[], int *INFO); 

/* Double precision */
   void F77CALL(dgecon)(char const *NORM, int const *N, const double A[], 
	int const *LDA, double const *ANORM, double *RCOND, 
	double WORK[], int IWORK[], int *INFO); 

#endif

#endif

