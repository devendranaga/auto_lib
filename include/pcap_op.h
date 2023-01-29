/**
 * @brief - implements PCAP read / writer
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2022-present All rights reserved
 */
#ifndef AUTO_LIB_PCAP_OP_H
#define AUTO_LIB_PCAP_OP_H

#include <iostream>
#include <functional>
#include <socket_api.h>
#include <string>

namespace auto_os::lib {

enum class pcap_op_type {
    read_op,
    write_op,
};

/**
 * @brief - record header written for each record
 */
typedef struct pcap_rechdr_s {
    uint32_t ts_sec; // timestamp seconds
    uint32_t ts_usec; // timestamp microseconds
    uint32_t incl_len; // number of octets of packets
    uint32_t orig_len; // actual length of packet
} pcap_rechdr_t;

/**
 * @brief - first header for identification in reading
 */
typedef struct pcap_hdr_s {
    uint32_t magic_number; // magic number
    uint16_t version_major; // major version number
    uint16_t version_minor; // minor version number
    int32_t thiszone; // GMT to local correction
    uint32_t sigfigs; // accuracy of timestamp
    uint32_t snaplen; // max length of capture
    uint32_t network; // data link type
} pcap_hdr_t;

typedef std::function<void(uint8_t *data, size_t data_len)> capture_cb;
typedef std::function<void(const std::string filename)> notify_func;

/**
 * @brief - defines pcap operation
 */
class pcap_op {
    public:
        explicit pcap_op(const std::string devname, bool log_enable, const std::string filename_prefix, size_t rotate_filesize, notify_func cb);

        /**
         * @brief - set pcap ops
         *
         * @param in filename - filename to read/write
         * @param in op - operation read or write
         *
         * @throws exception
         */
        explicit pcap_op(const std::string filename, pcap_op_type op);
        ~pcap_op();

        int capture(capture_cb cb);
        int capture(uint8_t *buf, size_t bufsize);
        void stop_capture();
        int read_record(pcap_rechdr_t &rec, uint8_t *buf, size_t bufsize);
        int write_record(uint8_t *buf, size_t bufsize);
        void flush();

    private:
        // kernel fd for grabbing packets
        int fd_;
        FILE *fp_;
        FILE *fp_read_;
        FILE *fp_write_;
        std::unique_ptr<raw_socket> raw_sock_;
        notify_func notify_cb_;
        bool stop_capture_;
};

}

#endif //AUTO_OS_PCAP_OP_H


