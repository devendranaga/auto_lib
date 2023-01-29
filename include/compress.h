/**
 * @brief - implement compress abstract class
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2021-present All rights reserved
 */
#ifndef __AUTO_OS_LIB_COMPRESS_H__
#define __AUTO_OS_LIB_COMPRESS_H__

#include <iostream>
#include <memory>

namespace auto_os::lib {

/**
 * @brief - list of supported compression algorithms
 */
enum class compression_algorithm {
    // gzip compression
    gz,
    // zstd compression
    zstd,
};

/**
 * @brief - implements compress interface
 */
class compress {
    public:
        explicit compress() = default;
        ~compress() = default;

        virtual int write_buff(uint8_t *buff, size_t buff_size) = 0;
        virtual int read_buff(uint8_t *buff, size_t buff_size) = 0;
};

/**
 * @brief - implements file compress interface
 */
class file_compress {
    public:
        explicit file_compress() = default;
        ~file_compress() = default;

        /**
         * @brief - compress file
         * 
         * @param in filename - input filename 
         * @param out out_filename - output filename 
         * @return 0 on success -1 on failure
         */
        virtual int compress_file(const std::string filename, const std::string out_filename) = 0;

        /**
         * @brief - decompress file
         * 
         * @param in filename - input filename 
         * @param out out_filename - output filename 
         * @return 0 on success -1 on failure
         */
        virtual int decompress_file(const std::string filename, const std::string out_filename) = 0;
};

}

#endif

