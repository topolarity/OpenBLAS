/*********************************************************************/
/* Copyright 2009, 2010 The University of Texas at Austin.           */
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

#ifdef _MSC_VER
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#endif

#ifdef ARCH_X86
#define EXTERN extern
#else
#define EXTERN
#endif

#ifdef DYNAMIC_LIST

#ifdef DYN_ATHLON
#else
#define OPENBLAS_CORE_ATHLON OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_KATMAI
#else
#define OPENBLAS_CORE_KATMAI OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_BANIAS
#else
#define OPENBLAS_CORE_BANIAS OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_COPPERMINE
#else
#define OPENBLAS_CORE_COPPERMINE OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_NORTHWOOD
#else
#define OPENBLAS_CORE_NORTHWOOD OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_CORE2
#else
#define OPENBLAS_CORE_CORE2 OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_NEHALEM
#else
#define OPENBLAS_CORE_NEHALEM OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_BARCELONA
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_BARCELONA OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_BARCELONA OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_ATOM
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_ATOM OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_ATOM OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_NANO
#else
#define OPENBLAS_CORE_NANO OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_PENRYN
#else
#define OPENBLAS_CORE_PENRYN OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_DUNNINGTON
#else
#define OPENBLAS_CORE_DUNNINGTON OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_OPTERON
#else
#define OPENBLAS_CORE_OPTERON OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_OPTERON_SSE3
#else
#define OPENBLAS_CORE_OPTERON_SSE3 OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_BOBCAT
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_BOBCAT OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_BOBCAT OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_SANDYBRIDGE
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_SANDYBRIDGE OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_SANDYBRIDGE OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_BULLDOZER
#elif defined(DYN_SANDYBRIDGE)
#define OPENBLAS_CORE_BULLDOZER OPENBLAS_CORE_SANDYBRIDGE
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_BULLDOZER OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_BULLDOZER OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_PILEDRIVER
#elif defined(DYN_SANDYBRIDGE)
#define OPENBLAS_CORE_PILEDRIVER OPENBLAS_CORE_SANDYBRIDGE
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_PILEDRIVER OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_PILEDRIVER OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_STEAMROLLER
#elif defined(DYN_SANDYBRIDGE)
#define OPENBLAS_CORE_STEAMROLLER OPENBLAS_CORE_SANDYBRIDGE
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_STEAMROLLER OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_STEAMROLLER OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_EXCAVATOR
#elif defined(DYN_SANDYBRIDGE)
#define OPENBLAS_CORE_EXCAVATOR OPENBLAS_CORE_SANDYBRIDGE
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_EXCAVATOR OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_EXCAVATOR OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_HASWELL
#elif defined(DYN_SANDYBRIDGE)
#define OPENBLAS_CORE_HASWELL OPENBLAS_CORE_SANDYBRIDGE
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_HASWELL OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_HASWELL OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_ZEN
#elif defined(DYN_HASWELL)
#define OPENBLAS_CORE_ZEN OPENBLAS_CORE_HASWELL
#elif defined(DYN_SANDYBRIDGE)
#define OPENBLAS_CORE_ZEN OPENBLAS_CORE_SANDYBRIDGE
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_ZEN OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_ZEN OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_SKYLAKEX
#elif defined(DYN_HASWELL)
#define OPENBLAS_CORE_SKYLAKEX OPENBLAS_CORE_HASWELL
#elif defined(DYN_SANDYBRIDGE)
#define OPENBLAS_CORE_SKYLAKEX OPENBLAS_CORE_SANDYBRIDGE
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_SKYLAKEX OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_SKYLAKEX OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_COOPERLAKE
#elif defined(DYN_SKYLAKEX)
#define OPENBLAS_CORE_COOPERLAKE OPENBLAS_CORE_SKYLAKEX
#elif defined(DYN_HASWELL)
#define OPENBLAS_CORE_COOPERLAKE OPENBLAS_CORE_HASWELL
#elif defined(DYN_SANDYBRIDGE)
#define OPENBLAS_CORE_COOPERLAKE OPENBLAS_CORE_SANDYBRIDGE
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_COOPERLAKE OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_COOPERLAKE OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYN_SAPPHIRERAPIDS
#elif defined(DYN_SKYLAKEX)
#define OPENBLAS_CORE_SAPPHIRERAPIDS OPENBLAS_CORE_SKYLAKEX
#elif defined(DYN_HASWELL)
#define OPENBLAS_CORE_SAPPHIRERAPIDS OPENBLAS_CORE_HASWELL
#elif defined(DYN_SANDYBRIDGE)
#define OPENBLAS_CORE_SAPPHIRERAPIDS OPENBLAS_CORE_SANDYBRIDGE
#elif defined(DYN_NEHALEM)
#define OPENBLAS_CORE_SAPPHIRERAPIDS OPENBLAS_CORE_NEHALEM
#else
#define OPENBLAS_CORE_SAPPHIRERAPIDS OPENBLAS_CORE_PRESCOTT
#endif


#else // not DYNAMIC_LIST
#ifndef ARCH_X86
/* These cores are 32-bit only and are not built into DYNAMIC_CORE on
   x86_64, so they have no enumerator of their own.  Alias them to
   PRESCOTT - the 64-bit sanity check below folds them there anyway. */
#define OPENBLAS_CORE_KATMAI     OPENBLAS_CORE_PRESCOTT
#define OPENBLAS_CORE_COPPERMINE OPENBLAS_CORE_PRESCOTT
#define OPENBLAS_CORE_NORTHWOOD  OPENBLAS_CORE_PRESCOTT
#define OPENBLAS_CORE_BANIAS     OPENBLAS_CORE_PRESCOTT
#define OPENBLAS_CORE_ATHLON     OPENBLAS_CORE_PRESCOTT
#endif
#ifdef DYNAMIC_OLDER
#else
#define OPENBLAS_CORE_ATOM OPENBLAS_CORE_NEHALEM
#define OPENBLAS_CORE_NANO OPENBLAS_CORE_NEHALEM
#define OPENBLAS_CORE_PENRYN OPENBLAS_CORE_CORE2
#define OPENBLAS_CORE_DUNNINGTON OPENBLAS_CORE_CORE2
#define OPENBLAS_CORE_OPTERON OPENBLAS_CORE_CORE2
#define OPENBLAS_CORE_OPTERON_SSE3 OPENBLAS_CORE_CORE2
#define OPENBLAS_CORE_BOBCAT OPENBLAS_CORE_CORE2
#endif

#ifndef NO_AVX
#ifdef NO_AVX2
#define OPENBLAS_CORE_HASWELL OPENBLAS_CORE_SANDYBRIDGE
#define OPENBLAS_CORE_SKYLAKEX OPENBLAS_CORE_SANDYBRIDGE
#define OPENBLAS_CORE_COOPERLAKE OPENBLAS_CORE_SANDYBRIDGE
#define OPENBLAS_CORE_ZEN OPENBLAS_CORE_SANDYBRIDGE
#define OPENBLAS_CORE_SAPPHIRERAPIDS OPENBLAS_CORE_SANDYBRIDGE
#else
#ifndef NO_AVX512
#else
#define OPENBLAS_CORE_SKYLAKEX OPENBLAS_CORE_HASWELL
#define OPENBLAS_CORE_COOPERLAKE OPENBLAS_CORE_HASWELL
#define OPENBLAS_CORE_SAPPHIRERAPIDS OPENBLAS_CORE_HASWELL
#endif
#endif
#else
//Use NEHALEM kernels for sandy bridge
#define OPENBLAS_CORE_SANDYBRIDGE OPENBLAS_CORE_NEHALEM
#define OPENBLAS_CORE_HASWELL OPENBLAS_CORE_NEHALEM
#define OPENBLAS_CORE_SKYLAKEX OPENBLAS_CORE_NEHALEM
#define OPENBLAS_CORE_COOPERLAKE OPENBLAS_CORE_NEHALEM
#define OPENBLAS_CORE_SAPPHIRERAPIDS OPENBLAS_CORE_NEHALEM
#define OPENBLAS_CORE_BULLDOZER OPENBLAS_CORE_BARCELONA
#define OPENBLAS_CORE_PILEDRIVER OPENBLAS_CORE_BARCELONA
#define OPENBLAS_CORE_STEAMROLLER OPENBLAS_CORE_BARCELONA
#define OPENBLAS_CORE_EXCAVATOR OPENBLAS_CORE_BARCELONA
#define OPENBLAS_CORE_ZEN OPENBLAS_CORE_BARCELONA
#endif

#endif // DYNAMIC_LIST

#define VENDOR_INTEL      1
#define VENDOR_AMD        2
#define VENDOR_CENTAUR    3
#define VENDOR_HYGON	  4
#define VENDOR_ZHAOXIN    5
#define VENDOR_UNKNOWN   99

#define BITMASK(a, b, c) ((((a) >> (b)) & (c)))

#ifndef NO_AVX
static inline void xgetbv(int op, int * eax, int * edx){
  //Use binary code for xgetbv
  __asm__ __volatile__
    (".byte 0x0f, 0x01, 0xd0": "=a" (*eax), "=d" (*edx) : "c" (op) : "cc");
}
#endif

int support_avx(){
#ifndef NO_AVX
  int eax, ebx, ecx, edx;
  int ret=0;

  cpuid(1, &eax, &ebx, &ecx, &edx);
  if ((ecx & (1 << 28)) != 0 && (ecx & (1 << 27)) != 0 && (ecx & (1 << 26)) != 0){
    xgetbv(0, &eax, &edx);
    if((eax & 6) == 6){
      ret=1;  //OS support AVX
    }
  }
  return ret;
#else
  return 0;
#endif
}

int support_avx2(){
#ifndef NO_AVX2
  int eax, ebx, ecx=0, edx;
  int ret=0;

  if (!support_avx())
    return 0;
  cpuid(7, &eax, &ebx, &ecx, &edx);
  if((ebx & (1<<5)) != 0)
      ret=1;  //AVX2 flag is set
  return ret;
#else
  return 0;
#endif
}

int support_avx512(){
#if !defined(NO_AVX) && !defined(NO_AVX512)
  int eax, ebx, ecx, edx;
  int ret=0;

  if (!support_avx())
    return 0;
  cpuid(7, &eax, &ebx, &ecx, &edx);
  if((ebx & (1<<5)) == 0){
      ret=0;  //cpu does not have avx2 flag
  }
  if((ebx & (1<<31)) != 0){ //AVX512VL flag is set
    xgetbv(0, &eax, &edx);
    if((eax & 0xe0) == 0xe0)
      ret=1;  //OS supports saving zmm register
  }
  return ret;
#else
  return 0;
#endif
}

int support_avx512_bf16(){
#if !defined(NO_AVX) && !defined(NO_AVX512)
  int eax, ebx, ecx, edx;
  int ret=0;

  if (!support_avx512())
    return 0;
  cpuid_count(7, 1, &eax, &ebx, &ecx, &edx);
  if((eax & 32) == 32){
      ret=1;  // CPUID.7.1:EAX[bit 5] indicates whether avx512_bf16 supported or not
  }
  return ret;
#else
  return 0;
#endif
}

#define BIT_AMX_TILE	0x01000000
#define BIT_AMX_BF16	0x00400000
#define BIT_AMX_ENBD	0x00060000

int support_amx_bf16() {
#if !defined(NO_AVX) && !defined(NO_AVX512)
  int eax, ebx, ecx, edx;
  int ret=0;

  if (!support_avx512())
    return 0;
  // CPUID.7.0:EDX indicates AMX support
  cpuid_count(7, 0, &eax, &ebx, &ecx, &edx);
  if ((edx & BIT_AMX_TILE) && (edx & BIT_AMX_BF16)) {
    // CPUID.D.0:EAX[17:18] indicates AMX enabled
    cpuid_count(0xd, 0, &eax, &ebx, &ecx, &edx);
    if ((eax & BIT_AMX_ENBD) == BIT_AMX_ENBD)
      ret = 1;
  }
  return ret;
#else
  return 0;
#endif
}

extern void openblas_warning(int verbose, const char * msg);
#define FALLBACK_VERBOSE 1
#define NEHALEM_FALLBACK "OpenBLAS : Your OS does not support AVX instructions. OpenBLAS is using Nehalem kernels as a fallback, which may give poorer performance.\n"
#define SANDYBRIDGE_FALLBACK "OpenBLAS : Your OS does not support AVX2 instructions. OpenBLAS is using Sandybridge kernels as a fallback, which may give poorer performance.\n"
#define HASWELL_FALLBACK "OpenBLAS : Your OS does not support AVX512VL instructions. OpenBLAS is using Haswell kernels as a fallback, which may give poorer performance.\n"
#define BARCELONA_FALLBACK "OpenBLAS : Your OS does not support AVX instructions. OpenBLAS is using Barcelona kernels as a fallback, which may give poorer performance.\n"

static int get_vendor(void){
  int eax, ebx, ecx, edx;

  union
  {
        char vchar[16];
        int  vint[4];
  } vendor;

  cpuid(0, &eax, &ebx, &ecx, &edx);

  *(&vendor.vint[0]) = ebx;
  *(&vendor.vint[1]) = edx;
  *(&vendor.vint[2]) = ecx;

  vendor.vchar[12] = '\0';

  if (!strcmp(vendor.vchar, "GenuineIntel")) return VENDOR_INTEL;
  if (!strcmp(vendor.vchar, "AuthenticAMD")) return VENDOR_AMD;
  if (!strcmp(vendor.vchar, "CentaurHauls")) return VENDOR_CENTAUR;
  if (!strcmp(vendor.vchar, "  Shanghai  ")) return VENDOR_ZHAOXIN;
  if (!strcmp(vendor.vchar, "HygonGenuine")) return VENDOR_HYGON;

  if ((eax == 0) || ((eax & 0x500) != 0)) return VENDOR_INTEL;

  return VENDOR_UNKNOWN;
}

static int get_coretype(void){

  int eax, ebx, ecx, edx;
  int family, exfamily, model, vendor, exmodel, stepping;

  cpuid(1, &eax, &ebx, &ecx, &edx);

  family   = BITMASK(eax,  8, 0x0f);
  exfamily = BITMASK(eax, 20, 0xff);
  model    = BITMASK(eax,  4, 0x0f);
  exmodel  = BITMASK(eax, 16, 0x0f);
  stepping = BITMASK(eax,  0, 0x0f);

  vendor = get_vendor();

  if (vendor == VENDOR_INTEL){
    switch (family) {
    case 0x6:
      switch (exmodel) {
      case 0:
	if (model <= 0x7) return OPENBLAS_CORE_KATMAI;
	if ((model == 0x8) || (model == 0xa) || (model == 0xb)) return OPENBLAS_CORE_COPPERMINE;
	if ((model == 0x9) || (model == 0xd)) return OPENBLAS_CORE_BANIAS;
	if (model == 14) return OPENBLAS_CORE_BANIAS;
	if (model == 15) return OPENBLAS_CORE_CORE2;
	return -1;

      case 1:
	if (model == 6) return OPENBLAS_CORE_CORE2;
	if (model == 7) return OPENBLAS_CORE_PENRYN;
	if (model == 13) return OPENBLAS_CORE_DUNNINGTON;
	if ((model == 10) || (model == 11) || (model == 14) || (model == 15)) return OPENBLAS_CORE_NEHALEM;
	if (model == 12) return OPENBLAS_CORE_ATOM;
	return -1;

      case 2:
	//Intel Core (Clarkdale) / Core (Arrandale)
	// Pentium (Clarkdale) / Pentium Mobile (Arrandale)
	// Xeon (Clarkdale), 32nm
	if (model ==  5) return OPENBLAS_CORE_NEHALEM;

	//Intel Xeon Processor 5600 (Westmere-EP)
	//Xeon Processor E7 (Westmere-EX)
	//Xeon E7540
	if (model == 12 || model == 14 || model == 15) return OPENBLAS_CORE_NEHALEM;

	//Intel Core i5-2000 /i7-2000 (Sandy Bridge)
	//Intel Core i7-3000 / Xeon E5
	if (model == 10 || model == 13) {
	  if(support_avx())
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  else{
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
	}
	return -1;
      case 3:
	//Intel Sandy Bridge 22nm (Ivy Bridge?)
	if (model == 10 || model == 14) {
	  if(support_avx())
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  else{
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
	}
	//Intel Haswell
	if (model == 12 || model == 15) {
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
	}
	//Intel Broadwell
	if (model == 13) {
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
	}
	if (model == 7) return OPENBLAS_CORE_ATOM; //Bay Trail	
	return -1;
      case 4:
		//Intel Haswell
	if (model == 5 || model == 6) {
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
	}
	//Intel Broadwell
	if (model == 7 || model == 15) {
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
	}
	//Intel Skylake
	if (model == 14) {
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
	}
	//Intel Braswell / Avoton
	if (model == 12 || model == 13) { 
	  return OPENBLAS_CORE_NEHALEM;
	}	
	return -1;
      case 5:
	//Intel Broadwell
	if (model == 6) {
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
	}
	if (model == 5) {
	// Intel Cooperlake
          if(support_avx512_bf16())
             return OPENBLAS_CORE_COOPERLAKE;
	// Intel Skylake X
          if (support_avx512()) 
	    return OPENBLAS_CORE_SKYLAKEX;
	  if(support_avx2()){
	    openblas_warning(FALLBACK_VERBOSE, HASWELL_FALLBACK);
	    return OPENBLAS_CORE_HASWELL;
          }
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
          openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
          return OPENBLAS_CORE_NEHALEM;
          }
	}
	//Intel Skylake
	if (model == 14) {
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
	}
	//Intel Phi Knights Landing
	if (model == 7) {
	  if(support_avx2()){
	    openblas_warning(FALLBACK_VERBOSE, HASWELL_FALLBACK);
	    return OPENBLAS_CORE_HASWELL;
	  }  
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
	}
	//Apollo Lake or Denverton
	if (model == 12 || model == 15) { 
	  return OPENBLAS_CORE_NEHALEM;
	}	
	return -1;
      case 6:
        if (model == 6) {
          // Cannon Lake
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM;
	  }
        }
	if (model == 10 || model == 12){
          // Ice Lake SP
	   if(support_avx512_bf16())
             return OPENBLAS_CORE_COOPERLAKE;
          if (support_avx512()) 
	    return OPENBLAS_CORE_SKYLAKEX;
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM;
	  }
        }
        return -1;  
      case 7:
	if (model == 10) // Goldmont Plus
	   return OPENBLAS_CORE_NEHALEM;
        if (model == 13 || model == 14) {
	// Ice Lake
          if (support_avx512()) 
	    return OPENBLAS_CORE_SKYLAKEX;
	  if(support_avx2()){
	    openblas_warning(FALLBACK_VERBOSE, HASWELL_FALLBACK);
	    return OPENBLAS_CORE_HASWELL;
          }
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
          openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
          return OPENBLAS_CORE_NEHALEM;
          }
        }
        return -1;  
      case 8:
        if (model == 12 || model == 13) { // Tiger Lake
          if (support_avx512()) 
            return OPENBLAS_CORE_SKYLAKEX;
          if(support_avx2()){
            openblas_warning(FALLBACK_VERBOSE, HASWELL_FALLBACK);
            return OPENBLAS_CORE_HASWELL;
          }
          if(support_avx()) {
            openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
            return OPENBLAS_CORE_SANDYBRIDGE;
          } else {
          openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
          return OPENBLAS_CORE_NEHALEM;
          }
        }
	if (model == 14 ) { // Kaby Lake, Coffee Lake
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
	}
	if (model == 15){          // Sapphire Rapids
	   if(support_amx_bf16())
	     return OPENBLAS_CORE_SAPPHIRERAPIDS;
	   if(support_avx512_bf16())
             return OPENBLAS_CORE_COOPERLAKE;
          if (support_avx512()) 
	    return OPENBLAS_CORE_SKYLAKEX;
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM;
	  }
        }
	return -1;
	
	
      case 9:
        if (model == 7 || model == 10) { // Alder Lake
	   if(support_avx512_bf16())
             return OPENBLAS_CORE_COOPERLAKE;
          if (support_avx512()) 
	    return OPENBLAS_CORE_SKYLAKEX;
          if(support_avx2()){
            return OPENBLAS_CORE_HASWELL;
          }
          if(support_avx()) {
            openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
            return OPENBLAS_CORE_SANDYBRIDGE;
          } else {
          openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
          return OPENBLAS_CORE_NEHALEM;
          }
        }
	if (model == 14 ) { // Kaby Lake, Coffee Lake
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
	}
	return -1;
      case 10:
        if (model == 5 || model == 6) {
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
        }
        if (model == 7) {
	  if (support_avx512()) 
	    return OPENBLAS_CORE_SKYLAKEX;
	  if(support_avx2())
	    return OPENBLAS_CORE_HASWELL;
	  if(support_avx()) {
	    openblas_warning(FALLBACK_VERBOSE, SANDYBRIDGE_FALLBACK);
	    return OPENBLAS_CORE_SANDYBRIDGE;
	  } else {
	    openblas_warning(FALLBACK_VERBOSE, NEHALEM_FALLBACK);
	    return OPENBLAS_CORE_NEHALEM; //OS doesn't support AVX. Use old kernels.
	  }
        }      
	return -1;
      }
      break;
    case 0xf:
      if (model <= 0x2) return OPENBLAS_CORE_NORTHWOOD;
      return OPENBLAS_CORE_PRESCOTT;
    }
  }

  if (vendor == VENDOR_AMD || vendor == VENDOR_HYGON){
    if (family <= 0xe) {
        // Verify that CPU has 3dnow and 3dnowext before claiming it is Athlon
        cpuid(0x80000000, &eax, &ebx, &ecx, &edx);
        if ( (eax & 0xffff)  >= 0x01) {
            cpuid(0x80000001, &eax, &ebx, &ecx, &edx);
            if ((edx & (1 << 30)) == 0 || (edx & (1u << 31)) == 0)
              return -1;
          }
        else
          return -1;

        return OPENBLAS_CORE_ATHLON;
      }
    if (family == 0xf){
      if ((exfamily == 0) || (exfamily == 2)) {
		if (exmodel == 6 && model == 11) { /*QEMU virtual cpu*/
	      if (support_avx512_bf16())
             return OPENBLAS_CORE_COOPERLAKE;
          if (support_avx512())
	         return OPENBLAS_CORE_SKYLAKEX;
          if (support_avx2())
			 return OPENBLAS_CORE_ZEN;
          else
            return OPENBLAS_CORE_BARCELONA;
		}
	    if (ecx & (1 <<  0)) return OPENBLAS_CORE_OPTERON_SSE3;
	else return OPENBLAS_CORE_OPTERON;
      }  else if (exfamily == 5 || exfamily == 7) {
	return OPENBLAS_CORE_BOBCAT;
      } else if (exfamily == 6) {
	if(model == 1){
	  //AMD Bulldozer Opteron 6200 / Opteron 4200 / AMD FX-Series
	  if(support_avx())
	    return OPENBLAS_CORE_BULLDOZER;
	  else{
	    openblas_warning(FALLBACK_VERBOSE, BARCELONA_FALLBACK);
	    return OPENBLAS_CORE_BARCELONA; //OS doesn't support AVX. Use old kernels.
	  }
	}else if(model == 2 || model == 3){
	  //AMD Bulldozer Opteron 6300 / Opteron 4300 / Opteron 3300
	  if(support_avx())
	    return OPENBLAS_CORE_PILEDRIVER;
	  else{
	    openblas_warning(FALLBACK_VERBOSE, BARCELONA_FALLBACK);
	    return OPENBLAS_CORE_BARCELONA; //OS doesn't support AVX. Use old kernels.
	  }
	}else if(model == 5){
	  if(support_avx())
	    return OPENBLAS_CORE_EXCAVATOR;
	  else{
	    openblas_warning(FALLBACK_VERBOSE, BARCELONA_FALLBACK);
	    return OPENBLAS_CORE_BARCELONA; //OS doesn't support AVX. Use old kernels.
	  }
	}else if(model == 0 || model == 8){
	  if (exmodel == 1) {
	    //AMD Trinity
	    if(support_avx())
	      return OPENBLAS_CORE_PILEDRIVER;
	    else{
	      openblas_warning(FALLBACK_VERBOSE, BARCELONA_FALLBACK);
	      return OPENBLAS_CORE_BARCELONA; //OS doesn't support AVX. Use old kernels.
	    }
	   }else if (exmodel == 3) {
	    //AMD STEAMROLLER
	    if(support_avx())
	      return OPENBLAS_CORE_STEAMROLLER;
	    else{
	      openblas_warning(FALLBACK_VERBOSE, BARCELONA_FALLBACK);
	      return OPENBLAS_CORE_BARCELONA; //OS doesn't support AVX. Use old kernels.
	    }
	  }else if (exmodel == 6) {
	    if(support_avx())
	      return OPENBLAS_CORE_EXCAVATOR;
	    else{
	      openblas_warning(FALLBACK_VERBOSE, BARCELONA_FALLBACK);
	      return OPENBLAS_CORE_BARCELONA; //OS doesn't support AVX. Use old kernels.
	    }

	  }
	}
      } else if (exfamily == 8) {
	/* if (model == 1 || model == 8) */ {
	  if(support_avx())
	    return OPENBLAS_CORE_ZEN;
	  else{
	    openblas_warning(FALLBACK_VERBOSE, BARCELONA_FALLBACK);
	    return OPENBLAS_CORE_BARCELONA; //OS doesn't support AVX. Use old kernels.
	  }
	}
      } else if (exfamily == 9) {  
	  if(support_avx())
	    return OPENBLAS_CORE_ZEN;
	  else{
	    openblas_warning(FALLBACK_VERBOSE, BARCELONA_FALLBACK);
	    return OPENBLAS_CORE_BARCELONA; //OS doesn't support AVX. Use old kernels.
          }
      } else if (exfamily == 10) {
	  if(support_avx512_bf16())
	    return OPENBLAS_CORE_COOPERLAKE;
	  if(support_avx512())
	    return OPENBLAS_CORE_SKYLAKEX;
	  if(support_avx())
	    return OPENBLAS_CORE_ZEN;
	  else{
	    openblas_warning(FALLBACK_VERBOSE, BARCELONA_FALLBACK);
	    return OPENBLAS_CORE_BARCELONA; //OS doesn't support AVX. Use old kernels.
          }
      }else {
	return -1;
      }
   
    }
  }

  if (vendor == VENDOR_CENTAUR) {
    switch (family) {
    case 0x6:
      if (model == 0xf && stepping < 0xe)
        return OPENBLAS_CORE_NANO;
      return OPENBLAS_CORE_NEHALEM;
	case 0x7:
      switch (exmodel) {
      case 5:
      case 6:
        if (support_avx2())
          return OPENBLAS_CORE_ZEN;
        else
          return OPENBLAS_CORE_DUNNINGTON;
      default:
        return OPENBLAS_CORE_NEHALEM;
      }
    default:
      if (family >= 0x8)
        return OPENBLAS_CORE_NEHALEM;
    }
  }

  if (vendor == VENDOR_ZHAOXIN) {
    switch (family) {
      case 0x7:
        switch (exmodel) {
        case 5:
          if (support_avx2())
            return OPENBLAS_CORE_ZEN;
          else
            return OPENBLAS_CORE_DUNNINGTON;
        default:
          if (support_avx2())
            return OPENBLAS_CORE_ZEN;
          else
          return OPENBLAS_CORE_NEHALEM;
        }
      default:
          if (support_avx2())
            return OPENBLAS_CORE_ZEN;
          else
        return OPENBLAS_CORE_NEHALEM;
    }
  }

  return -1;
}

static char *corename[] = {
    "Unknown",
    "Katmai",
    "Coppermine",
    "Northwood",
    "Prescott",
    "Banias",
    "Atom",
    "Core2",
    "Penryn",
    "Dunnington",
    "Nehalem",
    "Athlon",
    "Opteron",
    "Opteron_SSE3",
    "Barcelona",
    "Nano",
    "Sandybridge",
    "Bobcat",
    "Bulldozer",
    "Piledriver",
    "Haswell",
    "Steamroller",
    "Excavator",
    "Zen",
    "SkylakeX",
    "Cooperlake",
    "SapphireRapids"
};

char *gotoblas_corename(void) {

  /* On x86_64 the 32-bit-only cores are aliases of PRESCOTT (see above), so
     testing them here would claim every Prescott selection is a Katmai.  They
     only have identities of their own on x86. */
#ifdef ARCH_X86
  if (openblas_core == OPENBLAS_CORE_KATMAI)       return corename[ 1];
  if (openblas_core == OPENBLAS_CORE_COPPERMINE)   return corename[ 2];
  if (openblas_core == OPENBLAS_CORE_NORTHWOOD)    return corename[ 3];
#endif
  if (openblas_core == OPENBLAS_CORE_PRESCOTT)     return corename[ 4];
#ifdef ARCH_X86
  if (openblas_core == OPENBLAS_CORE_BANIAS)       return corename[ 5];
#endif
  if (openblas_core == OPENBLAS_CORE_ATOM)
#ifdef DYNAMIC_OLDER
           return corename[ 6];
#else
           return corename[10];
#endif
  if (openblas_core == OPENBLAS_CORE_CORE2)        return corename[ 7];
  if (openblas_core == OPENBLAS_CORE_PENRYN)
#ifdef DYNAMIC_OLDER
           return corename[ 8];
#else
           return corename[7];
#endif
  if (openblas_core == OPENBLAS_CORE_DUNNINGTON)
#ifdef DYNAMIC_OLDER
           return corename[ 9];
#else
           return corename[7];
#endif
  if (openblas_core == OPENBLAS_CORE_NEHALEM)      return corename[10];
#ifdef ARCH_X86
  if (openblas_core == OPENBLAS_CORE_ATHLON)       return corename[11];
#endif
  if (openblas_core == OPENBLAS_CORE_OPTERON_SSE3)
#ifdef DYNAMIC_OLDER
           return corename[12];
#else
           return corename[7];
#endif
  if (openblas_core == OPENBLAS_CORE_OPTERON)
#ifdef DYNAMIC_OLDER
           return corename[13];
#else
           return corename[7];
#endif
  if (openblas_core == OPENBLAS_CORE_BARCELONA)    return corename[14];
  if (openblas_core == OPENBLAS_CORE_NANO)
#ifdef DYNAMIC_OLDER
           return corename[15];
#else
           return corename[10];
#endif
  if (openblas_core == OPENBLAS_CORE_SANDYBRIDGE)  return corename[16];
  if (openblas_core == OPENBLAS_CORE_BOBCAT)
#ifdef DYNAMIC_OLDER
           return corename[17];
#else
           return corename[7];
#endif
  if (openblas_core == OPENBLAS_CORE_BULLDOZER)    return corename[18];
  if (openblas_core == OPENBLAS_CORE_PILEDRIVER)   return corename[19];
  if (openblas_core == OPENBLAS_CORE_HASWELL)      return corename[20];
  if (openblas_core == OPENBLAS_CORE_STEAMROLLER)  return corename[21];
  if (openblas_core == OPENBLAS_CORE_EXCAVATOR)    return corename[22];
  if (openblas_core == OPENBLAS_CORE_ZEN)          return corename[23];
  if (openblas_core == OPENBLAS_CORE_SKYLAKEX)     return corename[24];
  if (openblas_core == OPENBLAS_CORE_COOPERLAKE)   return corename[25];
  if (openblas_core == OPENBLAS_CORE_SAPPHIRERAPIDS) return corename[26];
  return corename[0];
}



static int force_coretype(char *coretype){

	int i ;
	int found = -1;
	char message[128];
	//char mname[20];

	for ( i=1 ; i <= 25; i++)
	{
		if (!strncasecmp(coretype,corename[i],20))
		{
			found = i;
			break;
		}
	}
	if (found < 0)
	{
	        //strncpy(mname,coretype,20);
	        snprintf(message, 128, "Core not found: %s\n",coretype);
    		openblas_warning(1, message);
		return -1;
	}

	switch (found)
	{
		case 25: return OPENBLAS_CORE_COOPERLAKE;
		case 24: return OPENBLAS_CORE_SKYLAKEX;	
		case 23: return OPENBLAS_CORE_ZEN;
		case 22: return OPENBLAS_CORE_EXCAVATOR;
		case 21: return OPENBLAS_CORE_STEAMROLLER;
		case 20: return OPENBLAS_CORE_HASWELL;
		case 19: return OPENBLAS_CORE_PILEDRIVER;
		case 18: return OPENBLAS_CORE_BULLDOZER;
		case 17: return OPENBLAS_CORE_BOBCAT;
		case 16: return OPENBLAS_CORE_SANDYBRIDGE;
		case 15: return OPENBLAS_CORE_NANO;
		case 14: return OPENBLAS_CORE_BARCELONA;
		case 13: return OPENBLAS_CORE_OPTERON;
		case 12: return OPENBLAS_CORE_OPTERON_SSE3;
		case 11: return OPENBLAS_CORE_ATHLON;
		case 10: return OPENBLAS_CORE_NEHALEM;
		case  9: return OPENBLAS_CORE_DUNNINGTON;
		case  8: return OPENBLAS_CORE_PENRYN;
		case  7: return OPENBLAS_CORE_CORE2;
		case  6: return OPENBLAS_CORE_ATOM;
		case  5: return OPENBLAS_CORE_BANIAS;
		case  4: return OPENBLAS_CORE_PRESCOTT;
		case  3: return OPENBLAS_CORE_NORTHWOOD;
		case  2: return OPENBLAS_CORE_COPPERMINE;
		case  1: return OPENBLAS_CORE_KATMAI;
	}
	return -1;

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

#ifdef ARCH_X86
  if (openblas_core < 0) openblas_core = OPENBLAS_CORE_KATMAI;
#else
  if (openblas_core < 0) {
   if (support_avx512_bf16()) openblas_core = OPENBLAS_CORE_COOPERLAKE;
   else if (support_avx512()) openblas_core = OPENBLAS_CORE_SKYLAKEX;
   else if   (support_avx2()) openblas_core = OPENBLAS_CORE_HASWELL;
   else if    (support_avx()) openblas_core = OPENBLAS_CORE_SANDYBRIDGE;
   else                       openblas_core = OPENBLAS_CORE_PRESCOTT;
  }
  /* sanity check, if 64bit pointer we can't have a 32 bit cpu */
  if (sizeof(void*) == 8) {
      if (openblas_core == OPENBLAS_CORE_KATMAI ||
          openblas_core == OPENBLAS_CORE_COPPERMINE ||
          openblas_core == OPENBLAS_CORE_NORTHWOOD ||
          openblas_core == OPENBLAS_CORE_BANIAS ||
          openblas_core == OPENBLAS_CORE_ATHLON)
          openblas_core = OPENBLAS_CORE_PRESCOTT;
  }
#endif

  if (openblas_core >= 0 && openblas_params_tab[openblas_core]->init) {
    strncpy(coren,gotoblas_corename(),20);
    sprintf(coremsg, "Core: %s\n",coren);
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
