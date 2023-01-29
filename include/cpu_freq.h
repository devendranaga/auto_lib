/**
 * 
 * @brief - implements cpu frequency
 * 
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2021-present All rights reserved
 */
#ifndef __AUTO_LIB_CPU_FREQ_H__
#define __AUTO_LIB_CPU_FREQ_H__

#include <string>
#include <vector>
#include <stdint.h>
#include <logger.h>

namespace auto_os::lib {

/**
 * @brief - cpu scaling governor
 */
enum class cpu_scaling_governor {
    eConservative,
    eOndemand,
    eUserspace,
    ePowersave,
    ePerformance,
    eUnknown,
};

/**
 * @brief - interface for cpu frequency
 */
class cpu_freq {
    public:
        explicit cpu_freq() = default;
        ~cpu_freq() = default;

        /**
         * @brief - get supported governors
         *
         * @param in gov - scaling governors
         *
         * @return 0 on success -1 on failure
         */
        virtual int get_supp_governors(std::vector<cpu_scaling_governor> &gov) = 0;

        /**
         * @brief - get current governor
         *
         * @return returns cpu_scaling_governor
         */
        virtual cpu_scaling_governor get_cur_governor() = 0;

        /**
         * @brief - get cpu governor string
         *
         * @param in gov - scaling governor
         * @param in gov_str - scaling governor in string format
         */
        virtual void get_cpu_gov_str(cpu_scaling_governor &gov, std::string &gov_str) = 0;

        /**
         * @brief - set governor
         *
         * @param in gov - scaling governor
         *
         * @return 0 on success -1 on failure
         */
        virtual int set_governor(const cpu_scaling_governor gov) = 0;

        /**
         * @brief - has cpu frequency changeable
         *
         * @return unsupported
         */
        virtual bool has_cpu_freq_changeable() = 0;

        /**
         * @brief - get supported cpu frequency
         *
         * @return unsupported
         */
        virtual int get_supp_cpu_freq(std::vector<uint32_t> &freq) = 0;

        /**
         * @brief - set cpu frequency
         *
         * @return unsupported
         */
        virtual int set_cpu_freq(const uint32_t freq) = 0;
};

/**
 * @brief - supported hardware for cpu frequency
 */
enum class cpu_freq_device {
    eNanopi_R1,
};

/**
 * @brief - cpu frequency factory to create devices
 */
class cpu_freq_factory {
    public:
        explicit cpu_freq_factory() = default;
        ~cpu_freq_factory() = default;

        /**
         * @brief - create cpu frequency governor
         *
         * @param in device - type of hardware
         *
         * @return std::unique_ptr to the governor
         */
        std::unique_ptr<cpu_freq> create(const cpu_freq_device device);
};

}

#endif


