/**
 *
 * @brief - Implements the Logger class
 *
 * @author - Devendra Naga (devendra.aarua@outlook.com)
 * @copyright - 2020-present All rights reserved
 */
#ifndef __AUTO_LIB_LOGGER_H__
#define __AUTO_LIB_LOGGER_H__

#include <string>
#include <memory>

namespace auto_os::lib {

/**
 * @brief - Logging Type
 */
enum class logging_type {
    // console logging
    console_logging,
    // dummy logging
    dummy_logging,
    // file logging
    file_logging,
    // syslog logging
    syslog_logging,
};

/**
 * @brief - Log parameters.. internal to the logger
 */
struct log_params {
    uint32_t info;
    uint32_t verbose;
    uint32_t debug;
    uint32_t warning;
    uint32_t error;
    uint32_t fatal;

    void init();
};

/**
 * @brief - A Logger abstract class
 */
class logger {
    public:
        explicit logger() = default;
        ~logger() = default;

        /**
         * @brief - Set application name to appear in console / file logging
         *
         * @param in app_name - application name
         *
         */
        virtual void set_app_name(const std::string app_name) = 0;

        /**
         * @brief - Set log param
         * 
         * @param in params - set info, verbose, debug, error or fatal
         * 
         * set one of these to enable dump,
         * set to 0, the below functions will be disabled
         * even after they are called
         */
        virtual void set_log_params(log_params &params) = 0;

        /**
         * @brief - Dump info message
         * 
         * @param in fmt - log format
         * 
         * @return 0 on success -1 on failure
         */
        virtual int info(const char *fmt, ...) = 0;

        /**
         * @brief - Dump verbose message
         * 
         * @param in fmt - log format
         * 
         * @return 0 on success -1 on failure
         */
        virtual int verbose(const char *fmt, ...) = 0;

        /**
         * @brief - Dump debug message
         * 
         * @param in fmt - log format
         * 
         * @return 0 on success -1 on failure
         */
        virtual int debug(const char *fmt, ...) = 0;

        /**
         * @brief - Dump Warning message
         *
         * @param in fmt - log format
         *
         * @return 0 on success -1 on failure
         */
        virtual int warning(const char *fmt, ...) = 0;

        /**
         * @brief - Dump error message
         * 
         * @param in fmt - log format
         * 
         * @return 0 on success -1 on failure
         */
        virtual int error(const char *fmt, ...) = 0;

        /**
         * @brief - Dump fatal message
         * 
         * @param in fmt - log format
         * 
         * @return 0 on success -1 on failure
         */
        virtual int fatal(const char *fmt, ...) = 0;
};

/**
 * @brief - logger factory creates log classes of various types
 */
class logger_factory {
    public:
        ~logger_factory() = default;
        explicit logger_factory(const logger_factory &) = delete;
        logger_factory &operator=(logger_factory &) = delete;
        explicit logger_factory(const logger_factory &&) = delete;
        logger_factory &&operator=(logger_factory &&) = delete;

        static logger_factory *Instance() {
            static logger_factory f;

            return &f;
        }
        /**
         * @brief - create logging instance
         * 
         * @param in type - logging type (console or file logging)
         *
         * @return shared_ptr to logger instance
         */
        std::shared_ptr<logger> create(logging_type type);

    private:
        explicit logger_factory() = default;
};

/* Macro definitions that help ease the use of logger class */

/**
 * @brief - create console log
 *
 * @param __log - log instance
 * @param __app_name - application name
 */
#define AUTO_LIB_CREATE_CONSOLE_LOG(__log, __app_name) {\
    __log = auto_os::lib::logger_factory::Instance()->create(\
                auto_os::lib::logging_type::console_logging);\
    __log->set_app_name(__app_name);\
}

#define AUTO_LIB_LOG_INFO(__log, fmt, ...)\
    __log->info(fmt, ##__VA_ARGS__)

#define AUTO_LIB_LOG_VERBOSE(__log, fmt, ...)\
    __log->verbose(fmt, ##__VA_ARGS__)

#define AUTO_LIB_LOG_DEUBG(__log, fmt, ...)\
    __log->debug(fmt, ##__VA_ARGS__)

#define AUTO_LIB_LOG_ERROR(__log, fmt, ...)\
    __log->error(fmt, ##__VA_ARGS__)

#define AUTO_LIB_LOG_FATAL(__log, fmt, ...)\
    __log->fatal(fmt, ##__VA_ARGS__)

#define AUTO_LIB_LOG_TRACE_START_OF_FUNC(__log, __fmt)\
    __log->verbose("%s: start of %s:%u\n", __fmt, __func__, __LINE__)

#define AUTO_LIB_LOG_TRACE_END_OF_FUNC(__log, __fmt)\
    __log->verbose("%s: end of %s:%u\n", __fmt, __func__, __LINE__)

#define AUTO_LIB_LOG_TRACE(__log, __fmt)\
    __log->verbose("%s: %s:%u\n", __fmt, __func__, __LINE__)

}

#endif

