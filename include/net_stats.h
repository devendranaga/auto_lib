/**
 * @brief - get network interface stats from /proc/net/dev
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright All rights reserved 2021-present Devendra Naga (devendra.naga@outlook.com)
 */
#ifndef __AUTO_LIB_NET_STATS_H__
#define __AUTO_LIB_NET_STATS_H__

#include "auto_os_errors.h"

namespace auto_os::lib {

/**
 * @brief - Network interface stats structure
 */
struct Network_Interface {
    std::string ifname;
    uint64_t tx_bytes;
    uint64_t tx_pkts;
    uint64_t tx_errs;
    uint64_t tx_drop;
    uint64_t tx_fifo;
    uint64_t tx_collisions;
    uint64_t tx_carrier;
    uint64_t tx_compressed;
    uint64_t rx_bytes;
    uint64_t rx_pkts;
    uint64_t rx_errs;
    uint64_t rx_drop;
    uint64_t rx_fifo;
    uint64_t rx_frame;
    uint64_t rx_compressed;
    uint64_t rx_multicast;
};

/**
 * @brief - Implements Network stats class
 */
class Network_Stats {
    public:
        explicit Network_Stats() { }
        ~Network_Stats() { }

        /**
         * @brief - Get the statistics of the network interfaces
         *
         * @return ERROR_NO_ERROR on success
         * @return ERROR_NETWORK_STATS_FILE_OPEN_FALURE on failure
         */
        auto_os::errors::error_type
        Get(std::vector<Network_Interface> &ifaces);
};

}

#endif

