/*********************************************************************/
/* Copyright 2009, 2010 The University of Texas at Austin.           */
/* Copyright 2023-2024, 2026 The OpenBLAS Project                    */
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

#include "common.h"

#ifndef _MSC_VER
#include <strings.h>
#else
#define strncasecmp _strnicmp
#endif

#if (defined OS_LINUX || defined OS_ANDROID)
#include <asm/hwcap.h>
#include <sys/auxv.h>
#endif

#ifdef __APPLE__
#include <sys/sysctl.h>
int32_t value;
size_t length=sizeof(value);
int64_t value64;
size_t length64=sizeof(value64);
#endif
#ifdef DYNAMIC_LIST
#ifdef DYN_CORTEXA53
#else
#define OPENBLAS_CORE_CORTEXA53 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_CORTEXA57
#else
#define OPENBLAS_CORE_CORTEXA57 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_CORTEXA72
#else
#define OPENBLAS_CORE_CORTEXA72 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_CORTEXA73
#else
#define OPENBLAS_CORE_CORTEXA73 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_FALKOR
#else
#define OPENBLAS_CORE_FALKOR OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_TSV110
#else
#define OPENBLAS_CORE_TSV110 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_THUNDERX
#else
#define OPENBLAS_CORE_THUNDERX OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_THUNDERX2T99
#else
#define OPENBLAS_CORE_THUNDERX2T99 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_THUNDERX3T110
#else
#define OPENBLAS_CORE_THUNDERX3T110 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_EMAG8180
#else
#define OPENBLAS_CORE_EMAG8180 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_NEOVERSEN1
#else
#define OPENBLAS_CORE_NEOVERSEN1 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_NEOVERSEV1
#else
#define OPENBLAS_CORE_NEOVERSEV1 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_NEOVERSEN2
#else
#define OPENBLAS_CORE_NEOVERSEN2 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_ARMV8SVE
#else
#define OPENBLAS_CORE_ARMV8SVE OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_ARMV9SME
#else
#define OPENBLAS_CORE_ARMV9SME OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_VORTEX
#elif defined(DYN_NEOVERSEN1)
#define OPENBLAS_CORE_VORTEX OPENBLAS_CORE_NEOVERSEN1
#else
#define OPENBLAS_CORE_VORTEX OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_VORTEXM4
#else
#define OPENBLAS_CORE_VORTEXM4 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_CORTEXA55
#else
#define OPENBLAS_CORE_CORTEXA55 OPENBLAS_CORE_ARMV8
#endif
#ifdef DYN_A64FX
#else
#define OPENBLAS_CORE_A64FX OPENBLAS_CORE_ARMV8
#endif

#else //not a user-specified dynamic_list

#ifdef OS_DARWIN
#define OPENBLAS_CORE_CORTEXA53 OPENBLAS_CORE_ARMV8
#else
#endif
#define OPENBLAS_CORE_CORTEXA55 OPENBLAS_CORE_CORTEXA53
#ifdef OS_DARWIN
#define OPENBLAS_CORE_CORTEXA57 OPENBLAS_CORE_ARMV8
#else
#endif
#define OPENBLAS_CORE_CORTEXA72 OPENBLAS_CORE_CORTEXA57
#define OPENBLAS_CORE_CORTEXA73 OPENBLAS_CORE_CORTEXA57
#define OPENBLAS_CORE_FALKOR OPENBLAS_CORE_CORTEXA57
#ifdef OS_DARWIN
#define OPENBLAS_CORE_THUNDERX OPENBLAS_CORE_ARMV8
#define OPENBLAS_CORE_THUNDERX2T99 OPENBLAS_CORE_ARMV8
#define OPENBLAS_CORE_THUNDERX3T110 OPENBLAS_CORE_ARMV8
#define OPENBLAS_CORE_TSV110 OPENBLAS_CORE_ARMV8
#define OPENBLAS_CORE_EMAG8180 OPENBLAS_CORE_ARMV8
#else
#endif
#define OPENBLAS_CORE_VORTEX OPENBLAS_CORE_NEOVERSEN1
#ifndef OS_DARWIN
#ifndef NO_SVE
#else
#define OPENBLAS_CORE_NEOVERSEV1 OPENBLAS_CORE_ARMV8
#define OPENBLAS_CORE_NEOVERSEN2 OPENBLAS_CORE_ARMV8
#define OPENBLAS_CORE_ARMV8SVE OPENBLAS_CORE_ARMV8
#define OPENBLAS_CORE_A64FX OPENBLAS_CORE_ARMV8
#endif
#else
#define OPENBLAS_CORE_NEOVERSEV1 OPENBLAS_CORE_ARMV8
#define OPENBLAS_CORE_NEOVERSEN2 OPENBLAS_CORE_ARMV8
#define OPENBLAS_CORE_ARMV8SVE OPENBLAS_CORE_ARMV8
#define OPENBLAS_CORE_A64FX OPENBLAS_CORE_ARMV8
#endif
#ifndef NO_SME
#if defined (__clang__) && defined(OS_DARWIN)
#else
#define OPENBLAS_CORE_VORTEXM4 OPENBLAS_CORE_NEOVERSEN1
#endif
#else
#ifndef NO_SVE
#define OPENBLAS_CORE_ARMV9SME OPENBLAS_CORE_ARMV8SVE
#else
#define OPENBLAS_CORE_ARMV9SME OPENBLAS_CORE_NEOVERSEN1
#endif
#define OPENBLAS_CORE_VORTEXM4 OPENBLAS_CORE_NEOVERSEN1
#endif

#endif
#define OPENBLAS_CORE_NEOVERSEV2 OPENBLAS_CORE_NEOVERSEN2

extern void openblas_warning(int verbose, const char * msg);
#define FALLBACK_VERBOSE 1
#define NEOVERSEN1_FALLBACK "OpenBLAS : Your OS does not support SVE instructions. OpenBLAS is using Neoverse N1 kernels as a fallback, which may give poorer performance.\n"

#define NUM_CORETYPES   21

/*
 * In case asm/hwcap.h is outdated on the build system, make sure
 * that HWCAP_CPUID is defined 
 */
#ifndef HWCAP_CPUID
#define HWCAP_CPUID (1 << 11)
#endif
#ifndef HWCAP_SVE
#define HWCAP_SVE (1 << 22)
#endif
#ifndef HWCAP2_SME
#define HWCAP2_SME 1<<23
#endif

#define get_cpu_ftr(id, var) ({					\
		__asm__ __volatile__ ("mrs %0, "#id : "=r" (var));		\
	})

static char *corename[] = {
  "armv8",
  "cortexa53",
  "cortexa57",
  "cortexa72",
  "cortexa73",
  "falkor",
  "thunderx",
  "thunderx2t99",
  "tsv110",
  "emag8180",
  "neoversen1",
  "neoversev1",
  "neoversev2",
  "neoversen2",
  "thunderx3t110",
  "cortexa55",
  "armv8sve",
  "a64fx",
  "armv9sme",
  "vortex",
  "vortexm4",
  "unknown"
};

char *gotoblas_corename(void) {
  if (openblas_core == OPENBLAS_CORE_ARMV8)        return corename[ 0];
  if (openblas_core == OPENBLAS_CORE_CORTEXA53)    return corename[ 1];
  if (openblas_core == OPENBLAS_CORE_CORTEXA57)    return corename[ 2];
  if (openblas_core == OPENBLAS_CORE_CORTEXA72)    return corename[ 3];
  if (openblas_core == OPENBLAS_CORE_CORTEXA73)    return corename[ 4];
  if (openblas_core == OPENBLAS_CORE_FALKOR)       return corename[ 5];
  if (openblas_core == OPENBLAS_CORE_THUNDERX)     return corename[ 6];
  if (openblas_core == OPENBLAS_CORE_THUNDERX2T99) return corename[ 7];
  if (openblas_core == OPENBLAS_CORE_TSV110)       return corename[ 8];
  if (openblas_core == OPENBLAS_CORE_EMAG8180)     return corename[ 9];
  if (openblas_core == OPENBLAS_CORE_NEOVERSEN1)   return corename[10];
  if (openblas_core == OPENBLAS_CORE_NEOVERSEV1)   return corename[11];
  if (openblas_core == OPENBLAS_CORE_NEOVERSEV2)   return corename[12];
  if (openblas_core == OPENBLAS_CORE_NEOVERSEN2)   return corename[13];
  if (openblas_core == OPENBLAS_CORE_THUNDERX3T110) return corename[14];
  if (openblas_core == OPENBLAS_CORE_CORTEXA55)    return corename[15];
  if (openblas_core == OPENBLAS_CORE_ARMV8SVE)     return corename[16];
  if (openblas_core == OPENBLAS_CORE_A64FX)        return corename[17];
  if (openblas_core == OPENBLAS_CORE_ARMV9SME)     return corename[18];
  if (openblas_core == OPENBLAS_CORE_VORTEX)     return corename[19];
  if (openblas_core == OPENBLAS_CORE_VORTEXM4)     return corename[20];
  return corename[NUM_CORETYPES];
}

static int force_coretype(char *coretype) {
  int i ;
  int found = -1;
  char message[128];

  for ( i=0 ; i < NUM_CORETYPES; i++)
  {
    if (!strncasecmp(coretype, corename[i], 20))
    {
        found = i;
        break;
    }
  }

  switch (found)
  {
    case  0: return OPENBLAS_CORE_ARMV8;
    case  1: return OPENBLAS_CORE_CORTEXA53;
    case  2: return OPENBLAS_CORE_CORTEXA57;
    case  3: return OPENBLAS_CORE_CORTEXA72;
    case  4: return OPENBLAS_CORE_CORTEXA73;
    case  5: return OPENBLAS_CORE_FALKOR;
    case  6: return OPENBLAS_CORE_THUNDERX;
    case  7: return OPENBLAS_CORE_THUNDERX2T99;
    case  8: return OPENBLAS_CORE_TSV110;
    case  9: return OPENBLAS_CORE_EMAG8180;
    case 10: return OPENBLAS_CORE_NEOVERSEN1;
    case 11: return OPENBLAS_CORE_NEOVERSEV1;
    case 12: return OPENBLAS_CORE_NEOVERSEV2;
    case 13: return OPENBLAS_CORE_NEOVERSEN2;
    case 14: return OPENBLAS_CORE_THUNDERX3T110;
    case 15: return OPENBLAS_CORE_CORTEXA55;
    case 16: return OPENBLAS_CORE_ARMV8SVE;
    case 17: return OPENBLAS_CORE_A64FX;
    case 18: return OPENBLAS_CORE_ARMV9SME;
    case 19: return OPENBLAS_CORE_VORTEX;
    case 20: return OPENBLAS_CORE_VORTEXM4;
  }
  snprintf(message, 128, "Core not found: %s\n", coretype);
  openblas_warning(1, message);
  return -1;
}

static int get_coretype(void) {
  int implementer, variant, part, arch, revision, midr_el1;
  char coremsg[128];

#if defined (OS_DARWIN)
#if !defined(NO_SME)
  if (support_sme1()) {
   	return OPENBLAS_CORE_VORTEXM4;
  }
#endif
  return OPENBLAS_CORE_VORTEX;
#endif
	
#if (!defined OS_LINUX && !defined OS_ANDROID)
  return -1;
#else

  if (!(getauxval(AT_HWCAP) & HWCAP_CPUID)) {
#ifdef __linux
	int i;
        int ncores=0;
	int prt,cpucap,cpulowperf=0,cpumidperf=0,cpuhiperf=0;
        FILE *infile;
        char buffer[512], *cpu_part = NULL, *cpu_implementer = NULL;

	infile = fopen("/sys/devices/system/cpu/possible","r");
	if (infile) {
		(void)fgets(buffer, sizeof(buffer), infile);
		sscanf(buffer,"0-%d",&ncores);
		fclose (infile);
		ncores++;
	} else {
		infile = fopen("/proc/cpuinfo","r");
                while (fgets(buffer, sizeof(buffer), infile)) {
                        if (!strncmp("processor", buffer, 9))
                        ncores++;
		}
	}
	for (i=0;i<ncores;i++) {
		sprintf(buffer,"/sys/devices/system/cpu/cpu%d/regs/identification/midr_el1",i);
		infile = fopen(buffer,"r");
		if (!infile) return -1;
		(void)fgets(buffer, sizeof(buffer), infile);
		midr_el1=strtoul(buffer,NULL,16);
  		implementer = (midr_el1 >> 24) & 0xFF;
  		prt        = (midr_el1 >> 4)  & 0xFFF;
		fclose(infile);
		sprintf(buffer,"/sys/devices/system/cpu/cpu%d/cpu_capability",i);
		infile = fopen(buffer,"r");
		if (infile) {
			(void)fgets(buffer, sizeof(buffer), infile);
			cpucap=strtoul(buffer,NULL,16);
			fclose(infile);
			if (cpucap >= 1000) cpuhiperf++;
			else if (cpucap >=500) cpumidperf++;
			else cpulowperf++;
			if (cpucap >=1000) part = prt;
		} else if (implementer == 0x41 ){
			if (prt >= 0xd4b) cpuhiperf++;
			else if (prt>= 0xd07) cpumidperf++;
			else cpulowperf++;
		} else cpulowperf++;
	}
	if (!part) part = prt;
#else	
    snprintf(coremsg, 128, "Kernel lacks cpuid feature support. Auto detection of core type failed !!!\n");
    openblas_warning(1, coremsg);
    return -1;
#endif
  } else {
    get_cpu_ftr(MIDR_EL1, midr_el1);
  
  /*
   * MIDR_EL1
   *
   * 31          24 23     20 19          16 15          4 3        0
   * -----------------------------------------------------------------
   * | Implementer | Variant | Architecture | Part Number | Revision |
   * -----------------------------------------------------------------
   */
  implementer = (midr_el1 >> 24) & 0xFF;
  part        = (midr_el1 >> 4)  & 0xFFF;
  }
  switch(implementer)
  {
    case 0x41: // ARM
      switch (part)
      {
        case 0xd03: // Cortex A53
          return OPENBLAS_CORE_CORTEXA53;
        case 0xd07: // Cortex A57
          return OPENBLAS_CORE_CORTEXA57;
        case 0xd08: // Cortex A72
          return OPENBLAS_CORE_CORTEXA72;
        case 0xd09: // Cortex A73
	case 0xd0a: // Cortex A75
	case 0xd0b: // Cortex A76
          return OPENBLAS_CORE_CORTEXA73;
        case 0xd0c: // Neoverse N1
          return OPENBLAS_CORE_NEOVERSEN1;
#ifndef NO_SVE
        case 0xd49:
	  if (!(getauxval(AT_HWCAP) & HWCAP_SVE)) {
	    openblas_warning(FALLBACK_VERBOSE, NEOVERSEN1_FALLBACK);  
	    return OPENBLAS_CORE_NEOVERSEN1;
	  } else
            return OPENBLAS_CORE_NEOVERSEN2;
	case 0xd40:
	  if (!(getauxval(AT_HWCAP) & HWCAP_SVE)) {
		  openblas_warning(FALLBACK_VERBOSE, NEOVERSEN1_FALLBACK);
	    return OPENBLAS_CORE_NEOVERSEN1;
      	  }else
	    return OPENBLAS_CORE_NEOVERSEV1;
  case 0xd4f: // Neoverse V2
  case 0xd83: // Neoverse V3AE
  case 0xd84: // Neoverse V3
  case 0xd85: // Cortex X925
  case 0xd87: // Cortex A725
      if (!(getauxval(AT_HWCAP) & HWCAP_SVE)) {
        openblas_warning(FALLBACK_VERBOSE, NEOVERSEN1_FALLBACK);
        return OPENBLAS_CORE_NEOVERSEN1;
      } else {
	      return OPENBLAS_CORE_NEOVERSEV2;
      }
#endif
	case 0xd05: // Cortex A55
	  return OPENBLAS_CORE_CORTEXA55;
      }
      break;
    case 0x42: // Broadcom
      switch (part)
      {
        case 0x516: // Vulcan
          return OPENBLAS_CORE_THUNDERX2T99;
      }
      break;
    case 0x43: // Cavium
      switch (part)
      {
        case 0x0a1: // ThunderX
          return OPENBLAS_CORE_THUNDERX;
        case 0x0af: // ThunderX2
          return OPENBLAS_CORE_THUNDERX2T99;
        case 0x0b8: // ThunderX3
          return OPENBLAS_CORE_THUNDERX3T110;
      }
      break;
    case 0x46: // Fujitsu
      switch (part)
      {
#ifndef NO_SVE
        case 0x001: // A64FX
          return OPENBLAS_CORE_A64FX;
#endif
      }
      break;
    case 0x48: // HiSilicon
      switch (part)
      {
        case 0xd01: // tsv110
          return OPENBLAS_CORE_TSV110;
      }
      break;
    case 0x50: // Ampere/AppliedMicro
      switch (part)
      {
        case 0x000: // Skylark/EMAG8180
          return OPENBLAS_CORE_EMAG8180;
      }
      break;
    case 0xc0: // Ampere
      switch(part)
      {
	case 0xac3:
	case 0xac4:
	  return OPENBLAS_CORE_NEOVERSEN1;
      }
      break;
    case 0x51: // Qualcomm
      switch (part)
      {
        case 0xc00: // Falkor
          return OPENBLAS_CORE_FALKOR;
      }
      break;
    case 0x61: // Apple
	if (support_sme1()) return OPENBLAS_CORE_VORTEXM4;
	return OPENBLAS_CORE_VORTEX;
      break;
    default:
      snprintf(coremsg, 128, "Unknown CPU model - implementer %x part %x\n",implementer,part);
      openblas_warning(1, coremsg);
  }

#if !defined(NO_SME)
  if (support_sme1()) {
    return OPENBLAS_CORE_ARMV9SME;
  }
#endif

#ifndef NO_SVE
  if ((getauxval(AT_HWCAP) & HWCAP_SVE)) {
    return OPENBLAS_CORE_ARMV8SVE;
  }
#endif

  return -1;
#endif
}

void gotoblas_dynamic_init(void) {

  char coremsg[128];
  char coren[22];
  char *p;

  if (openblas_core >= 0) return;

  p = getenv("OPENBLAS_CORETYPE");
  if ( p )
  {
    openblas_core = force_coretype(p);
  }
  else
  {
    openblas_core = get_coretype();
  }

  if (openblas_core < 0)
  {
    snprintf(coremsg, 128, "Falling back to generic ARMV8 core\n");
    openblas_warning(1, coremsg);
    openblas_core = OPENBLAS_CORE_ARMV8;
  }

  if (openblas_core >= 0 && openblas_params_tab[openblas_core]->init) {
    strncpy(coren, gotoblas_corename(), 20);
    sprintf(coremsg, "Core: %s\n", coren);
    openblas_warning(2, coremsg);
    openblas_params_tab[openblas_core]->init();
  } else {
    openblas_warning(0, "OpenBLAS : Architecture Initialization failed. No initialization function found.\n");
    exit(1);
  }

}

void gotoblas_dynamic_quit(void) {
  openblas_core = -1;
}

int support_sme1(void) {
        int ret = 0;

#if (defined OS_LINUX || defined OS_ANDROID)
        ret = getauxval(AT_HWCAP2) & HWCAP2_SME;
        if(getauxval(AT_HWCAP2) & HWCAP2_SME){
                ret = 1;
        }
#endif
#if defined(__APPLE__)
	sysctlbyname("hw.optional.arm.FEAT_SME",&value64,&length64,NULL,0);
	ret = value64;
#endif
       return ret;
}
