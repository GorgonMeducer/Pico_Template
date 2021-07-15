/****************************************************************************
*  Copyright 2021 Gorgon Meducer (Email:embedded_zhuoran@hotmail.com)       *
*                                                                           *
*  Licensed under the Apache License, Version 2.0 (the "License");          *
*  you may not use this file except in compliance with the License.         *
*  You may obtain a copy of the License at                                  *
*                                                                           *
*     http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                           *
*  Unless required by applicable law or agreed to in writing, software      *
*  distributed under the License is distributed on an "AS IS" BASIS,        *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
*  See the License for the specific language governing permissions and      *
*  limitations under the License.                                           *
*                                                                           *
****************************************************************************/

/*============================ INCLUDES ======================================*/
#include "cmsis_compiler.h"


/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
/*============================ IMPLEMENTATION ================================*/

void __attribute__((noreturn)) panic(const char *fmt, ...)
{
    UNUSED_PARAM(fmt);
    
    while(1) {
        __ASM("nop");
    }
}

#if __IS_COMPILER_ARM_COMPILER_6__
__asm(".global __use_no_semihosting\n\t");
#   ifndef __MICROLIB
__asm(".global __ARM_use_no_argv\n\t");
#   endif

#if defined(__MICROLIB)
_ARMABI_NORETURN 
void __aeabi_assert(const char *chCond, const char *chLine, int wErrCode) 
{
    UNUSED_PARAM(chCond);
    UNUSED_PARAM(chLine);
    UNUSED_PARAM(wErrCode);
    while(1) {
        __NOP();
    }
}
#endif

void _ttywrch(int ch)
{
    UNUSED_PARAM(ch);
}

#include <rt_sys.h>

FILEHANDLE $Sub$$_sys_open(const char *name, int openmode)
{
    UNUSED_PARAM(name);
    UNUSED_PARAM(openmode);
    return 0;
}



__NO_RETURN
void _sys_exit(int ret)
{
    UNUSED_PARAM(ret);
    while(1) {}
}

#endif
