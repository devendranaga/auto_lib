/**
 * @brief - implements compress factory
 * 
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2021-present All rights reserved
 */
#ifndef __AUTO_OS_LIB_COMPRESS_FACTORY_H__
#define __AUTO_OS_LIB_COMPRESS_FACTORY_H__

#include <compress.h>
#include <gzip_compress.h>
#include <zstd_compress.h>

namespace auto_os::lib {

/**
 * @brief - implements compressor factory interface
 */
class compressor_factory {
    public:
        ~compressor_factory() { }
        compressor_factory(const compressor_factory &) = delete;
        compressor_factory &operator=(const compressor_factory &) = delete;
        compressor_factory(const compressor_factory &&) = delete;
        compressor_factory &&operator=(const compressor_factory &&) = delete;

        /**
         * @brief - get compressor factory instance
         *
         * @return factory instance
         */
        static compressor_factory *instance()
        {
            static compressor_factory fac;
            return &fac;
        }

        /**
         * @brief - create compressor buffer instance
         * 
         * @param in alg - compression algorithm
         * @param in filename - filename
         * @param in mode - file mode
         * 
         * @return returns gzip compressor instance if algorithm is gz
         */
        std::shared_ptr<compress> create_buf_compressor(
                                         compression_algorithm alg,
                                         const std::string filename,
                                         const std::string mode)
        {
            if (alg == compression_algorithm::gz) {
                return std::make_shared<gzip_compress>(filename, mode);
            } else if (alg == compression_algorithm::zstd) {
                return std::make_shared<zstd_compress>(filename, mode);
            }
            return nullptr;
        }

        /**
         * @brief - create file compressor
         * 
         * @param in alg - compression algorithm
         * 
         * @return return gzip file compressor instance if algorithm is gz
         */
        std::shared_ptr<file_compress> create_file_compressor(
                                                        compression_algorithm alg)
        {
            if (alg == compression_algorithm::gz) {
                return std::make_shared<gzip_file_compress>();
            } else if (alg == compression_algorithm::zstd) {
                return std::make_shared<zstd_file_compress>();
            }
            return nullptr;
        }

    private:
        explicit compressor_factory() { }
};

}

#endif

