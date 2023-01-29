#ifndef __AUTO_LIB_RTC_DEVICE_H__
#define __AUTO_LIB_RTC_DEVICE_H__

#include <time_date.h>

#include "auto_os_errors.h"

namespace auto_os::lib {

class linux_rtc {
    public:
        explicit linux_rtc();
        ~linux_rtc();

        auto_os::errors::error_type read_time(timestamp &t);

    private:
        int fd_;
};

}

#endif

