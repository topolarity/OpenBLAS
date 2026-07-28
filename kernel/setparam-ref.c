/*********************************************************************/
/* Copyright 2009, 2010 The University of Texas at Austin.           */
/* Copyright 2023, 2025 The OpenBLAS Project.                        */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/*   1. Redistributions of source code must retain the above         */
/*      copyright notice, this list of conditions and the following  */
/*      disclaimer.                                                  */
/*                                                                   */
/*   2. Redistributions in binary form must reproduce the above      */
/*      copyright notice, this list of conditions and the following  */
/*      disclaimer in the documentation and/or other materials       */
/*      provided with the distribution.                              */
/*                                                                   */
/*    THIS  SOFTWARE IS PROVIDED  BY THE  UNIVERSITY OF  TEXAS AT    */
/*    AUSTIN  ``AS IS''  AND ANY  EXPRESS OR  IMPLIED WARRANTIES,    */
/*    INCLUDING, BUT  NOT LIMITED  TO, THE IMPLIED  WARRANTIES OF    */
/*    MERCHANTABILITY  AND FITNESS FOR  A PARTICULAR  PURPOSE ARE    */
/*    DISCLAIMED.  IN  NO EVENT SHALL THE UNIVERSITY  OF TEXAS AT    */
/*    AUSTIN OR CONTRIBUTORS BE  LIABLE FOR ANY DIRECT, INDIRECT,    */
/*    INCIDENTAL,  SPECIAL, EXEMPLARY,  OR  CONSEQUENTIAL DAMAGES    */
/*    (INCLUDING, BUT  NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE    */
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFITS;  OR    */
/*    BUSINESS INTERRUPTION) HOWEVER CAUSED  AND ON ANY THEORY OF    */
/*    LIABILITY, WHETHER  IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*    (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY WAY OUT    */
/*    OF  THE  USE OF  THIS  SOFTWARE,  EVEN  IF ADVISED  OF  THE    */
/*    POSSIBILITY OF SUCH DAMAGE.                                    */
/*                                                                   */
/* The views and conclusions contained in the software and           */
/* documentation are those of the authors and should not be          */
/* interpreted as representing official policies, either expressed   */
/* or implied, of The University of Texas at Austin.                 */
/*********************************************************************/

#include <stdio.h>
#include <string.h>
#include "common.h"

#ifdef BUILD_KERNEL
#include "kernelTS.h"
#endif

#undef DEBUG

static void init_parameter(void);

openblas_params_t openblas_paramsTS = {
  DTB_DEFAULT_ENTRIES,
  SWITCH_RATIO,
  GEMM_DIVIDE_RATE,
  GEMM_DIVIDE_LIMIT,
  GEMM_PREFERRED_SIZE,
  GEMM_DEFAULT_OFFSET_A,
  GEMM_DEFAULT_OFFSET_B,
  GEMM_DEFAULT_ALIGN,
#ifdef BUILD_HFLOAT16
  0,
  0,
  0,
  SHGEMM_DEFAULT_UNROLL_M,
  SHGEMM_DEFAULT_UNROLL_N,
#ifdef SHGEMM_DEFAULT_UNROLL_MN
 SHGEMM_DEFAULT_UNROLL_MN,
#else
 MAX(SHGEMM_DEFAULT_UNROLL_M, SHGEMM_DEFAULT_UNROLL_N),
#endif
#if SHGEMM_DEFAULT_UNROLL_M != SHGEMM_DEFAULT_UNROLL_N
#else
#endif
#endif
#ifdef BUILD_BFLOAT16
  0,
  0,
  0,
  BGEMM_DEFAULT_UNROLL_M,
  BGEMM_DEFAULT_UNROLL_N,
#ifdef BGEMM_DEFAULT_UNROLL_MN
 BGEMM_DEFAULT_UNROLL_MN,
#else
 MAX(BGEMM_DEFAULT_UNROLL_M, BGEMM_DEFAULT_UNROLL_N),
#endif
  BGEMM_ALIGN_K,
  0,
  0,
  0,
  SBGEMM_DEFAULT_UNROLL_M,
  SBGEMM_DEFAULT_UNROLL_N,
#ifdef SBGEMM_DEFAULT_UNROLL_MN
 SBGEMM_DEFAULT_UNROLL_MN,
#else
 MAX(SBGEMM_DEFAULT_UNROLL_M, SBGEMM_DEFAULT_UNROLL_N),
#endif
  SBGEMM_ALIGN_K,
  0,
#endif
#if ( BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1) || (BUILD_COMPLEX16==1)
  0,
  0,
  0,
  SGEMM_DEFAULT_UNROLL_M,
  SGEMM_DEFAULT_UNROLL_N,
#ifdef SGEMM_DEFAULT_UNROLL_MN
 SGEMM_DEFAULT_UNROLL_MN,
#else
 MAX(SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N),
#endif
#endif
#ifdef HAVE_EXCLUSIVE_CACHE
  1,
#else
  0,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  0,
  0,
  0,
  DGEMM_DEFAULT_UNROLL_M,
  DGEMM_DEFAULT_UNROLL_N,
#ifdef DGEMM_DEFAULT_UNROLL_MN
 DGEMM_DEFAULT_UNROLL_MN,
#else
 MAX(DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N),
#endif
#endif
#ifdef EXPRECISION
  0,
  0,
  0,
  QGEMM_DEFAULT_UNROLL_M,
  QGEMM_DEFAULT_UNROLL_N,
  MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),
#endif
#if (BUILD_COMPLEX)
  0,
  0,
  0,
  CGEMM_DEFAULT_UNROLL_M,
  CGEMM_DEFAULT_UNROLL_N,
#ifdef CGEMM_DEFAULT_UNROLL_MN
 CGEMM_DEFAULT_UNROLL_MN,
#else
 MAX(CGEMM_DEFAULT_UNROLL_M, CGEMM_DEFAULT_UNROLL_N),
#endif
#endif
#if (BUILD_COMPLEX)
  0,
  0,
  0,
#if (USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_UNROLL_M
  CGEMM3M_DEFAULT_UNROLL_M,
  CGEMM3M_DEFAULT_UNROLL_N,
  MAX(CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N),
#else
  SGEMM_DEFAULT_UNROLL_M,
  SGEMM_DEFAULT_UNROLL_N,
  MAX(SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N),
#endif
#else
  0,
  0,
  0,
#endif
#endif
#if BUILD_COMPLEX16 == 1
  0,
  0,
  0,
  ZGEMM_DEFAULT_UNROLL_M,
  ZGEMM_DEFAULT_UNROLL_N,
#ifdef ZGEMM_DEFAULT_UNROLL_MN
 ZGEMM_DEFAULT_UNROLL_MN,
#else
 MAX(ZGEMM_DEFAULT_UNROLL_M, ZGEMM_DEFAULT_UNROLL_N),
#endif
#endif
#if BUILD_COMPLEX16 == 1
  0,
  0,
  0,
#if (USE_GEMM3M)
#ifdef ZGEMM3M_DEFAULT_UNROLL_M
  ZGEMM3M_DEFAULT_UNROLL_M,
  ZGEMM3M_DEFAULT_UNROLL_N,
  MAX(ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N),
#else
  DGEMM_DEFAULT_UNROLL_M,
  DGEMM_DEFAULT_UNROLL_N,
  MAX(DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N),
#endif
#else
  0,
  0,
  0,
#endif
#endif
#ifdef EXPRECISION
  0,
  0,
  0,
  XGEMM_DEFAULT_UNROLL_M,
  XGEMM_DEFAULT_UNROLL_N,
  MAX(XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N),
#endif
#ifdef EXPRECISION
  0,
  0,
  0,
#if (USE_GEMM3M)
  QGEMM_DEFAULT_UNROLL_M,
  QGEMM_DEFAULT_UNROLL_N,
  MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),
#else
  0,
  0,
  0,
#endif
#endif
  init_parameter,
  SNUMOPT,
  DNUMOPT,
  QNUMOPT,
};

#if BUILD_HFLOAT16 == 1
const openblas_shgemm_dispatch_t openblas_shgemm_dispatchTS = {
#ifdef BUILD_HFLOAT16
  shgemm_kernelTS,
  shgemm_betaTS,
#if SHGEMM_DEFAULT_UNROLL_M != SHGEMM_DEFAULT_UNROLL_N
  shgemm_incopyTS,
  shgemm_itcopyTS,
#else
  shgemm_oncopyTS,
  shgemm_otcopyTS,
#endif
  shgemm_oncopyTS,
  shgemm_otcopyTS,
#endif
};
#endif

#if BUILD_HFLOAT16 == 1
const openblas_shgemv_dispatch_t openblas_shgemv_dispatchTS = {
#ifdef BUILD_HFLOAT16
  shgemv_nTS,
  shgemv_tTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbstobf16_dispatch_t openblas_sbstobf16_dispatchTS = {
#ifdef BUILD_BFLOAT16
  sbstobf16_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbdtobf16_dispatch_t openblas_sbdtobf16_dispatchTS = {
#ifdef BUILD_BFLOAT16
  sbdtobf16_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbf16tos_dispatch_t openblas_sbf16tos_dispatchTS = {
#ifdef BUILD_BFLOAT16
  sbf16tos_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_dbf16tod_dispatch_t openblas_dbf16tod_dispatchTS = {
#ifdef BUILD_BFLOAT16
  dbf16tod_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbamax_dispatch_t openblas_sbamax_dispatchTS = {
#ifdef BUILD_BFLOAT16
  samax_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbamin_dispatch_t openblas_sbamin_dispatchTS = {
#ifdef BUILD_BFLOAT16
  samin_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbmax_dispatch_t openblas_sbmax_dispatchTS = {
#ifdef BUILD_BFLOAT16
  smax_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbmin_dispatch_t openblas_sbmin_dispatchTS = {
#ifdef BUILD_BFLOAT16
  smin_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_isbamax_dispatch_t openblas_isbamax_dispatchTS = {
#ifdef BUILD_BFLOAT16
  isamax_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_isbamin_dispatch_t openblas_isbamin_dispatchTS = {
#ifdef BUILD_BFLOAT16
  isamin_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_isbmax_dispatch_t openblas_isbmax_dispatchTS = {
#ifdef BUILD_BFLOAT16
  ismax_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_isbmin_dispatch_t openblas_isbmin_dispatchTS = {
#ifdef BUILD_BFLOAT16
  ismin_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbnrm2_dispatch_t openblas_sbnrm2_dispatchTS = {
#ifdef BUILD_BFLOAT16
  snrm2_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbasum_dispatch_t openblas_sbasum_dispatchTS = {
#ifdef BUILD_BFLOAT16
  sasum_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbsum_dispatch_t openblas_sbsum_dispatchTS = {
#ifdef BUILD_BFLOAT16
  ssum_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbcopy_dispatch_t openblas_sbcopy_dispatchTS = {
#ifdef BUILD_BFLOAT16
  scopy_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbdot_dispatch_t openblas_sbdot_dispatchTS = {
#ifdef BUILD_BFLOAT16
  sbdot_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_dsbdot_dispatch_t openblas_dsbdot_dispatchTS = {
#ifdef BUILD_BFLOAT16
  dsdot_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbrot_dispatch_t openblas_sbrot_dispatchTS = {
#ifdef BUILD_BFLOAT16
  srot_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbrotm_dispatch_t openblas_sbrotm_dispatchTS = {
#ifdef BUILD_BFLOAT16
  srotm_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_bscal_dispatch_t openblas_bscal_dispatchTS = {
#ifdef BUILD_BFLOAT16
  bscal_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbaxpy_dispatch_t openblas_sbaxpy_dispatchTS = {
#ifdef BUILD_BFLOAT16
  saxpy_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbscal_dispatch_t openblas_sbscal_dispatchTS = {
#ifdef BUILD_BFLOAT16
  sscal_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbswap_dispatch_t openblas_sbswap_dispatchTS = {
#ifdef BUILD_BFLOAT16
  sswap_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_bgemv_dispatch_t openblas_bgemv_dispatchTS = {
#ifdef BUILD_BFLOAT16
  bgemv_nTS,
  bgemv_tTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbgemv_dispatch_t openblas_sbgemv_dispatchTS = {
#ifdef BUILD_BFLOAT16
  sbgemv_nTS,
  sbgemv_tTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbger_dispatch_t openblas_sbger_dispatchTS = {
#ifdef BUILD_BFLOAT16
  sger_kTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbsymv_dispatch_t openblas_sbsymv_dispatchTS = {
#ifdef BUILD_BFLOAT16
  ssymv_LTS,
  ssymv_UTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_bgemm_dispatch_t openblas_bgemm_dispatchTS = {
#ifdef BUILD_BFLOAT16
  bgemm_kernelTS,
  bgemm_betaTS,
#if BGEMM_DEFAULT_UNROLL_M != BGEMM_DEFAULT_UNROLL_N
  bgemm_incopyTS,
  bgemm_itcopyTS,
#else
  bgemm_oncopyTS,
  bgemm_otcopyTS,
#endif
  bgemm_oncopyTS,
  bgemm_otcopyTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbgemm_dispatch_t openblas_sbgemm_dispatchTS = {
#ifdef BUILD_BFLOAT16
  sbgemm_kernelTS,
  sbgemm_betaTS,
#if SBGEMM_DEFAULT_UNROLL_M != SBGEMM_DEFAULT_UNROLL_N
  sbgemm_incopyTS,
  sbgemm_itcopyTS,
#else
  sbgemm_oncopyTS,
  sbgemm_otcopyTS,
#endif
  sbgemm_oncopyTS,
  sbgemm_otcopyTS,
#endif
#ifdef BUILD_BFLOAT16
#ifdef SMALL_MATRIX_OPT
  sbgemm_small_matrix_permitTS,
  sbgemm_small_kernel_nnTS,
  sbgemm_small_kernel_ntTS,
  sbgemm_small_kernel_tnTS,
  sbgemm_small_kernel_ttTS,
  sbgemm_small_kernel_b0_nnTS,
  sbgemm_small_kernel_b0_ntTS,
  sbgemm_small_kernel_b0_tnTS,
  sbgemm_small_kernel_b0_ttTS,
#endif
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbtrsm_dispatch_t openblas_sbtrsm_dispatchTS = {
#ifdef BUILD_BFLOAT16
  strsm_kernel_LNTS,
  strsm_kernel_LTTS,
  strsm_kernel_RNTS,
  strsm_kernel_RTTS,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopyTS,
  strsm_iunncopyTS,
  strsm_iutucopyTS,
  strsm_iutncopyTS,
  strsm_ilnucopyTS,
  strsm_ilnncopyTS,
  strsm_iltucopyTS,
  strsm_iltncopyTS,
#else
  strsm_ounucopyTS,
  strsm_ounncopyTS,
  strsm_outucopyTS,
  strsm_outncopyTS,
  strsm_olnucopyTS,
  strsm_olnncopyTS,
  strsm_oltucopyTS,
  strsm_oltncopyTS,
#endif
  strsm_ounucopyTS,
  strsm_ounncopyTS,
  strsm_outucopyTS,
  strsm_outncopyTS,
  strsm_olnucopyTS,
  strsm_olnncopyTS,
  strsm_oltucopyTS,
  strsm_oltncopyTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbtrmm_dispatch_t openblas_sbtrmm_dispatchTS = {
#ifdef BUILD_BFLOAT16
  strmm_kernel_RNTS,
  strmm_kernel_RTTS,
  strmm_kernel_LNTS,
  strmm_kernel_LTTS,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopyTS,
  strmm_iunncopyTS,
  strmm_iutucopyTS,
  strmm_iutncopyTS,
  strmm_ilnucopyTS,
  strmm_ilnncopyTS,
  strmm_iltucopyTS,
  strmm_iltncopyTS,
#else
  strmm_ounucopyTS,
  strmm_ounncopyTS,
  strmm_outucopyTS,
  strmm_outncopyTS,
  strmm_olnucopyTS,
  strmm_olnncopyTS,
  strmm_oltucopyTS,
  strmm_oltncopyTS,
#endif
  strmm_ounucopyTS,
  strmm_ounncopyTS,
  strmm_outucopyTS,
  strmm_outncopyTS,
  strmm_olnucopyTS,
  strmm_olnncopyTS,
  strmm_oltucopyTS,
  strmm_oltncopyTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbsymm_dispatch_t openblas_sbsymm_dispatchTS = {
#ifdef BUILD_BFLOAT16
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopyTS,
  ssymm_iltcopyTS,
#else
  ssymm_outcopyTS,
  ssymm_oltcopyTS,
#endif
  ssymm_outcopyTS,
  ssymm_oltcopyTS,
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sbneg_dispatch_t openblas_sbneg_dispatchTS = {
#ifdef BUILD_BFLOAT16
#ifndef NO_LAPACK
  sneg_tcopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#if BUILD_BFLOAT16 == 1
const openblas_sblaswp_dispatch_t openblas_sblaswp_dispatchTS = {
#ifdef BUILD_BFLOAT16
#ifndef NO_LAPACK
  slaswp_ncopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#if (BUILD_SINGLE == 1) || (BUILD_COMPLEX == 1)
const openblas_samax_dispatch_t openblas_samax_dispatchTS = {
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  samax_kTS,
#endif
};
#endif

#if (BUILD_SINGLE == 1) || (BUILD_COMPLEX == 1)
const openblas_samin_dispatch_t openblas_samin_dispatchTS = {
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  samin_kTS,
#endif
};
#endif

#if (BUILD_SINGLE == 1) || (BUILD_COMPLEX == 1)
const openblas_smax_dispatch_t openblas_smax_dispatchTS = {
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  smax_kTS,
#endif
};
#endif

#if (BUILD_SINGLE == 1) || (BUILD_COMPLEX == 1)
const openblas_smin_dispatch_t openblas_smin_dispatchTS = {
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  smin_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE ==1) || (BUILD_COMPLEX==1)
const openblas_isamax_dispatch_t openblas_isamax_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  isamax_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
const openblas_isamin_dispatch_t openblas_isamin_dispatchTS = {
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  isamin_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
const openblas_ismax_dispatch_t openblas_ismax_dispatchTS = {
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  ismax_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
const openblas_ismin_dispatch_t openblas_ismin_dispatchTS = {
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  ismin_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
const openblas_snrm2_dispatch_t openblas_snrm2_dispatchTS = {
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  snrm2_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
const openblas_sasum_dispatch_t openblas_sasum_dispatchTS = {
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  sasum_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1)
const openblas_ssum_dispatch_t openblas_ssum_dispatchTS = {
#if BUILD_SINGLE == 1
  ssum_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
const openblas_scopy_dispatch_t openblas_scopy_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  scopy_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
const openblas_sdot_dispatch_t openblas_sdot_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  sdot_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
const openblas_srot_dispatch_t openblas_srot_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  srot_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
const openblas_srotm_dispatch_t openblas_srotm_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  srotm_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
const openblas_saxpy_dispatch_t openblas_saxpy_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  saxpy_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1) || (BUILD_COMPLEX16==1)
const openblas_sscal_dispatch_t openblas_sscal_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1) || (BUILD_COMPLEX16==1)
  sscal_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
const openblas_sswap_dispatch_t openblas_sswap_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  sswap_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
const openblas_sgemv_dispatch_t openblas_sgemv_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  sgemv_nTS,
  sgemv_tTS,
#endif
};
#endif

#if (BUILD_SINGLE==1)
const openblas_sger_dispatch_t openblas_sger_dispatchTS = {
#if BUILD_SINGLE == 1
  sger_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1)
const openblas_ssymv_dispatch_t openblas_ssymv_dispatchTS = {
#if BUILD_SINGLE == 1
  ssymv_LTS,
  ssymv_UTS,
#endif
};
#endif

const openblas_sgemm_dispatch_t openblas_sgemm_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_X86_64
  sgemm_directTS,
  sgemm_direct_performantTS,
#endif
#ifdef ARCH_ARM64
  sgemm_directTS,
  sgemm_direct_performantTS,
  sgemm_direct_alpha_betaTS,
#endif
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_X86_64
#endif
#ifdef ARCH_ARM64
#endif
  sgemm_kernelTS,
  sgemm_betaTS,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  sgemm_incopyTS,
  sgemm_itcopyTS,
#else
  sgemm_oncopyTS,
  sgemm_otcopyTS,
#endif
  sgemm_oncopyTS,
  sgemm_otcopyTS,
#endif
#if BUILD_SINGLE == 1 || BUILD_DOUBLE == 1 || BUILD_COMPLEX == 1
#ifdef SMALL_MATRIX_OPT
  sgemm_small_matrix_permitTS,
  sgemm_small_kernel_nnTS,
  sgemm_small_kernel_ntTS,
  sgemm_small_kernel_tnTS,
  sgemm_small_kernel_ttTS,
  sgemm_small_kernel_b0_nnTS,
  sgemm_small_kernel_b0_ntTS,
  sgemm_small_kernel_b0_tnTS,
  sgemm_small_kernel_b0_ttTS,
#endif
#endif
};

const openblas_ssymm_dispatch_t openblas_ssymm_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_ARM64
  ssymm_direct_alpha_betaLUTS,
  ssymm_direct_alpha_betaLLTS,
#endif
#endif
#if (BUILD_SINGLE==1)
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopyTS,
  ssymm_iltcopyTS,
#else
  ssymm_outcopyTS,
  ssymm_oltcopyTS,
#endif
  ssymm_outcopyTS,
  ssymm_oltcopyTS,
#endif
};

const openblas_strmm_dispatch_t openblas_strmm_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_ARM64
  strmm_direct_LNUNTS,
  strmm_direct_LNLNTS,
  strmm_direct_LTUNTS,
  strmm_direct_LTLNTS,
#endif
#endif
#if (BUILD_SINGLE==1)
  strmm_kernel_RNTS,
  strmm_kernel_RTTS,
  strmm_kernel_LNTS,
  strmm_kernel_LTTS,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopyTS,
  strmm_iunncopyTS,
  strmm_iutucopyTS,
  strmm_iutncopyTS,
  strmm_ilnucopyTS,
  strmm_ilnncopyTS,
  strmm_iltucopyTS,
  strmm_iltncopyTS,
#else
  strmm_ounucopyTS,
  strmm_ounncopyTS,
  strmm_outucopyTS,
  strmm_outncopyTS,
  strmm_olnucopyTS,
  strmm_olnncopyTS,
  strmm_oltucopyTS,
  strmm_oltncopyTS,
#endif
  strmm_ounucopyTS,
  strmm_ounncopyTS,
  strmm_outucopyTS,
  strmm_outncopyTS,
  strmm_olnucopyTS,
  strmm_olnncopyTS,
  strmm_oltucopyTS,
  strmm_oltncopyTS,
#endif
};

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_ARM64
const openblas_ssyrk_dispatch_t openblas_ssyrk_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_ARM64
  ssyrk_direct_alpha_betaUNTS,
  ssyrk_direct_alpha_betaUTTS,
  ssyrk_direct_alpha_betaLNTS,
  ssyrk_direct_alpha_betaLTTS,
#endif
#endif
};
#endif
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_ARM64
const openblas_ssyr2k_dispatch_t openblas_ssyr2k_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_ARM64
  ssyr2k_direct_alpha_betaUNTS,
  ssyr2k_direct_alpha_betaUTTS,
  ssyr2k_direct_alpha_betaLNTS,
  ssyr2k_direct_alpha_betaLTTS,
#endif
#endif
};
#endif
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
const openblas_strsm_dispatch_t openblas_strsm_dispatchTS = {
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX == 1)
  strsm_kernel_LNTS,
  strsm_kernel_LTTS,
  strsm_kernel_RNTS,
  strsm_kernel_RTTS,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopyTS,
  strsm_iunncopyTS,
  strsm_iutucopyTS,
  strsm_iutncopyTS,
  strsm_ilnucopyTS,
  strsm_ilnncopyTS,
  strsm_iltucopyTS,
  strsm_iltncopyTS,
#else
  strsm_ounucopyTS,
  strsm_ounncopyTS,
  strsm_outucopyTS,
  strsm_outncopyTS,
  strsm_olnucopyTS,
  strsm_olnncopyTS,
  strsm_oltucopyTS,
  strsm_oltncopyTS,
#endif
  strsm_ounucopyTS,
  strsm_ounncopyTS,
  strsm_outucopyTS,
  strsm_outncopyTS,
  strsm_olnucopyTS,
  strsm_olnncopyTS,
  strsm_oltucopyTS,
  strsm_oltncopyTS,
#endif
};
#endif

#if (BUILD_SINGLE==1)
const openblas_sneg_dispatch_t openblas_sneg_dispatchTS = {
#if (BUILD_SINGLE==1)
#ifndef NO_LAPACK
  sneg_tcopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#if (BUILD_SINGLE==1)
const openblas_slaswp_dispatch_t openblas_slaswp_dispatchTS = {
#if (BUILD_SINGLE==1)
#ifndef NO_LAPACK
  slaswp_ncopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_damax_dispatch_t openblas_damax_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  damax_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_damin_dispatch_t openblas_damin_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  damin_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_dmax_dispatch_t openblas_dmax_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  dmax_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_dmin_dispatch_t openblas_dmin_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  dmin_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_idamax_dispatch_t openblas_idamax_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  idamax_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_idamin_dispatch_t openblas_idamin_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  idamin_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_idmax_dispatch_t openblas_idmax_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  idmax_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_idmin_dispatch_t openblas_idmin_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  idmin_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_dnrm2_dispatch_t openblas_dnrm2_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  dnrm2_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_dasum_dispatch_t openblas_dasum_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  dasum_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1)
const openblas_dsum_dispatch_t openblas_dsum_dispatchTS = {
#if  (BUILD_DOUBLE==1)
  dsum_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_dcopy_dispatch_t openblas_dcopy_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  dcopy_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_ddot_dispatch_t openblas_ddot_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  ddot_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1)
const openblas_dsdot_dispatch_t openblas_dsdot_dispatchTS = {
#if  (BUILD_SINGLE==1) || (BUILD_DOUBLE==1)
  dsdot_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_drot_dispatch_t openblas_drot_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  drot_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_drotm_dispatch_t openblas_drotm_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  drotm_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_daxpy_dispatch_t openblas_daxpy_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  daxpy_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_dscal_dispatch_t openblas_dscal_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  dscal_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_dswap_dispatch_t openblas_dswap_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  dswap_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
const openblas_dgemv_dispatch_t openblas_dgemv_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  dgemv_nTS,
  dgemv_tTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1)
const openblas_dger_dispatch_t openblas_dger_dispatchTS = {
#if  (BUILD_DOUBLE==1)
  dger_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1)
const openblas_dsymv_dispatch_t openblas_dsymv_dispatchTS = {
#if  (BUILD_DOUBLE==1)
  dsymv_LTS,
  dsymv_UTS,
#endif
};
#endif

const openblas_dgemm_dispatch_t openblas_dgemm_dispatchTS = {
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  dgemm_kernelTS,
  dgemm_betaTS,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dgemm_incopyTS,
  dgemm_itcopyTS,
#else
  dgemm_oncopyTS,
  dgemm_otcopyTS,
#endif
  dgemm_oncopyTS,
  dgemm_otcopyTS,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#ifdef SMALL_MATRIX_OPT
  dgemm_small_matrix_permitTS,
  dgemm_small_kernel_nnTS,
  dgemm_small_kernel_ntTS,
  dgemm_small_kernel_tnTS,
  dgemm_small_kernel_ttTS,
  dgemm_small_kernel_b0_nnTS,
  dgemm_small_kernel_b0_ntTS,
  dgemm_small_kernel_b0_tnTS,
  dgemm_small_kernel_b0_ttTS,
#endif
#endif
};

#if (BUILD_DOUBLE==1)
const openblas_dtrsm_dispatch_t openblas_dtrsm_dispatchTS = {
#if  (BUILD_DOUBLE==1)
  dtrsm_kernel_LNTS,
  dtrsm_kernel_LTTS,
  dtrsm_kernel_RNTS,
  dtrsm_kernel_RTTS,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrsm_iunucopyTS,
  dtrsm_iunncopyTS,
  dtrsm_iutucopyTS,
  dtrsm_iutncopyTS,
  dtrsm_ilnucopyTS,
  dtrsm_ilnncopyTS,
  dtrsm_iltucopyTS,
  dtrsm_iltncopyTS,
#else
  dtrsm_ounucopyTS,
  dtrsm_ounncopyTS,
  dtrsm_outucopyTS,
  dtrsm_outncopyTS,
  dtrsm_olnucopyTS,
  dtrsm_olnncopyTS,
  dtrsm_oltucopyTS,
  dtrsm_oltncopyTS,
#endif
  dtrsm_ounucopyTS,
  dtrsm_ounncopyTS,
  dtrsm_outucopyTS,
  dtrsm_outncopyTS,
  dtrsm_olnucopyTS,
  dtrsm_olnncopyTS,
  dtrsm_oltucopyTS,
  dtrsm_oltncopyTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1)
const openblas_dtrmm_dispatch_t openblas_dtrmm_dispatchTS = {
#if  (BUILD_DOUBLE==1)
  dtrmm_kernel_RNTS,
  dtrmm_kernel_RTTS,
  dtrmm_kernel_LNTS,
  dtrmm_kernel_LTTS,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrmm_iunucopyTS,
  dtrmm_iunncopyTS,
  dtrmm_iutucopyTS,
  dtrmm_iutncopyTS,
  dtrmm_ilnucopyTS,
  dtrmm_ilnncopyTS,
  dtrmm_iltucopyTS,
  dtrmm_iltncopyTS,
#else
  dtrmm_ounucopyTS,
  dtrmm_ounncopyTS,
  dtrmm_outucopyTS,
  dtrmm_outncopyTS,
  dtrmm_olnucopyTS,
  dtrmm_olnncopyTS,
  dtrmm_oltucopyTS,
  dtrmm_oltncopyTS,
#endif
  dtrmm_ounucopyTS,
  dtrmm_ounncopyTS,
  dtrmm_outucopyTS,
  dtrmm_outncopyTS,
  dtrmm_olnucopyTS,
  dtrmm_olnncopyTS,
  dtrmm_oltucopyTS,
  dtrmm_oltncopyTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1)
const openblas_dsymm_dispatch_t openblas_dsymm_dispatchTS = {
#if  (BUILD_DOUBLE==1)
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dsymm_iutcopyTS,
  dsymm_iltcopyTS,
#else
  dsymm_outcopyTS,
  dsymm_oltcopyTS,
#endif
  dsymm_outcopyTS,
  dsymm_oltcopyTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1)
const openblas_dneg_dispatch_t openblas_dneg_dispatchTS = {
#if  (BUILD_DOUBLE==1)
#ifndef NO_LAPACK
  dneg_tcopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#if (BUILD_DOUBLE==1)
const openblas_dlaswp_dispatch_t openblas_dlaswp_dispatchTS = {
#if  (BUILD_DOUBLE==1)
#ifndef NO_LAPACK
  dlaswp_ncopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qamax_dispatch_t openblas_qamax_dispatchTS = {
#ifdef EXPRECISION
  qamax_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qamin_dispatch_t openblas_qamin_dispatchTS = {
#ifdef EXPRECISION
  qamin_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qmax_dispatch_t openblas_qmax_dispatchTS = {
#ifdef EXPRECISION
  qmax_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qmin_dispatch_t openblas_qmin_dispatchTS = {
#ifdef EXPRECISION
  qmin_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_iqamax_dispatch_t openblas_iqamax_dispatchTS = {
#ifdef EXPRECISION
  iqamax_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_iqamin_dispatch_t openblas_iqamin_dispatchTS = {
#ifdef EXPRECISION
  iqamin_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_iqmax_dispatch_t openblas_iqmax_dispatchTS = {
#ifdef EXPRECISION
  iqmax_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_iqmin_dispatch_t openblas_iqmin_dispatchTS = {
#ifdef EXPRECISION
  iqmin_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qnrm2_dispatch_t openblas_qnrm2_dispatchTS = {
#ifdef EXPRECISION
  qnrm2_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qasum_dispatch_t openblas_qasum_dispatchTS = {
#ifdef EXPRECISION
  qasum_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qsum_dispatch_t openblas_qsum_dispatchTS = {
#ifdef EXPRECISION
  qsum_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qcopy_dispatch_t openblas_qcopy_dispatchTS = {
#ifdef EXPRECISION
  qcopy_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qdot_dispatch_t openblas_qdot_dispatchTS = {
#ifdef EXPRECISION
  qdot_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qrot_dispatch_t openblas_qrot_dispatchTS = {
#ifdef EXPRECISION
  qrot_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qrotm_dispatch_t openblas_qrotm_dispatchTS = {
#ifdef EXPRECISION
  qrotm_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qaxpy_dispatch_t openblas_qaxpy_dispatchTS = {
#ifdef EXPRECISION
  qaxpy_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qscal_dispatch_t openblas_qscal_dispatchTS = {
#ifdef EXPRECISION
  qscal_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qswap_dispatch_t openblas_qswap_dispatchTS = {
#ifdef EXPRECISION
  qswap_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qgemv_dispatch_t openblas_qgemv_dispatchTS = {
#ifdef EXPRECISION
  qgemv_nTS,
  qgemv_tTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qger_dispatch_t openblas_qger_dispatchTS = {
#ifdef EXPRECISION
  qger_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qsymv_dispatch_t openblas_qsymv_dispatchTS = {
#ifdef EXPRECISION
  qsymv_LTS,
  qsymv_UTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qgemm_dispatch_t openblas_qgemm_dispatchTS = {
#ifdef EXPRECISION
  qgemm_kernelTS,
  qgemm_betaTS,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qgemm_incopyTS,
  qgemm_itcopyTS,
#else
  qgemm_oncopyTS,
  qgemm_otcopyTS,
#endif
  qgemm_oncopyTS,
  qgemm_otcopyTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qtrsm_dispatch_t openblas_qtrsm_dispatchTS = {
#ifdef EXPRECISION
  qtrsm_kernel_LNTS,
  qtrsm_kernel_LTTS,
  qtrsm_kernel_RNTS,
  qtrsm_kernel_RTTS,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrsm_iunucopyTS,
  qtrsm_iunncopyTS,
  qtrsm_iutucopyTS,
  qtrsm_iutncopyTS,
  qtrsm_ilnucopyTS,
  qtrsm_ilnncopyTS,
  qtrsm_iltucopyTS,
  qtrsm_iltncopyTS,
#else
  qtrsm_ounucopyTS,
  qtrsm_ounncopyTS,
  qtrsm_outucopyTS,
  qtrsm_outncopyTS,
  qtrsm_olnucopyTS,
  qtrsm_olnncopyTS,
  qtrsm_oltucopyTS,
  qtrsm_oltncopyTS,
#endif
  qtrsm_ounucopyTS,
  qtrsm_ounncopyTS,
  qtrsm_outucopyTS,
  qtrsm_outncopyTS,
  qtrsm_olnucopyTS,
  qtrsm_olnncopyTS,
  qtrsm_oltucopyTS,
  qtrsm_oltncopyTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qtrmm_dispatch_t openblas_qtrmm_dispatchTS = {
#ifdef EXPRECISION
  qtrmm_kernel_RNTS,
  qtrmm_kernel_RTTS,
  qtrmm_kernel_LNTS,
  qtrmm_kernel_LTTS,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrmm_iunucopyTS,
  qtrmm_iunncopyTS,
  qtrmm_iutucopyTS,
  qtrmm_iutncopyTS,
  qtrmm_ilnucopyTS,
  qtrmm_ilnncopyTS,
  qtrmm_iltucopyTS,
  qtrmm_iltncopyTS,
#else
  qtrmm_ounucopyTS,
  qtrmm_ounncopyTS,
  qtrmm_outucopyTS,
  qtrmm_outncopyTS,
  qtrmm_olnucopyTS,
  qtrmm_olnncopyTS,
  qtrmm_oltucopyTS,
  qtrmm_oltncopyTS,
#endif
  qtrmm_ounucopyTS,
  qtrmm_ounncopyTS,
  qtrmm_outucopyTS,
  qtrmm_outncopyTS,
  qtrmm_olnucopyTS,
  qtrmm_olnncopyTS,
  qtrmm_oltucopyTS,
  qtrmm_oltncopyTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qsymm_dispatch_t openblas_qsymm_dispatchTS = {
#ifdef EXPRECISION
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qsymm_iutcopyTS,
  qsymm_iltcopyTS,
#else
  qsymm_outcopyTS,
  qsymm_oltcopyTS,
#endif
  qsymm_outcopyTS,
  qsymm_oltcopyTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qneg_dispatch_t openblas_qneg_dispatchTS = {
#ifdef EXPRECISION
#ifndef NO_LAPACK
  qneg_tcopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#ifdef EXPRECISION
const openblas_qlaswp_dispatch_t openblas_qlaswp_dispatchTS = {
#ifdef EXPRECISION
#ifndef NO_LAPACK
  qlaswp_ncopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_camax_dispatch_t openblas_camax_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  camax_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_camin_dispatch_t openblas_camin_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  camin_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_icamax_dispatch_t openblas_icamax_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  icamax_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_icamin_dispatch_t openblas_icamin_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  icamin_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cnrm2_dispatch_t openblas_cnrm2_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  cnrm2_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_casum_dispatch_t openblas_casum_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  casum_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_csum_dispatch_t openblas_csum_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  csum_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_ccopy_dispatch_t openblas_ccopy_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  ccopy_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cdotu_dispatch_t openblas_cdotu_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  cdotu_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cdotc_dispatch_t openblas_cdotc_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  cdotc_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_csrot_dispatch_t openblas_csrot_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
 csrot_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_caxpy_dispatch_t openblas_caxpy_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  caxpy_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_caxpyc_dispatch_t openblas_caxpyc_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  caxpyc_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cscal_dispatch_t openblas_cscal_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  cscal_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cswap_dispatch_t openblas_cswap_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  cswap_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cgemv_dispatch_t openblas_cgemv_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  cgemv_nTS,
  cgemv_tTS,
  cgemv_rTS,
  cgemv_cTS,
  cgemv_oTS,
  cgemv_uTS,
  cgemv_sTS,
  cgemv_dTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cgeru_dispatch_t openblas_cgeru_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  cgeru_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cgerc_dispatch_t openblas_cgerc_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  cgerc_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cgerv_dispatch_t openblas_cgerv_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  cgerv_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cgerd_dispatch_t openblas_cgerd_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  cgerd_kTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_csymv_dispatch_t openblas_csymv_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  csymv_LTS,
  csymv_UTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_chemv_dispatch_t openblas_chemv_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  chemv_LTS,
  chemv_UTS,
  chemv_MTS,
  chemv_VTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cgemm_dispatch_t openblas_cgemm_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  cgemm_kernel_nTS,
  cgemm_kernel_lTS,
  cgemm_kernel_rTS,
  cgemm_kernel_bTS,
  cgemm_betaTS,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  cgemm_incopyTS,
  cgemm_itcopyTS,
#else
  cgemm_oncopyTS,
  cgemm_otcopyTS,
#endif
  cgemm_oncopyTS,
  cgemm_otcopyTS,
#ifdef SMALL_MATRIX_OPT
  cgemm_small_matrix_permitTS,
  cgemm_small_kernel_nnTS,
  cgemm_small_kernel_ntTS,
  cgemm_small_kernel_nrTS,
  cgemm_small_kernel_ncTS,
  cgemm_small_kernel_tnTS,
  cgemm_small_kernel_ttTS,
  cgemm_small_kernel_trTS,
  cgemm_small_kernel_tcTS,
  cgemm_small_kernel_rnTS,
  cgemm_small_kernel_rtTS,
  cgemm_small_kernel_rrTS,
  cgemm_small_kernel_rcTS,
  cgemm_small_kernel_cnTS,
  cgemm_small_kernel_ctTS,
  cgemm_small_kernel_crTS,
  cgemm_small_kernel_ccTS,
  cgemm_small_kernel_b0_nnTS,
  cgemm_small_kernel_b0_ntTS,
  cgemm_small_kernel_b0_nrTS,
  cgemm_small_kernel_b0_ncTS,
  cgemm_small_kernel_b0_tnTS,
  cgemm_small_kernel_b0_ttTS,
  cgemm_small_kernel_b0_trTS,
  cgemm_small_kernel_b0_tcTS,
  cgemm_small_kernel_b0_rnTS,
  cgemm_small_kernel_b0_rtTS,
  cgemm_small_kernel_b0_rrTS,
  cgemm_small_kernel_b0_rcTS,
  cgemm_small_kernel_b0_cnTS,
  cgemm_small_kernel_b0_ctTS,
  cgemm_small_kernel_b0_crTS,
  cgemm_small_kernel_b0_ccTS,
#endif
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_ctrsm_dispatch_t openblas_ctrsm_dispatchTS = {
#if (BUILD_COMPLEX)
#if (BUILD_COMPLEX)
  ctrsm_kernel_LNTS,
  ctrsm_kernel_LTTS,
  ctrsm_kernel_LRTS,
  ctrsm_kernel_LCTS,
  ctrsm_kernel_RNTS,
  ctrsm_kernel_RTTS,
  ctrsm_kernel_RRTS,
  ctrsm_kernel_RCTS,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrsm_iunucopyTS,
  ctrsm_iunncopyTS,
  ctrsm_iutucopyTS,
  ctrsm_iutncopyTS,
  ctrsm_ilnucopyTS,
  ctrsm_ilnncopyTS,
  ctrsm_iltucopyTS,
  ctrsm_iltncopyTS,
#else
  ctrsm_ounucopyTS,
  ctrsm_ounncopyTS,
  ctrsm_outucopyTS,
  ctrsm_outncopyTS,
  ctrsm_olnucopyTS,
  ctrsm_olnncopyTS,
  ctrsm_oltucopyTS,
  ctrsm_oltncopyTS,
#endif
  ctrsm_ounucopyTS,
  ctrsm_ounncopyTS,
  ctrsm_outucopyTS,
  ctrsm_outncopyTS,
  ctrsm_olnucopyTS,
  ctrsm_olnncopyTS,
  ctrsm_oltucopyTS,
  ctrsm_oltncopyTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_ctrmm_dispatch_t openblas_ctrmm_dispatchTS = {
#if (BUILD_COMPLEX)
  ctrmm_kernel_RNTS,
  ctrmm_kernel_RTTS,
  ctrmm_kernel_RRTS,
  ctrmm_kernel_RCTS,
  ctrmm_kernel_LNTS,
  ctrmm_kernel_LTTS,
  ctrmm_kernel_LRTS,
  ctrmm_kernel_LCTS,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrmm_iunucopyTS,
  ctrmm_iunncopyTS,
  ctrmm_iutucopyTS,
  ctrmm_iutncopyTS,
  ctrmm_ilnucopyTS,
  ctrmm_ilnncopyTS,
  ctrmm_iltucopyTS,
  ctrmm_iltncopyTS,
#else
  ctrmm_ounucopyTS,
  ctrmm_ounncopyTS,
  ctrmm_outucopyTS,
  ctrmm_outncopyTS,
  ctrmm_olnucopyTS,
  ctrmm_olnncopyTS,
  ctrmm_oltucopyTS,
  ctrmm_oltncopyTS,
#endif
  ctrmm_ounucopyTS,
  ctrmm_ounncopyTS,
  ctrmm_outucopyTS,
  ctrmm_outncopyTS,
  ctrmm_olnucopyTS,
  ctrmm_olnncopyTS,
  ctrmm_oltucopyTS,
  ctrmm_oltncopyTS,
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_csymm_dispatch_t openblas_csymm_dispatchTS = {
#if (BUILD_COMPLEX)
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  csymm_iutcopyTS,
  csymm_iltcopyTS,
#else
  csymm_outcopyTS,
  csymm_oltcopyTS,
#endif
  csymm_outcopyTS,
  csymm_oltcopyTS,
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_chemm_dispatch_t openblas_chemm_dispatchTS = {
#if (BUILD_COMPLEX)
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  chemm_iutcopyTS,
  chemm_iltcopyTS,
#else
  chemm_outcopyTS,
  chemm_oltcopyTS,
#endif
  chemm_outcopyTS,
  chemm_oltcopyTS,
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cgemm3m_dispatch_t openblas_cgemm3m_dispatchTS = {
#if (BUILD_COMPLEX)
#if (USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_UNROLL_M
#else
#endif
  cgemm3m_kernelTS,
  cgemm3m_incopybTS,
  cgemm3m_incopyrTS,
  cgemm3m_incopyiTS,
  cgemm3m_itcopybTS,
  cgemm3m_itcopyrTS,
  cgemm3m_itcopyiTS,
  cgemm3m_oncopybTS,
  cgemm3m_oncopyrTS,
  cgemm3m_oncopyiTS,
  cgemm3m_otcopybTS,
  cgemm3m_otcopyrTS,
  cgemm3m_otcopyiTS,
#else
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_csymm3m_dispatch_t openblas_csymm3m_dispatchTS = {
#if (BUILD_COMPLEX)
#if (USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_UNROLL_M
#else
#endif
  csymm3m_iucopybTS,
  csymm3m_ilcopybTS,
  csymm3m_iucopyrTS,
  csymm3m_ilcopyrTS,
  csymm3m_iucopyiTS,
  csymm3m_ilcopyiTS,
  csymm3m_oucopybTS,
  csymm3m_olcopybTS,
  csymm3m_oucopyrTS,
  csymm3m_olcopyrTS,
  csymm3m_oucopyiTS,
  csymm3m_olcopyiTS,
#else
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_chemm3m_dispatch_t openblas_chemm3m_dispatchTS = {
#if (BUILD_COMPLEX)
#if (USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_UNROLL_M
#else
#endif
  chemm3m_iucopybTS,
  chemm3m_ilcopybTS,
  chemm3m_iucopyrTS,
  chemm3m_ilcopyrTS,
  chemm3m_iucopyiTS,
  chemm3m_ilcopyiTS,
  chemm3m_oucopybTS,
  chemm3m_olcopybTS,
  chemm3m_oucopyrTS,
  chemm3m_olcopyrTS,
  chemm3m_oucopyiTS,
  chemm3m_olcopyiTS,
#else
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cneg_dispatch_t openblas_cneg_dispatchTS = {
#if (BUILD_COMPLEX)
#ifndef NO_LAPACK
  cneg_tcopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_claswp_dispatch_t openblas_claswp_dispatchTS = {
#if (BUILD_COMPLEX)
#ifndef NO_LAPACK
   claswp_ncopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zamax_dispatch_t openblas_zamax_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zamax_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zamin_dispatch_t openblas_zamin_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zamin_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_izamax_dispatch_t openblas_izamax_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  izamax_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_izamin_dispatch_t openblas_izamin_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  izamin_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_znrm2_dispatch_t openblas_znrm2_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  znrm2_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zasum_dispatch_t openblas_zasum_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zasum_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zsum_dispatch_t openblas_zsum_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zsum_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zcopy_dispatch_t openblas_zcopy_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zcopy_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zdotu_dispatch_t openblas_zdotu_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zdotu_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zdotc_dispatch_t openblas_zdotc_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zdotc_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zdrot_dispatch_t openblas_zdrot_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zdrot_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zaxpy_dispatch_t openblas_zaxpy_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zaxpy_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zaxpyc_dispatch_t openblas_zaxpyc_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zaxpyc_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zscal_dispatch_t openblas_zscal_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zscal_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zswap_dispatch_t openblas_zswap_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zswap_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zgemv_dispatch_t openblas_zgemv_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zgemv_nTS,
  zgemv_tTS,
  zgemv_rTS,
  zgemv_cTS,
  zgemv_oTS,
  zgemv_uTS,
  zgemv_sTS,
  zgemv_dTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zgeru_dispatch_t openblas_zgeru_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zgeru_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zgerc_dispatch_t openblas_zgerc_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zgerc_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zgerv_dispatch_t openblas_zgerv_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zgerv_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zgerd_dispatch_t openblas_zgerd_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zgerd_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zsymv_dispatch_t openblas_zsymv_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zsymv_LTS,
  zsymv_UTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zhemv_dispatch_t openblas_zhemv_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zhemv_LTS,
  zhemv_UTS,
  zhemv_MTS,
  zhemv_VTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zgemm_dispatch_t openblas_zgemm_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zgemm_kernel_nTS,
  zgemm_kernel_lTS,
  zgemm_kernel_rTS,
  zgemm_kernel_bTS,
  zgemm_betaTS,
#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zgemm_incopyTS,
  zgemm_itcopyTS,
#else
  zgemm_oncopyTS,
  zgemm_otcopyTS,
#endif
  zgemm_oncopyTS,
  zgemm_otcopyTS,
#ifdef SMALL_MATRIX_OPT
  zgemm_small_matrix_permitTS,
  zgemm_small_kernel_nnTS,
  zgemm_small_kernel_ntTS,
  zgemm_small_kernel_nrTS,
  zgemm_small_kernel_ncTS,
  zgemm_small_kernel_tnTS,
  zgemm_small_kernel_ttTS,
  zgemm_small_kernel_trTS,
  zgemm_small_kernel_tcTS,
  zgemm_small_kernel_rnTS,
  zgemm_small_kernel_rtTS,
  zgemm_small_kernel_rrTS,
  zgemm_small_kernel_rcTS,
  zgemm_small_kernel_cnTS,
  zgemm_small_kernel_ctTS,
  zgemm_small_kernel_crTS,
  zgemm_small_kernel_ccTS,
  zgemm_small_kernel_b0_nnTS,
  zgemm_small_kernel_b0_ntTS,
  zgemm_small_kernel_b0_nrTS,
  zgemm_small_kernel_b0_ncTS,
  zgemm_small_kernel_b0_tnTS,
  zgemm_small_kernel_b0_ttTS,
  zgemm_small_kernel_b0_trTS,
  zgemm_small_kernel_b0_tcTS,
  zgemm_small_kernel_b0_rnTS,
  zgemm_small_kernel_b0_rtTS,
  zgemm_small_kernel_b0_rrTS,
  zgemm_small_kernel_b0_rcTS,
  zgemm_small_kernel_b0_cnTS,
  zgemm_small_kernel_b0_ctTS,
  zgemm_small_kernel_b0_crTS,
  zgemm_small_kernel_b0_ccTS,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_ztrsm_dispatch_t openblas_ztrsm_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  ztrsm_kernel_LNTS,
  ztrsm_kernel_LTTS,
  ztrsm_kernel_LRTS,
  ztrsm_kernel_LCTS,
  ztrsm_kernel_RNTS,
  ztrsm_kernel_RTTS,
  ztrsm_kernel_RRTS,
  ztrsm_kernel_RCTS,
#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrsm_iunucopyTS,
  ztrsm_iunncopyTS,
  ztrsm_iutucopyTS,
  ztrsm_iutncopyTS,
  ztrsm_ilnucopyTS,
  ztrsm_ilnncopyTS,
  ztrsm_iltucopyTS,
  ztrsm_iltncopyTS,
#else
  ztrsm_ounucopyTS,
  ztrsm_ounncopyTS,
  ztrsm_outucopyTS,
  ztrsm_outncopyTS,
  ztrsm_olnucopyTS,
  ztrsm_olnncopyTS,
  ztrsm_oltucopyTS,
  ztrsm_oltncopyTS,
#endif
  ztrsm_ounucopyTS,
  ztrsm_ounncopyTS,
  ztrsm_outucopyTS,
  ztrsm_outncopyTS,
  ztrsm_olnucopyTS,
  ztrsm_olnncopyTS,
  ztrsm_oltucopyTS,
  ztrsm_oltncopyTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_ztrmm_dispatch_t openblas_ztrmm_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  ztrmm_kernel_RNTS,
  ztrmm_kernel_RTTS,
  ztrmm_kernel_RRTS,
  ztrmm_kernel_RCTS,
  ztrmm_kernel_LNTS,
  ztrmm_kernel_LTTS,
  ztrmm_kernel_LRTS,
  ztrmm_kernel_LCTS,
#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrmm_iunucopyTS,
  ztrmm_iunncopyTS,
  ztrmm_iutucopyTS,
  ztrmm_iutncopyTS,
  ztrmm_ilnucopyTS,
  ztrmm_ilnncopyTS,
  ztrmm_iltucopyTS,
  ztrmm_iltncopyTS,
#else
  ztrmm_ounucopyTS,
  ztrmm_ounncopyTS,
  ztrmm_outucopyTS,
  ztrmm_outncopyTS,
  ztrmm_olnucopyTS,
  ztrmm_olnncopyTS,
  ztrmm_oltucopyTS,
  ztrmm_oltncopyTS,
#endif
  ztrmm_ounucopyTS,
  ztrmm_ounncopyTS,
  ztrmm_outucopyTS,
  ztrmm_outncopyTS,
  ztrmm_olnucopyTS,
  ztrmm_olnncopyTS,
  ztrmm_oltucopyTS,
  ztrmm_oltncopyTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zsymm_dispatch_t openblas_zsymm_dispatchTS = {
#if BUILD_COMPLEX16 == 1
#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zsymm_iutcopyTS,
  zsymm_iltcopyTS,
#else
  zsymm_outcopyTS,
  zsymm_oltcopyTS,
#endif
  zsymm_outcopyTS,
  zsymm_oltcopyTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zhemm_dispatch_t openblas_zhemm_dispatchTS = {
#if BUILD_COMPLEX16 == 1
#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zhemm_iutcopyTS,
  zhemm_iltcopyTS,
#else
  zhemm_outcopyTS,
  zhemm_oltcopyTS,
#endif
  zhemm_outcopyTS,
  zhemm_oltcopyTS,
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zgemm3m_dispatch_t openblas_zgemm3m_dispatchTS = {
#if BUILD_COMPLEX16 == 1
#if (USE_GEMM3M)
#ifdef ZGEMM3M_DEFAULT_UNROLL_M
#else
#endif
  zgemm3m_kernelTS,
  zgemm3m_incopybTS,
  zgemm3m_incopyrTS,
  zgemm3m_incopyiTS,
  zgemm3m_itcopybTS,
  zgemm3m_itcopyrTS,
  zgemm3m_itcopyiTS,
  zgemm3m_oncopybTS,
  zgemm3m_oncopyrTS,
  zgemm3m_oncopyiTS,
  zgemm3m_otcopybTS,
  zgemm3m_otcopyrTS,
  zgemm3m_otcopyiTS,
#else
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zsymm3m_dispatch_t openblas_zsymm3m_dispatchTS = {
#if BUILD_COMPLEX16 == 1
#if (USE_GEMM3M)
#ifdef ZGEMM3M_DEFAULT_UNROLL_M
#else
#endif
  zsymm3m_iucopybTS,
  zsymm3m_ilcopybTS,
  zsymm3m_iucopyrTS,
  zsymm3m_ilcopyrTS,
  zsymm3m_iucopyiTS,
  zsymm3m_ilcopyiTS,
  zsymm3m_oucopybTS,
  zsymm3m_olcopybTS,
  zsymm3m_oucopyrTS,
  zsymm3m_olcopyrTS,
  zsymm3m_oucopyiTS,
  zsymm3m_olcopyiTS,
#else
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zhemm3m_dispatch_t openblas_zhemm3m_dispatchTS = {
#if BUILD_COMPLEX16 == 1
#if (USE_GEMM3M)
#ifdef ZGEMM3M_DEFAULT_UNROLL_M
#else
#endif
  zhemm3m_iucopybTS,
  zhemm3m_ilcopybTS,
  zhemm3m_iucopyrTS,
  zhemm3m_ilcopyrTS,
  zhemm3m_iucopyiTS,
  zhemm3m_ilcopyiTS,
  zhemm3m_oucopybTS,
  zhemm3m_olcopybTS,
  zhemm3m_oucopyrTS,
  zhemm3m_olcopyrTS,
  zhemm3m_oucopyiTS,
  zhemm3m_olcopyiTS,
#else
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zneg_dispatch_t openblas_zneg_dispatchTS = {
#if BUILD_COMPLEX16 == 1
#ifndef NO_LAPACK
  zneg_tcopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#if (BUILD_COMPLEX16 == 1)
const openblas_zlaswp_dispatch_t openblas_zlaswp_dispatchTS = {
#if BUILD_COMPLEX16 == 1
#ifndef NO_LAPACK
  zlaswp_ncopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xamax_dispatch_t openblas_xamax_dispatchTS = {
#ifdef EXPRECISION
  xamax_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xamin_dispatch_t openblas_xamin_dispatchTS = {
#ifdef EXPRECISION
  xamin_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_ixamax_dispatch_t openblas_ixamax_dispatchTS = {
#ifdef EXPRECISION
  ixamax_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_ixamin_dispatch_t openblas_ixamin_dispatchTS = {
#ifdef EXPRECISION
  ixamin_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xnrm2_dispatch_t openblas_xnrm2_dispatchTS = {
#ifdef EXPRECISION
  xnrm2_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xasum_dispatch_t openblas_xasum_dispatchTS = {
#ifdef EXPRECISION
  xasum_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xsum_dispatch_t openblas_xsum_dispatchTS = {
#ifdef EXPRECISION
  xsum_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xcopy_dispatch_t openblas_xcopy_dispatchTS = {
#ifdef EXPRECISION
  xcopy_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xdotu_dispatch_t openblas_xdotu_dispatchTS = {
#ifdef EXPRECISION
  xdotu_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xdotc_dispatch_t openblas_xdotc_dispatchTS = {
#ifdef EXPRECISION
  xdotc_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xqrot_dispatch_t openblas_xqrot_dispatchTS = {
#ifdef EXPRECISION
  xqrot_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xaxpy_dispatch_t openblas_xaxpy_dispatchTS = {
#ifdef EXPRECISION
  xaxpy_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xaxpyc_dispatch_t openblas_xaxpyc_dispatchTS = {
#ifdef EXPRECISION
  xaxpyc_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xscal_dispatch_t openblas_xscal_dispatchTS = {
#ifdef EXPRECISION
  xscal_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xswap_dispatch_t openblas_xswap_dispatchTS = {
#ifdef EXPRECISION
  xswap_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xgemv_dispatch_t openblas_xgemv_dispatchTS = {
#ifdef EXPRECISION
  xgemv_nTS,
  xgemv_tTS,
  xgemv_rTS,
  xgemv_cTS,
  xgemv_oTS,
  xgemv_uTS,
  xgemv_sTS,
  xgemv_dTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xgeru_dispatch_t openblas_xgeru_dispatchTS = {
#ifdef EXPRECISION
  xgeru_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xgerc_dispatch_t openblas_xgerc_dispatchTS = {
#ifdef EXPRECISION
  xgerc_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xgerv_dispatch_t openblas_xgerv_dispatchTS = {
#ifdef EXPRECISION
  xgerv_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xgerd_dispatch_t openblas_xgerd_dispatchTS = {
#ifdef EXPRECISION
  xgerd_kTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xsymv_dispatch_t openblas_xsymv_dispatchTS = {
#ifdef EXPRECISION
  xsymv_LTS,
  xsymv_UTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xhemv_dispatch_t openblas_xhemv_dispatchTS = {
#ifdef EXPRECISION
  xhemv_LTS,
  xhemv_UTS,
  xhemv_MTS,
  xhemv_VTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xgemm_dispatch_t openblas_xgemm_dispatchTS = {
#ifdef EXPRECISION
  xgemm_kernel_nTS,
  xgemm_kernel_lTS,
  xgemm_kernel_rTS,
  xgemm_kernel_bTS,
  xgemm_betaTS,
#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xgemm_incopyTS,
  xgemm_itcopyTS,
#else
  xgemm_oncopyTS,
  xgemm_otcopyTS,
#endif
  xgemm_oncopyTS,
  xgemm_otcopyTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xtrsm_dispatch_t openblas_xtrsm_dispatchTS = {
#ifdef EXPRECISION
  xtrsm_kernel_LNTS,
  xtrsm_kernel_LTTS,
  xtrsm_kernel_LRTS,
  xtrsm_kernel_LCTS,
  xtrsm_kernel_RNTS,
  xtrsm_kernel_RTTS,
  xtrsm_kernel_RRTS,
  xtrsm_kernel_RCTS,
#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrsm_iunucopyTS,
  xtrsm_iunncopyTS,
  xtrsm_iutucopyTS,
  xtrsm_iutncopyTS,
  xtrsm_ilnucopyTS,
  xtrsm_ilnncopyTS,
  xtrsm_iltucopyTS,
  xtrsm_iltncopyTS,
#else
  xtrsm_ounucopyTS,
  xtrsm_ounncopyTS,
  xtrsm_outucopyTS,
  xtrsm_outncopyTS,
  xtrsm_olnucopyTS,
  xtrsm_olnncopyTS,
  xtrsm_oltucopyTS,
  xtrsm_oltncopyTS,
#endif
  xtrsm_ounucopyTS,
  xtrsm_ounncopyTS,
  xtrsm_outucopyTS,
  xtrsm_outncopyTS,
  xtrsm_olnucopyTS,
  xtrsm_olnncopyTS,
  xtrsm_oltucopyTS,
  xtrsm_oltncopyTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xtrmm_dispatch_t openblas_xtrmm_dispatchTS = {
#ifdef EXPRECISION
  xtrmm_kernel_RNTS,
  xtrmm_kernel_RTTS,
  xtrmm_kernel_RRTS,
  xtrmm_kernel_RCTS,
  xtrmm_kernel_LNTS,
  xtrmm_kernel_LTTS,
  xtrmm_kernel_LRTS,
  xtrmm_kernel_LCTS,
#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrmm_iunucopyTS,
  xtrmm_iunncopyTS,
  xtrmm_iutucopyTS,
  xtrmm_iutncopyTS,
  xtrmm_ilnucopyTS,
  xtrmm_ilnncopyTS,
  xtrmm_iltucopyTS,
  xtrmm_iltncopyTS,
#else
  xtrmm_ounucopyTS,
  xtrmm_ounncopyTS,
  xtrmm_outucopyTS,
  xtrmm_outncopyTS,
  xtrmm_olnucopyTS,
  xtrmm_olnncopyTS,
  xtrmm_oltucopyTS,
  xtrmm_oltncopyTS,
#endif
  xtrmm_ounucopyTS,
  xtrmm_ounncopyTS,
  xtrmm_outucopyTS,
  xtrmm_outncopyTS,
  xtrmm_olnucopyTS,
  xtrmm_olnncopyTS,
  xtrmm_oltucopyTS,
  xtrmm_oltncopyTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xsymm_dispatch_t openblas_xsymm_dispatchTS = {
#ifdef EXPRECISION
#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xsymm_iutcopyTS,
  xsymm_iltcopyTS,
#else
  xsymm_outcopyTS,
  xsymm_oltcopyTS,
#endif
  xsymm_outcopyTS,
  xsymm_oltcopyTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xhemm_dispatch_t openblas_xhemm_dispatchTS = {
#ifdef EXPRECISION
#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xhemm_iutcopyTS,
  xhemm_iltcopyTS,
#else
  xhemm_outcopyTS,
  xhemm_oltcopyTS,
#endif
  xhemm_outcopyTS,
  xhemm_oltcopyTS,
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xgemm3m_dispatch_t openblas_xgemm3m_dispatchTS = {
#ifdef EXPRECISION
#if (USE_GEMM3M)
  xgemm3m_kernelTS,
  xgemm3m_incopybTS,
  xgemm3m_incopyrTS,
  xgemm3m_incopyiTS,
  xgemm3m_itcopybTS,
  xgemm3m_itcopyrTS,
  xgemm3m_itcopyiTS,
  xgemm3m_oncopybTS,
  xgemm3m_oncopyrTS,
  xgemm3m_oncopyiTS,
  xgemm3m_otcopybTS,
  xgemm3m_otcopyrTS,
  xgemm3m_otcopyiTS,
#else
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
#endif
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xsymm3m_dispatch_t openblas_xsymm3m_dispatchTS = {
#ifdef EXPRECISION
#if (USE_GEMM3M)
  xsymm3m_iucopybTS,
  xsymm3m_ilcopybTS,
  xsymm3m_iucopyrTS,
  xsymm3m_ilcopyrTS,
  xsymm3m_iucopyiTS,
  xsymm3m_ilcopyiTS,
  xsymm3m_oucopybTS,
  xsymm3m_olcopybTS,
  xsymm3m_oucopyrTS,
  xsymm3m_olcopyrTS,
  xsymm3m_oucopyiTS,
  xsymm3m_olcopyiTS,
#else
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
#endif
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xhemm3m_dispatch_t openblas_xhemm3m_dispatchTS = {
#ifdef EXPRECISION
#if (USE_GEMM3M)
  xhemm3m_iucopybTS,
  xhemm3m_ilcopybTS,
  xhemm3m_iucopyrTS,
  xhemm3m_ilcopyrTS,
  xhemm3m_iucopyiTS,
  xhemm3m_ilcopyiTS,
  xhemm3m_oucopybTS,
  xhemm3m_olcopybTS,
  xhemm3m_oucopyrTS,
  xhemm3m_olcopyrTS,
  xhemm3m_oucopyiTS,
  xhemm3m_olcopyiTS,
#else
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
#endif
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xneg_dispatch_t openblas_xneg_dispatchTS = {
#ifdef EXPRECISION
#ifndef NO_LAPACK
  xneg_tcopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#ifdef EXPRECISION
const openblas_xlaswp_dispatch_t openblas_xlaswp_dispatchTS = {
#ifdef EXPRECISION
#ifndef NO_LAPACK
  xlaswp_ncopyTS,
#else
  NULL,
#endif
#endif
};
#endif

#if (BUILD_SINGLE==1)
const openblas_saxpby_dispatch_t openblas_saxpby_dispatchTS = {
#if BUILD_SINGLE == 1
  saxpby_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1)
const openblas_daxpby_dispatch_t openblas_daxpby_dispatchTS = {
#if BUILD_DOUBLE  == 1
  daxpby_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_caxpby_dispatch_t openblas_caxpby_dispatchTS = {
#if BUILD_COMPLEX == 1
  caxpby_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16==1)
const openblas_zaxpby_dispatch_t openblas_zaxpby_dispatchTS = {
#if BUILD_COMPLEX16== 1
  zaxpby_kTS,
#endif
};
#endif

#if (BUILD_SINGLE==1)
const openblas_somatcopy_dispatch_t openblas_somatcopy_dispatchTS = {
#if BUILD_SINGLE == 1
  somatcopy_k_cnTS,
  somatcopy_k_ctTS,
  somatcopy_k_rnTS,
  somatcopy_k_rtTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1)
const openblas_domatcopy_dispatch_t openblas_domatcopy_dispatchTS = {
#if BUILD_DOUBLE== 1
  domatcopy_k_cnTS,
  domatcopy_k_ctTS,
  domatcopy_k_rnTS,
  domatcopy_k_rtTS,
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_comatcopy_dispatch_t openblas_comatcopy_dispatchTS = {
#if BUILD_COMPLEX == 1
  comatcopy_k_cnTS,
  comatcopy_k_ctTS,
  comatcopy_k_rnTS,
  comatcopy_k_rtTS,
  comatcopy_k_cncTS,
  comatcopy_k_ctcTS,
  comatcopy_k_rncTS,
  comatcopy_k_rtcTS,
#endif
};
#endif

#if (BUILD_COMPLEX16==1)
const openblas_zomatcopy_dispatch_t openblas_zomatcopy_dispatchTS = {
#if BUILD_COMPLEX16 == 1
  zomatcopy_k_cnTS,
  zomatcopy_k_ctTS,
  zomatcopy_k_rnTS,
  zomatcopy_k_rtTS,
  zomatcopy_k_cncTS,
  zomatcopy_k_ctcTS,
  zomatcopy_k_rncTS,
  zomatcopy_k_rtcTS,
#endif
};
#endif

#if (BUILD_SINGLE==1)
const openblas_simatcopy_dispatch_t openblas_simatcopy_dispatchTS = {
#if BUILD_SINGLE == 1
  simatcopy_k_cnTS,
  simatcopy_k_ctTS,
  simatcopy_k_rnTS,
  simatcopy_k_rtTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1)
const openblas_dimatcopy_dispatch_t openblas_dimatcopy_dispatchTS = {
#if BUILD_DOUBLE== 1
  dimatcopy_k_cnTS,
  dimatcopy_k_ctTS,
  dimatcopy_k_rnTS,
  dimatcopy_k_rtTS,
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cimatcopy_dispatch_t openblas_cimatcopy_dispatchTS = {
#if BUILD_COMPLEX== 1
  cimatcopy_k_cnTS,
  cimatcopy_k_ctTS,
  cimatcopy_k_rnTS,
  cimatcopy_k_rtTS,
  cimatcopy_k_cncTS,
  cimatcopy_k_ctcTS,
  cimatcopy_k_rncTS,
  cimatcopy_k_rtcTS,
#endif
};
#endif

#if (BUILD_COMPLEX16==1)
const openblas_zimatcopy_dispatch_t openblas_zimatcopy_dispatchTS = {
#if BUILD_COMPLEX16==1
  zimatcopy_k_cnTS,
  zimatcopy_k_ctTS,
  zimatcopy_k_rnTS,
  zimatcopy_k_rtTS,
  zimatcopy_k_cncTS,
  zimatcopy_k_ctcTS,
  zimatcopy_k_rncTS,
  zimatcopy_k_rtcTS,
#endif
};
#endif

#if (BUILD_SINGLE==1)
const openblas_sgeadd_dispatch_t openblas_sgeadd_dispatchTS = {
#if BUILD_SINGLE == 1
  sgeadd_kTS,
#endif
};
#endif

#if (BUILD_DOUBLE==1)
const openblas_dgeadd_dispatch_t openblas_dgeadd_dispatchTS = {
#if BUILD_DOUBLE==1
  dgeadd_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX==1)
const openblas_cgeadd_dispatch_t openblas_cgeadd_dispatchTS = {
#if BUILD_COMPLEX==1
  cgeadd_kTS,
#endif
};
#endif

#if (BUILD_COMPLEX16==1)
const openblas_zgeadd_dispatch_t openblas_zgeadd_dispatchTS = {
#if BUILD_COMPLEX16==1
  zgeadd_kTS,
#endif
};
#endif

#if (ARCH_ARM64)
static void init_parameter(void) {
#if (BUILD_BFLOAT16)
  openblas_paramsTS.sbgemm_p = SBGEMM_DEFAULT_P;
  openblas_paramsTS.bgemm_p = BGEMM_DEFAULT_P;
#endif
#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE == 1 || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX==1
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16==1
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif

#if (BUILD_BFLOAT16)
  openblas_paramsTS.sbgemm_q = SBGEMM_DEFAULT_Q;
  openblas_paramsTS.bgemm_q = BGEMM_DEFAULT_Q;
#endif
#if BUILD_SINGLE == 1 || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_q = SGEMM_DEFAULT_Q;
#endif
#if BUILD_DOUBLE== 1 || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_q = DGEMM_DEFAULT_Q;
#endif
#if BUILD_COMPLEX== 1
  openblas_paramsTS.cgemm_q = CGEMM_DEFAULT_Q;
#endif
#if BUILD_COMPLEX16==1
  openblas_paramsTS.zgemm_q = ZGEMM_DEFAULT_Q;
#endif

#if (BUILD_BFLOAT16)
  openblas_paramsTS.sbgemm_r = SBGEMM_DEFAULT_R;
  openblas_paramsTS.bgemm_r = BGEMM_DEFAULT_R;
#endif
#if BUILD_SINGLE == 1 || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_r = SGEMM_DEFAULT_R;
#endif
#if BUILD_DOUBLE==1  || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_r = DGEMM_DEFAULT_R;
#endif
#if BUILD_COMPLEX==1
  openblas_paramsTS.cgemm_r = CGEMM_DEFAULT_R;
#endif
#if BUILD_COMPLEX16==1
  openblas_paramsTS.zgemm_r = ZGEMM_DEFAULT_R;
#endif

#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
  openblas_paramsTS.qgemm_q = QGEMM_DEFAULT_Q;
  openblas_paramsTS.xgemm_q = XGEMM_DEFAULT_Q;
  openblas_paramsTS.qgemm_r = QGEMM_DEFAULT_R;
  openblas_paramsTS.xgemm_r = XGEMM_DEFAULT_R;
#endif

#if (USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_P
  openblas_paramsTS.cgemm3m_p = CGEMM3M_DEFAULT_P;
#else
  openblas_paramsTS.cgemm3m_p = openblas_paramsTS.sgemm_p;
#endif

#ifdef ZGEMM3M_DEFAULT_P
  openblas_paramsTS.zgemm3m_p = ZGEMM3M_DEFAULT_P;
#else
  openblas_paramsTS.zgemm3m_p = openblas_paramsTS.dgemm_p;
#endif

#ifdef CGEMM3M_DEFAULT_Q
  openblas_paramsTS.cgemm3m_q = CGEMM3M_DEFAULT_Q;
#else
  openblas_paramsTS.cgemm3m_q = openblas_paramsTS.sgemm_q;
#endif

#ifdef ZGEMM3M_DEFAULT_Q
  openblas_paramsTS.zgemm3m_q = ZGEMM3M_DEFAULT_Q;
#else
  openblas_paramsTS.zgemm3m_q = openblas_paramsTS.dgemm_q;
#endif

#ifdef CGEMM3M_DEFAULT_R
  openblas_paramsTS.cgemm3m_r = CGEMM3M_DEFAULT_R;
#else
  openblas_paramsTS.cgemm3m_r = openblas_paramsTS.sgemm_r;
#endif

#ifdef ZGEMM3M_DEFAULT_R
  openblas_paramsTS.zgemm3m_r = ZGEMM3M_DEFAULT_R;
#else
  openblas_paramsTS.zgemm3m_r = openblas_paramsTS.dgemm_r;
#endif

#ifdef EXPRECISION
  openblas_paramsTS.xgemm3m_p = openblas_paramsTS.qgemm_p;
  openblas_paramsTS.xgemm3m_q = openblas_paramsTS.qgemm_q;
  openblas_paramsTS.xgemm3m_r = openblas_paramsTS.qgemm_r;
#endif
#endif

}
#else // (ARCH_ARM64)
#if defined(ARCH_MIPS64)
static void init_parameter(void) {
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;

  openblas_paramsTS.sgemm_q = SGEMM_DEFAULT_Q;
  openblas_paramsTS.dgemm_q = DGEMM_DEFAULT_Q;
  openblas_paramsTS.cgemm_q = CGEMM_DEFAULT_Q;
  openblas_paramsTS.zgemm_q = ZGEMM_DEFAULT_Q;

  openblas_paramsTS.sgemm_r = SGEMM_DEFAULT_R;
  openblas_paramsTS.dgemm_r = 640;
  openblas_paramsTS.cgemm_r = CGEMM_DEFAULT_R;
  openblas_paramsTS.zgemm_r = ZGEMM_DEFAULT_R;

#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
  openblas_paramsTS.qgemm_q = QGEMM_DEFAULT_Q;
  openblas_paramsTS.xgemm_q = XGEMM_DEFAULT_Q;
  openblas_paramsTS.qgemm_r = QGEMM_DEFAULT_R;
  openblas_paramsTS.xgemm_r = XGEMM_DEFAULT_R;
#endif

#if defined(USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_P
  openblas_paramsTS.cgemm3m_p = CGEMM3M_DEFAULT_P;
#else
  openblas_paramsTS.cgemm3m_p = openblas_paramsTS.sgemm_p;
#endif

#ifdef ZGEMM3M_DEFAULT_P
  openblas_paramsTS.zgemm3m_p = ZGEMM3M_DEFAULT_P;
#else
  openblas_paramsTS.zgemm3m_p = openblas_paramsTS.dgemm_p;
#endif

#ifdef CGEMM3M_DEFAULT_Q
  openblas_paramsTS.cgemm3m_q = CGEMM3M_DEFAULT_Q;
#else
  openblas_paramsTS.cgemm3m_q = openblas_paramsTS.sgemm_q;
#endif

#ifdef ZGEMM3M_DEFAULT_Q
  openblas_paramsTS.zgemm3m_q = ZGEMM3M_DEFAULT_Q;
#else
  openblas_paramsTS.zgemm3m_q = openblas_paramsTS.dgemm_q;
#endif

#ifdef CGEMM3M_DEFAULT_R
  openblas_paramsTS.cgemm3m_r = CGEMM3M_DEFAULT_R;
#else
  openblas_paramsTS.cgemm3m_r = openblas_paramsTS.sgemm_r;
#endif

#ifdef ZGEMM3M_DEFAULT_R
  openblas_paramsTS.zgemm3m_r = ZGEMM3M_DEFAULT_R;
#else
  openblas_paramsTS.zgemm3m_r = openblas_paramsTS.dgemm_r;
#endif

#ifdef EXPRECISION
  openblas_paramsTS.xgemm3m_p = openblas_paramsTS.qgemm_p;
  openblas_paramsTS.xgemm3m_q = openblas_paramsTS.qgemm_q;
  openblas_paramsTS.xgemm3m_r = openblas_paramsTS.qgemm_r;
#endif
#endif
}
#else // (ARCH_MIPS64)
#if (ARCH_LOONGARCH64)
static int get_L3_size() {
  int ret = 0, id = 0x14;
  __asm__ volatile (
    "cpucfg %[ret], %[id]"
    : [ret]"=r"(ret)
    : [id]"r"(id)
    : "memory"
  );
  return ((ret & 0xffff) + 1) * pow(2, ((ret >> 16) & 0xff)) * pow(2, ((ret >> 24) & 0x7f)) / 1024 / 1024; // MB
}
static int get_cpu_prid() {
  int ret = 0, id = 0x0;
  __asm__ volatile (
    "cpucfg %[ret], %[id]"
    : [ret]"=r"(ret)
    : [id]"r"(id)
    : "memory"
  );
  return ret;
}
static void init_parameter(void) {

#ifdef BUILD_BFLOAT16
  openblas_paramsTS.sbgemm_p = SBGEMM_DEFAULT_P;
  openblas_paramsTS.bgemm_p = BGEMM_DEFAULT_P;
#endif

#ifdef BUILD_BFLOAT16
  openblas_paramsTS.sbgemm_r = SBGEMM_DEFAULT_R;
  openblas_paramsTS.bgemm_r = BGEMM_DEFAULT_R;
#endif

#if defined(LA464)
  int L3_size = get_L3_size();
#ifdef SMP
  if(blas_num_threads == 1){
#endif
    //single thread
    if (L3_size == 32){ // 3C5000 and 3D5000
      openblas_paramsTS.sgemm_p = 256;
      openblas_paramsTS.sgemm_q = 384;
      openblas_paramsTS.sgemm_r = 8192;

      openblas_paramsTS.dgemm_p = 112;
      openblas_paramsTS.dgemm_q = 289;
      openblas_paramsTS.dgemm_r = 4096;

      openblas_paramsTS.cgemm_p = 128;
      openblas_paramsTS.cgemm_q = 256;
      openblas_paramsTS.cgemm_r = 4096;

      openblas_paramsTS.zgemm_p = 128;
      openblas_paramsTS.zgemm_q = 128;
      openblas_paramsTS.zgemm_r = 2048;
    } else { // 3A5000 and 3C5000L
      openblas_paramsTS.sgemm_p = 256;
      openblas_paramsTS.sgemm_q = 384;
      openblas_paramsTS.sgemm_r = 4096;

      openblas_paramsTS.dgemm_p = 112;
      openblas_paramsTS.dgemm_q = 300;
      openblas_paramsTS.dgemm_r = 3024;

      openblas_paramsTS.cgemm_p = 128;
      openblas_paramsTS.cgemm_q = 256;
      openblas_paramsTS.cgemm_r = 2048;

      openblas_paramsTS.zgemm_p = 128;
      openblas_paramsTS.zgemm_q = 128;
      openblas_paramsTS.zgemm_r = 1024;
    }
#ifdef SMP
  }else{
    //multi thread
    if (L3_size == 32){ // 3C5000 and 3D5000
      openblas_paramsTS.sgemm_p = 256;
      openblas_paramsTS.sgemm_q = 384;
      openblas_paramsTS.sgemm_r = 1024;

      openblas_paramsTS.dgemm_p = 112;
      openblas_paramsTS.dgemm_q = 289;
      openblas_paramsTS.dgemm_r = 353;

      openblas_paramsTS.cgemm_p = 128;
      openblas_paramsTS.cgemm_q = 256;
      openblas_paramsTS.cgemm_r = 512;

      openblas_paramsTS.zgemm_p = 128;
      openblas_paramsTS.zgemm_q = 128;
      openblas_paramsTS.zgemm_r = 512;
    } else { // 3A5000 and 3C5000L
      openblas_paramsTS.sgemm_p = 256;
      openblas_paramsTS.sgemm_q = 384;
      openblas_paramsTS.sgemm_r = 2048;

      openblas_paramsTS.dgemm_p = 112;
      openblas_paramsTS.dgemm_q = 300;
      openblas_paramsTS.dgemm_r = 738;

      openblas_paramsTS.cgemm_p = 128;
      openblas_paramsTS.cgemm_q = 256;
      openblas_paramsTS.cgemm_r = 1024;

      openblas_paramsTS.zgemm_p = 128;
      openblas_paramsTS.zgemm_q = 128;
      openblas_paramsTS.zgemm_r = 1024;
    }
  }
#endif
#elif defined(LA264)
  int prid = get_cpu_prid();
  if (prid == 0x0014b020) { //2k3000
        openblas_paramsTS.zgemm_p = 128;
        openblas_paramsTS.zgemm_q = 176;
        openblas_paramsTS.zgemm_r = 360;
  } else {
        openblas_paramsTS.zgemm_p = 64;
        openblas_paramsTS.zgemm_q = 120;
        openblas_paramsTS.zgemm_r = 4096;
  }
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;

  openblas_paramsTS.sgemm_q = SGEMM_DEFAULT_Q;
  openblas_paramsTS.dgemm_q = DGEMM_DEFAULT_Q;
  openblas_paramsTS.cgemm_q = CGEMM_DEFAULT_Q;

  openblas_paramsTS.sgemm_r = SGEMM_DEFAULT_R;
  openblas_paramsTS.dgemm_r = DGEMM_DEFAULT_R;
  openblas_paramsTS.cgemm_r = CGEMM_DEFAULT_R;
#else
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;

  openblas_paramsTS.sgemm_q = SGEMM_DEFAULT_Q;
  openblas_paramsTS.dgemm_q = DGEMM_DEFAULT_Q;
  openblas_paramsTS.cgemm_q = CGEMM_DEFAULT_Q;
  openblas_paramsTS.zgemm_q = ZGEMM_DEFAULT_Q;

  openblas_paramsTS.sgemm_r = SGEMM_DEFAULT_R;
  openblas_paramsTS.dgemm_r = DGEMM_DEFAULT_R;
  openblas_paramsTS.cgemm_r = CGEMM_DEFAULT_R;
  openblas_paramsTS.zgemm_r = ZGEMM_DEFAULT_R;
#endif

#ifdef BUILD_BFLOAT16
  openblas_paramsTS.sbgemm_q = SBGEMM_DEFAULT_Q;
  openblas_paramsTS.bgemm_q = BGEMM_DEFAULT_Q;
#endif
}
#else // (ARCH_LOONGARCH64)
#if (ARCH_POWER)
static void init_parameter(void) {

#ifdef BUILD_BFLOAT16
  openblas_paramsTS.sbgemm_p = SBGEMM_DEFAULT_P;
  openblas_paramsTS.bgemm_p = BGEMM_DEFAULT_P;
#endif
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;

#ifdef BUILD_BFLOAT16
  openblas_paramsTS.sbgemm_r = SBGEMM_DEFAULT_R;
  openblas_paramsTS.bgemm_r = BGEMM_DEFAULT_R;
#endif
  openblas_paramsTS.sgemm_r = SGEMM_DEFAULT_R;
  openblas_paramsTS.dgemm_r = DGEMM_DEFAULT_R;
  openblas_paramsTS.cgemm_r = CGEMM_DEFAULT_R;
  openblas_paramsTS.zgemm_r = ZGEMM_DEFAULT_R;


#ifdef BUILD_BFLOAT16
  openblas_paramsTS.sbgemm_q = SBGEMM_DEFAULT_Q;
  openblas_paramsTS.bgemm_q = BGEMM_DEFAULT_Q;
#endif
  openblas_paramsTS.sgemm_q = SGEMM_DEFAULT_Q;
  openblas_paramsTS.dgemm_q = DGEMM_DEFAULT_Q;
  openblas_paramsTS.cgemm_q = CGEMM_DEFAULT_Q;
  openblas_paramsTS.zgemm_q = ZGEMM_DEFAULT_Q;
}
#else //POWER

#if (ARCH_ZARCH)
static void init_parameter(void) {
#ifdef BUILD_BFLOAT16
	openblas_paramsTS.sbgemm_p = SBGEMM_DEFAULT_P;
	openblas_paramsTS.bgemm_p = BGEMM_DEFAULT_P;
#endif
	openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
	openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
	openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
	openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;

#ifdef BUILD_BFLOAT16
	openblas_paramsTS.sbgemm_r = SBGEMM_DEFAULT_R;
	openblas_paramsTS.bgemm_r = BGEMM_DEFAULT_R;
#endif
	openblas_paramsTS.sgemm_r = SGEMM_DEFAULT_R;
	openblas_paramsTS.dgemm_r = DGEMM_DEFAULT_R;
	openblas_paramsTS.cgemm_r = CGEMM_DEFAULT_R;
	openblas_paramsTS.zgemm_r = ZGEMM_DEFAULT_R;


#ifdef BUILD_BFLOAT16
	openblas_paramsTS.sbgemm_q = SBGEMM_DEFAULT_Q;
	openblas_paramsTS.bgemm_q = BGEMM_DEFAULT_Q;
#endif
	openblas_paramsTS.sgemm_q = SGEMM_DEFAULT_Q;
	openblas_paramsTS.dgemm_q = DGEMM_DEFAULT_Q;
	openblas_paramsTS.cgemm_q = CGEMM_DEFAULT_Q;
	openblas_paramsTS.zgemm_q = ZGEMM_DEFAULT_Q;
}
#else //ZARCH

#if (ARCH_RISCV64)
static void init_parameter(void) {

#ifdef BUILD_BFLOAT16
  openblas_paramsTS.sbgemm_p = SBGEMM_DEFAULT_P;
  openblas_paramsTS.bgemm_p = BGEMM_DEFAULT_P;
#endif
#ifdef BUILD_HFLOAT16
  openblas_paramsTS.shgemm_p = SHGEMM_DEFAULT_P;
#endif
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;

#ifdef BUILD_BFLOAT16
  openblas_paramsTS.sbgemm_r = SBGEMM_DEFAULT_R;
  openblas_paramsTS.bgemm_r = BGEMM_DEFAULT_R;
#endif
#ifdef BUILD_HFLOAT16
  openblas_paramsTS.shgemm_r = SHGEMM_DEFAULT_R;
#endif
  openblas_paramsTS.sgemm_r = SGEMM_DEFAULT_R;
  openblas_paramsTS.dgemm_r = DGEMM_DEFAULT_R;
  openblas_paramsTS.cgemm_r = CGEMM_DEFAULT_R;
  openblas_paramsTS.zgemm_r = ZGEMM_DEFAULT_R;


#ifdef BUILD_BFLOAT16
  openblas_paramsTS.sbgemm_q = SBGEMM_DEFAULT_Q;
  openblas_paramsTS.bgemm_q = BGEMM_DEFAULT_Q;
#endif
#ifdef BUILD_HFLOAT16
  openblas_paramsTS.shgemm_q = SHGEMM_DEFAULT_Q;
#endif
  openblas_paramsTS.sgemm_q = SGEMM_DEFAULT_Q;
  openblas_paramsTS.dgemm_q = DGEMM_DEFAULT_Q;
  openblas_paramsTS.cgemm_q = CGEMM_DEFAULT_Q;
  openblas_paramsTS.zgemm_q = ZGEMM_DEFAULT_Q;
}
#else //RISCV64

#ifdef ARCH_X86
static int get_l2_size_old(void){
  int i, eax, ebx, ecx, edx, cpuid_level;
  int info[15];

  cpuid(2, &eax, &ebx, &ecx, &edx);

  info[ 0] = BITMASK(eax,  8, 0xff);
  info[ 1] = BITMASK(eax, 16, 0xff);
  info[ 2] = BITMASK(eax, 24, 0xff);

  info[ 3] = BITMASK(ebx,  0, 0xff);
  info[ 4] = BITMASK(ebx,  8, 0xff);
  info[ 5] = BITMASK(ebx, 16, 0xff);
  info[ 6] = BITMASK(ebx, 24, 0xff);

  info[ 7] = BITMASK(ecx,  0, 0xff);
  info[ 8] = BITMASK(ecx,  8, 0xff);
  info[ 9] = BITMASK(ecx, 16, 0xff);
  info[10] = BITMASK(ecx, 24, 0xff);

  info[11] = BITMASK(edx,  0, 0xff);
  info[12] = BITMASK(edx,  8, 0xff);
  info[13] = BITMASK(edx, 16, 0xff);
  info[14] = BITMASK(edx, 24, 0xff);

  for (i = 0; i < 15; i++){

    switch (info[i]){

      /* This table is from http://www.sandpile.org/ia32/cpuid.htm */

    case 0x1a :
      return 96;

    case 0x39 :
    case 0x3b :
    case 0x41 :
    case 0x79 :
    case 0x81 :
      return 128;

    case 0x3a :
      return 192;

    case 0x21 :
    case 0x3c :
    case 0x42 :
    case 0x7a :
    case 0x7e :
    case 0x82 :
      return 256;

    case 0x3d :
      return 384;

    case 0x3e :
    case 0x43 :
    case 0x7b :
    case 0x7f :
    case 0x83 :
    case 0x86 :
      return 512;

    case 0x44 :
    case 0x78 :
    case 0x7c :
    case 0x84 :
    case 0x87 :
      return 1024;

    case 0x45 :
    case 0x7d :
    case 0x85 :
      return 2048;

    case 0x48 :
      return 3184;

    case 0x49 :
      return 4096;

    case 0x4e :
      return 6144;
    }
  }
//  return 0;
fprintf (stderr,"OpenBLAS WARNING - could not determine the L2 cache size on this system, assuming 256k\n");
return 256;
}
#endif

static __inline__ int get_l2_size(void){

  int eax, ebx, ecx, edx, l2;

  l2 = readenv_atoi("OPENBLAS_L2_SIZE");
  if (l2 != 0)
    return l2;

  cpuid(0x80000006, &eax, &ebx, &ecx, &edx);

  l2 = BITMASK(ecx, 16, 0xffff);

#ifndef ARCH_X86
  if (l2 <= 0) {
     fprintf (stderr,"OpenBLAS WARNING - could not determine the L2 cache size on this system, assuming 256k\n");
     return 256;
  }
  return l2;

#else

  if (l2 > 0) return l2;

  return get_l2_size_old();
#endif
}

static __inline__ int get_l3_size(void){

  int eax, ebx, ecx, edx;

  cpuid(0x80000006, &eax, &ebx, &ecx, &edx);

  return BITMASK(edx, 18, 0x3fff) * 512;
}


static void init_parameter(void) {

  int l2 = get_l2_size();

  (void) l2; /* dirty trick to suppress unused variable warning for targets */
             /* where the GEMM unrolling parameters do not depend on l2 */

#ifdef BUILD_BFLOAT16
  openblas_paramsTS.sbgemm_p = SBGEMM_DEFAULT_P;
  openblas_paramsTS.sbgemm_q = SBGEMM_DEFAULT_Q;
  openblas_paramsTS.bgemm_p = BGEMM_DEFAULT_P;
  openblas_paramsTS.bgemm_q = BGEMM_DEFAULT_Q;
#endif
#ifdef BUILD_HFLOAT16
  openblas_paramsTS.shgemm_p = SHGEMM_DEFAULT_P;
  openblas_paramsTS.shgemm_q = SHGEMM_DEFAULT_Q;
#endif
#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_q = SGEMM_DEFAULT_Q;
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16)
  openblas_paramsTS.dgemm_q = DGEMM_DEFAULT_Q;
#endif
#if BUILD_COMPLEX == 1
  openblas_paramsTS.cgemm_q = CGEMM_DEFAULT_Q;
#endif
#if BUILD_COMPLEX16==1
  openblas_paramsTS.zgemm_q = ZGEMM_DEFAULT_Q;
#endif

#if BUILD_COMPLEX == 1
#ifdef CGEMM3M_DEFAULT_Q
  openblas_paramsTS.cgemm3m_q = CGEMM3M_DEFAULT_Q;
#else
  openblas_paramsTS.cgemm3m_q = SGEMM_DEFAULT_Q;
#endif
#endif

#if BUILD_COMPLEX16 == 1
#ifdef ZGEMM3M_DEFAULT_Q
  openblas_paramsTS.zgemm3m_q = ZGEMM3M_DEFAULT_Q;
#else
  openblas_paramsTS.zgemm3m_q = DGEMM_DEFAULT_Q;
#endif
#endif

#ifdef EXPRECISION
  openblas_paramsTS.qgemm_q = QGEMM_DEFAULT_Q;
  openblas_paramsTS.xgemm_q = XGEMM_DEFAULT_Q;
  openblas_paramsTS.xgemm3m_q = QGEMM_DEFAULT_Q;
#endif

#if defined(CORE_KATMAI)  || defined(CORE_COPPERMINE) || defined(CORE_BANIAS) || defined(CORE_YONAH) || defined(CORE_ATHLON)

#ifdef DEBUG
  fprintf(stderr, "Katmai, Coppermine, Banias, Athlon\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p =  64 * (l2 >> 7);
#endif
#if BUILD_DOUBLE == 1 || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p =  32 * (l2 >> 7);
#endif
#if BUILD_COMPLEX==1
  openblas_paramsTS.cgemm_p =  32 * (l2 >> 7);
#endif
#if BUILD_COMPLEX16==1
  openblas_paramsTS.zgemm_p =  16 * (l2 >> 7);
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p =  16 * (l2 >> 7);
  openblas_paramsTS.xgemm_p =   8 * (l2 >> 7);
#endif
#endif

#ifdef CORE_NORTHWOOD

#ifdef DEBUG
  fprintf(stderr, "Northwood\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p =  96 * (l2 >> 7);
#endif
#if BUILD_DOUBLE == 1 || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p =  48 * (l2 >> 7);
#endif
#if BUILD_COMPLEX==1
  openblas_paramsTS.cgemm_p =  48 * (l2 >> 7);
#endif
#if BUILD_COMPLEX16==1
  openblas_paramsTS.zgemm_p =  24 * (l2 >> 7);
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p =  24 * (l2 >> 7);
  openblas_paramsTS.xgemm_p =  12 * (l2 >> 7);
#endif
#endif

#ifdef ATOM

#ifdef DEBUG
  fprintf(stderr, "Atom\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = 256;
#endif
#if BUILD_DOUBLE ==1 || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = 128;
#endif
#if BUILD_COMPLEX==1
  openblas_paramsTS.cgemm_p = 128;
#endif
#if BUILD_COMPLEX16==1
  openblas_paramsTS.zgemm_p =  64;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p =  64;
  openblas_paramsTS.xgemm_p =  32;
#endif
#endif

#ifdef CORE_PRESCOTT

#ifdef DEBUG
  fprintf(stderr, "Prescott\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p =  56 * (l2 >> 7);
#endif
#if BUILD_DOUBLE ==1  || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p =  28 * (l2 >> 7);
#endif
#if BUILD_COMPLEX==1
  openblas_paramsTS.cgemm_p =  28 * (l2 >> 7);
#endif
#if BUILD_COMPLEX16 == 1
  openblas_paramsTS.zgemm_p =  14 * (l2 >> 7);
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p =  14 * (l2 >> 7);
  openblas_paramsTS.xgemm_p =   7 * (l2 >> 7);
#endif
#endif

#ifdef CORE2

#ifdef DEBUG
  fprintf(stderr, "Core2\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p =  92 * (l2 >> 9) + 8;
#endif
#if BUILD_DOUBLE==1 || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p =  46 * (l2 >> 9) + 8;
#endif
#if BUILD_COMPLEX==1
  openblas_paramsTS.cgemm_p =  46 * (l2 >> 9) + 4;
#endif
#if BUILD_COMPLEX16==1
  openblas_paramsTS.zgemm_p =  23 * (l2 >> 9) + 4;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p =  92 * (l2 >> 9) + 8;
  openblas_paramsTS.xgemm_p =  46 * (l2 >> 9) + 4;
#endif
#endif

#ifdef PENRYN

#ifdef DEBUG
  fprintf(stderr, "Penryn\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p =  42 * (l2 >> 9) + 8;
#endif
#if BUILD_DOUBLE == 1 || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p =  42 * (l2 >> 9) + 8;
#endif
#if BUILD_COMPLEX==1
  openblas_paramsTS.cgemm_p =  21 * (l2 >> 9) + 4;
#endif
#if BUILD_COMPLEX16==1
  openblas_paramsTS.zgemm_p =  21 * (l2 >> 9) + 4;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p =  42 * (l2 >> 9) + 8;
  openblas_paramsTS.xgemm_p =  21 * (l2 >> 9) + 4;
#endif
#endif

#ifdef DUNNINGTON

#ifdef DEBUG
  fprintf(stderr, "Dunnington\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p =  42 * (l2 >> 9) + 8;
#endif
#if BUILD_DOUBLE ==1 || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p =  42 * (l2 >> 9) + 8;
#endif
#if BUILD_COMPLEX==1
  openblas_paramsTS.cgemm_p =  21 * (l2 >> 9) + 4;
#endif
#if BUILD_COMPLEX16==1
  openblas_paramsTS.zgemm_p =  21 * (l2 >> 9) + 4;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p =  42 * (l2 >> 9) + 8;
  openblas_paramsTS.xgemm_p =  21 * (l2 >> 9) + 4;
#endif
#endif


#ifdef NEHALEM

#ifdef DEBUG
  fprintf(stderr, "Nehalem\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef SANDYBRIDGE

#ifdef DEBUG
  fprintf(stderr, "Sandybridge\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef HASWELL

#ifdef DEBUG
  fprintf(stderr, "Haswell\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#if defined(SKYLAKEX) || defined(COOPERLAKE) || defined(SAPPHIRERAPIDS)

#ifdef DEBUG
  fprintf(stderr, "SkylakeX\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif


#ifdef OPTERON

#ifdef DEBUG
  fprintf(stderr, "Opteron\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = 224 +  56 * (l2 >> 7);
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = 112 +  28 * (l2 >> 7);
#endif
#if BUILD_COMPLEX
  openblas_paramsTS.cgemm_p = 112 +  28 * (l2 >> 7);
#endif
#if BUILD_COMPLEX16
  openblas_paramsTS.zgemm_p =  56 +  14 * (l2 >> 7);
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p =  56 +  14 * (l2 >> 7);
  openblas_paramsTS.xgemm_p =  28 +   7 * (l2 >> 7);
#endif
#endif

#ifdef BARCELONA

#ifdef DEBUG
  fprintf(stderr, "Barcelona\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef BOBCAT

#ifdef DEBUG
  fprintf(stderr, "Bobcate\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef BULLDOZER

#ifdef DEBUG
  fprintf(stderr, "Bulldozer\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef EXCAVATOR

#ifdef DEBUG
  fprintf(stderr, "Excavator\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif


#ifdef PILEDRIVER

#ifdef DEBUG
  fprintf(stderr, "Piledriver\n");
#endif

#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef STEAMROLLER

#ifdef DEBUG
  fprintf(stderr, "Steamroller\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef ZEN

#ifdef DEBUG
  fprintf(stderr, "Zen\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif


#ifdef NANO

#ifdef DEBUG
  fprintf(stderr, "NANO\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  openblas_paramsTS.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  openblas_paramsTS.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if (BUILD_COMPLEX==1)
  openblas_paramsTS.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if (BUILD_COMPLEX16==1)
  openblas_paramsTS.zgemm_p = ZGEMM_DEFAULT_P;
#endif


#ifdef EXPRECISION
  openblas_paramsTS.qgemm_p = QGEMM_DEFAULT_P;
  openblas_paramsTS.xgemm_p = XGEMM_DEFAULT_P;
#endif

#endif

#ifdef SAPPHIRERAPIDS
#if (BUILD_BFLOAT16 == 1)
  openblas_paramsTS.need_amxtile_permission = 1;
#endif
#endif

#if BUILD_COMPLEX==1
#ifdef CGEMM3M_DEFAULT_P
  openblas_paramsTS.cgemm3m_p = CGEMM3M_DEFAULT_P;
#else
  openblas_paramsTS.cgemm3m_p = openblas_paramsTS.sgemm_p;
#endif
#endif

#if BUILD_COMPLEX16==1
#ifdef ZGEMM3M_DEFAULT_P
  openblas_paramsTS.zgemm3m_p = ZGEMM3M_DEFAULT_P;
#else
  openblas_paramsTS.zgemm3m_p = openblas_paramsTS.dgemm_p;
#endif
#endif

#ifdef EXPRECISION
  openblas_paramsTS.xgemm3m_p = openblas_paramsTS.qgemm_p;
#endif

{
    int l3_kb = get_l3_size();
    int l2_kb = get_l2_size();
    unsigned int eax, ebx, ecx, edx;
    unsigned int cpuid7_eax, cpuid7_ebx, cpuid7_ecx, cpuid7_edx;

    cpuid(0, &eax, &ebx, &ecx, &edx);

    if ((ebx == 0x68747541) && (l3_kb > 0) && (l3_kb % 32768 == 0) && (l2_kb == 1024)) { //Auth AMD
        
        cpuid(7, &cpuid7_eax, &cpuid7_ebx, &cpuid7_ecx, &cpuid7_edx);
        
        if (cpuid7_ebx & (1 << 16)) { // avx512 - Zen 4, 5
#if BUILD_SINGLE == 1
            openblas_paramsTS.sgemm_p = 384;
            openblas_paramsTS.sgemm_q = 512;
#endif
#if BUILD_DOUBLE == 1
            openblas_paramsTS.dgemm_p = 512;
            openblas_paramsTS.dgemm_q = 512;
#endif
#if BUILD_COMPLEX == 1
            openblas_paramsTS.cgemm_p = 160;
            openblas_paramsTS.cgemm_q = 480;
#endif
#if BUILD_COMPLEX16 == 1
            openblas_paramsTS.zgemm_p = 176;
            openblas_paramsTS.zgemm_q = 256;
#endif
        }
    }
}

#if BUILD_SINGLE == 1
  openblas_paramsTS.sgemm_p = ((openblas_paramsTS.sgemm_p + SGEMM_DEFAULT_UNROLL_M - 1)/SGEMM_DEFAULT_UNROLL_M) * SGEMM_DEFAULT_UNROLL_M;
#endif
#if BUILD_DOUBLE== 1
  openblas_paramsTS.dgemm_p = ((openblas_paramsTS.dgemm_p + DGEMM_DEFAULT_UNROLL_M - 1)/DGEMM_DEFAULT_UNROLL_M) * DGEMM_DEFAULT_UNROLL_M;
#endif
#if BUILD_COMPLEX==1
  openblas_paramsTS.cgemm_p = ((openblas_paramsTS.cgemm_p + CGEMM_DEFAULT_UNROLL_M - 1)/CGEMM_DEFAULT_UNROLL_M) * CGEMM_DEFAULT_UNROLL_M;
#endif
#if BUILD_COMPLEX16==1
  openblas_paramsTS.zgemm_p = ((openblas_paramsTS.zgemm_p + ZGEMM_DEFAULT_UNROLL_M - 1)/ZGEMM_DEFAULT_UNROLL_M) * ZGEMM_DEFAULT_UNROLL_M;
#endif

#if BUILD_COMPLEX==1
#ifdef CGEMM3M_DEFAULT_UNROLL_M
  openblas_paramsTS.cgemm3m_p = ((openblas_paramsTS.cgemm3m_p + CGEMM3M_DEFAULT_UNROLL_M - 1)/CGEMM3M_DEFAULT_UNROLL_M) * CGEMM3M_DEFAULT_UNROLL_M;
#else
  openblas_paramsTS.cgemm3m_p = ((openblas_paramsTS.cgemm3m_p + SGEMM_DEFAULT_UNROLL_M - 1)/SGEMM_DEFAULT_UNROLL_M) * SGEMM_DEFAULT_UNROLL_M;
#endif
#endif

#if BUILD_COMPLEX16==1
#ifdef ZGEMM3M_DEFAULT_UNROLL_M
  openblas_paramsTS.zgemm3m_p = ((openblas_paramsTS.zgemm3m_p + ZGEMM3M_DEFAULT_UNROLL_M - 1)/ZGEMM3M_DEFAULT_UNROLL_M) * ZGEMM3M_DEFAULT_UNROLL_M;
#else
  openblas_paramsTS.zgemm3m_p = ((openblas_paramsTS.zgemm3m_p + DGEMM_DEFAULT_UNROLL_M - 1)/DGEMM_DEFAULT_UNROLL_M) * DGEMM_DEFAULT_UNROLL_M;
#endif
#endif

#ifdef QUAD_PRECISION
  openblas_paramsTS.qgemm_p = ((openblas_paramsTS.qgemm_p + QGEMM_DEFAULT_UNROLL_M - 1)/QGEMM_DEFAULT_UNROLL_M) * QGEMM_DEFAULT_UNROLL_M;
  openblas_paramsTS.xgemm_p = ((openblas_paramsTS.xgemm_p + XGEMM_DEFAULT_UNROLL_M - 1)/XGEMM_DEFAULT_UNROLL_M) * XGEMM_DEFAULT_UNROLL_M;
  openblas_paramsTS.xgemm3m_p = ((openblas_paramsTS.xgemm3m_p + QGEMM_DEFAULT_UNROLL_M - 1)/QGEMM_DEFAULT_UNROLL_M) * QGEMM_DEFAULT_UNROLL_M;
#endif

#ifdef DEBUG
  fprintf(stderr, "L2 = %8d DGEMM_P  .. %d\n", l2, openblas_paramsTS.dgemm_p);
#endif

#if BUILD_BFLOAT16==1
  openblas_paramsTS.sbgemm_r = (((BUFFER_SIZE -
			       ((openblas_paramsTS.sbgemm_p * openblas_paramsTS.sbgemm_q *  4 + openblas_paramsTS.offsetA
				 + openblas_paramsTS.align) & ~openblas_paramsTS.align)
			       ) / (openblas_paramsTS.sbgemm_q *  4) - 15) & ~15);
  openblas_paramsTS.bgemm_r = (((BUFFER_SIZE -
			       ((openblas_paramsTS.bgemm_p * openblas_paramsTS.bgemm_q *  4 + openblas_paramsTS.offsetA
				 + openblas_paramsTS.align) & ~openblas_paramsTS.align)
			       ) / (openblas_paramsTS.bgemm_q *  4) - 15) & ~15);
#endif

#if BUILD_HFLOAT16==1
  openblas_paramsTS.shgemm_r = (((BUFFER_SIZE -
			       ((openblas_paramsTS.shgemm_p * openblas_paramsTS.shgemm_q *  4 + openblas_paramsTS.offsetA
				 + openblas_paramsTS.align) & ~openblas_paramsTS.align)
			       ) / (openblas_paramsTS.shgemm_q *  4) - 15) & ~15);
#endif

#if BUILD_SINGLE==1
  openblas_paramsTS.sgemm_r = (((BUFFER_SIZE -
			       ((openblas_paramsTS.sgemm_p * openblas_paramsTS.sgemm_q *  4 + openblas_paramsTS.offsetA
				 + openblas_paramsTS.align) & ~openblas_paramsTS.align)
			       ) / (openblas_paramsTS.sgemm_q *  4) - 15) & ~15);
#endif

#if BUILD_DOUBLE==1
  openblas_paramsTS.dgemm_r = (((BUFFER_SIZE -
			       ((openblas_paramsTS.dgemm_p * openblas_paramsTS.dgemm_q *  8 + openblas_paramsTS.offsetA
				 + openblas_paramsTS.align) & ~openblas_paramsTS.align)
			       ) / (openblas_paramsTS.dgemm_q *  8) - 15) & ~15);
#endif

#ifdef EXPRECISION
  openblas_paramsTS.qgemm_r = (((BUFFER_SIZE -
			       ((openblas_paramsTS.qgemm_p * openblas_paramsTS.qgemm_q * 16 + openblas_paramsTS.offsetA
				 + openblas_paramsTS.align) & ~openblas_paramsTS.align)
			       ) / (openblas_paramsTS.qgemm_q * 16) - 15) & ~15);
#endif

#if BUILD_COMPLEX ==1
  openblas_paramsTS.cgemm_r = (((BUFFER_SIZE -
			       ((openblas_paramsTS.cgemm_p * openblas_paramsTS.cgemm_q *  8 + openblas_paramsTS.offsetA
				 + openblas_paramsTS.align) & ~openblas_paramsTS.align)
			       ) / (openblas_paramsTS.cgemm_q *  8) - 15) & ~15);
#endif

#if BUILD_COMPLEX16 ==1
  openblas_paramsTS.zgemm_r = (((BUFFER_SIZE -
			       ((openblas_paramsTS.zgemm_p * openblas_paramsTS.zgemm_q * 16 + openblas_paramsTS.offsetA
				 + openblas_paramsTS.align) & ~openblas_paramsTS.align)
			       ) / (openblas_paramsTS.zgemm_q * 16) - 15) & ~15);
#endif

#if BUILD_COMPLEX == 1
  openblas_paramsTS.cgemm3m_r = (((BUFFER_SIZE -
			       ((openblas_paramsTS.cgemm3m_p * openblas_paramsTS.cgemm3m_q *  8 + openblas_paramsTS.offsetA
				 + openblas_paramsTS.align) & ~openblas_paramsTS.align)
			       ) / (openblas_paramsTS.cgemm3m_q *  8) - 15) & ~15);
#endif

#if BUILD_COMPLEX16 == 1
  openblas_paramsTS.zgemm3m_r = (((BUFFER_SIZE -
			       ((openblas_paramsTS.zgemm3m_p * openblas_paramsTS.zgemm3m_q * 16 + openblas_paramsTS.offsetA
				 + openblas_paramsTS.align) & ~openblas_paramsTS.align)
			       ) / (openblas_paramsTS.zgemm3m_q * 16) - 15) & ~15);
#endif



#ifdef EXPRECISION
  openblas_paramsTS.xgemm_r = (((BUFFER_SIZE -
			       ((openblas_paramsTS.xgemm_p * openblas_paramsTS.xgemm_q * 32 + openblas_paramsTS.offsetA
				 + openblas_paramsTS.align) & ~openblas_paramsTS.align)
		       ) / (openblas_paramsTS.xgemm_q * 32) - 15) & ~15);

  openblas_paramsTS.xgemm3m_r = (((BUFFER_SIZE -
			       ((openblas_paramsTS.xgemm3m_p * openblas_paramsTS.xgemm3m_q * 32 + openblas_paramsTS.offsetA
				 + openblas_paramsTS.align) & ~openblas_paramsTS.align)
		       ) / (openblas_paramsTS.xgemm3m_q * 32) - 15) & ~15);

#endif



}
#endif //RISCV64
#endif //POWER
#endif //ZARCH
#endif //(ARCH_LOONGARCH64)
#endif //(ARCH_MIPS64)
#endif //(ARCH_ARM64)
