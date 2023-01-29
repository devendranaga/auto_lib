/**
 * @brief - implements gzip compression interface
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2022-present All rights reserved
 */
#ifndef __AUTO_OS_LIB_ZSTD_COMPRESS_H__
#define __AUTO_OS_LIB_ZSTD_COMPRESS_H__

#include <compress.h>
#include <zstd.h>

namespace auto_os::lib {

class zstd_compress :  public compress {
    public:
        explicit zstd_compress(const std::string filename, const std::string mode);
        virtual ~zstd_compress();

        int write_buff(uint8_t *buff, size_t buff_size);
        int read_buff(uint8_t *buff, size_t buff_size);
};

class zstd_file_compress : public file_compress {
    public:
        explicit zstd_file_compress();
        virtual ~zstd_file_compress();

        int compress_file(const std::string in_file, const std::string out_file);
        int decompress_file(const std::string in_file, const std::string out_file);

    private:
        void *bufin_;
        void *bufout_;
        uint32_t bufin_size_;
        uint32_t bufout_size_;
        ZSTD_CCtx *zstd_cctx_;
        ZSTD_DCtx *zstd_dctx_;
};

}

#endif

