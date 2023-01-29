/**
 * @brief - implements gzip compression interface
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2022-present All rights reserved
 */
#ifndef __AUTO_OS_LIB_GZIP_COMPRESS_H__
#define __AUTO_OS_LIB_GZIP_COMPRESS_H__

#include <compress.h>
#include <zlib.h>

namespace auto_os::lib {

class gzip_compress :  public compress {
    public:
        explicit gzip_compress(const std::string filename, const std::string mode);
        virtual ~gzip_compress();

        int write_buff(uint8_t *buff, size_t buff_size);
        int read_buff(uint8_t *buff, size_t buff_size);
};

class gzip_file_compress : public file_compress {
    public:
        explicit gzip_file_compress();
        virtual ~gzip_file_compress();

        int compress_file(const std::string in_file, const std::string out_file);
        int decompress_file(const std::string in_file, const std::string out_file);
};

}

#endif

