/**
 * @brief - implements helpers
 *
 * @copyright - All rights reserved Devendra Naga (devendra.aaru@outlook.com) 2020-present
 */
#ifndef __AUTO_LIB_HELPERS_H__
#define __AUTO_LIB_HELPERS_H__

#include <types.h>
#include <unistd.h>
#include <stdlib.h>

namespace auto_os::lib {

// Logs to stdout
#define LOG_STDOUT(fmt, ...) fprintf(stdout, fmt, __VA_ARGS__)

// Logs to stderr
#define LOG_STDERR(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)

// safely close a file descriptor
#define AUTO_OS_SAFE_CLOSE_FD(__fd) {\
    if (__fd >= 0) { close(__fd); __fd = -1; } \
}

// safely free memory pointer allocated by a c malloc / calloc API
#define AUTO_OS_SAFE_FREE_MEM_C(__ptr) {\
    if (__ptr) { free(__ptr); } \
}

/**
 * @brief - hexdump contents in a line
 *
 * @param in buf - buffer input
 * @param in buf_len - size of buffer
 */
void hexdump(const uint8_t *buf, size_t buf_len);

/**
 * @brief - hexdump contents in a line
 * 
 * @param in text - text message to print
 * @param in buf - buffer content to print
 * @param in buf_len - length of the buffer content to print
 */
void hexdump(const std::string text, const uint8_t *buf, size_t buf_len);

/**
 * @brief - swap 16 bits
 *
 * @param in source - source 16 bit data
 * 
 * @return returns network endian source or vice versa
 */
uint16_t bswap16b(uint16_t source);

/**
 * @brief - swap 32 bits
 *
 * @param in source - source 32 bit data
 * 
 * @return returns network endian source or vice versa
 */
uint32_t bswap32b(uint32_t source);

/**
 * @brief - swap 64 bits
 *
 * @param in source - source 64 bit data
 * 
 * @return returns network endian source or vice versa
 */
uint64_t bswap64b(uint64_t source);

void runtime_err(const char *fmt, ...);
void system_err(int err, const char *fmt, ...);

int convert_to_int(const std::string val, int &val_int);
int convert_to_uint(const std::string val, uint32_t &val_int);
int convert_to_hex(const std::string val, uint32_t &val_int);
int convert_to_double(const std::string val, double &val_double);
int convert_to_mac(const std::string val, uint8_t *mac);
int compare_mac(uint8_t *src, uint8_t *dst);
void convert_mac_to_str(std::string &mac_str, uint8_t *mac);

class console_color_output {
    public:
        ~console_color_output();

        static console_color_output *instance()
        {
            static console_color_output output;
            return &output;
        }

        void info(const char *msg);
        void verbose(const char *msg);
        void debug(const char *msg);
        void warning(const char *msg);
        void fatal(const char *msg);
        void error(const char *msg);

    private:
        explicit console_color_output() { }
};

}

#endif


