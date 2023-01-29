/**
 * @brief - implements random number generator
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 *
 * @copyright - 2021-presesnt All Rights Reserved
 */
#ifndef __AUTO_LIB_RAND_GENERATOR_H__
#define __AUTO_LIB_RAND_GENERATOR_H__

#include <iostream>
#include <string>
#include <memory>

namespace auto_os::lib {

/**
 * @brief - define random generator type to use
 */
enum class random_generator_type {
    /* linux random generator */
    elinux_random = 0,

    /* hardware random - not supported */
    ehw_random = 1,
    eunsupported,
};

/**
 * @brief - abstract random generator
 */
class random_generator {
    public:
        explicit random_generator() = default;
        ~random_generator() = default;

        /**
         * @brief - get random generator
         *
         * @param out out - out buffer
         * @param in data_len - length of random data to generate
         *
         * @return number of bytes of random data on success -1 on failure
         */
        virtual int get(uint8_t *out, size_t data_len) = 0;

        /**
         * @brief - get random generator
         *
         * @param out out - out buffer
         *
         * @return number of bytes of random data on success -1 on failure
         */
        virtual int get(int &out) = 0;

        /**
         * @brief - get random generator
         *
         * @param out - out buffer 32 bits
         *
         * @return number of bytes of random data on success -1 on failure
         */
        virtual int get(uint32_t &out) = 0;

        /**
         * @brief - get random generator
         *
         * @param out - out buffer 16 bits
         *
         * @return number of bytes of random data on success -1 on failure
         */
        virtual int get(uint16_t &out) = 0;
};

/**
 * @brief - random generator factory
 */
class random_generator_factory {
    public:
        static random_generator_factory *get()
        {
            static random_generator_factory gen;

            return &gen;
        }
        ~random_generator_factory() { }
        random_generator_factory(const random_generator_factory &) = delete;
        random_generator_factory &operator=(const random_generator_factory &) = delete;
        random_generator_factory(const random_generator_factory &&) = delete;
        random_generator_factory &&operator=(const random_generator_factory &&) = delete;

        /**
         * @brief - create a random generator type
         * 
         * @param in t - random generator type
         * 
         * @return unique_ptr of type random_generator
         */
        std::unique_ptr<random_generator> create(random_generator_type t);

    private:
        random_generator_factory() = default;
};

}

#endif

