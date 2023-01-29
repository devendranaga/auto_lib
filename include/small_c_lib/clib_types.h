//
// Created by devnaga on 5/30/20.
//

#ifndef AUTO_OS_CLIB_TYPES_H
#define AUTO_OS_CLIB_TYPES_H

#if defined(CONFIG_OS_LINUX) && defined(CONFIG_LIBC_SUPPORT)
// contains stdio.h
#include <stdio.h>

#else
#define NULL (void *)0
#endif

#endif //AUTO_OS_CLIB_TYPES_H
