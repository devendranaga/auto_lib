/**
 * @brief - defines mmap file API
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2022-present All rights reserved
 */
#ifndef __AUTO_LIB_MMAP_API_H__
#define __AUTO_LIB_MMAP_API_H__

#include <iostream>

namespace auto_os::lib {

/**
 * @brief - map file contents to disk once all writes are complete
 */
class map_file {
    public:
        explicit map_file() = default;
        ~map_file() = default;

        /**
         * @brief - open file
         *
         * @param in filename - name of the file
         * @param in mode - mode of file "w" for write "r" for read
         * @param in filesize - size of the file - required to map memory
         *
         * @return 0 on success -1 on failure
         */
        int open_file(const std::string filename,
                      const std::string mode,
                      const size_t filesize);

        /**
         * @brief - write file
         *
         * @param in data - input
         * @param description write content to the memory and eventually
         *                  to the file once close_file or sync_file called
         *
         * @return number of bytes on success -1 on failure
         */
        int write_file(const std::string &data);

        /**
         * @brief - write file
         *
         * @param in data - input
         * @param in data_len - length of buffer
         *
         * @param description write content to the memory and eventually
         *                    to the file once close_file or sync_file called
         *
         *
         * @return number of bytes on success -1 on failure
         */
        int write_file(const uint8_t *data,  size_t data_len);

        /**
         * @brief - read data from the file
         *
         * @param in buf - input buffer
         * @param in buf_size - length of buffer
         *
         * @param description read content from the memory
         *                    mapped memory is already read
         *
         *
         * @return number of bytes on success -1 on failure
         */
        int read_file(char **buf, size_t &buf_size);

        /**
         * @brief - read data from the file
         *
         * @param in buf - input buffer
         * @param in buf_size - length of buffer
         *
         * @param description read content from the memory
         *                    mapped memory is already read
         *
         *
         * @return number of bytes on success -1 on failure
         */
        int read_file(uint8_t **buf, size_t &buf_size);

        /**
         * @brief - sync contents of the file to disk
         */
        void sync_file();

        /**
         * @brief - close file
         */
        void close_file();

    private:
        void *mem_;
        int fd_;
        size_t off_;
        std::string filename_;
        std::string mode_;
        size_t filesize_;
};

}

#endif


