/**
 * @brief - implements version info
 * 
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2021-present All rights reserved
 */
#ifndef __AUTO_OS_LIB_VERSION_H__
#define __AUTO_OS_LIB_VERSION_H__

namespace auto_os::lib {

struct version_info_msg {
    int major;
    int minor;
    int patch;
};

class version_info {
    public:
        explicit version_info() noexcept
        {
#define AUTO_LIB_MAJOR 1
#define AUTO_LIB_MINOR 0
#define AUTO_LIB_PATCH 0
            msg_.major = AUTO_LIB_MAJOR;
            msg_.minor = AUTO_LIB_MINOR;
            msg_.patch = AUTO_LIB_PATCH;
        }
        ~version_info();

        void get(version_info_msg &msg) { msg = msg_; }

    private:
        version_info_msg msg_;
};

}

#endif

