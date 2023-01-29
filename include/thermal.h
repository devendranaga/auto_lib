/**
 * @brief - implements temperature interface.
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com).
 * @copyight - 2021-present All rights reserved.
 */
#ifndef __AUTO_LIB_THERMAL_H__
#define __AUTO_LIB_THERMAL_H__

#include <memory>

namespace auto_os::lib {

/**
 * @brief - reading of temperatures is supported on the following devices
 */
enum class thermal_device_type : int {
    // Raspberry PI4
    Rpi4,

    // Nanopi Neo
    NanoPI_Neo,
};

/**
 * @brief - thermal information
 */
class thermal_info {
    public:
        explicit thermal_info() { }
        virtual ~thermal_info() { }

        /**
         * @brief - get thermal temperature
         *
         * @param in temp_celcius - temperature in celcius
         *
         * @return 0 on success -1 on failure
         */
        virtual int get_thermal_temp(double &temp_celcius) = 0;

        /**
         * @brief - get fan speed in rpm
         *
         * @return fan_speed on success -1 on failure
         */
        virtual int get_fan_speed_rpm() = 0;
};

class thermal_info_rpi4 : public thermal_info {
    public:
        explicit thermal_info_rpi4() { }
        virtual ~thermal_info_rpi4() { }

        int get_thermal_temp(double &temp_celcius);
        int get_fan_speed_rpm();
};

class thermal_info_nanopi_neo : public thermal_info {
    public:
        explicit thermal_info_nanopi_neo() = default;
        virtual ~thermal_info_nanopi_neo() = default;

        int get_thermal_temp(double &temp_celcius);
        int get_fan_speed_rpm();
};

/**
 * @brief - factory to create thermal read out
 */
class thermal_info_factory {
    public:
        ~thermal_info_factory() { }

        thermal_info_factory(const thermal_info_factory &) = delete;
        const thermal_info_factory &operator=(const thermal_info_factory &) = delete;
        thermal_info_factory(const thermal_info_factory &&) = delete;
        const thermal_info_factory &&operator=(const thermal_info_factory &&) = delete;

        /**
         * @brief - get instance of the thermal_info_factory
         *
         * @return instance of the thermal info
         */
        static thermal_info_factory *instance()
        {
            static thermal_info_factory factory;
            return &factory;
        }

        /**
         * @brief - create a thermal device info
         *
         * @param in type - thermal device type
         *
         * @return returns pointer to teh device specific class
         */
        std::unique_ptr<thermal_info> create(thermal_device_type type)
        {
            switch (type) {
                case thermal_device_type::Rpi4:
                    return std::make_unique<thermal_info_rpi4>();
                case thermal_device_type::NanoPI_Neo:
                    return std::make_unique<thermal_info_nanopi_neo>();
            }

            return nullptr;
        }
    private:
        explicit thermal_info_factory() { }
};

}

#endif


