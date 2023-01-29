#ifndef __AUTO_LIB_SECCOMP_FILTER_H__
#define __AUTO_LIB_SECCOMP_FILTER_H__

#include <string>
#include <vector>
#include <seccomp.h>

namespace auto_os::lib {

class seccomp_filter {
    public:
        explicit seccomp_filter();
        ~seccomp_filter();

        int restrict_network(std::vector<std::pair<int, int>> set);

    private:
        scmp_filter_ctx scmp_ctx;
};

}

#endif

