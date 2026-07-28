#include "common.h"
#include "cpuid_zarch.h"
#include <stdbool.h>
#ifdef DYN_Z13
#endif
#ifdef DYN_Z14
#endif

#define NUM_CORETYPES 4

extern int openblas_verbose(void);
extern void openblas_warning(int verbose, const char* msg);

char* gotoblas_corename(void) {
#ifdef DYN_Z13
	if (openblas_core == OPENBLAS_CORE_Z13)	return cpuname[CPU_Z13];
#endif
#ifdef DYN_Z14
	if (openblas_core == OPENBLAS_CORE_Z14)	return cpuname[CPU_Z14];
#endif
	if (openblas_core == OPENBLAS_CORE_ZARCH_GENERIC) return cpuname[CPU_GENERIC];

	return "unknown";
}

#ifndef HWCAP_S390_VXE
#define HWCAP_S390_VXE 8192
#endif

/**
 * Detect the fitting set of kernels by retrieving the CPU features supported by
 * OS from the auxiliary value AT_HWCAP and choosing the set of kernels
 * ("coretype") that exploits most of the features and can be compiled with the
 * available gcc version.
 * Note that we cannot use vector registers on a z13 or newer unless supported
 * by the OS kernel (which needs to handle them properly during context switch).
 */
static int get_coretype(void) {

	int cpu = detect();

	switch(cpu) {
	// z14 and z15 systems: exploit Vector Facility (SIMD) and
	// Vector-Enhancements Facility 1 (float SIMD instructions), if present.
	case CPU_Z14:
#ifdef DYN_Z14
		return OPENBLAS_CORE_Z14;
#endif

	// z13: Vector Facility (SIMD for double)
	case CPU_Z13:
#ifdef DYN_Z13
		return OPENBLAS_CORE_Z13;
#endif

	default:
	// fallback in case of missing compiler support, systems before z13, or
	// when the OS does not advertise support for the Vector Facility (e.g.,
	// missing support in the OS kernel)
		return OPENBLAS_CORE_ZARCH_GENERIC;
	}
}

static int force_coretype(char* coretype) {

	int i;
	int found = -1;
	char message[128];

	for (i = 0; i < NUM_CORETYPES; i++)
	{
		if (!strncasecmp(coretype, cpuname[i], 20))
		{
			found = i;
			break;
		}
	}

	if (found == CPU_Z13) {
#ifdef DYN_Z13
		return OPENBLAS_CORE_Z13;
#else
		openblas_warning(1, "Z13 support not compiled in");
		return -1;
#endif
	} else if (found == CPU_Z14) {
#ifdef DYN_Z14
		return OPENBLAS_CORE_Z14;
#else
		openblas_warning(1, "Z14 support not compiled in");
		return -1;
#endif
	} else if (found == CPU_GENERIC) {
		return OPENBLAS_CORE_ZARCH_GENERIC;
	}

	snprintf(message, 128, "Core not found: %s\n", coretype);
	openblas_warning(1, message);
	return -1;
}

void gotoblas_dynamic_init(void) {

	char coremsg[128];
	char coren[22];
	char* p;


	if (openblas_core >= 0) return;

	p = getenv("OPENBLAS_CORETYPE");
	if (p)
	{
		openblas_core = force_coretype(p);
	}
	else
	{
		openblas_core = get_coretype();
		if (openblas_verbose() >= 2) {
			snprintf(coremsg, sizeof(coremsg), "Choosing kernels based on getauxval(AT_HWCAP)=0x%lx\n",
				 getauxval(AT_HWCAP));
			openblas_warning(2, coremsg);
		}
	}

	if (openblas_core < 0)
	{
		snprintf(coremsg, 128, "Failed to detect system, falling back to generic z support.\n");
		openblas_warning(1, coremsg);
		openblas_core = OPENBLAS_CORE_ZARCH_GENERIC;
	}

	if (openblas_core >= 0 && openblas_params_tab[openblas_core]->init) {
		if (openblas_verbose() >= 2) {
			strncpy(coren, gotoblas_corename(), 20);
			sprintf(coremsg, "Core: %s\n", coren);
			openblas_warning(2, coremsg);
		}
		openblas_params_tab[openblas_core]->init();
	}
	else {
		openblas_warning(0, "OpenBLAS : Architecture Initialization failed. No initialization function found.\n");
		exit(1);
	}
}

void gotoblas_dynamic_quit(void) {
	openblas_core = -1;
}
