/**
 * @brief - Implements All Error Codes in Auto OS
 */
#ifndef __AUTO_OS_ERRORS_H__
#define __AUTO_OS_ERRORS_H__

namespace auto_os::errors {

enum class error_type {
    ERROR_NO_ERROR,
    ERROR_INVALID_FILE_FD,
    /* Invalid /dev/rtc or /dev/rtc0 fd */
    ERROR_INVALID_RTC_FD,

    /* Failed to open network stats file */
    ERROR_NETWORK_STATS_FILE_OPEN_FAILURE,

    /* Failed to read network stats file */
    ERROR_NETWORK_STATS_FILE_READ_FAILURE,

    /* failed to open proc hostname file */
    ERROR_PROC_HOSTNAME_OPEN_FAILURE,

    /* File writes are failed */
    ERROR_FILE_IO_WRITES_FAILURE,

    ERROR_PROC_HOSTNAME_SET_FAILURE,
};

/**
 * @brief - Get error in string format.
 *
 * @param in type - error type.
 *
 * @return string value of the error type.
 */
const std::string get_error_str(const error_type type);

}

#endif

