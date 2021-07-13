#ifndef __ENV_WRAPPER_H__
#   define __ENV_WRAPPER_H__        1

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

//! \name The macros to identify the compiler
//! @{

//! \note for IAR
#ifdef __IS_COMPILER_IAR__
#   undef __IS_COMPILER_IAR__
#endif
#if defined(__IAR_SYSTEMS_ICC__)
#   define __IS_COMPILER_IAR__                  1
#endif

//! \note for arm compiler 5
#ifdef __IS_COMPILER_ARM_COMPILER_5__
#   undef __IS_COMPILER_ARM_COMPILER_5__
#endif
#if ((__ARMCC_VERSION >= 5000000) && (__ARMCC_VERSION < 6000000))
#   define __IS_COMPILER_ARM_COMPILER_5__       1
#endif
//! @}

//! \note for arm compiler 6
#ifdef __IS_COMPILER_ARM_COMPILER_6__
#   undef __IS_COMPILER_ARM_COMPILER_6__
#endif
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#   define __IS_COMPILER_ARM_COMPILER_6__       1
#endif

#ifdef __IS_COMPILER_LLVM__
#   undef  __IS_COMPILER_LLVM__
#endif
#if defined(__clang__) && !__IS_COMPILER_ARM_COMPILER_6__
#   define __IS_COMPILER_LLVM__                 1
#else
//! \note for gcc
#   ifdef __IS_COMPILER_GCC__
#       undef __IS_COMPILER_GCC__
#   endif
#   if defined(__GNUC__) && !(  defined(__IS_COMPILER_ARM_COMPILER_5__)         \
                            ||  defined(__IS_COMPILER_ARM_COMPILER_6__)         \
                            ||  defined(__IS_COMPILER_LLVM__))
#       define __IS_COMPILER_GCC__              1
#   endif
//! @}
#endif
//! @}


#ifndef   __ASM
  #define __ASM                                  __asm
#endif


#if defined(__clang__) || defined(__IS_COMPILER_ARM_COMPILER_5__)
#   undef __force_inline
#   define __force_inline       __attribute__((always_inline))

#   undef __always_inline
#   define __always_inline      __attribute__((always_inline))   

#   undef __unused
#   define __unused             __attribute__((unused))

#   undef __packed_aligned
#   define __packed_aligned     __attribute__((packed, aligned(4)))
#endif

#undef __STRING
#   define __STRING(__S)        #__S


#undef offsetof
#if defined(__clang__) || defined(__IS_COMPILER_GCC__)
#   define offsetof(st, m)      __builtin_offsetof(st, m)
#else
#   undef static_assert     
#   define static_assert(...)
#   define offsetof(st, m)      ((size_t)((char *)&((st *)0)->m - (char *)0))
#endif

typedef unsigned int        uint;


/**
  \brief   Get Control Register
  \details Returns the content of the Control Register.
  \return               Control Register value
 */
static __force_inline uint32_t __get_current_exception(void)
{
  uint32_t result;

  __ASM volatile ("MRS %0, ipsr" : "=r" (result) );
  return(result);
}


#include "pico/platform.h"

#endif
