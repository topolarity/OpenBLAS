#ifndef COMMON_D_H
#define COMMON_D_H

#ifndef DYNAMIC_ARCH

#define	DAMAX_K			damax_k
#define	DAMIN_K			damin_k
#define	DMAX_K			dmax_k
#define	DMIN_K			dmin_k
#define	IDAMAX_K		idamax_k
#define	IDAMIN_K		idamin_k
#define	IDMAX_K			idmax_k
#define	IDMIN_K			idmin_k
#define	DASUM_K			dasum_k
#define	DAXPYU_K		daxpy_k
#define	DAXPYC_K		daxpy_k
#define	DCOPY_K			dcopy_k
#define	DDOTU_K			ddot_k
#define	DDOTC_K			ddot_k
#define	DNRM2_K			dnrm2_k
#define	DSCAL_K			dscal_k
#define	DSUM_K			dsum_k
#define	DSWAP_K			dswap_k
#define	DROT_K			drot_k
#define DROTM_K         drotm_k

#define	DGEMV_N			dgemv_n
#define	DGEMV_T			dgemv_t
#define	DGEMV_R			dgemv_n
#define	DGEMV_C			dgemv_t
#define	DGEMV_O			dgemv_n
#define	DGEMV_U			dgemv_t
#define	DGEMV_S			dgemv_n
#define	DGEMV_D			dgemv_t

#define	DGERU_K			dger_k
#define	DGERC_K			dger_k
#define	DGERV_K			dger_k
#define	DGERD_K			dger_k

#define DSYMV_U			dsymv_U
#define DSYMV_L			dsymv_L

#define DSYMV_THREAD_U		dsymv_thread_U
#define DSYMV_THREAD_L		dsymv_thread_L

#define	DGEMM_ONCOPY		dgemm_oncopy
#define	DGEMM_OTCOPY		dgemm_otcopy

#if DGEMM_DEFAULT_UNROLL_M == DGEMM_DEFAULT_UNROLL_N
#define	DGEMM_INCOPY		dgemm_oncopy
#define	DGEMM_ITCOPY		dgemm_otcopy
#else
#define	DGEMM_INCOPY		dgemm_incopy
#define	DGEMM_ITCOPY		dgemm_itcopy
#endif

#define	DTRMM_OUNUCOPY		dtrmm_ounucopy
#define	DTRMM_OUNNCOPY		dtrmm_ounncopy
#define	DTRMM_OUTUCOPY		dtrmm_outucopy
#define	DTRMM_OUTNCOPY		dtrmm_outncopy
#define	DTRMM_OLNUCOPY		dtrmm_olnucopy
#define	DTRMM_OLNNCOPY		dtrmm_olnncopy
#define	DTRMM_OLTUCOPY		dtrmm_oltucopy
#define	DTRMM_OLTNCOPY		dtrmm_oltncopy

#define	DTRSM_OUNUCOPY		dtrsm_ounucopy
#define	DTRSM_OUNNCOPY		dtrsm_ounncopy
#define	DTRSM_OUTUCOPY		dtrsm_outucopy
#define	DTRSM_OUTNCOPY		dtrsm_outncopy
#define	DTRSM_OLNUCOPY		dtrsm_olnucopy
#define	DTRSM_OLNNCOPY		dtrsm_olnncopy
#define	DTRSM_OLTUCOPY		dtrsm_oltucopy
#define	DTRSM_OLTNCOPY		dtrsm_oltncopy

#if DGEMM_DEFAULT_UNROLL_M == DGEMM_DEFAULT_UNROLL_N
#define	DTRMM_IUNUCOPY		dtrmm_ounucopy
#define	DTRMM_IUNNCOPY		dtrmm_ounncopy
#define	DTRMM_IUTUCOPY		dtrmm_outucopy
#define	DTRMM_IUTNCOPY		dtrmm_outncopy
#define	DTRMM_ILNUCOPY		dtrmm_olnucopy
#define	DTRMM_ILNNCOPY		dtrmm_olnncopy
#define	DTRMM_ILTUCOPY		dtrmm_oltucopy
#define	DTRMM_ILTNCOPY		dtrmm_oltncopy

#define	DTRSM_IUNUCOPY		dtrsm_ounucopy
#define	DTRSM_IUNNCOPY		dtrsm_ounncopy
#define	DTRSM_IUTUCOPY		dtrsm_outucopy
#define	DTRSM_IUTNCOPY		dtrsm_outncopy
#define	DTRSM_ILNUCOPY		dtrsm_olnucopy
#define	DTRSM_ILNNCOPY		dtrsm_olnncopy
#define	DTRSM_ILTUCOPY		dtrsm_oltucopy
#define	DTRSM_ILTNCOPY		dtrsm_oltncopy
#else
#define	DTRMM_IUNUCOPY		dtrmm_iunucopy
#define	DTRMM_IUNNCOPY		dtrmm_iunncopy
#define	DTRMM_IUTUCOPY		dtrmm_iutucopy
#define	DTRMM_IUTNCOPY		dtrmm_iutncopy
#define	DTRMM_ILNUCOPY		dtrmm_ilnucopy
#define	DTRMM_ILNNCOPY		dtrmm_ilnncopy
#define	DTRMM_ILTUCOPY		dtrmm_iltucopy
#define	DTRMM_ILTNCOPY		dtrmm_iltncopy

#define	DTRSM_IUNUCOPY		dtrsm_iunucopy
#define	DTRSM_IUNNCOPY		dtrsm_iunncopy
#define	DTRSM_IUTUCOPY		dtrsm_iutucopy
#define	DTRSM_IUTNCOPY		dtrsm_iutncopy
#define	DTRSM_ILNUCOPY		dtrsm_ilnucopy
#define	DTRSM_ILNNCOPY		dtrsm_ilnncopy
#define	DTRSM_ILTUCOPY		dtrsm_iltucopy
#define	DTRSM_ILTNCOPY		dtrsm_iltncopy
#endif

#define	DGEMM_BETA		dgemm_beta

#define	DGEMM_KERNEL		dgemm_kernel

#define	DTRMM_KERNEL_LN		dtrmm_kernel_LN
#define	DTRMM_KERNEL_LT		dtrmm_kernel_LT
#define	DTRMM_KERNEL_LR		dtrmm_kernel_LN
#define	DTRMM_KERNEL_LC		dtrmm_kernel_LT
#define	DTRMM_KERNEL_RN		dtrmm_kernel_RN
#define	DTRMM_KERNEL_RT		dtrmm_kernel_RT
#define	DTRMM_KERNEL_RR		dtrmm_kernel_RN
#define	DTRMM_KERNEL_RC		dtrmm_kernel_RT

#define	DTRSM_KERNEL_LN		dtrsm_kernel_LN
#define	DTRSM_KERNEL_LT		dtrsm_kernel_LT
#define	DTRSM_KERNEL_LR		dtrsm_kernel_LN
#define	DTRSM_KERNEL_LC		dtrsm_kernel_LT
#define	DTRSM_KERNEL_RN		dtrsm_kernel_RN
#define	DTRSM_KERNEL_RT		dtrsm_kernel_RT
#define	DTRSM_KERNEL_RR		dtrsm_kernel_RN
#define	DTRSM_KERNEL_RC		dtrsm_kernel_RT

#define	DSYMM_OUTCOPY		dsymm_outcopy
#define	DSYMM_OLTCOPY		dsymm_oltcopy
#if DGEMM_DEFAULT_UNROLL_M == DGEMM_DEFAULT_UNROLL_N
#define	DSYMM_IUTCOPY		dsymm_outcopy
#define	DSYMM_ILTCOPY		dsymm_oltcopy
#else
#define	DSYMM_IUTCOPY		dsymm_iutcopy
#define	DSYMM_ILTCOPY		dsymm_iltcopy
#endif

#define DNEG_TCOPY		dneg_tcopy
#define DLASWP_NCOPY		dlaswp_ncopy

#define	DAXPBY_K		daxpby_k
#define DOMATCOPY_K_CN		domatcopy_k_cn
#define DOMATCOPY_K_RN		domatcopy_k_rn
#define DOMATCOPY_K_CT		domatcopy_k_ct
#define DOMATCOPY_K_RT		domatcopy_k_rt

#define DIMATCOPY_K_CN		dimatcopy_k_cn
#define DIMATCOPY_K_RN		dimatcopy_k_rn
#define DIMATCOPY_K_CT      dimatcopy_k_ct
#define DIMATCOPY_K_RT      dimatcopy_k_rt
#define DGEADD_K                dgeadd_k 

#define DGEMM_SMALL_MATRIX_PERMIT	dgemm_small_matrix_permit

#else

#define	DAMAX_K			openblas_damax_dispatch[openblas_core]->damax_k
#define	DAMIN_K			openblas_damin_dispatch[openblas_core]->damin_k
#define	DMAX_K			openblas_dmax_dispatch[openblas_core]->dmax_k
#define	DMIN_K			openblas_dmin_dispatch[openblas_core]->dmin_k
#define	IDAMAX_K		openblas_idamax_dispatch[openblas_core]->idamax_k
#define	IDAMIN_K		openblas_idamin_dispatch[openblas_core]->idamin_k
#define	IDMAX_K			openblas_idmax_dispatch[openblas_core]->idmax_k
#define	IDMIN_K			openblas_idmin_dispatch[openblas_core]->idmin_k
#define	DASUM_K			openblas_dasum_dispatch[openblas_core]->dasum_k
#define	DAXPYU_K		openblas_daxpy_dispatch[openblas_core]->daxpy_k
#define	DAXPYC_K		openblas_daxpy_dispatch[openblas_core]->daxpy_k
#define	DCOPY_K			openblas_dcopy_dispatch[openblas_core]->dcopy_k
#define	DDOTU_K			openblas_ddot_dispatch[openblas_core]->ddot_k
#define	DDOTC_K			openblas_ddot_dispatch[openblas_core]->ddot_k
#define	DNRM2_K			openblas_dnrm2_dispatch[openblas_core]->dnrm2_k
#define	DSCAL_K			openblas_dscal_dispatch[openblas_core]->dscal_k
#define	DSUM_K			openblas_dsum_dispatch[openblas_core]->dsum_k
#define	DSWAP_K			openblas_dswap_dispatch[openblas_core]->dswap_k
#define	DROT_K			openblas_drot_dispatch[openblas_core]->drot_k
#define	DROTM_K			openblas_drotm_dispatch[openblas_core]->drotm_k

#define	DGEMV_N			openblas_dgemv_dispatch[openblas_core]->dgemv_n
#define	DGEMV_T			openblas_dgemv_dispatch[openblas_core]->dgemv_t
#define	DGEMV_R			openblas_dgemv_dispatch[openblas_core]->dgemv_n
#define	DGEMV_C			openblas_dgemv_dispatch[openblas_core]->dgemv_t
#define	DGEMV_O			openblas_dgemv_dispatch[openblas_core]->dgemv_n
#define	DGEMV_U			openblas_dgemv_dispatch[openblas_core]->dgemv_t
#define	DGEMV_S			openblas_dgemv_dispatch[openblas_core]->dgemv_n
#define	DGEMV_D			openblas_dgemv_dispatch[openblas_core]->dgemv_t

#define	DGERU_K			openblas_dger_dispatch[openblas_core]->dger_k
#define	DGERC_K			openblas_dger_dispatch[openblas_core]->dger_k
#define	DGERV_K			openblas_dger_dispatch[openblas_core]->dger_k
#define	DGERD_K			openblas_dger_dispatch[openblas_core]->dger_k

#define DSYMV_U			openblas_dsymv_dispatch[openblas_core]->dsymv_U
#define DSYMV_L			openblas_dsymv_dispatch[openblas_core]->dsymv_L

#define DSYMV_THREAD_U		dsymv_thread_U
#define DSYMV_THREAD_L		dsymv_thread_L

#define	DGEMM_ONCOPY		openblas_dgemm_dispatch[openblas_core]->dgemm_oncopy
#define	DGEMM_OTCOPY		openblas_dgemm_dispatch[openblas_core]->dgemm_otcopy
#define	DGEMM_INCOPY		openblas_dgemm_dispatch[openblas_core]->dgemm_incopy
#define	DGEMM_ITCOPY		openblas_dgemm_dispatch[openblas_core]->dgemm_itcopy

#define	DTRMM_OUNUCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_ounucopy
#define	DTRMM_OUTUCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_outucopy
#define	DTRMM_OLNUCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_olnucopy
#define	DTRMM_OLTUCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_oltucopy
#define	DTRSM_OUNUCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_ounucopy
#define	DTRSM_OUTUCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_outucopy
#define	DTRSM_OLNUCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_olnucopy
#define	DTRSM_OLTUCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_oltucopy

#define	DTRMM_IUNUCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_iunucopy
#define	DTRMM_IUTUCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_iutucopy
#define	DTRMM_ILNUCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_ilnucopy
#define	DTRMM_ILTUCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_iltucopy
#define	DTRSM_IUNUCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_iunucopy
#define	DTRSM_IUTUCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_iutucopy
#define	DTRSM_ILNUCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_ilnucopy
#define	DTRSM_ILTUCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_iltucopy

#define	DTRMM_OUNNCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_ounncopy
#define	DTRMM_OUTNCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_outncopy
#define	DTRMM_OLNNCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_olnncopy
#define	DTRMM_OLTNCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_oltncopy
#define	DTRSM_OUNNCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_ounncopy
#define	DTRSM_OUTNCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_outncopy
#define	DTRSM_OLNNCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_olnncopy
#define	DTRSM_OLTNCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_oltncopy

#define	DTRMM_IUNNCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_iunncopy
#define	DTRMM_IUTNCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_iutncopy
#define	DTRMM_ILNNCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_ilnncopy
#define	DTRMM_ILTNCOPY		openblas_dtrmm_dispatch[openblas_core]->dtrmm_iltncopy
#define	DTRSM_IUNNCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_iunncopy
#define	DTRSM_IUTNCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_iutncopy
#define	DTRSM_ILNNCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_ilnncopy
#define	DTRSM_ILTNCOPY		openblas_dtrsm_dispatch[openblas_core]->dtrsm_iltncopy

#define	DGEMM_BETA		openblas_dgemm_dispatch[openblas_core]->dgemm_beta
#define	DGEMM_KERNEL		openblas_dgemm_dispatch[openblas_core]->dgemm_kernel

#define	DTRMM_KERNEL_LN		openblas_dtrmm_dispatch[openblas_core]->dtrmm_kernel_LN
#define	DTRMM_KERNEL_LT		openblas_dtrmm_dispatch[openblas_core]->dtrmm_kernel_LT
#define	DTRMM_KERNEL_LR		openblas_dtrmm_dispatch[openblas_core]->dtrmm_kernel_LN
#define	DTRMM_KERNEL_LC		openblas_dtrmm_dispatch[openblas_core]->dtrmm_kernel_LT
#define	DTRMM_KERNEL_RN		openblas_dtrmm_dispatch[openblas_core]->dtrmm_kernel_RN
#define	DTRMM_KERNEL_RT		openblas_dtrmm_dispatch[openblas_core]->dtrmm_kernel_RT
#define	DTRMM_KERNEL_RR		openblas_dtrmm_dispatch[openblas_core]->dtrmm_kernel_RN
#define	DTRMM_KERNEL_RC		openblas_dtrmm_dispatch[openblas_core]->dtrmm_kernel_RT

#define	DTRSM_KERNEL_LN		openblas_dtrsm_dispatch[openblas_core]->dtrsm_kernel_LN
#define	DTRSM_KERNEL_LT		openblas_dtrsm_dispatch[openblas_core]->dtrsm_kernel_LT
#define	DTRSM_KERNEL_LR		openblas_dtrsm_dispatch[openblas_core]->dtrsm_kernel_LN
#define	DTRSM_KERNEL_LC		openblas_dtrsm_dispatch[openblas_core]->dtrsm_kernel_LT
#define	DTRSM_KERNEL_RN		openblas_dtrsm_dispatch[openblas_core]->dtrsm_kernel_RN
#define	DTRSM_KERNEL_RT		openblas_dtrsm_dispatch[openblas_core]->dtrsm_kernel_RT
#define	DTRSM_KERNEL_RR		openblas_dtrsm_dispatch[openblas_core]->dtrsm_kernel_RN
#define	DTRSM_KERNEL_RC		openblas_dtrsm_dispatch[openblas_core]->dtrsm_kernel_RT

#define	DSYMM_IUTCOPY		openblas_dsymm_dispatch[openblas_core]->dsymm_iutcopy
#define	DSYMM_ILTCOPY		openblas_dsymm_dispatch[openblas_core]->dsymm_iltcopy
#define	DSYMM_OUTCOPY		openblas_dsymm_dispatch[openblas_core]->dsymm_outcopy
#define	DSYMM_OLTCOPY		openblas_dsymm_dispatch[openblas_core]->dsymm_oltcopy

#define DNEG_TCOPY		openblas_dneg_dispatch[openblas_core]->dneg_tcopy
#define DLASWP_NCOPY		openblas_dlaswp_dispatch[openblas_core]->dlaswp_ncopy

#define	DAXPBY_K		openblas_daxpby_dispatch[openblas_core]->daxpby_k
#define DOMATCOPY_K_CN		openblas_domatcopy_dispatch[openblas_core]->domatcopy_k_cn
#define DOMATCOPY_K_RN		openblas_domatcopy_dispatch[openblas_core]->domatcopy_k_rn
#define DOMATCOPY_K_CT		openblas_domatcopy_dispatch[openblas_core]->domatcopy_k_ct
#define DOMATCOPY_K_RT		openblas_domatcopy_dispatch[openblas_core]->domatcopy_k_rt
#define DIMATCOPY_K_CN		openblas_dimatcopy_dispatch[openblas_core]->dimatcopy_k_cn
#define DIMATCOPY_K_RN		openblas_dimatcopy_dispatch[openblas_core]->dimatcopy_k_rn
#define DIMATCOPY_K_CT		openblas_dimatcopy_dispatch[openblas_core]->dimatcopy_k_ct
#define DIMATCOPY_K_RT		openblas_dimatcopy_dispatch[openblas_core]->dimatcopy_k_rt

#define DGEADD_K                openblas_dgeadd_dispatch[openblas_core]->dgeadd_k 

#define DGEMM_SMALL_MATRIX_PERMIT	openblas_dgemm_dispatch[openblas_core]->dgemm_small_matrix_permit

#endif

#define	DGEMM_SMALL_KERNEL_BASE	OB_SLOT_BASE(dgemm)
#define DGEMM_SMALL_KERNEL_NN		OB_SLOT_OFFSET(dgemm, dgemm_small_kernel_nn)
#define DGEMM_SMALL_KERNEL_NT		OB_SLOT_OFFSET(dgemm, dgemm_small_kernel_nt)
#define DGEMM_SMALL_KERNEL_TN		OB_SLOT_OFFSET(dgemm, dgemm_small_kernel_tn)
#define DGEMM_SMALL_KERNEL_TT		OB_SLOT_OFFSET(dgemm, dgemm_small_kernel_tt)

#define DGEMM_SMALL_KERNEL_B0_NN	OB_SLOT_OFFSET(dgemm, dgemm_small_kernel_b0_nn)
#define DGEMM_SMALL_KERNEL_B0_NT	OB_SLOT_OFFSET(dgemm, dgemm_small_kernel_b0_nt)
#define DGEMM_SMALL_KERNEL_B0_TN	OB_SLOT_OFFSET(dgemm, dgemm_small_kernel_b0_tn)
#define DGEMM_SMALL_KERNEL_B0_TT	OB_SLOT_OFFSET(dgemm, dgemm_small_kernel_b0_tt)


#define	DGEMM_NN		dgemm_nn
#define	DGEMM_CN		dgemm_tn
#define	DGEMM_TN		dgemm_tn
#define	DGEMM_NC		dgemm_nt
#define	DGEMM_NT		dgemm_nt
#define	DGEMM_CC		dgemm_tt
#define	DGEMM_CT		dgemm_tt
#define	DGEMM_TC		dgemm_tt
#define	DGEMM_TT		dgemm_tt
#define	DGEMM_NR		dgemm_nn
#define	DGEMM_TR		dgemm_tn
#define	DGEMM_CR		dgemm_tn
#define	DGEMM_RN		dgemm_nn
#define	DGEMM_RT		dgemm_nt
#define	DGEMM_RC		dgemm_nt
#define	DGEMM_RR		dgemm_nn

#define	DSYMM_LU		dsymm_LU
#define	DSYMM_LL		dsymm_LL
#define	DSYMM_RU		dsymm_RU
#define	DSYMM_RL		dsymm_RL

#define	DHEMM_LU		dhemm_LU
#define	DHEMM_LL		dhemm_LL
#define	DHEMM_RU		dhemm_RU
#define	DHEMM_RL		dhemm_RL

#define	DSYRK_UN		dsyrk_UN
#define	DSYRK_UT		dsyrk_UT
#define	DSYRK_LN		dsyrk_LN
#define	DSYRK_LT		dsyrk_LT
#define	DSYRK_UR		dsyrk_UN
#define	DSYRK_UC		dsyrk_UT
#define	DSYRK_LR		dsyrk_LN
#define	DSYRK_LC		dsyrk_LT

#define	DSYRK_KERNEL_U		dsyrk_kernel_U
#define	DSYRK_KERNEL_L		dsyrk_kernel_L

#define	DHERK_UN		dsyrk_UN
#define	DHERK_LN		dsyrk_LN
#define	DHERK_UC		dsyrk_UT
#define	DHERK_LC		dsyrk_LT

#define	DHER2K_UN		dsyr2k_UN
#define	DHER2K_LN		dsyr2k_LN
#define	DHER2K_UC		dsyr2k_UT
#define	DHER2K_LC		dsyr2k_LT

#define	DSYR2K_UN		dsyr2k_UN
#define	DSYR2K_UT		dsyr2k_UT
#define	DSYR2K_LN		dsyr2k_LN
#define	DSYR2K_LT		dsyr2k_LT
#define	DSYR2K_UR		dsyr2k_UN
#define	DSYR2K_UC		dsyr2k_UT
#define	DSYR2K_LR		dsyr2k_LN
#define	DSYR2K_LC		dsyr2k_LT

#define	DSYR2K_KERNEL_U		dsyr2k_kernel_U
#define	DSYR2K_KERNEL_L		dsyr2k_kernel_L

#define	DTRMM_LNUU		dtrmm_LNUU
#define	DTRMM_LNUN		dtrmm_LNUN
#define	DTRMM_LNLU		dtrmm_LNLU
#define	DTRMM_LNLN		dtrmm_LNLN
#define	DTRMM_LTUU		dtrmm_LTUU
#define	DTRMM_LTUN		dtrmm_LTUN
#define	DTRMM_LTLU		dtrmm_LTLU
#define	DTRMM_LTLN		dtrmm_LTLN
#define	DTRMM_LRUU		dtrmm_LNUU
#define	DTRMM_LRUN		dtrmm_LNUN
#define	DTRMM_LRLU		dtrmm_LNLU
#define	DTRMM_LRLN		dtrmm_LNLN
#define	DTRMM_LCUU		dtrmm_LTUU
#define	DTRMM_LCUN		dtrmm_LTUN
#define	DTRMM_LCLU		dtrmm_LTLU
#define	DTRMM_LCLN		dtrmm_LTLN
#define	DTRMM_RNUU		dtrmm_RNUU
#define	DTRMM_RNUN		dtrmm_RNUN
#define	DTRMM_RNLU		dtrmm_RNLU
#define	DTRMM_RNLN		dtrmm_RNLN
#define	DTRMM_RTUU		dtrmm_RTUU
#define	DTRMM_RTUN		dtrmm_RTUN
#define	DTRMM_RTLU		dtrmm_RTLU
#define	DTRMM_RTLN		dtrmm_RTLN
#define	DTRMM_RRUU		dtrmm_RNUU
#define	DTRMM_RRUN		dtrmm_RNUN
#define	DTRMM_RRLU		dtrmm_RNLU
#define	DTRMM_RRLN		dtrmm_RNLN
#define	DTRMM_RCUU		dtrmm_RTUU
#define	DTRMM_RCUN		dtrmm_RTUN
#define	DTRMM_RCLU		dtrmm_RTLU
#define	DTRMM_RCLN		dtrmm_RTLN

#define	DTRSM_LNUU		dtrsm_LNUU
#define	DTRSM_LNUN		dtrsm_LNUN
#define	DTRSM_LNLU		dtrsm_LNLU
#define	DTRSM_LNLN		dtrsm_LNLN
#define	DTRSM_LTUU		dtrsm_LTUU
#define	DTRSM_LTUN		dtrsm_LTUN
#define	DTRSM_LTLU		dtrsm_LTLU
#define	DTRSM_LTLN		dtrsm_LTLN
#define	DTRSM_LRUU		dtrsm_LNUU
#define	DTRSM_LRUN		dtrsm_LNUN
#define	DTRSM_LRLU		dtrsm_LNLU
#define	DTRSM_LRLN		dtrsm_LNLN
#define	DTRSM_LCUU		dtrsm_LTUU
#define	DTRSM_LCUN		dtrsm_LTUN
#define	DTRSM_LCLU		dtrsm_LTLU
#define	DTRSM_LCLN		dtrsm_LTLN
#define	DTRSM_RNUU		dtrsm_RNUU
#define	DTRSM_RNUN		dtrsm_RNUN
#define	DTRSM_RNLU		dtrsm_RNLU
#define	DTRSM_RNLN		dtrsm_RNLN
#define	DTRSM_RTUU		dtrsm_RTUU
#define	DTRSM_RTUN		dtrsm_RTUN
#define	DTRSM_RTLU		dtrsm_RTLU
#define	DTRSM_RTLN		dtrsm_RTLN
#define	DTRSM_RRUU		dtrsm_RNUU
#define	DTRSM_RRUN		dtrsm_RNUN
#define	DTRSM_RRLU		dtrsm_RNLU
#define	DTRSM_RRLN		dtrsm_RNLN
#define	DTRSM_RCUU		dtrsm_RTUU
#define	DTRSM_RCUN		dtrsm_RTUN
#define	DTRSM_RCLU		dtrsm_RTLU
#define	DTRSM_RCLN		dtrsm_RTLN

#define	DGEMM_THREAD_NN		dgemm_thread_nn
#define	DGEMM_THREAD_CN		dgemm_thread_tn
#define	DGEMM_THREAD_TN		dgemm_thread_tn
#define	DGEMM_THREAD_NC		dgemm_thread_nt
#define	DGEMM_THREAD_NT		dgemm_thread_nt
#define	DGEMM_THREAD_CC		dgemm_thread_tt
#define	DGEMM_THREAD_CT		dgemm_thread_tt
#define	DGEMM_THREAD_TC		dgemm_thread_tt
#define	DGEMM_THREAD_TT		dgemm_thread_tt
#define	DGEMM_THREAD_NR		dgemm_thread_nn
#define	DGEMM_THREAD_TR		dgemm_thread_tn
#define	DGEMM_THREAD_CR		dgemm_thread_tn
#define	DGEMM_THREAD_RN		dgemm_thread_nn
#define	DGEMM_THREAD_RT		dgemm_thread_nt
#define	DGEMM_THREAD_RC		dgemm_thread_nt
#define	DGEMM_THREAD_RR		dgemm_thread_nn

#define	DSYMM_THREAD_LU		dsymm_thread_LU
#define	DSYMM_THREAD_LL		dsymm_thread_LL
#define	DSYMM_THREAD_RU		dsymm_thread_RU
#define	DSYMM_THREAD_RL		dsymm_thread_RL

#define	DHEMM_THREAD_LU		dhemm_thread_LU
#define	DHEMM_THREAD_LL		dhemm_thread_LL
#define	DHEMM_THREAD_RU		dhemm_thread_RU
#define	DHEMM_THREAD_RL		dhemm_thread_RL

#define	DSYRK_THREAD_UN		dsyrk_thread_UN
#define	DSYRK_THREAD_UT		dsyrk_thread_UT
#define	DSYRK_THREAD_LN		dsyrk_thread_LN
#define	DSYRK_THREAD_LT		dsyrk_thread_LT
#define	DSYRK_THREAD_UR		dsyrk_thread_UN
#define	DSYRK_THREAD_UC		dsyrk_thread_UT
#define	DSYRK_THREAD_LR		dsyrk_thread_LN
#define	DSYRK_THREAD_LC		dsyrk_thread_LT

#define	DHERK_THREAD_UN		dsyrk_thread_UN
#define	DHERK_THREAD_UT		dsyrk_thread_UT
#define	DHERK_THREAD_LN		dsyrk_thread_LN
#define	DHERK_THREAD_LT		dsyrk_thread_LT
#define	DHERK_THREAD_UR		dsyrk_thread_UN
#define	DHERK_THREAD_UC		dsyrk_thread_UT
#define	DHERK_THREAD_LR		dsyrk_thread_LN
#define	DHERK_THREAD_LC		dsyrk_thread_LT

#endif
