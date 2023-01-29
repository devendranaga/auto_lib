#ifndef __AUTO_LIB_THREAD_INTF_H__
#define __AUTO_LIB_THREAD_INTF_H__

#include <thread>

namespace auto_os::lib {

enum class scheduler_policy {
    FIFO,
    RR,
};

int set_schedule_cpu(int cpu_no, std::thread::native_handle_type tid);
int set_schedule_policy(int priority, scheduler_policy policy, std::thread::native_handle_type tid);

}

#endif
