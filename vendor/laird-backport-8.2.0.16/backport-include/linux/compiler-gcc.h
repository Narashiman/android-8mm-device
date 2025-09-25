#ifndef __BACKPORT_LINUX_COMPILER_GCC_H
#define __BACKPORT_LINUX_COMPILER_GCC_H
#include_next <linux/compiler-gcc.h>

#ifndef __alias
#define __alias(symbol)		__attribute__((alias(#symbol)))
#endif

#endif
