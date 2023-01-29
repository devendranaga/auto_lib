#ifndef __AUTO_LIB_CAPABILITIES_INTF_H__
#define __AUTO_LIB_CAPABILITIES_INTF_H__

#include <string>
#include <vector>

namespace auto_os::lib {

class capabilities_intf {
    public:
        explicit capabilities_intf();
        ~capabilities_intf();

        int set_capability(std::vector<std::string> &list);
        void get_supported_caps(std::vector<std::string> &caps);
};

}

#endif

