/**
 * @brief - Implements leds interface
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2022-present All rights reserved
 */
#ifndef __AUTO_LIB_LEDS_H__
#define __AUTO_LIB_LEDS_H__

#include <memory>

namespace auto_os::lib {

/**
 * @brief - Implements leds interface
 */
class leds {
    public:
        explicit leds() = default;
        ~leds() = default;

        virtual int blink(int turn_on_ms, int turn_off_ms) = 0;
        virtual int heartbeat() = 0;
        virtual int turn_on() = 0;
        virtual int turn_off() = 0;
};

enum leds_types {
    NANOPI_NEO_RED,
    NANOPI_NEO_BLUE,
    BBB_HEARTBEAT_LED, // D2
    BBB_MMC_LED, // D3
    BBB_USR2_LED, // D4
    BBB_USR3_LED, // D5
};

class led_factory {
    public:
        ~led_factory() = default;
        explicit led_factory(const led_factory &) = delete;
        const led_factory &operator=(const led_factory &) = delete;
        explicit led_factory(const led_factory &&) = delete;
        const led_factory &&operator=(const led_factory &&) = delete;

        static led_factory *instance()
        {
            static led_factory fact;
            return &fact;
        }

        std::unique_ptr<leds> get(leds_types type);
    private:
        explicit led_factory() = default;
};

}

#endif

