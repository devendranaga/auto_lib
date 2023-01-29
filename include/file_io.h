/**
 * @brief - implements file i/o
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 *
 * @copyright - 2022-present All rights reserved
 */
#ifndef __AUTO_LIB_FILE_IO_H__
#define __AUTO_LIB_FILE_IO_H__

#include <auto_os_errors.h>

namespace auto_os::lib {

/**
 * @brief - defines file i/o
 */
class file_io {
    public:
        /**
         * @brief - open a file
         *
         * @param in filename - filename
         * @param in mode - file mode "w" for write "r" for read "a" for append
         */
        explicit file_io(const std::string filename, const std::string mode);
        explicit file_io();
        ~file_io();

        /**
         * @brief - flush the contents of the file to the disk / flash
         */
        void flush();

        /**
         * @brief - open the file
         *
         * @param in filename - filename
         * @param in mode - file mode "w" for write "r" for read "a" for append
         *
         * @return 0 on success -1 on failure
         */
        int open_file(const std::string filename, const std::string mode);

        /**
         * @brief - read data from the file
         *
         * @param in data - data input
         * @param in data_len - length of data
         *
         * @return number of bytes read from the file
         */
        int read_data(uint8_t *data, size_t data_len);

        /**
         * @brief - write data to the file
         *
         * @param in data - data input
         * @param in data_len - length of data
         *
         * @return number of bytes written to the file
         */
        int write_data(const uint8_t *data, size_t data_len);

        /**
         * @brief - read data from the file
         *
         * @param in data - data input
         * @param in data_len - length of data
         *
         * @return number of bytes read from the file
         */
        int read_data(char *data, size_t data_len);

        /**
         * @brief - write data to the file
         *
         * @param in data - data input
         * @param in data_len - length of data
         *
         * @return number of bytes written to the file
         */
        int write_data(const char *data, size_t data_len);

        /**
         * @brief - copy file from source to destination.
         *
         * @param in file_src - source file.
         * @param in file_dst - destination file.
         *
         * @return ERROR_NO_ERROR on success.
         * @return ERROR_FILE_IO_WRITES_FAILURE on failure.
         */
        auto_os::errors::error_type
        copy_file(const std::string &file_src, const std::string &file_dst);

        /**
         * @brief - close file
         */
        void close_file();

    private:
        int fd_;
};

}

#endif


