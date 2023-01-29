/**
 * @brief - implements memory usage
 * 
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2021-present All rights reserved
 */
#ifndef __AUTO_OS_LIB_MEMORY_USE_H__
#define __AUTO_OS_LIB_MEMORY_USE_H__

#include <iostream>

namespace auto_os::lib {

/**
 * @brief - defines /proc/memory equal structure
 */
struct memory_info {
    uint32_t mem_total_kbytes;
    uint32_t mem_free_kbytes;
    uint32_t mem_available_kbytes;
    uint32_t buffers_kbytes;
    uint32_t cached_kbytes;
    uint32_t swap_cached_kbytes;
    uint32_t active_anon_kbytes;
    uint32_t inactive_anon_kbytes;
    uint32_t active_file_kbytes;
    uint32_t inactive_file_kbytes;
    uint32_t unevictable_kbytes;

    memory_info()
    {
        mem_total_kbytes =
        mem_free_kbytes =
        mem_available_kbytes =
        buffers_kbytes =
        cached_kbytes =
        swap_cached_kbytes =
        active_anon_kbytes =
        inactive_anon_kbytes =
        active_file_kbytes =
        inactive_file_kbytes =
        unevictable_kbytes = 0;
    }
};

/**
 * @brief - memory info .. parses /proc/meminfo on linux
 */
class mem_info_use {
    public:
        explicit mem_info_use();
        ~mem_info_use();

        /**
         * @brief - get the memory info used, free and available
         *
         * @param in info - memory info
         *
         * @return 0 on success -1 on failure
         */
        int get(memory_info &info);
};

}

#endif

