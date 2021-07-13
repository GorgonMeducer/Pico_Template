
#include "cmsis_compiler.h"


void __attribute__((noreturn)) panic(const char *fmt, ...)
{
    UNUSED_PARAM(fmt);
    
    while(1) {
        __ASM("nop");
    }
}