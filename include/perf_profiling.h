/**
 * @brief - implements a performance profiler
 * 
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * 
 * @copyright - 2021-present All rights reserved
 */
#ifndef __PERF_PROFILING_H__
#define __PERF_PROFILING_H__

#include <iostream>
#include <vector>
#include <memory>
#include <time_date.h>
#include <logger.h>

namespace auto_os::lib {

/**
 * @brief - profiling data of a given sample
 */
struct profiling_data {
    std::string     profile_id;
    double          avg;
    double          standard_deviation;
    double          min;
    double          max;
};

/**
 * @brief - profiler block for each performance indicator
 */
class profiler_block {
    public:
        explicit profiler_block(std::string profile_id) noexcept;
        ~profiler_block();

        void sample_start();
        void sample_stop();

        /**
         * @brief - clear profiler data
         */
        inline void clear() { delta_values_.clear(); }

        /**
         * @brief - dump profiler data
         */
        void dump();

        /**
         * @brief - dump profiler data
         *
         * @param in log - log pointer to use for printing the profiling info
         */
        void dump(std::shared_ptr<auto_os::lib::logger> &log);

        /**
         * @brief - get profiler data
         *
         * @param in profiler_data - profiler data
         */
        void get_results(profiling_data &);

    private:
        uint32_t start_sec_;
        long long start_nsec_;
        uint32_t stop_sec_;
        long long stop_nsec_;
        std::string profile_id_;
        std::vector<double> delta_values_;
        double avg_;
        double standard_deviation_;
        double min_;
        double max_;
        void calc_perf_results();
};

class perf_profiler {
    public:
        explicit perf_profiler() noexcept;
        ~perf_profiler();

        std::shared_ptr<profiler_block> create_new(std::string profile_id);
        void dump();
        void get_results(std::vector<profiling_data> &);

    private:
        std::vector<std::shared_ptr<profiler_block>> profiles_;
};

}

#endif

