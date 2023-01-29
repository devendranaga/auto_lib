/**
 * @brief - Implements cpu usage
 * 
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * 
 * @copyright - 2021-present All Rights Reserved
 */
#ifndef __AUTO_LIB_CPU_USE_H__
#define __AUTO_LIB_CPU_USE_H__

namespace auto_os::lib {

/**
 * @brief - implements getting cpu usage from the linux
 * 
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * 
 * @copyright - 2021-present All Rights Reserved
 */
class cpu_use {
    public:
        explicit cpu_use();

        explicit cpu_use(const cpu_use &) = delete;
        cpu_use &operator=(const cpu_use &) = delete;
        explicit cpu_use(const cpu_use &&) = delete;
        cpu_use &&operator=(const cpu_use &&) = delete;

        ~cpu_use();

        /**
         * @brief - Get cpu usage
         *
         * @details - Call this every 1 second to get accurate usage details
         * 
         * @return cpu usage in percentage
         */
        double get();

    private:
        int fd_;
};

}

#endif


