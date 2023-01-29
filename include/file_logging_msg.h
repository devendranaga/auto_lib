/**
 *
 * @brief - implements file logging interface with Logger
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2021-present All rights reserved
 */
#ifndef __AUTO_OS_LIB_FILE_LOGGING_MSG_H__
#define __AUTO_OS_LIB_FILE_LOGGING_MSG_H__

#include <stdint.h>

/**
 * @brief - file logging type
 */
enum auto_os_file_logging_type {
    eFile_Logging_Log_Msg = 0,
};

/**
 * @brief - log message level / type
 */
enum auto_os_file_log_msg_type {
    eFile_Logging_Type_Info = 0,
    eFile_Logging_Type_Debug,
    eFile_Logging_Type_Warn,
    eFile_Logging_Type_Error,
    eFile_Logging_Type_Verbose,
    eFILE_Logging_Type_Fatal,
};

/**
 * @brief - log message sent from apps to auto_logger daemon
 */
struct auto_os_file_log_msg {
    // log message type
    enum auto_os_file_log_msg_type type;

    // log message .. length is found by received message length from transport protocol
    char data[0];
} __attribute__ ((__packed__));

/**
 * @brief - logging message wrapper
 */
struct auto_os_file_logging_msg {
    // type
    //
    // for logging- it is Log_Msg
    enum auto_os_file_logging_type type;
    // data
    //
    // log mesasge data
    uint8_t data[0];
} __attribute__((__packed__));

#endif

