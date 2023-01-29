/**
 * @brief - implements main test code
 *
 * @copyright - 2021 - present All rights reserved Devendra.aaru@gmail.com
 */
#include <iostream>
#include <string>
#include <memory>

#if 0
int test_mqtt();
int test_fileio();
int test_event_loop_server();
int test_event_loop_client();
int test_event_loop();
int test_profiler();
int test_logger();
int test_canif();
int test_netif();
int test_random_generator();
int test_socketapi();
int test_seccomp();
int test_cpuinfo();
int test_file_info();
int test_leds();
int test_rtc();
int test_cpufreq();
int test_thermal();
int test_mmap_api();
int test_mcast();
int test_compress();
#endif
int test_cpuusage();

/**
 * @brief defines the test cases to be automated
 */
static struct test_case_def {
    const std::string test_name;
    int (*func)(void);
    bool auto_exec;
} test_case_set[] = {
#if 0
    {"test_evt_loop_server",    test_event_loop_server,     false},
    {"test_evt_loop_client",    test_event_loop,            false},
    {"test_profiler",           test_profiler,              true},
    {"test_leds",               test_leds,                  true},
    {"test_compress",           test_compress,              true},
    {"test_rtc",                test_rtc,                   true},
    {"test_fileio",             test_fileio,                true},
    //{"test_mqtt",               test_mqtt,                  true},
    {"test_logger",             test_logger,                true},
    {"test_canif",              test_canif,                 true},
    {"test_cpuinfo",            test_cpuinfo,               true},
    {"test_netif",              test_netif,                 true},
    {"test_random_generator",   test_random_generator,      true},
    {"test_socketapi",          test_socketapi,             true},
    //{"test_seccomp",            test_seccomp,               true},
    {"test_file_info",          test_file_info,             true},
    {"test_cpufreq",            test_cpufreq,               true},
    {"test_thermal",            test_thermal,               true},
    {"test_mmap_api",           test_mmap_api,              true},
    {"test_mcast",              test_mcast,                 false},
#endif
    {"test_cpuusage",           test_cpuusage,              true},
};

int main(int argc, char **argv)
{
    uint32_t i;
    int ret;

    if (argc < 2) {
        fprintf(stderr, "<%s> <command> where command is \n", argv[0]);
        for (i = 0; i < sizeof(test_case_set) / sizeof(test_case_set[0]); i ++) {
            fprintf(stderr, "\t\t <%s>\n", test_case_set[i].test_name.c_str());
        }
        fprintf(stderr, "\n");
        return -1;
    }

    if (std::string(argv[1]) == "test_all") {
        for (i = 0; i < sizeof(test_case_set) / sizeof(test_case_set[0]); i ++) {
            if (test_case_set[i].auto_exec) {
                ret = test_case_set[i].func();
                if (ret < 0) {
                    fprintf(stderr, "test [%s] failed\n", test_case_set[i].test_name.c_str());
                }
            }
        }
    } else {
        for (i = 0; i < sizeof(test_case_set) / sizeof(test_case_set[0]); i ++) {
            if (std::string(argv[1]) == test_case_set[i].test_name) {
                ret = test_case_set[i].func();
                if (ret < 0) {
                    fprintf(stderr, "test [%s] failed\n", test_case_set[i].test_name.c_str());
                } else {
                    fprintf(stderr, "test [%s] success\n", test_case_set[i].test_name.c_str());
                }
                break;
            }
        }
    }
    return 0;
}

