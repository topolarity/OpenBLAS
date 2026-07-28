## Author: Hank Anderson <hank@statease.com>
## Description: Ported from portion of OpenBLAS/Makefile.system
##              Sets various variables based on architecture.

if (X86 OR X86_64)

  if (X86)
    if (NOT BINARY)
      set(NO_BINARY_MODE 1)
    endif ()
  endif ()

  if (NOT NO_EXPRECISION)
    if (${F_COMPILER} MATCHES "GFORTRAN")
      # N.B. I'm not sure if CMake differentiates between GCC and LSB -hpa
      if (${CMAKE_C_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_C_COMPILER_ID} STREQUAL "LSB")
        set(EXPRECISION	1)
        set(CCOMMON_OPT "${CCOMMON_OPT} -DEXPRECISION -m128bit-long-double")
        set(FCOMMON_OPT	"${FCOMMON_OPT} -m128bit-long-double")
      endif ()
      if (${CMAKE_C_COMPILER_ID} STREQUAL "Clang")
        set(EXPRECISION	1)
        set(CCOMMON_OPT "${CCOMMON_OPT} -DEXPRECISION")
        set(FCOMMON_OPT	"${FCOMMON_OPT} -m128bit-long-double")
      endif ()
    endif ()
  endif ()
endif ()

if (${CMAKE_C_COMPILER_ID} STREQUAL "Intel")
  set(CCOMMON_OPT "${CCOMMON_OPT} -wd981")
endif ()

if (DYNAMIC_ARCH)
  if (ARM64)
    set(DYNAMIC_CORE ARMV8 CORTEXA53 CORTEXA57 THUNDERX THUNDERX2T99 TSV110 EMAG8180 NEOVERSEN1 THUNDERX3T110)
    if (${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
      if (${CMAKE_C_COMPILER_VERSION} VERSION_GREATER_EQUAL 10) # SVE ACLE supported in GCC >= 10
        set(DYNAMIC_CORE ${DYNAMIC_CORE} NEOVERSEV1 NEOVERSEN2 ARMV8SVE A64FX)
      endif ()
      if (${CMAKE_C_COMPILER_VERSION} VERSION_GREATER_EQUAL 14) # SME ACLE supported in GCC >= 14
        set(DYNAMIC_CORE ${DYNAMIC_CORE} ARMV9SME)
      endif()
	  if (${CMAKE_C_COMPILER_ID} MATCHES "Clang" AND ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
	    set(DYNAMIC_CORE ${DYNAMIC_CORE} VORTEXM4)
      endif()
    elseif (${CMAKE_C_COMPILER_ID} MATCHES "Clang")
      if (${CMAKE_C_COMPILER_VERSION} VERSION_GREATER_EQUAL 11) # SVE ACLE supported in LLVM >= 11
        set(DYNAMIC_CORE ${DYNAMIC_CORE} NEOVERSEV1 NEOVERSEN2 ARMV8SVE A64FX)
      endif ()
	  if (${CMAKE_C_COMPILER_VERSION} VERSION_GREATER_EQUAL 17) # SME ACLE supported in LLVM >= 17
        set(DYNAMIC_CORE ${DYNAMIC_CORE} ARMV9SME)
      endif()

	  if (NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
      if (${CMAKE_C_COMPILER_VERSION} VERSION_GREATER_EQUAL 19 OR (${CMAKE_C_COMPILER_ID} MATCHES AppleClang AND ${CMAKE_C_COMPILER_VERSION} VERSION_GREATER_EQUAL 17) ) # SME w/out SVE supported in LLVM >= 19 and AppleClang >= 17
        set(DYNAMIC_CORE ${DYNAMIC_CORE} VORTEXM4)
      endif()
	  endif()
    endif ()

    if (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin" OR ${CMAKE_SYSTEM_NAME} STREQUAL "iOS")
      set(DYNAMIC_CORE ARMV8 NEOVERSEN1)
      if (${CMAKE_C_COMPILER_VERSION} VERSION_GREATER_EQUAL 19 OR (${CMAKE_C_COMPILER_ID} MATCHES AppleClang AND ${CMAKE_C_COMPILER_VERSION} VERSION_GREATER_EQUAL 17) ) # SME ACLE supported in LLVM >= 19 and AppleClang >= 17
        set(DYNAMIC_CORE ${DYNAMIC_CORE} VORTEXM4)
      endif()
      if (${CMAKE_C_COMPILER_VERSION} VERSION_GREATER_EQUAL 14) # SME ACLE supported in GCC >= 14
        set(DYNAMIC_CORE ${DYNAMIC_CORE} ARMV9SME)
      endif()
    endif()
    
    if (DYNAMIC_LIST)
	  set(DYNAMIC_CORE ARMV8 ${DYNAMIC_LIST})
    endif ()
  endif ()
  
  if (POWER)
	  set(DYNAMIC_CORE POWER6 POWER8 POWER9 POWER10)
	  set(CCOMMON_OPT "${CCOMMON_OPT} -DHAVE_P10_SUPPORT")
  endif ()
 
  if (RISCV64)
	  set(DYNAMIC_CORE RISCV64_GENERIC RISCV64_ZVL128B RISCV64_ZVL256B) 
  endif ()

  if (X86)
    set(DYNAMIC_CORE KATMAI COPPERMINE NORTHWOOD PRESCOTT BANIAS CORE2 PENRYN DUNNINGTON NEHALEM ATHLON OPTERON OPTERON_SSE3 BARCELONA BOBCAT ATOM NANO)
  endif ()

  if (X86_64)
    set(DYNAMIC_CORE PRESCOTT CORE2)
    if (DYNAMIC_OLDER)
	set (DYNAMIC_CORE ${DYNAMIC_CORE} PENRYN DUNNINGTON)
    endif ()
    set (DYNAMIC_CORE ${DYNAMIC_CORE} NEHALEM)
    if (DYNAMIC_OLDER)
	set (DYNAMIC_CORE ${DYNAMIC_CORE} OPTERON OPTERON_SSE3)
    endif ()
    set (DYNAMIC_CORE ${DYNAMIC_CORE} BARCELONA) 
    if (DYNAMIC_OLDER)
	set (DYNAMIC_CORE ${DYNAMIC_CORE} BOBCAT ATOM NANO)
    endif ()
    if (NOT NO_AVX)
      set(DYNAMIC_CORE ${DYNAMIC_CORE} SANDYBRIDGE BULLDOZER PILEDRIVER STEAMROLLER EXCAVATOR)
    endif ()
    if (NOT NO_AVX2)
      set(DYNAMIC_CORE ${DYNAMIC_CORE} HASWELL ZEN)
    endif ()
    if (NOT NO_AVX512)
      set(DYNAMIC_CORE ${DYNAMIC_CORE} SKYLAKEX COOPERLAKE SAPPHIRERAPIDS)
      string(REGEX REPLACE "-march=native" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    endif ()
    if (DYNAMIC_LIST)
      set(DYNAMIC_CORE PRESCOTT ${DYNAMIC_LIST})
    endif ()
  endif ()
  
  if (ZARCH)
    set(DYNAMIC_CORE Z13 Z14 ZARCH_GENERIC)
    set(DYN_Z13 1)
	set(DYN_Z14 1)
  endif ()
  
  if (LOONGARCH64)
    set(DYNAMIC_CORE LA64_GENERIC LA264 LA464)
  endif ()

  if (EXISTS ${PROJECT_SOURCE_DIR}/dyn_cores.h)
	  message (FATAL_ERROR "Your source directory contains a file dyn_cores.h, probably from a previous compilation with make. The kernel targets search the source directory first, so it would shadow the one generated here - please remove the file before trying again")
  endif ()

  if (EXISTS ${PROJECT_SOURCE_DIR}/config_kernel.h)
	  message (FATAL_ERROR "Your build directory contains a file config_kernel.h, probably from a previous compilation with make. This will conflict with the cmake compilation and cause strange compiler errors - please remove the file before trying again")
  endif ()

  if (NOT DYNAMIC_CORE)
    message (STATUS "DYNAMIC_ARCH is not supported on this architecture, removing from options")
    unset(DYNAMIC_ARCH CACHE)
  endif ()
endif ()

if (${ARCH} STREQUAL "ia64")
  set(NO_BINARY_MODE 1)
  set(BINARY_DEFINED 1)

  if (${F_COMPILER} MATCHES "GFORTRAN")
    if (${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
      # EXPRECISION	= 1
      # CCOMMON_OPT	+= -DEXPRECISION
    endif ()
  endif ()
endif ()

if (MIPS32 OR MIPS64)
  set(NO_BINARY_MODE 1)
endif ()

if (LOONGARCH64)
  set(NO_BINARY_MODE 1)
endif ()

if (${ARCH} STREQUAL "alpha")
  set(NO_BINARY_MODE 1)
  set(BINARY_DEFINED 1)
endif ()

if (ARM)
  set(NO_BINARY_MODE 1)
  set(BINARY_DEFINED 1)
endif ()

if (ARM64)
  set(NO_BINARY_MODE 1)
  set(BINARY_DEFINED 1)
endif ()

if (RISCV64)
  set(NO_BINARY_MODE 1)
  set(BINARY_DEFINED 1)
endif ()


# Generate dyn_cores.h: the canonical order of DYNAMIC_CORE, as an enum plus an
# X-macro list.  openblas_core indexes into this, and driver/others/dispatch.c
# walks the list to build the per-group dispatch arrays.  Kept in step with the
# equivalent rule in Makefile.system.
if (DYNAMIC_ARCH)
  # sorted so that make and cmake, which build DYNAMIC_CORE in different
  # orders, agree on the enum values
  set(DYNAMIC_CORE_SORTED ${DYNAMIC_CORE})
  list(SORT DYNAMIC_CORE_SORTED)
  set(DYN_CORES_H_BODY "/* GENERATED by cmake/arch.cmake from DYNAMIC_CORE - do not edit. */\n")
  string(APPEND DYN_CORES_H_BODY "#ifndef OPENBLAS_DYN_CORES_H\n#define OPENBLAS_DYN_CORES_H\n")
  string(APPEND DYN_CORES_H_BODY "#define OPENBLAS_CORE_LIST(X) \\\n")
  foreach (DC ${DYNAMIC_CORE_SORTED})
    string(APPEND DYN_CORES_H_BODY "        X(${DC}) \\\n")
  endforeach ()
  string(APPEND DYN_CORES_H_BODY "        /**/\nenum {\n")
  foreach (DC ${DYNAMIC_CORE_SORTED})
    string(APPEND DYN_CORES_H_BODY "        OPENBLAS_CORE_${DC},\n")
  endforeach ()
  string(APPEND DYN_CORES_H_BODY "        OPENBLAS_NUM_CORES\n};\n#endif\n")
  file(WRITE ${PROJECT_BINARY_DIR}/dyn_cores.h.tmp "${DYN_CORES_H_BODY}")
  execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different
                  ${PROJECT_BINARY_DIR}/dyn_cores.h.tmp ${PROJECT_BINARY_DIR}/dyn_cores.h)
  file(REMOVE ${PROJECT_BINARY_DIR}/dyn_cores.h.tmp)
  # Put each dispatch table and each kernel in its own section so that a static
  # link with --gc-sections can drop the kernel groups a program never calls.
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections")
endif ()
