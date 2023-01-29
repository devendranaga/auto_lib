/**
 * @brief - implements cpu usage tests
 * 
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * 
 * @copyright - 2021-present All rights reserved
 */
#include <iostream>
#include <auto_lib.h>

int test_cpuusage()
{
    auto_os::lib::cpu_use cpu;
    int count  = 10;

    while (count > 0) {
        double usage = cpu.get();

        std::this_thread::sleep_for(std::chrono::seconds(1));
        printf("cpu usage [%f]\n", usage);
        count --;
    }

    return 0;
}

