//
// Created by devnaga on 5/30/20.
//

#ifndef AUTO_OS_MEMORY_MGMT_H
#define AUTO_OS_MEMORY_MGMT_H

/**
 * Linux OS definitions for memory management routines
 */
#if defined(CONFIG_OS_LINUX) && defined(CONFIG_LIBC_SUPPORT)

#include <stdlib.h>

#define os_malloc malloc
#define os_calloc calloc
#define os_realloc realloc
#define os_free free

#endif

#endif //AUTO_OS_MEMORY_MGMT_H
