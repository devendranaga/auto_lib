/**
 * @brief - implements time date header
 *
 * @copyright All rights reserved Devendra Naga (devnaga@tuta.io) 2020-present
 */
#ifndef __AUTO_LIB_TIMEDATE_H__
#define __AUTO_LIB_TIMEDATE_H__

namespace auto_os::lib {

/**
 * @brief - timestamp data structure
 */
struct timestamp {
    uint32_t year;
    uint32_t mon;
    uint32_t day;
    uint32_t hour;
    uint32_t min;
    uint32_t sec;
    uint32_t msec;
    uint64_t nsec;

    explicit timestamp()
    {
        year = 0;
        mon  = 0;
        day  = 0;
        hour = 0;
        min  = 0;
        sec  = 0;
        msec = 0;
        nsec = 0;
    }
};

/**
 * @brief - get timestamp from sec
 *
 * @param in sec - second
 * @param out t - timestamp converted
 *
 * @return 0 on success -1 on failure
 */
int get_timestamp_from_sec(uint32_t sec, timestamp &t);

/**
 * @brief - get timestamp into "timestamp" struct
 *
 * @param in ts - timestamp
 *
 * @return 0 on success -1 on failure
 */
int get_timestamp(timestamp &ts);

/**
 * @brief - get monotonic timestamp
 * @param in sec - seconds
 * @param in nsec - nanoseconds
 *
 * @return 0 on success -1 on failure
 */
int get_monotonic_time(uint32_t &sec, long long &nsec);
int get_process_cputime(uint32_t &sec, long long &nsec);

/**
 * @brief - get realtime clock
 *
 * @param in sec - seconds
 * @param in nsec - nanoseconds
 *
 * @return 0 on success -1 on failure
 */
int get_wallclock_time(uint32_t &sec, long long &usec);
int make_timestamp_str(std::string &timestamp);
void get_delta_timestamp(uint32_t start_sec, long long start_nsec,
                        uint32_t stop_sec, long long stop_nsec,
                        uint32_t &delta_sec, long long &delta_nsec);

}

#endif


