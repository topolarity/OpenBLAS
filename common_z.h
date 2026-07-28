#ifndef COMMON_Z_H
#define COMMON_Z_H

#ifndef DYNAMIC_ARCH

#define	ZAMAX_K			zamax_k
#define	ZAMIN_K			zamin_k
#define	ZMAX_K			zmax_k
#define	ZMIN_K			zmin_k
#define	IZAMAX_K		izamax_k
#define	IZAMIN_K		izamin_k
#define	IZMAX_K			izmax_k
#define	IZMIN_K			izmin_k
#define	ZASUM_K			zasum_k
#define	ZAXPYU_K		zaxpy_k
#define	ZAXPYC_K		zaxpyc_k
#define	ZCOPY_K			zcopy_k
#define	ZDOTU_K			zdotu_k
#define	ZDOTC_K			zdotc_k
#define	ZNRM2_K			znrm2_k
#define	ZSCAL_K			zscal_k
#define	ZSUM_K			zsum_k
#define	ZSWAP_K			zswap_k
#define	ZROT_K			zdrot_k

#define	ZGEMV_N			zgemv_n
#define	ZGEMV_T			zgemv_t
#define	ZGEMV_R			zgemv_r
#define	ZGEMV_C			zgemv_c
#define	ZGEMV_O			zgemv_o
#define	ZGEMV_U			zgemv_u
#define	ZGEMV_S			zgemv_s
#define	ZGEMV_D			zgemv_d

#define	ZGERU_K			zgeru_k
#define	ZGERC_K			zgerc_k
#define	ZGERV_K			zgerv_k
#define	ZGERD_K			zgerd_k

#define ZSYMV_U			zsymv_U
#define ZSYMV_L			zsymv_L
#define ZHEMV_U			zhemv_U
#define ZHEMV_L			zhemv_L
#define ZHEMV_V			zhemv_V
#define ZHEMV_M			zhemv_M

#define ZSYMV_THREAD_U		zsymv_thread_U
#define ZSYMV_THREAD_L		zsymv_thread_L
#define ZHEMV_THREAD_U		zhemv_thread_U
#define ZHEMV_THREAD_L		zhemv_thread_L
#define ZHEMV_THREAD_V		zhemv_thread_V
#define ZHEMV_THREAD_M		zhemv_thread_M

#define	ZGEMM_ONCOPY		zgemm_oncopy
#define	ZGEMM_OTCOPY		zgemm_otcopy

#if ZGEMM_DEFAULT_UNROLL_M == ZGEMM_DEFAULT_UNROLL_N
#define	ZGEMM_INCOPY		zgemm_oncopy
#define	ZGEMM_ITCOPY		zgemm_otcopy
#else
#define	ZGEMM_INCOPY		zgemm_incopy
#define	ZGEMM_ITCOPY		zgemm_itcopy
#endif

#define	ZTRMM_OUNUCOPY		ztrmm_ounucopy
#define	ZTRMM_OUNNCOPY		ztrmm_ounncopy
#define	ZTRMM_OUTUCOPY		ztrmm_outucopy
#define	ZTRMM_OUTNCOPY		ztrmm_outncopy
#define	ZTRMM_OLNUCOPY		ztrmm_olnucopy
#define	ZTRMM_OLNNCOPY		ztrmm_olnncopy
#define	ZTRMM_OLTUCOPY		ztrmm_oltucopy
#define	ZTRMM_OLTNCOPY		ztrmm_oltncopy

#define	ZTRSM_OUNUCOPY		ztrsm_ounucopy
#define	ZTRSM_OUNNCOPY		ztrsm_ounncopy
#define	ZTRSM_OUTUCOPY		ztrsm_outucopy
#define	ZTRSM_OUTNCOPY		ztrsm_outncopy
#define	ZTRSM_OLNUCOPY		ztrsm_olnucopy
#define	ZTRSM_OLNNCOPY		ztrsm_olnncopy
#define	ZTRSM_OLTUCOPY		ztrsm_oltucopy
#define	ZTRSM_OLTNCOPY		ztrsm_oltncopy

#if ZGEMM_DEFAULT_UNROLL_M == ZGEMM_DEFAULT_UNROLL_N
#define	ZTRMM_IUNUCOPY		ztrmm_ounucopy
#define	ZTRMM_IUNNCOPY		ztrmm_ounncopy
#define	ZTRMM_IUTUCOPY		ztrmm_outucopy
#define	ZTRMM_IUTNCOPY		ztrmm_outncopy
#define	ZTRMM_ILNUCOPY		ztrmm_olnucopy
#define	ZTRMM_ILNNCOPY		ztrmm_olnncopy
#define	ZTRMM_ILTUCOPY		ztrmm_oltucopy
#define	ZTRMM_ILTNCOPY		ztrmm_oltncopy

#define	ZTRSM_IUNUCOPY		ztrsm_ounucopy
#define	ZTRSM_IUNNCOPY		ztrsm_ounncopy
#define	ZTRSM_IUTUCOPY		ztrsm_outucopy
#define	ZTRSM_IUTNCOPY		ztrsm_outncopy
#define	ZTRSM_ILNUCOPY		ztrsm_olnucopy
#define	ZTRSM_ILNNCOPY		ztrsm_olnncopy
#define	ZTRSM_ILTUCOPY		ztrsm_oltucopy
#define	ZTRSM_ILTNCOPY		ztrsm_oltncopy
#else
#define	ZTRMM_IUNUCOPY		ztrmm_iunucopy
#define	ZTRMM_IUNNCOPY		ztrmm_iunncopy
#define	ZTRMM_IUTUCOPY		ztrmm_iutucopy
#define	ZTRMM_IUTNCOPY		ztrmm_iutncopy
#define	ZTRMM_ILNUCOPY		ztrmm_ilnucopy
#define	ZTRMM_ILNNCOPY		ztrmm_ilnncopy
#define	ZTRMM_ILTUCOPY		ztrmm_iltucopy
#define	ZTRMM_ILTNCOPY		ztrmm_iltncopy

#define	ZTRSM_IUNUCOPY		ztrsm_iunucopy
#define	ZTRSM_IUNNCOPY		ztrsm_iunncopy
#define	ZTRSM_IUTUCOPY		ztrsm_iutucopy
#define	ZTRSM_IUTNCOPY		ztrsm_iutncopy
#define	ZTRSM_ILNUCOPY		ztrsm_ilnucopy
#define	ZTRSM_ILNNCOPY		ztrsm_ilnncopy
#define	ZTRSM_ILTUCOPY		ztrsm_iltucopy
#define	ZTRSM_ILTNCOPY		ztrsm_iltncopy
#endif

#define	ZGEMM_BETA		zgemm_beta

#define	ZGEMM_KERNEL_N		zgemm_kernel_n
#define	ZGEMM_KERNEL_L		zgemm_kernel_l
#define	ZGEMM_KERNEL_R		zgemm_kernel_r
#define	ZGEMM_KERNEL_B		zgemm_kernel_b

#define	ZTRMM_KERNEL_LN		ztrmm_kernel_LN
#define	ZTRMM_KERNEL_LT		ztrmm_kernel_LT
#define	ZTRMM_KERNEL_LR		ztrmm_kernel_LR
#define	ZTRMM_KERNEL_LC		ztrmm_kernel_LC
#define	ZTRMM_KERNEL_RN		ztrmm_kernel_RN
#define	ZTRMM_KERNEL_RT		ztrmm_kernel_RT
#define	ZTRMM_KERNEL_RR		ztrmm_kernel_RR
#define	ZTRMM_KERNEL_RC		ztrmm_kernel_RC

#define	ZTRSM_KERNEL_LN		ztrsm_kernel_LN
#define	ZTRSM_KERNEL_LT		ztrsm_kernel_LT
#define	ZTRSM_KERNEL_LR		ztrsm_kernel_LR
#define	ZTRSM_KERNEL_LC		ztrsm_kernel_LC
#define	ZTRSM_KERNEL_RN		ztrsm_kernel_RN
#define	ZTRSM_KERNEL_RT		ztrsm_kernel_RT
#define	ZTRSM_KERNEL_RR		ztrsm_kernel_RR
#define	ZTRSM_KERNEL_RC		ztrsm_kernel_RC

#define	ZSYMM_OUTCOPY		zsymm_outcopy
#define	ZSYMM_OLTCOPY		zsymm_oltcopy
#if ZGEMM_DEFAULT_UNROLL_M == ZGEMM_DEFAULT_UNROLL_N
#define	ZSYMM_IUTCOPY		zsymm_outcopy
#define	ZSYMM_ILTCOPY		zsymm_oltcopy
#else
#define	ZSYMM_IUTCOPY		zsymm_iutcopy
#define	ZSYMM_ILTCOPY		zsymm_iltcopy
#endif

#define	ZHEMM_OUTCOPY		zhemm_outcopy
#define	ZHEMM_OLTCOPY		zhemm_oltcopy
#if ZGEMM_DEFAULT_UNROLL_M == ZGEMM_DEFAULT_UNROLL_N
#define	ZHEMM_IUTCOPY		zhemm_outcopy
#define	ZHEMM_ILTCOPY		zhemm_oltcopy
#else
#define	ZHEMM_IUTCOPY		zhemm_iutcopy
#define	ZHEMM_ILTCOPY		zhemm_iltcopy
#endif

#define	ZGEMM3M_ONCOPYB		zgemm3m_oncopyb
#define	ZGEMM3M_ONCOPYR		zgemm3m_oncopyr
#define	ZGEMM3M_ONCOPYI		zgemm3m_oncopyi
#define	ZGEMM3M_OTCOPYB		zgemm3m_otcopyb
#define	ZGEMM3M_OTCOPYR		zgemm3m_otcopyr
#define	ZGEMM3M_OTCOPYI		zgemm3m_otcopyi

#define	ZGEMM3M_INCOPYB		zgemm3m_incopyb
#define	ZGEMM3M_INCOPYR		zgemm3m_incopyr
#define	ZGEMM3M_INCOPYI		zgemm3m_incopyi
#define	ZGEMM3M_ITCOPYB		zgemm3m_itcopyb
#define	ZGEMM3M_ITCOPYR		zgemm3m_itcopyr
#define	ZGEMM3M_ITCOPYI		zgemm3m_itcopyi

#define	ZSYMM3M_ILCOPYB		zsymm3m_ilcopyb
#define	ZSYMM3M_IUCOPYB		zsymm3m_iucopyb
#define	ZSYMM3M_ILCOPYR		zsymm3m_ilcopyr
#define	ZSYMM3M_IUCOPYR		zsymm3m_iucopyr
#define	ZSYMM3M_ILCOPYI		zsymm3m_ilcopyi
#define	ZSYMM3M_IUCOPYI		zsymm3m_iucopyi

#define	ZSYMM3M_OLCOPYB		zsymm3m_olcopyb
#define	ZSYMM3M_OUCOPYB		zsymm3m_oucopyb
#define	ZSYMM3M_OLCOPYR		zsymm3m_olcopyr
#define	ZSYMM3M_OUCOPYR		zsymm3m_oucopyr
#define	ZSYMM3M_OLCOPYI		zsymm3m_olcopyi
#define	ZSYMM3M_OUCOPYI		zsymm3m_oucopyi

#define	ZHEMM3M_ILCOPYB		zhemm3m_ilcopyb
#define	ZHEMM3M_IUCOPYB		zhemm3m_iucopyb
#define	ZHEMM3M_ILCOPYR		zhemm3m_ilcopyr
#define	ZHEMM3M_IUCOPYR		zhemm3m_iucopyr
#define	ZHEMM3M_ILCOPYI		zhemm3m_ilcopyi
#define	ZHEMM3M_IUCOPYI		zhemm3m_iucopyi

#define	ZHEMM3M_OLCOPYB		zhemm3m_olcopyb
#define	ZHEMM3M_OUCOPYB		zhemm3m_oucopyb
#define	ZHEMM3M_OLCOPYR		zhemm3m_olcopyr
#define	ZHEMM3M_OUCOPYR		zhemm3m_oucopyr
#define	ZHEMM3M_OLCOPYI		zhemm3m_olcopyi
#define	ZHEMM3M_OUCOPYI		zhemm3m_oucopyi

#define	ZGEMM3M_KERNEL		zgemm3m_kernel

#define ZNEG_TCOPY		zneg_tcopy
#define ZLASWP_NCOPY		zlaswp_ncopy

#define ZAXPBY_K                zaxpby_k

#define ZOMATCOPY_K_CN          zomatcopy_k_cn
#define ZOMATCOPY_K_RN          zomatcopy_k_rn
#define ZOMATCOPY_K_CT          zomatcopy_k_ct
#define ZOMATCOPY_K_RT          zomatcopy_k_rt
#define ZOMATCOPY_K_CNC         zomatcopy_k_cnc
#define ZOMATCOPY_K_RNC         zomatcopy_k_rnc
#define ZOMATCOPY_K_CTC         zomatcopy_k_ctc
#define ZOMATCOPY_K_RTC         zomatcopy_k_rtc

#define ZIMATCOPY_K_CN          zimatcopy_k_cn
#define ZIMATCOPY_K_RN          zimatcopy_k_rn
#define ZIMATCOPY_K_CT          zimatcopy_k_ct
#define ZIMATCOPY_K_RT          zimatcopy_k_rt
#define ZIMATCOPY_K_CNC         zimatcopy_k_cnc
#define ZIMATCOPY_K_RNC         zimatcopy_k_rnc
#define ZIMATCOPY_K_CTC         zimatcopy_k_ctc
#define ZIMATCOPY_K_RTC         zimatcopy_k_rtc

#define ZGEADD_K                zgeadd_k 

#define ZGEMM_SMALL_MATRIX_PERMIT	zgemm_small_matrix_permit

#else

#define	ZAMAX_K			openblas_zamax_dispatch[openblas_core]->zamax_k
#define	ZAMIN_K			openblas_zamin_dispatch[openblas_core]->zamin_k
#define	IZAMAX_K		openblas_izamax_dispatch[openblas_core]->izamax_k
#define	IZAMIN_K		openblas_izamin_dispatch[openblas_core]->izamin_k
#define	ZASUM_K			openblas_zasum_dispatch[openblas_core]->zasum_k
#define	ZAXPYU_K		openblas_zaxpy_dispatch[openblas_core]->zaxpy_k
#define	ZAXPYC_K		openblas_zaxpyc_dispatch[openblas_core]->zaxpyc_k
#define	ZCOPY_K			openblas_zcopy_dispatch[openblas_core]->zcopy_k
#define	ZDOTU_K			openblas_zdotu_dispatch[openblas_core]->zdotu_k
#define	ZDOTC_K			openblas_zdotc_dispatch[openblas_core]->zdotc_k
#define	ZNRM2_K			openblas_znrm2_dispatch[openblas_core]->znrm2_k
#define	ZSCAL_K			openblas_zscal_dispatch[openblas_core]->zscal_k
#define	ZSUM_K			openblas_zsum_dispatch[openblas_core]->zsum_k
#define	ZSWAP_K			openblas_zswap_dispatch[openblas_core]->zswap_k
#define	ZROT_K			openblas_zdrot_dispatch[openblas_core]->zdrot_k

#define	ZGEMV_N			openblas_zgemv_dispatch[openblas_core]->zgemv_n
#define	ZGEMV_T			openblas_zgemv_dispatch[openblas_core]->zgemv_t
#define	ZGEMV_R			openblas_zgemv_dispatch[openblas_core]->zgemv_r
#define	ZGEMV_C			openblas_zgemv_dispatch[openblas_core]->zgemv_c
#define	ZGEMV_O			openblas_zgemv_dispatch[openblas_core]->zgemv_o
#define	ZGEMV_U			openblas_zgemv_dispatch[openblas_core]->zgemv_u
#define	ZGEMV_S			openblas_zgemv_dispatch[openblas_core]->zgemv_s
#define	ZGEMV_D			openblas_zgemv_dispatch[openblas_core]->zgemv_d

#define	ZGERU_K			openblas_zgeru_dispatch[openblas_core]->zgeru_k
#define	ZGERC_K			openblas_zgerc_dispatch[openblas_core]->zgerc_k
#define	ZGERV_K			openblas_zgerv_dispatch[openblas_core]->zgerv_k
#define	ZGERD_K			openblas_zgerd_dispatch[openblas_core]->zgerd_k

#define ZSYMV_U			openblas_zsymv_dispatch[openblas_core]->zsymv_U
#define ZSYMV_L			openblas_zsymv_dispatch[openblas_core]->zsymv_L
#define ZHEMV_U			openblas_zhemv_dispatch[openblas_core]->zhemv_U
#define ZHEMV_L			openblas_zhemv_dispatch[openblas_core]->zhemv_L
#define ZHEMV_V			openblas_zhemv_dispatch[openblas_core]->zhemv_V
#define ZHEMV_M			openblas_zhemv_dispatch[openblas_core]->zhemv_M

#define ZSYMV_THREAD_U		zsymv_thread_U
#define ZSYMV_THREAD_L		zsymv_thread_L
#define ZHEMV_THREAD_U		zhemv_thread_U
#define ZHEMV_THREAD_L		zhemv_thread_L
#define ZHEMV_THREAD_V		zhemv_thread_V
#define ZHEMV_THREAD_M		zhemv_thread_M

#define	ZGEMM_ONCOPY		openblas_zgemm_dispatch[openblas_core]->zgemm_oncopy
#define	ZGEMM_OTCOPY		openblas_zgemm_dispatch[openblas_core]->zgemm_otcopy
#define	ZGEMM_INCOPY		openblas_zgemm_dispatch[openblas_core]->zgemm_incopy
#define	ZGEMM_ITCOPY		openblas_zgemm_dispatch[openblas_core]->zgemm_itcopy

#define	ZTRMM_OUNUCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_ounucopy
#define	ZTRMM_OUTUCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_outucopy
#define	ZTRMM_OLNUCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_olnucopy
#define	ZTRMM_OLTUCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_oltucopy
#define	ZTRSM_OUNUCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_ounucopy
#define	ZTRSM_OUTUCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_outucopy
#define	ZTRSM_OLNUCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_olnucopy
#define	ZTRSM_OLTUCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_oltucopy

#define	ZTRMM_IUNUCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_iunucopy
#define	ZTRMM_IUTUCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_iutucopy
#define	ZTRMM_ILNUCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_ilnucopy
#define	ZTRMM_ILTUCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_iltucopy
#define	ZTRSM_IUNUCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_iunucopy
#define	ZTRSM_IUTUCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_iutucopy
#define	ZTRSM_ILNUCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_ilnucopy
#define	ZTRSM_ILTUCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_iltucopy

#define	ZTRMM_OUNNCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_ounncopy
#define	ZTRMM_OUTNCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_outncopy
#define	ZTRMM_OLNNCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_olnncopy
#define	ZTRMM_OLTNCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_oltncopy
#define	ZTRSM_OUNNCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_ounncopy
#define	ZTRSM_OUTNCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_outncopy
#define	ZTRSM_OLNNCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_olnncopy
#define	ZTRSM_OLTNCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_oltncopy

#define	ZTRMM_IUNNCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_iunncopy
#define	ZTRMM_IUTNCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_iutncopy
#define	ZTRMM_ILNNCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_ilnncopy
#define	ZTRMM_ILTNCOPY		openblas_ztrmm_dispatch[openblas_core]->ztrmm_iltncopy
#define	ZTRSM_IUNNCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_iunncopy
#define	ZTRSM_IUTNCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_iutncopy
#define	ZTRSM_ILNNCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_ilnncopy
#define	ZTRSM_ILTNCOPY		openblas_ztrsm_dispatch[openblas_core]->ztrsm_iltncopy

#define	ZGEMM_BETA		openblas_zgemm_dispatch[openblas_core]->zgemm_beta
#define	ZGEMM_KERNEL_N		openblas_zgemm_dispatch[openblas_core]->zgemm_kernel_n
#define	ZGEMM_KERNEL_L		openblas_zgemm_dispatch[openblas_core]->zgemm_kernel_l
#define	ZGEMM_KERNEL_R		openblas_zgemm_dispatch[openblas_core]->zgemm_kernel_r
#define	ZGEMM_KERNEL_B		openblas_zgemm_dispatch[openblas_core]->zgemm_kernel_b

#define	ZTRMM_KERNEL_LN		openblas_ztrmm_dispatch[openblas_core]->ztrmm_kernel_LN
#define	ZTRMM_KERNEL_LT		openblas_ztrmm_dispatch[openblas_core]->ztrmm_kernel_LT
#define	ZTRMM_KERNEL_LR		openblas_ztrmm_dispatch[openblas_core]->ztrmm_kernel_LR
#define	ZTRMM_KERNEL_LC		openblas_ztrmm_dispatch[openblas_core]->ztrmm_kernel_LC
#define	ZTRMM_KERNEL_RN		openblas_ztrmm_dispatch[openblas_core]->ztrmm_kernel_RN
#define	ZTRMM_KERNEL_RT		openblas_ztrmm_dispatch[openblas_core]->ztrmm_kernel_RT
#define	ZTRMM_KERNEL_RR		openblas_ztrmm_dispatch[openblas_core]->ztrmm_kernel_RR
#define	ZTRMM_KERNEL_RC		openblas_ztrmm_dispatch[openblas_core]->ztrmm_kernel_RC

#define	ZTRSM_KERNEL_LN		openblas_ztrsm_dispatch[openblas_core]->ztrsm_kernel_LN
#define	ZTRSM_KERNEL_LT		openblas_ztrsm_dispatch[openblas_core]->ztrsm_kernel_LT
#define	ZTRSM_KERNEL_LR		openblas_ztrsm_dispatch[openblas_core]->ztrsm_kernel_LR
#define	ZTRSM_KERNEL_LC		openblas_ztrsm_dispatch[openblas_core]->ztrsm_kernel_LC
#define	ZTRSM_KERNEL_RN		openblas_ztrsm_dispatch[openblas_core]->ztrsm_kernel_RN
#define	ZTRSM_KERNEL_RT		openblas_ztrsm_dispatch[openblas_core]->ztrsm_kernel_RT
#define	ZTRSM_KERNEL_RR		openblas_ztrsm_dispatch[openblas_core]->ztrsm_kernel_RR
#define	ZTRSM_KERNEL_RC		openblas_ztrsm_dispatch[openblas_core]->ztrsm_kernel_RC

#define	ZSYMM_IUTCOPY		openblas_zsymm_dispatch[openblas_core]->zsymm_iutcopy
#define	ZSYMM_ILTCOPY		openblas_zsymm_dispatch[openblas_core]->zsymm_iltcopy
#define	ZSYMM_OUTCOPY		openblas_zsymm_dispatch[openblas_core]->zsymm_outcopy
#define	ZSYMM_OLTCOPY		openblas_zsymm_dispatch[openblas_core]->zsymm_oltcopy

#define	ZHEMM_OUTCOPY		openblas_zhemm_dispatch[openblas_core]->zhemm_outcopy
#define	ZHEMM_OLTCOPY		openblas_zhemm_dispatch[openblas_core]->zhemm_oltcopy
#define	ZHEMM_IUTCOPY		openblas_zhemm_dispatch[openblas_core]->zhemm_iutcopy
#define	ZHEMM_ILTCOPY		openblas_zhemm_dispatch[openblas_core]->zhemm_iltcopy

#define	ZGEMM3M_ONCOPYB		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_oncopyb
#define	ZGEMM3M_ONCOPYR		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_oncopyr
#define	ZGEMM3M_ONCOPYI		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_oncopyi
#define	ZGEMM3M_OTCOPYB		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_otcopyb
#define	ZGEMM3M_OTCOPYR		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_otcopyr
#define	ZGEMM3M_OTCOPYI		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_otcopyi

#define	ZGEMM3M_INCOPYB		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_incopyb
#define	ZGEMM3M_INCOPYR		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_incopyr
#define	ZGEMM3M_INCOPYI		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_incopyi
#define	ZGEMM3M_ITCOPYB		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_itcopyb
#define	ZGEMM3M_ITCOPYR		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_itcopyr
#define	ZGEMM3M_ITCOPYI		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_itcopyi

#define	ZSYMM3M_ILCOPYB		openblas_zsymm3m_dispatch[openblas_core]->zsymm3m_ilcopyb
#define	ZSYMM3M_IUCOPYB		openblas_zsymm3m_dispatch[openblas_core]->zsymm3m_iucopyb
#define	ZSYMM3M_ILCOPYR		openblas_zsymm3m_dispatch[openblas_core]->zsymm3m_ilcopyr
#define	ZSYMM3M_IUCOPYR		openblas_zsymm3m_dispatch[openblas_core]->zsymm3m_iucopyr
#define	ZSYMM3M_ILCOPYI		openblas_zsymm3m_dispatch[openblas_core]->zsymm3m_ilcopyi
#define	ZSYMM3M_IUCOPYI		openblas_zsymm3m_dispatch[openblas_core]->zsymm3m_iucopyi

#define	ZSYMM3M_OLCOPYB		openblas_zsymm3m_dispatch[openblas_core]->zsymm3m_olcopyb
#define	ZSYMM3M_OUCOPYB		openblas_zsymm3m_dispatch[openblas_core]->zsymm3m_oucopyb
#define	ZSYMM3M_OLCOPYR		openblas_zsymm3m_dispatch[openblas_core]->zsymm3m_olcopyr
#define	ZSYMM3M_OUCOPYR		openblas_zsymm3m_dispatch[openblas_core]->zsymm3m_oucopyr
#define	ZSYMM3M_OLCOPYI		openblas_zsymm3m_dispatch[openblas_core]->zsymm3m_olcopyi
#define	ZSYMM3M_OUCOPYI		openblas_zsymm3m_dispatch[openblas_core]->zsymm3m_oucopyi

#define	ZHEMM3M_ILCOPYB		openblas_zhemm3m_dispatch[openblas_core]->zhemm3m_ilcopyb
#define	ZHEMM3M_IUCOPYB		openblas_zhemm3m_dispatch[openblas_core]->zhemm3m_iucopyb
#define	ZHEMM3M_ILCOPYR		openblas_zhemm3m_dispatch[openblas_core]->zhemm3m_ilcopyr
#define	ZHEMM3M_IUCOPYR		openblas_zhemm3m_dispatch[openblas_core]->zhemm3m_iucopyr
#define	ZHEMM3M_ILCOPYI		openblas_zhemm3m_dispatch[openblas_core]->zhemm3m_ilcopyi
#define	ZHEMM3M_IUCOPYI		openblas_zhemm3m_dispatch[openblas_core]->zhemm3m_iucopyi

#define	ZHEMM3M_OLCOPYB		openblas_zhemm3m_dispatch[openblas_core]->zhemm3m_olcopyb
#define	ZHEMM3M_OUCOPYB		openblas_zhemm3m_dispatch[openblas_core]->zhemm3m_oucopyb
#define	ZHEMM3M_OLCOPYR		openblas_zhemm3m_dispatch[openblas_core]->zhemm3m_olcopyr
#define	ZHEMM3M_OUCOPYR		openblas_zhemm3m_dispatch[openblas_core]->zhemm3m_oucopyr
#define	ZHEMM3M_OLCOPYI		openblas_zhemm3m_dispatch[openblas_core]->zhemm3m_olcopyi
#define	ZHEMM3M_OUCOPYI		openblas_zhemm3m_dispatch[openblas_core]->zhemm3m_oucopyi

#define	ZGEMM3M_KERNEL		openblas_zgemm3m_dispatch[openblas_core]->zgemm3m_kernel

#define ZNEG_TCOPY		openblas_zneg_dispatch[openblas_core]->zneg_tcopy
#define ZLASWP_NCOPY		openblas_zlaswp_dispatch[openblas_core]->zlaswp_ncopy

#define ZAXPBY_K                openblas_zaxpby_dispatch[openblas_core]->zaxpby_k

#define ZOMATCOPY_K_CN          openblas_zomatcopy_dispatch[openblas_core]->zomatcopy_k_cn
#define ZOMATCOPY_K_RN          openblas_zomatcopy_dispatch[openblas_core]->zomatcopy_k_rn
#define ZOMATCOPY_K_CT          openblas_zomatcopy_dispatch[openblas_core]->zomatcopy_k_ct
#define ZOMATCOPY_K_RT          openblas_zomatcopy_dispatch[openblas_core]->zomatcopy_k_rt
#define ZOMATCOPY_K_CNC         openblas_zomatcopy_dispatch[openblas_core]->zomatcopy_k_cnc
#define ZOMATCOPY_K_RNC         openblas_zomatcopy_dispatch[openblas_core]->zomatcopy_k_rnc
#define ZOMATCOPY_K_CTC         openblas_zomatcopy_dispatch[openblas_core]->zomatcopy_k_ctc
#define ZOMATCOPY_K_RTC         openblas_zomatcopy_dispatch[openblas_core]->zomatcopy_k_rtc

#define ZIMATCOPY_K_CN          openblas_zimatcopy_dispatch[openblas_core]->zimatcopy_k_cn
#define ZIMATCOPY_K_RN          openblas_zimatcopy_dispatch[openblas_core]->zimatcopy_k_rn
#define ZIMATCOPY_K_CT          openblas_zimatcopy_dispatch[openblas_core]->zimatcopy_k_ct
#define ZIMATCOPY_K_RT          openblas_zimatcopy_dispatch[openblas_core]->zimatcopy_k_rt
#define ZIMATCOPY_K_CNC         openblas_zimatcopy_dispatch[openblas_core]->zimatcopy_k_cnc
#define ZIMATCOPY_K_RNC         openblas_zimatcopy_dispatch[openblas_core]->zimatcopy_k_rnc
#define ZIMATCOPY_K_CTC         openblas_zimatcopy_dispatch[openblas_core]->zimatcopy_k_ctc
#define ZIMATCOPY_K_RTC         openblas_zimatcopy_dispatch[openblas_core]->zimatcopy_k_rtc

#define ZGEADD_K                openblas_zgeadd_dispatch[openblas_core]->zgeadd_k

#define ZGEMM_SMALL_MATRIX_PERMIT	openblas_zgemm_dispatch[openblas_core]->zgemm_small_matrix_permit

#endif

#define	ZGEMM_SMALL_KERNEL_BASE	OB_SLOT_BASE(zgemm)
#define ZGEMM_SMALL_KERNEL_NN		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_nn)
#define ZGEMM_SMALL_KERNEL_NT		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_nt)
#define ZGEMM_SMALL_KERNEL_NR		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_nr)
#define ZGEMM_SMALL_KERNEL_NC		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_nc)

#define ZGEMM_SMALL_KERNEL_TN		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_tn)
#define ZGEMM_SMALL_KERNEL_TT		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_tt)
#define ZGEMM_SMALL_KERNEL_TR		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_tr)
#define ZGEMM_SMALL_KERNEL_TC		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_tc)

#define ZGEMM_SMALL_KERNEL_RN		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_rn)
#define ZGEMM_SMALL_KERNEL_RT		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_rt)
#define ZGEMM_SMALL_KERNEL_RR		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_rr)
#define ZGEMM_SMALL_KERNEL_RC		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_rc)

#define ZGEMM_SMALL_KERNEL_CN		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_cn)
#define ZGEMM_SMALL_KERNEL_CT		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_ct)
#define ZGEMM_SMALL_KERNEL_CR		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_cr)
#define ZGEMM_SMALL_KERNEL_CC		OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_cc)

#define ZGEMM_SMALL_KERNEL_B0_NN	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_nn)
#define ZGEMM_SMALL_KERNEL_B0_NT	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_nt)
#define ZGEMM_SMALL_KERNEL_B0_NR	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_nr)
#define ZGEMM_SMALL_KERNEL_B0_NC	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_nc)

#define ZGEMM_SMALL_KERNEL_B0_TN	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_tn)
#define ZGEMM_SMALL_KERNEL_B0_TT	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_tt)
#define ZGEMM_SMALL_KERNEL_B0_TR	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_tr)
#define ZGEMM_SMALL_KERNEL_B0_TC	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_tc)

#define ZGEMM_SMALL_KERNEL_B0_RN	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_rn)
#define ZGEMM_SMALL_KERNEL_B0_RT	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_rt)
#define ZGEMM_SMALL_KERNEL_B0_RR	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_rr)
#define ZGEMM_SMALL_KERNEL_B0_RC	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_rc)

#define ZGEMM_SMALL_KERNEL_B0_CN	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_cn)
#define ZGEMM_SMALL_KERNEL_B0_CT	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_ct)
#define ZGEMM_SMALL_KERNEL_B0_CR	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_cr)
#define ZGEMM_SMALL_KERNEL_B0_CC	OB_SLOT_OFFSET(zgemm, zgemm_small_kernel_b0_cc)


#define	ZGEMM_NN		zgemm_nn
#define	ZGEMM_CN		zgemm_cn
#define	ZGEMM_TN		zgemm_tn
#define	ZGEMM_NC		zgemm_nc
#define	ZGEMM_NT		zgemm_nt
#define	ZGEMM_CC		zgemm_cc
#define	ZGEMM_CT		zgemm_ct
#define	ZGEMM_TC		zgemm_tc
#define	ZGEMM_TT		zgemm_tt
#define	ZGEMM_NR		zgemm_nr
#define	ZGEMM_TR		zgemm_tr
#define	ZGEMM_CR		zgemm_cr
#define	ZGEMM_RN		zgemm_rn
#define	ZGEMM_RT		zgemm_rt
#define	ZGEMM_RC		zgemm_rc
#define	ZGEMM_RR		zgemm_rr

#define	ZSYMM_LU		zsymm_LU
#define	ZSYMM_LL		zsymm_LL
#define	ZSYMM_RU		zsymm_RU
#define	ZSYMM_RL		zsymm_RL

#define	ZHEMM_LU		zhemm_LU
#define	ZHEMM_LL		zhemm_LL
#define	ZHEMM_RU		zhemm_RU
#define	ZHEMM_RL		zhemm_RL

#define	ZSYRK_UN		zsyrk_UN
#define	ZSYRK_UT		zsyrk_UT
#define	ZSYRK_LN		zsyrk_LN
#define	ZSYRK_LT		zsyrk_LT
#define	ZSYRK_UR		zsyrk_UN
#define	ZSYRK_UC		zsyrk_UT
#define	ZSYRK_LR		zsyrk_LN
#define	ZSYRK_LC		zsyrk_LT

#define	ZSYRK_KERNEL_U		zsyrk_kernel_U
#define	ZSYRK_KERNEL_L		zsyrk_kernel_L

#define	ZHERK_UN		zherk_UN
#define	ZHERK_LN		zherk_LN
#define	ZHERK_UC		zherk_UC
#define	ZHERK_LC		zherk_LC

#define	ZHER2K_UN		zher2k_UN
#define	ZHER2K_LN		zher2k_LN
#define	ZHER2K_UC		zher2k_UC
#define	ZHER2K_LC		zher2k_LC

#define	ZSYR2K_UN		zsyr2k_UN
#define	ZSYR2K_UT		zsyr2k_UT
#define	ZSYR2K_LN		zsyr2k_LN
#define	ZSYR2K_LT		zsyr2k_LT
#define	ZSYR2K_UR		zsyr2k_UN
#define	ZSYR2K_UC		zsyr2k_UT
#define	ZSYR2K_LR		zsyr2k_LN
#define	ZSYR2K_LC		zsyr2k_LT

#define	ZSYR2K_KERNEL_U		zsyr2k_kernel_U
#define	ZSYR2K_KERNEL_L		zsyr2k_kernel_L

#define	ZTRMM_LNUU		ztrmm_LNUU
#define	ZTRMM_LNUN		ztrmm_LNUN
#define	ZTRMM_LNLU		ztrmm_LNLU
#define	ZTRMM_LNLN		ztrmm_LNLN
#define	ZTRMM_LTUU		ztrmm_LTUU
#define	ZTRMM_LTUN		ztrmm_LTUN
#define	ZTRMM_LTLU		ztrmm_LTLU
#define	ZTRMM_LTLN		ztrmm_LTLN
#define	ZTRMM_LRUU		ztrmm_LRUU
#define	ZTRMM_LRUN		ztrmm_LRUN
#define	ZTRMM_LRLU		ztrmm_LRLU
#define	ZTRMM_LRLN		ztrmm_LRLN
#define	ZTRMM_LCUU		ztrmm_LCUU
#define	ZTRMM_LCUN		ztrmm_LCUN
#define	ZTRMM_LCLU		ztrmm_LCLU
#define	ZTRMM_LCLN		ztrmm_LCLN
#define	ZTRMM_RNUU		ztrmm_RNUU
#define	ZTRMM_RNUN		ztrmm_RNUN
#define	ZTRMM_RNLU		ztrmm_RNLU
#define	ZTRMM_RNLN		ztrmm_RNLN
#define	ZTRMM_RTUU		ztrmm_RTUU
#define	ZTRMM_RTUN		ztrmm_RTUN
#define	ZTRMM_RTLU		ztrmm_RTLU
#define	ZTRMM_RTLN		ztrmm_RTLN
#define	ZTRMM_RRUU		ztrmm_RRUU
#define	ZTRMM_RRUN		ztrmm_RRUN
#define	ZTRMM_RRLU		ztrmm_RRLU
#define	ZTRMM_RRLN		ztrmm_RRLN
#define	ZTRMM_RCUU		ztrmm_RCUU
#define	ZTRMM_RCUN		ztrmm_RCUN
#define	ZTRMM_RCLU		ztrmm_RCLU
#define	ZTRMM_RCLN		ztrmm_RCLN

#define	ZTRSM_LNUU		ztrsm_LNUU
#define	ZTRSM_LNUN		ztrsm_LNUN
#define	ZTRSM_LNLU		ztrsm_LNLU
#define	ZTRSM_LNLN		ztrsm_LNLN
#define	ZTRSM_LTUU		ztrsm_LTUU
#define	ZTRSM_LTUN		ztrsm_LTUN
#define	ZTRSM_LTLU		ztrsm_LTLU
#define	ZTRSM_LTLN		ztrsm_LTLN
#define	ZTRSM_LRUU		ztrsm_LRUU
#define	ZTRSM_LRUN		ztrsm_LRUN
#define	ZTRSM_LRLU		ztrsm_LRLU
#define	ZTRSM_LRLN		ztrsm_LRLN
#define	ZTRSM_LCUU		ztrsm_LCUU
#define	ZTRSM_LCUN		ztrsm_LCUN
#define	ZTRSM_LCLU		ztrsm_LCLU
#define	ZTRSM_LCLN		ztrsm_LCLN
#define	ZTRSM_RNUU		ztrsm_RNUU
#define	ZTRSM_RNUN		ztrsm_RNUN
#define	ZTRSM_RNLU		ztrsm_RNLU
#define	ZTRSM_RNLN		ztrsm_RNLN
#define	ZTRSM_RTUU		ztrsm_RTUU
#define	ZTRSM_RTUN		ztrsm_RTUN
#define	ZTRSM_RTLU		ztrsm_RTLU
#define	ZTRSM_RTLN		ztrsm_RTLN
#define	ZTRSM_RRUU		ztrsm_RRUU
#define	ZTRSM_RRUN		ztrsm_RRUN
#define	ZTRSM_RRLU		ztrsm_RRLU
#define	ZTRSM_RRLN		ztrsm_RRLN
#define	ZTRSM_RCUU		ztrsm_RCUU
#define	ZTRSM_RCUN		ztrsm_RCUN
#define	ZTRSM_RCLU		ztrsm_RCLU
#define	ZTRSM_RCLN		ztrsm_RCLN

#define	ZGEMM_THREAD_NN		zgemm_thread_nn
#define	ZGEMM_THREAD_CN		zgemm_thread_cn
#define	ZGEMM_THREAD_TN		zgemm_thread_tn
#define	ZGEMM_THREAD_NC		zgemm_thread_nc
#define	ZGEMM_THREAD_NT		zgemm_thread_nt
#define	ZGEMM_THREAD_CC		zgemm_thread_cc
#define	ZGEMM_THREAD_CT		zgemm_thread_ct
#define	ZGEMM_THREAD_TC		zgemm_thread_tc
#define	ZGEMM_THREAD_TT		zgemm_thread_tt
#define	ZGEMM_THREAD_NR		zgemm_thread_nr
#define	ZGEMM_THREAD_TR		zgemm_thread_tr
#define	ZGEMM_THREAD_CR		zgemm_thread_cr
#define	ZGEMM_THREAD_RN		zgemm_thread_rn
#define	ZGEMM_THREAD_RT		zgemm_thread_rt
#define	ZGEMM_THREAD_RC		zgemm_thread_rc
#define	ZGEMM_THREAD_RR		zgemm_thread_rr

#define	ZSYMM_THREAD_LU		zsymm_thread_LU
#define	ZSYMM_THREAD_LL		zsymm_thread_LL
#define	ZSYMM_THREAD_RU		zsymm_thread_RU
#define	ZSYMM_THREAD_RL		zsymm_thread_RL

#define	ZHEMM_THREAD_LU		zhemm_thread_LU
#define	ZHEMM_THREAD_LL		zhemm_thread_LL
#define	ZHEMM_THREAD_RU		zhemm_thread_RU
#define	ZHEMM_THREAD_RL		zhemm_thread_RL

#define	ZSYRK_THREAD_UN		zsyrk_thread_UN
#define	ZSYRK_THREAD_UT		zsyrk_thread_UT
#define	ZSYRK_THREAD_LN		zsyrk_thread_LN
#define	ZSYRK_THREAD_LT		zsyrk_thread_LT
#define	ZSYRK_THREAD_UR		zsyrk_thread_UN
#define	ZSYRK_THREAD_UC		zsyrk_thread_UT
#define	ZSYRK_THREAD_LR		zsyrk_thread_LN
#define	ZSYRK_THREAD_LC		zsyrk_thread_LT

#define	ZHERK_THREAD_UN		zherk_thread_UN
#define	ZHERK_THREAD_UT		zherk_thread_UT
#define	ZHERK_THREAD_LN		zherk_thread_LN
#define	ZHERK_THREAD_LT		zherk_thread_LT
#define	ZHERK_THREAD_UR		zherk_thread_UR
#define	ZHERK_THREAD_UC		zherk_thread_UC
#define	ZHERK_THREAD_LR		zherk_thread_LR
#define	ZHERK_THREAD_LC		zherk_thread_LC

#define	ZGEMM3M_NN		zgemm3m_nn
#define	ZGEMM3M_CN		zgemm3m_cn
#define	ZGEMM3M_TN		zgemm3m_tn
#define	ZGEMM3M_NC		zgemm3m_nc
#define	ZGEMM3M_NT		zgemm3m_nt
#define	ZGEMM3M_CC		zgemm3m_cc
#define	ZGEMM3M_CT		zgemm3m_ct
#define	ZGEMM3M_TC		zgemm3m_tc
#define	ZGEMM3M_TT		zgemm3m_tt
#define	ZGEMM3M_NR		zgemm3m_nr
#define	ZGEMM3M_TR		zgemm3m_tr
#define	ZGEMM3M_CR		zgemm3m_cr
#define	ZGEMM3M_RN		zgemm3m_rn
#define	ZGEMM3M_RT		zgemm3m_rt
#define	ZGEMM3M_RC		zgemm3m_rc
#define	ZGEMM3M_RR		zgemm3m_rr

#define	ZGEMM3M_THREAD_NN	zgemm3m_thread_nn
#define	ZGEMM3M_THREAD_CN	zgemm3m_thread_cn
#define	ZGEMM3M_THREAD_TN	zgemm3m_thread_tn
#define	ZGEMM3M_THREAD_NC	zgemm3m_thread_nc
#define	ZGEMM3M_THREAD_NT	zgemm3m_thread_nt
#define	ZGEMM3M_THREAD_CC	zgemm3m_thread_cc
#define	ZGEMM3M_THREAD_CT	zgemm3m_thread_ct
#define	ZGEMM3M_THREAD_TC	zgemm3m_thread_tc
#define	ZGEMM3M_THREAD_TT	zgemm3m_thread_tt
#define	ZGEMM3M_THREAD_NR	zgemm3m_thread_nr
#define	ZGEMM3M_THREAD_TR	zgemm3m_thread_tr
#define	ZGEMM3M_THREAD_CR	zgemm3m_thread_cr
#define	ZGEMM3M_THREAD_RN	zgemm3m_thread_rn
#define	ZGEMM3M_THREAD_RT	zgemm3m_thread_rt
#define	ZGEMM3M_THREAD_RC	zgemm3m_thread_rc
#define	ZGEMM3M_THREAD_RR	zgemm3m_thread_rr

#define	ZSYMM3M_LU		zsymm3m_LU
#define	ZSYMM3M_LL		zsymm3m_LL
#define	ZSYMM3M_RU		zsymm3m_RU
#define	ZSYMM3M_RL		zsymm3m_RL

#define	ZSYMM3M_THREAD_LU	zsymm3m_thread_LU
#define	ZSYMM3M_THREAD_LL	zsymm3m_thread_LL
#define	ZSYMM3M_THREAD_RU	zsymm3m_thread_RU
#define	ZSYMM3M_THREAD_RL	zsymm3m_thread_RL

#define	ZHEMM3M_LU		zhemm3m_LU
#define	ZHEMM3M_LL		zhemm3m_LL
#define	ZHEMM3M_RU		zhemm3m_RU
#define	ZHEMM3M_RL		zhemm3m_RL

#define	ZHEMM3M_THREAD_LU	zhemm3m_thread_LU
#define	ZHEMM3M_THREAD_LL	zhemm3m_thread_LL
#define	ZHEMM3M_THREAD_RU	zhemm3m_thread_RU
#define	ZHEMM3M_THREAD_RL	zhemm3m_thread_RL

#endif
