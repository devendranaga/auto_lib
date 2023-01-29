/**
 * @brief - implements SAE J2735 message
 * 
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2021-present All rights reserved
 */
#ifndef __AUTO_LIB_CAN_IF_H__
#define __AUTO_LIB_CAN_IF_H__


#include <vector>
#include <functional>

namespace auto_os::lib {

/**
 * @brief - bit mode 11 or 19 bits
 */
enum class can_dev_bit_mode {
    bit_mode_11bit, // CAN 2.0 standard
    bit_mode_29bit, // CAN 2.0 extended
};

/**
 * @brief - can or canfd device
 */
enum class can_device_name {
    can,
    can_fd,
};

#define DATA_LEN_MAX 64

/**
 * @brief - can if frame
 */
struct can_if_frame {
    // CAN MSG Id
    uint32_t id;

    // bit mode - 11 or 29
    can_dev_bit_mode mode;

    // device name can or can-fd
    can_device_name devname;

    // remote transmit request
    bool rtr;

    // error frame
    bool err_frame;

    // length of CAN received / send message
    uint8_t len;

    // actual message content
    uint8_t data[DATA_LEN_MAX];
} __attribute__((__packed__));

/**
 * @brief - filter set
 */
struct can_if_filter_set {
    // bit mode 11 or 29
    can_dev_bit_mode mode;

    // can device name
    can_device_name name;

    // can id
    uint32_t id;
};

/**
 * @brief - receive callback
 */
typedef std::function<void(struct can_if_frame &fr)> can_callback;

/**
 * @brief - can callback data
 */
struct can_callback_data {
    // list of filters
    std::vector<can_if_filter_set> flt;

    // can receive callback
    can_callback cb;
};

/**
 * @brief - implement CAN interface class for sending and receiveing messages
 */
class can_if {
    public:
        /**
         * @brief - setup CAN interface with the hardware
         * 
         * @param in - device name
         */
        explicit can_if(const std::string dev_name);

        /**
         * @brief - mostly not used .. FIXME: need to be removed / modified
         */
        explicit can_if(const std::string dev_name, can_dev_bit_mode bit_mode, can_device_name name);
        ~can_if();

        /**
         * @brief - send a CAN frame
         * 
         * @param in fr - CAN frame to be sent over to the interface
         * 
         * @returns number of bytes sent on success -1 on failure
         */
        int send(can_if_frame &fr) noexcept;

        /**
         * @brief - get CAN socket
         */
        int get_can_socket() const noexcept;

        /**
         * @brief - receive a CAN frame
         * 
         * @param out fr - CAN frame received on the interface
         * 
         * @return 0 on success -1 on failure
         */
        int receive(struct can_if_frame &frame) noexcept;

    private:
        int fd_;
        std::string devname_;
        std::vector<can_callback_data> cb_data_;
};

}

#endif


