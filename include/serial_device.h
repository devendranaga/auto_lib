/**
 * @brief - implements serial device.
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com).
 * @copyight - 2021-present All rights reserved.
 */
#ifndef __AUTO_OS_LIB_SERIAL_DEVICE_H__
#define __AUTO_OS_LIB_SERIAL_DEVICE_H__

namespace auto_os::lib {

/**
 * Defines the UART device.
 */
class uart_device {
    public:
        explicit uart_device(uint32_t baudrate,
                             uint32_t max_chars,
                             bool wait_indefinitely) {
            fd_ = -1;
            baudrate_ = baudrate;
            max_chars_read_ = max_chars;
            wait_indefinitely_ = !wait_indefinitely;
        }
        ~uart_device() {
            if (fd_ > 0) { close(fd_); }
        }

        int open_device(const std::string &dev_name);
        int get_device_addr() { return fd_; }
        int read_device(uint8_t *data, uint32_t data_len);
        int write_device(uint8_t *data, uint32_t data_len);

    private:
        uint32_t max_chars_read_;
        bool wait_indefinitely_;
        uint32_t baudrate_;
        int fd_;
};

}

#endif

