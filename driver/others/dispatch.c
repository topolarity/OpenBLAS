/* GENERATED - per-group core dispatch arrays.
 *
 * One array per kernel group, each in its own section (-fdata-sections), so
 * --gc-sections drops the groups a program never calls and, with them, every
 * kernel reachable only through those groups.
 */

#include "common.h"

#define DECL(C) extern openblas_params_t openblas_params_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_params_##C,
openblas_params_t *const openblas_params_tab[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF

#if BUILD_HFLOAT16 == 1
#define DECL(C) extern const openblas_shgemm_dispatch_t openblas_shgemm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_shgemm_dispatch_##C,
const openblas_shgemm_dispatch_t *const openblas_shgemm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_HFLOAT16 == 1
#define DECL(C) extern const openblas_shgemv_dispatch_t openblas_shgemv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_shgemv_dispatch_##C,
const openblas_shgemv_dispatch_t *const openblas_shgemv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbstobf16_dispatch_t openblas_sbstobf16_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbstobf16_dispatch_##C,
const openblas_sbstobf16_dispatch_t *const openblas_sbstobf16_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbdtobf16_dispatch_t openblas_sbdtobf16_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbdtobf16_dispatch_##C,
const openblas_sbdtobf16_dispatch_t *const openblas_sbdtobf16_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbf16tos_dispatch_t openblas_sbf16tos_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbf16tos_dispatch_##C,
const openblas_sbf16tos_dispatch_t *const openblas_sbf16tos_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_dbf16tod_dispatch_t openblas_dbf16tod_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dbf16tod_dispatch_##C,
const openblas_dbf16tod_dispatch_t *const openblas_dbf16tod_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbamax_dispatch_t openblas_sbamax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbamax_dispatch_##C,
const openblas_sbamax_dispatch_t *const openblas_sbamax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbamin_dispatch_t openblas_sbamin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbamin_dispatch_##C,
const openblas_sbamin_dispatch_t *const openblas_sbamin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbmax_dispatch_t openblas_sbmax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbmax_dispatch_##C,
const openblas_sbmax_dispatch_t *const openblas_sbmax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbmin_dispatch_t openblas_sbmin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbmin_dispatch_##C,
const openblas_sbmin_dispatch_t *const openblas_sbmin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_isbamax_dispatch_t openblas_isbamax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_isbamax_dispatch_##C,
const openblas_isbamax_dispatch_t *const openblas_isbamax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_isbamin_dispatch_t openblas_isbamin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_isbamin_dispatch_##C,
const openblas_isbamin_dispatch_t *const openblas_isbamin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_isbmax_dispatch_t openblas_isbmax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_isbmax_dispatch_##C,
const openblas_isbmax_dispatch_t *const openblas_isbmax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_isbmin_dispatch_t openblas_isbmin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_isbmin_dispatch_##C,
const openblas_isbmin_dispatch_t *const openblas_isbmin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbnrm2_dispatch_t openblas_sbnrm2_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbnrm2_dispatch_##C,
const openblas_sbnrm2_dispatch_t *const openblas_sbnrm2_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbasum_dispatch_t openblas_sbasum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbasum_dispatch_##C,
const openblas_sbasum_dispatch_t *const openblas_sbasum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbsum_dispatch_t openblas_sbsum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbsum_dispatch_##C,
const openblas_sbsum_dispatch_t *const openblas_sbsum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbcopy_dispatch_t openblas_sbcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbcopy_dispatch_##C,
const openblas_sbcopy_dispatch_t *const openblas_sbcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbdot_dispatch_t openblas_sbdot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbdot_dispatch_##C,
const openblas_sbdot_dispatch_t *const openblas_sbdot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_dsbdot_dispatch_t openblas_dsbdot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dsbdot_dispatch_##C,
const openblas_dsbdot_dispatch_t *const openblas_dsbdot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbrot_dispatch_t openblas_sbrot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbrot_dispatch_##C,
const openblas_sbrot_dispatch_t *const openblas_sbrot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbrotm_dispatch_t openblas_sbrotm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbrotm_dispatch_##C,
const openblas_sbrotm_dispatch_t *const openblas_sbrotm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_bscal_dispatch_t openblas_bscal_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_bscal_dispatch_##C,
const openblas_bscal_dispatch_t *const openblas_bscal_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbaxpy_dispatch_t openblas_sbaxpy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbaxpy_dispatch_##C,
const openblas_sbaxpy_dispatch_t *const openblas_sbaxpy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbscal_dispatch_t openblas_sbscal_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbscal_dispatch_##C,
const openblas_sbscal_dispatch_t *const openblas_sbscal_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbswap_dispatch_t openblas_sbswap_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbswap_dispatch_##C,
const openblas_sbswap_dispatch_t *const openblas_sbswap_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_bgemv_dispatch_t openblas_bgemv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_bgemv_dispatch_##C,
const openblas_bgemv_dispatch_t *const openblas_bgemv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbgemv_dispatch_t openblas_sbgemv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbgemv_dispatch_##C,
const openblas_sbgemv_dispatch_t *const openblas_sbgemv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbger_dispatch_t openblas_sbger_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbger_dispatch_##C,
const openblas_sbger_dispatch_t *const openblas_sbger_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbsymv_dispatch_t openblas_sbsymv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbsymv_dispatch_##C,
const openblas_sbsymv_dispatch_t *const openblas_sbsymv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_bgemm_dispatch_t openblas_bgemm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_bgemm_dispatch_##C,
const openblas_bgemm_dispatch_t *const openblas_bgemm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbgemm_dispatch_t openblas_sbgemm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbgemm_dispatch_##C,
const openblas_sbgemm_dispatch_t *const openblas_sbgemm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbtrsm_dispatch_t openblas_sbtrsm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbtrsm_dispatch_##C,
const openblas_sbtrsm_dispatch_t *const openblas_sbtrsm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbtrmm_dispatch_t openblas_sbtrmm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbtrmm_dispatch_##C,
const openblas_sbtrmm_dispatch_t *const openblas_sbtrmm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbsymm_dispatch_t openblas_sbsymm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbsymm_dispatch_##C,
const openblas_sbsymm_dispatch_t *const openblas_sbsymm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sbneg_dispatch_t openblas_sbneg_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sbneg_dispatch_##C,
const openblas_sbneg_dispatch_t *const openblas_sbneg_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if BUILD_BFLOAT16 == 1
#define DECL(C) extern const openblas_sblaswp_dispatch_t openblas_sblaswp_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sblaswp_dispatch_##C,
const openblas_sblaswp_dispatch_t *const openblas_sblaswp_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE == 1) || (BUILD_COMPLEX == 1)
#define DECL(C) extern const openblas_samax_dispatch_t openblas_samax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_samax_dispatch_##C,
const openblas_samax_dispatch_t *const openblas_samax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE == 1) || (BUILD_COMPLEX == 1)
#define DECL(C) extern const openblas_samin_dispatch_t openblas_samin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_samin_dispatch_##C,
const openblas_samin_dispatch_t *const openblas_samin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE == 1) || (BUILD_COMPLEX == 1)
#define DECL(C) extern const openblas_smax_dispatch_t openblas_smax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_smax_dispatch_##C,
const openblas_smax_dispatch_t *const openblas_smax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE == 1) || (BUILD_COMPLEX == 1)
#define DECL(C) extern const openblas_smin_dispatch_t openblas_smin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_smin_dispatch_##C,
const openblas_smin_dispatch_t *const openblas_smin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE ==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_isamax_dispatch_t openblas_isamax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_isamax_dispatch_##C,
const openblas_isamax_dispatch_t *const openblas_isamax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_isamin_dispatch_t openblas_isamin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_isamin_dispatch_##C,
const openblas_isamin_dispatch_t *const openblas_isamin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_ismax_dispatch_t openblas_ismax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ismax_dispatch_##C,
const openblas_ismax_dispatch_t *const openblas_ismax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_ismin_dispatch_t openblas_ismin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ismin_dispatch_##C,
const openblas_ismin_dispatch_t *const openblas_ismin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_snrm2_dispatch_t openblas_snrm2_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_snrm2_dispatch_##C,
const openblas_snrm2_dispatch_t *const openblas_snrm2_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_sasum_dispatch_t openblas_sasum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sasum_dispatch_##C,
const openblas_sasum_dispatch_t *const openblas_sasum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1)
#define DECL(C) extern const openblas_ssum_dispatch_t openblas_ssum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ssum_dispatch_##C,
const openblas_ssum_dispatch_t *const openblas_ssum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_scopy_dispatch_t openblas_scopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_scopy_dispatch_##C,
const openblas_scopy_dispatch_t *const openblas_scopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_sdot_dispatch_t openblas_sdot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sdot_dispatch_##C,
const openblas_sdot_dispatch_t *const openblas_sdot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_srot_dispatch_t openblas_srot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_srot_dispatch_##C,
const openblas_srot_dispatch_t *const openblas_srot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_srotm_dispatch_t openblas_srotm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_srotm_dispatch_##C,
const openblas_srotm_dispatch_t *const openblas_srotm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_saxpy_dispatch_t openblas_saxpy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_saxpy_dispatch_##C,
const openblas_saxpy_dispatch_t *const openblas_saxpy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_sscal_dispatch_t openblas_sscal_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sscal_dispatch_##C,
const openblas_sscal_dispatch_t *const openblas_sscal_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_sswap_dispatch_t openblas_sswap_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sswap_dispatch_##C,
const openblas_sswap_dispatch_t *const openblas_sswap_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_sgemv_dispatch_t openblas_sgemv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sgemv_dispatch_##C,
const openblas_sgemv_dispatch_t *const openblas_sgemv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1)
#define DECL(C) extern const openblas_sger_dispatch_t openblas_sger_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sger_dispatch_##C,
const openblas_sger_dispatch_t *const openblas_sger_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1)
#define DECL(C) extern const openblas_ssymv_dispatch_t openblas_ssymv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ssymv_dispatch_##C,
const openblas_ssymv_dispatch_t *const openblas_ssymv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#define DECL(C) extern const openblas_sgemm_dispatch_t openblas_sgemm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sgemm_dispatch_##C,
const openblas_sgemm_dispatch_t *const openblas_sgemm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF

#define DECL(C) extern const openblas_ssymm_dispatch_t openblas_ssymm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ssymm_dispatch_##C,
const openblas_ssymm_dispatch_t *const openblas_ssymm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF

#define DECL(C) extern const openblas_strmm_dispatch_t openblas_strmm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_strmm_dispatch_##C,
const openblas_strmm_dispatch_t *const openblas_strmm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_ARM64
#define DECL(C) extern const openblas_ssyrk_dispatch_t openblas_ssyrk_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ssyrk_dispatch_##C,
const openblas_ssyrk_dispatch_t *const openblas_ssyrk_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_ARM64
#define DECL(C) extern const openblas_ssyr2k_dispatch_t openblas_ssyr2k_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ssyr2k_dispatch_##C,
const openblas_ssyr2k_dispatch_t *const openblas_ssyr2k_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_strsm_dispatch_t openblas_strsm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_strsm_dispatch_##C,
const openblas_strsm_dispatch_t *const openblas_strsm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1)
#define DECL(C) extern const openblas_sneg_dispatch_t openblas_sneg_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sneg_dispatch_##C,
const openblas_sneg_dispatch_t *const openblas_sneg_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1)
#define DECL(C) extern const openblas_slaswp_dispatch_t openblas_slaswp_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_slaswp_dispatch_##C,
const openblas_slaswp_dispatch_t *const openblas_slaswp_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_damax_dispatch_t openblas_damax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_damax_dispatch_##C,
const openblas_damax_dispatch_t *const openblas_damax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_damin_dispatch_t openblas_damin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_damin_dispatch_##C,
const openblas_damin_dispatch_t *const openblas_damin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_dmax_dispatch_t openblas_dmax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dmax_dispatch_##C,
const openblas_dmax_dispatch_t *const openblas_dmax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_dmin_dispatch_t openblas_dmin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dmin_dispatch_##C,
const openblas_dmin_dispatch_t *const openblas_dmin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_idamax_dispatch_t openblas_idamax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_idamax_dispatch_##C,
const openblas_idamax_dispatch_t *const openblas_idamax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_idamin_dispatch_t openblas_idamin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_idamin_dispatch_##C,
const openblas_idamin_dispatch_t *const openblas_idamin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_idmax_dispatch_t openblas_idmax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_idmax_dispatch_##C,
const openblas_idmax_dispatch_t *const openblas_idmax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_idmin_dispatch_t openblas_idmin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_idmin_dispatch_##C,
const openblas_idmin_dispatch_t *const openblas_idmin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_dnrm2_dispatch_t openblas_dnrm2_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dnrm2_dispatch_##C,
const openblas_dnrm2_dispatch_t *const openblas_dnrm2_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_dasum_dispatch_t openblas_dasum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dasum_dispatch_##C,
const openblas_dasum_dispatch_t *const openblas_dasum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_dsum_dispatch_t openblas_dsum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dsum_dispatch_##C,
const openblas_dsum_dispatch_t *const openblas_dsum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_dcopy_dispatch_t openblas_dcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dcopy_dispatch_##C,
const openblas_dcopy_dispatch_t *const openblas_dcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_ddot_dispatch_t openblas_ddot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ddot_dispatch_##C,
const openblas_ddot_dispatch_t *const openblas_ddot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_dsdot_dispatch_t openblas_dsdot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dsdot_dispatch_##C,
const openblas_dsdot_dispatch_t *const openblas_dsdot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_drot_dispatch_t openblas_drot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_drot_dispatch_##C,
const openblas_drot_dispatch_t *const openblas_drot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_drotm_dispatch_t openblas_drotm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_drotm_dispatch_##C,
const openblas_drotm_dispatch_t *const openblas_drotm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_daxpy_dispatch_t openblas_daxpy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_daxpy_dispatch_##C,
const openblas_daxpy_dispatch_t *const openblas_daxpy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_dscal_dispatch_t openblas_dscal_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dscal_dispatch_##C,
const openblas_dscal_dispatch_t *const openblas_dscal_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_dswap_dispatch_t openblas_dswap_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dswap_dispatch_##C,
const openblas_dswap_dispatch_t *const openblas_dswap_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_dgemv_dispatch_t openblas_dgemv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dgemv_dispatch_##C,
const openblas_dgemv_dispatch_t *const openblas_dgemv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_dger_dispatch_t openblas_dger_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dger_dispatch_##C,
const openblas_dger_dispatch_t *const openblas_dger_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_dsymv_dispatch_t openblas_dsymv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dsymv_dispatch_##C,
const openblas_dsymv_dispatch_t *const openblas_dsymv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#define DECL(C) extern const openblas_dgemm_dispatch_t openblas_dgemm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dgemm_dispatch_##C,
const openblas_dgemm_dispatch_t *const openblas_dgemm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF

#if (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_dtrsm_dispatch_t openblas_dtrsm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dtrsm_dispatch_##C,
const openblas_dtrsm_dispatch_t *const openblas_dtrsm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_dtrmm_dispatch_t openblas_dtrmm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dtrmm_dispatch_##C,
const openblas_dtrmm_dispatch_t *const openblas_dtrmm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_dsymm_dispatch_t openblas_dsymm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dsymm_dispatch_##C,
const openblas_dsymm_dispatch_t *const openblas_dsymm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_dneg_dispatch_t openblas_dneg_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dneg_dispatch_##C,
const openblas_dneg_dispatch_t *const openblas_dneg_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_dlaswp_dispatch_t openblas_dlaswp_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dlaswp_dispatch_##C,
const openblas_dlaswp_dispatch_t *const openblas_dlaswp_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qamax_dispatch_t openblas_qamax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qamax_dispatch_##C,
const openblas_qamax_dispatch_t *const openblas_qamax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qamin_dispatch_t openblas_qamin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qamin_dispatch_##C,
const openblas_qamin_dispatch_t *const openblas_qamin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qmax_dispatch_t openblas_qmax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qmax_dispatch_##C,
const openblas_qmax_dispatch_t *const openblas_qmax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qmin_dispatch_t openblas_qmin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qmin_dispatch_##C,
const openblas_qmin_dispatch_t *const openblas_qmin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_iqamax_dispatch_t openblas_iqamax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_iqamax_dispatch_##C,
const openblas_iqamax_dispatch_t *const openblas_iqamax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_iqamin_dispatch_t openblas_iqamin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_iqamin_dispatch_##C,
const openblas_iqamin_dispatch_t *const openblas_iqamin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_iqmax_dispatch_t openblas_iqmax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_iqmax_dispatch_##C,
const openblas_iqmax_dispatch_t *const openblas_iqmax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_iqmin_dispatch_t openblas_iqmin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_iqmin_dispatch_##C,
const openblas_iqmin_dispatch_t *const openblas_iqmin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qnrm2_dispatch_t openblas_qnrm2_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qnrm2_dispatch_##C,
const openblas_qnrm2_dispatch_t *const openblas_qnrm2_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qasum_dispatch_t openblas_qasum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qasum_dispatch_##C,
const openblas_qasum_dispatch_t *const openblas_qasum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qsum_dispatch_t openblas_qsum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qsum_dispatch_##C,
const openblas_qsum_dispatch_t *const openblas_qsum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qcopy_dispatch_t openblas_qcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qcopy_dispatch_##C,
const openblas_qcopy_dispatch_t *const openblas_qcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qdot_dispatch_t openblas_qdot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qdot_dispatch_##C,
const openblas_qdot_dispatch_t *const openblas_qdot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qrot_dispatch_t openblas_qrot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qrot_dispatch_##C,
const openblas_qrot_dispatch_t *const openblas_qrot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qrotm_dispatch_t openblas_qrotm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qrotm_dispatch_##C,
const openblas_qrotm_dispatch_t *const openblas_qrotm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qaxpy_dispatch_t openblas_qaxpy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qaxpy_dispatch_##C,
const openblas_qaxpy_dispatch_t *const openblas_qaxpy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qscal_dispatch_t openblas_qscal_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qscal_dispatch_##C,
const openblas_qscal_dispatch_t *const openblas_qscal_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qswap_dispatch_t openblas_qswap_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qswap_dispatch_##C,
const openblas_qswap_dispatch_t *const openblas_qswap_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qgemv_dispatch_t openblas_qgemv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qgemv_dispatch_##C,
const openblas_qgemv_dispatch_t *const openblas_qgemv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qger_dispatch_t openblas_qger_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qger_dispatch_##C,
const openblas_qger_dispatch_t *const openblas_qger_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qsymv_dispatch_t openblas_qsymv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qsymv_dispatch_##C,
const openblas_qsymv_dispatch_t *const openblas_qsymv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qgemm_dispatch_t openblas_qgemm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qgemm_dispatch_##C,
const openblas_qgemm_dispatch_t *const openblas_qgemm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qtrsm_dispatch_t openblas_qtrsm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qtrsm_dispatch_##C,
const openblas_qtrsm_dispatch_t *const openblas_qtrsm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qtrmm_dispatch_t openblas_qtrmm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qtrmm_dispatch_##C,
const openblas_qtrmm_dispatch_t *const openblas_qtrmm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qsymm_dispatch_t openblas_qsymm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qsymm_dispatch_##C,
const openblas_qsymm_dispatch_t *const openblas_qsymm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qneg_dispatch_t openblas_qneg_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qneg_dispatch_##C,
const openblas_qneg_dispatch_t *const openblas_qneg_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_qlaswp_dispatch_t openblas_qlaswp_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_qlaswp_dispatch_##C,
const openblas_qlaswp_dispatch_t *const openblas_qlaswp_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_camax_dispatch_t openblas_camax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_camax_dispatch_##C,
const openblas_camax_dispatch_t *const openblas_camax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_camin_dispatch_t openblas_camin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_camin_dispatch_##C,
const openblas_camin_dispatch_t *const openblas_camin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_icamax_dispatch_t openblas_icamax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_icamax_dispatch_##C,
const openblas_icamax_dispatch_t *const openblas_icamax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_icamin_dispatch_t openblas_icamin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_icamin_dispatch_##C,
const openblas_icamin_dispatch_t *const openblas_icamin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cnrm2_dispatch_t openblas_cnrm2_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cnrm2_dispatch_##C,
const openblas_cnrm2_dispatch_t *const openblas_cnrm2_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_casum_dispatch_t openblas_casum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_casum_dispatch_##C,
const openblas_casum_dispatch_t *const openblas_casum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_csum_dispatch_t openblas_csum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_csum_dispatch_##C,
const openblas_csum_dispatch_t *const openblas_csum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_ccopy_dispatch_t openblas_ccopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ccopy_dispatch_##C,
const openblas_ccopy_dispatch_t *const openblas_ccopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cdotu_dispatch_t openblas_cdotu_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cdotu_dispatch_##C,
const openblas_cdotu_dispatch_t *const openblas_cdotu_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cdotc_dispatch_t openblas_cdotc_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cdotc_dispatch_##C,
const openblas_cdotc_dispatch_t *const openblas_cdotc_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_csrot_dispatch_t openblas_csrot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_csrot_dispatch_##C,
const openblas_csrot_dispatch_t *const openblas_csrot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_caxpy_dispatch_t openblas_caxpy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_caxpy_dispatch_##C,
const openblas_caxpy_dispatch_t *const openblas_caxpy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_caxpyc_dispatch_t openblas_caxpyc_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_caxpyc_dispatch_##C,
const openblas_caxpyc_dispatch_t *const openblas_caxpyc_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cscal_dispatch_t openblas_cscal_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cscal_dispatch_##C,
const openblas_cscal_dispatch_t *const openblas_cscal_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cswap_dispatch_t openblas_cswap_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cswap_dispatch_##C,
const openblas_cswap_dispatch_t *const openblas_cswap_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cgemv_dispatch_t openblas_cgemv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cgemv_dispatch_##C,
const openblas_cgemv_dispatch_t *const openblas_cgemv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cgeru_dispatch_t openblas_cgeru_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cgeru_dispatch_##C,
const openblas_cgeru_dispatch_t *const openblas_cgeru_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cgerc_dispatch_t openblas_cgerc_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cgerc_dispatch_##C,
const openblas_cgerc_dispatch_t *const openblas_cgerc_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cgerv_dispatch_t openblas_cgerv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cgerv_dispatch_##C,
const openblas_cgerv_dispatch_t *const openblas_cgerv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cgerd_dispatch_t openblas_cgerd_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cgerd_dispatch_##C,
const openblas_cgerd_dispatch_t *const openblas_cgerd_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_csymv_dispatch_t openblas_csymv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_csymv_dispatch_##C,
const openblas_csymv_dispatch_t *const openblas_csymv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_chemv_dispatch_t openblas_chemv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_chemv_dispatch_##C,
const openblas_chemv_dispatch_t *const openblas_chemv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cgemm_dispatch_t openblas_cgemm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cgemm_dispatch_##C,
const openblas_cgemm_dispatch_t *const openblas_cgemm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_ctrsm_dispatch_t openblas_ctrsm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ctrsm_dispatch_##C,
const openblas_ctrsm_dispatch_t *const openblas_ctrsm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_ctrmm_dispatch_t openblas_ctrmm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ctrmm_dispatch_##C,
const openblas_ctrmm_dispatch_t *const openblas_ctrmm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_csymm_dispatch_t openblas_csymm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_csymm_dispatch_##C,
const openblas_csymm_dispatch_t *const openblas_csymm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_chemm_dispatch_t openblas_chemm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_chemm_dispatch_##C,
const openblas_chemm_dispatch_t *const openblas_chemm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cgemm3m_dispatch_t openblas_cgemm3m_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cgemm3m_dispatch_##C,
const openblas_cgemm3m_dispatch_t *const openblas_cgemm3m_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_csymm3m_dispatch_t openblas_csymm3m_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_csymm3m_dispatch_##C,
const openblas_csymm3m_dispatch_t *const openblas_csymm3m_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_chemm3m_dispatch_t openblas_chemm3m_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_chemm3m_dispatch_##C,
const openblas_chemm3m_dispatch_t *const openblas_chemm3m_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cneg_dispatch_t openblas_cneg_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cneg_dispatch_##C,
const openblas_cneg_dispatch_t *const openblas_cneg_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_claswp_dispatch_t openblas_claswp_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_claswp_dispatch_##C,
const openblas_claswp_dispatch_t *const openblas_claswp_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zamax_dispatch_t openblas_zamax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zamax_dispatch_##C,
const openblas_zamax_dispatch_t *const openblas_zamax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zamin_dispatch_t openblas_zamin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zamin_dispatch_##C,
const openblas_zamin_dispatch_t *const openblas_zamin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_izamax_dispatch_t openblas_izamax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_izamax_dispatch_##C,
const openblas_izamax_dispatch_t *const openblas_izamax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_izamin_dispatch_t openblas_izamin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_izamin_dispatch_##C,
const openblas_izamin_dispatch_t *const openblas_izamin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_znrm2_dispatch_t openblas_znrm2_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_znrm2_dispatch_##C,
const openblas_znrm2_dispatch_t *const openblas_znrm2_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zasum_dispatch_t openblas_zasum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zasum_dispatch_##C,
const openblas_zasum_dispatch_t *const openblas_zasum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zsum_dispatch_t openblas_zsum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zsum_dispatch_##C,
const openblas_zsum_dispatch_t *const openblas_zsum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zcopy_dispatch_t openblas_zcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zcopy_dispatch_##C,
const openblas_zcopy_dispatch_t *const openblas_zcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zdotu_dispatch_t openblas_zdotu_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zdotu_dispatch_##C,
const openblas_zdotu_dispatch_t *const openblas_zdotu_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zdotc_dispatch_t openblas_zdotc_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zdotc_dispatch_##C,
const openblas_zdotc_dispatch_t *const openblas_zdotc_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zdrot_dispatch_t openblas_zdrot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zdrot_dispatch_##C,
const openblas_zdrot_dispatch_t *const openblas_zdrot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zaxpy_dispatch_t openblas_zaxpy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zaxpy_dispatch_##C,
const openblas_zaxpy_dispatch_t *const openblas_zaxpy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zaxpyc_dispatch_t openblas_zaxpyc_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zaxpyc_dispatch_##C,
const openblas_zaxpyc_dispatch_t *const openblas_zaxpyc_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zscal_dispatch_t openblas_zscal_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zscal_dispatch_##C,
const openblas_zscal_dispatch_t *const openblas_zscal_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zswap_dispatch_t openblas_zswap_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zswap_dispatch_##C,
const openblas_zswap_dispatch_t *const openblas_zswap_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zgemv_dispatch_t openblas_zgemv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zgemv_dispatch_##C,
const openblas_zgemv_dispatch_t *const openblas_zgemv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zgeru_dispatch_t openblas_zgeru_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zgeru_dispatch_##C,
const openblas_zgeru_dispatch_t *const openblas_zgeru_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zgerc_dispatch_t openblas_zgerc_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zgerc_dispatch_##C,
const openblas_zgerc_dispatch_t *const openblas_zgerc_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zgerv_dispatch_t openblas_zgerv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zgerv_dispatch_##C,
const openblas_zgerv_dispatch_t *const openblas_zgerv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zgerd_dispatch_t openblas_zgerd_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zgerd_dispatch_##C,
const openblas_zgerd_dispatch_t *const openblas_zgerd_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zsymv_dispatch_t openblas_zsymv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zsymv_dispatch_##C,
const openblas_zsymv_dispatch_t *const openblas_zsymv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zhemv_dispatch_t openblas_zhemv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zhemv_dispatch_##C,
const openblas_zhemv_dispatch_t *const openblas_zhemv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zgemm_dispatch_t openblas_zgemm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zgemm_dispatch_##C,
const openblas_zgemm_dispatch_t *const openblas_zgemm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_ztrsm_dispatch_t openblas_ztrsm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ztrsm_dispatch_##C,
const openblas_ztrsm_dispatch_t *const openblas_ztrsm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_ztrmm_dispatch_t openblas_ztrmm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ztrmm_dispatch_##C,
const openblas_ztrmm_dispatch_t *const openblas_ztrmm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zsymm_dispatch_t openblas_zsymm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zsymm_dispatch_##C,
const openblas_zsymm_dispatch_t *const openblas_zsymm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zhemm_dispatch_t openblas_zhemm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zhemm_dispatch_##C,
const openblas_zhemm_dispatch_t *const openblas_zhemm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zgemm3m_dispatch_t openblas_zgemm3m_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zgemm3m_dispatch_##C,
const openblas_zgemm3m_dispatch_t *const openblas_zgemm3m_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zsymm3m_dispatch_t openblas_zsymm3m_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zsymm3m_dispatch_##C,
const openblas_zsymm3m_dispatch_t *const openblas_zsymm3m_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zhemm3m_dispatch_t openblas_zhemm3m_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zhemm3m_dispatch_##C,
const openblas_zhemm3m_dispatch_t *const openblas_zhemm3m_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zneg_dispatch_t openblas_zneg_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zneg_dispatch_##C,
const openblas_zneg_dispatch_t *const openblas_zneg_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16 == 1)
#define DECL(C) extern const openblas_zlaswp_dispatch_t openblas_zlaswp_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zlaswp_dispatch_##C,
const openblas_zlaswp_dispatch_t *const openblas_zlaswp_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xamax_dispatch_t openblas_xamax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xamax_dispatch_##C,
const openblas_xamax_dispatch_t *const openblas_xamax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xamin_dispatch_t openblas_xamin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xamin_dispatch_##C,
const openblas_xamin_dispatch_t *const openblas_xamin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_ixamax_dispatch_t openblas_ixamax_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ixamax_dispatch_##C,
const openblas_ixamax_dispatch_t *const openblas_ixamax_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_ixamin_dispatch_t openblas_ixamin_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_ixamin_dispatch_##C,
const openblas_ixamin_dispatch_t *const openblas_ixamin_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xnrm2_dispatch_t openblas_xnrm2_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xnrm2_dispatch_##C,
const openblas_xnrm2_dispatch_t *const openblas_xnrm2_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xasum_dispatch_t openblas_xasum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xasum_dispatch_##C,
const openblas_xasum_dispatch_t *const openblas_xasum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xsum_dispatch_t openblas_xsum_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xsum_dispatch_##C,
const openblas_xsum_dispatch_t *const openblas_xsum_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xcopy_dispatch_t openblas_xcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xcopy_dispatch_##C,
const openblas_xcopy_dispatch_t *const openblas_xcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xdotu_dispatch_t openblas_xdotu_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xdotu_dispatch_##C,
const openblas_xdotu_dispatch_t *const openblas_xdotu_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xdotc_dispatch_t openblas_xdotc_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xdotc_dispatch_##C,
const openblas_xdotc_dispatch_t *const openblas_xdotc_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xqrot_dispatch_t openblas_xqrot_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xqrot_dispatch_##C,
const openblas_xqrot_dispatch_t *const openblas_xqrot_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xaxpy_dispatch_t openblas_xaxpy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xaxpy_dispatch_##C,
const openblas_xaxpy_dispatch_t *const openblas_xaxpy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xaxpyc_dispatch_t openblas_xaxpyc_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xaxpyc_dispatch_##C,
const openblas_xaxpyc_dispatch_t *const openblas_xaxpyc_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xscal_dispatch_t openblas_xscal_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xscal_dispatch_##C,
const openblas_xscal_dispatch_t *const openblas_xscal_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xswap_dispatch_t openblas_xswap_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xswap_dispatch_##C,
const openblas_xswap_dispatch_t *const openblas_xswap_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xgemv_dispatch_t openblas_xgemv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xgemv_dispatch_##C,
const openblas_xgemv_dispatch_t *const openblas_xgemv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xgeru_dispatch_t openblas_xgeru_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xgeru_dispatch_##C,
const openblas_xgeru_dispatch_t *const openblas_xgeru_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xgerc_dispatch_t openblas_xgerc_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xgerc_dispatch_##C,
const openblas_xgerc_dispatch_t *const openblas_xgerc_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xgerv_dispatch_t openblas_xgerv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xgerv_dispatch_##C,
const openblas_xgerv_dispatch_t *const openblas_xgerv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xgerd_dispatch_t openblas_xgerd_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xgerd_dispatch_##C,
const openblas_xgerd_dispatch_t *const openblas_xgerd_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xsymv_dispatch_t openblas_xsymv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xsymv_dispatch_##C,
const openblas_xsymv_dispatch_t *const openblas_xsymv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xhemv_dispatch_t openblas_xhemv_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xhemv_dispatch_##C,
const openblas_xhemv_dispatch_t *const openblas_xhemv_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xgemm_dispatch_t openblas_xgemm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xgemm_dispatch_##C,
const openblas_xgemm_dispatch_t *const openblas_xgemm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xtrsm_dispatch_t openblas_xtrsm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xtrsm_dispatch_##C,
const openblas_xtrsm_dispatch_t *const openblas_xtrsm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xtrmm_dispatch_t openblas_xtrmm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xtrmm_dispatch_##C,
const openblas_xtrmm_dispatch_t *const openblas_xtrmm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xsymm_dispatch_t openblas_xsymm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xsymm_dispatch_##C,
const openblas_xsymm_dispatch_t *const openblas_xsymm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xhemm_dispatch_t openblas_xhemm_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xhemm_dispatch_##C,
const openblas_xhemm_dispatch_t *const openblas_xhemm_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xgemm3m_dispatch_t openblas_xgemm3m_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xgemm3m_dispatch_##C,
const openblas_xgemm3m_dispatch_t *const openblas_xgemm3m_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xsymm3m_dispatch_t openblas_xsymm3m_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xsymm3m_dispatch_##C,
const openblas_xsymm3m_dispatch_t *const openblas_xsymm3m_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xhemm3m_dispatch_t openblas_xhemm3m_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xhemm3m_dispatch_##C,
const openblas_xhemm3m_dispatch_t *const openblas_xhemm3m_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xneg_dispatch_t openblas_xneg_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xneg_dispatch_##C,
const openblas_xneg_dispatch_t *const openblas_xneg_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#ifdef EXPRECISION
#define DECL(C) extern const openblas_xlaswp_dispatch_t openblas_xlaswp_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_xlaswp_dispatch_##C,
const openblas_xlaswp_dispatch_t *const openblas_xlaswp_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1)
#define DECL(C) extern const openblas_saxpby_dispatch_t openblas_saxpby_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_saxpby_dispatch_##C,
const openblas_saxpby_dispatch_t *const openblas_saxpby_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_daxpby_dispatch_t openblas_daxpby_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_daxpby_dispatch_##C,
const openblas_daxpby_dispatch_t *const openblas_daxpby_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_caxpby_dispatch_t openblas_caxpby_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_caxpby_dispatch_##C,
const openblas_caxpby_dispatch_t *const openblas_caxpby_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_zaxpby_dispatch_t openblas_zaxpby_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zaxpby_dispatch_##C,
const openblas_zaxpby_dispatch_t *const openblas_zaxpby_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1)
#define DECL(C) extern const openblas_somatcopy_dispatch_t openblas_somatcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_somatcopy_dispatch_##C,
const openblas_somatcopy_dispatch_t *const openblas_somatcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_domatcopy_dispatch_t openblas_domatcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_domatcopy_dispatch_##C,
const openblas_domatcopy_dispatch_t *const openblas_domatcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_comatcopy_dispatch_t openblas_comatcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_comatcopy_dispatch_##C,
const openblas_comatcopy_dispatch_t *const openblas_comatcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_zomatcopy_dispatch_t openblas_zomatcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zomatcopy_dispatch_##C,
const openblas_zomatcopy_dispatch_t *const openblas_zomatcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1)
#define DECL(C) extern const openblas_simatcopy_dispatch_t openblas_simatcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_simatcopy_dispatch_##C,
const openblas_simatcopy_dispatch_t *const openblas_simatcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_dimatcopy_dispatch_t openblas_dimatcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dimatcopy_dispatch_##C,
const openblas_dimatcopy_dispatch_t *const openblas_dimatcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cimatcopy_dispatch_t openblas_cimatcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cimatcopy_dispatch_##C,
const openblas_cimatcopy_dispatch_t *const openblas_cimatcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_zimatcopy_dispatch_t openblas_zimatcopy_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zimatcopy_dispatch_##C,
const openblas_zimatcopy_dispatch_t *const openblas_zimatcopy_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_SINGLE==1)
#define DECL(C) extern const openblas_sgeadd_dispatch_t openblas_sgeadd_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_sgeadd_dispatch_##C,
const openblas_sgeadd_dispatch_t *const openblas_sgeadd_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_DOUBLE==1)
#define DECL(C) extern const openblas_dgeadd_dispatch_t openblas_dgeadd_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_dgeadd_dispatch_##C,
const openblas_dgeadd_dispatch_t *const openblas_dgeadd_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX==1)
#define DECL(C) extern const openblas_cgeadd_dispatch_t openblas_cgeadd_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_cgeadd_dispatch_##C,
const openblas_cgeadd_dispatch_t *const openblas_cgeadd_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

#if (BUILD_COMPLEX16==1)
#define DECL(C) extern const openblas_zgeadd_dispatch_t openblas_zgeadd_dispatch_##C;
OPENBLAS_CORE_LIST(DECL)
#undef DECL
#define REF(C) [OPENBLAS_CORE_##C] = &openblas_zgeadd_dispatch_##C,
const openblas_zgeadd_dispatch_t *const openblas_zgeadd_dispatch[OPENBLAS_NUM_CORES] = {
  OPENBLAS_CORE_LIST(REF)
};
#undef REF
#endif

