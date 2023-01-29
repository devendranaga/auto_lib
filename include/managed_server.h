/**
 * @brief - implements managed server
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2021-present All rights reserved
 */
#include <iostream>
#include <functional>
#include <memory>
#include <vector>
#include <event_manager.h>
#include <helpers.h>

namespace auto_os::lib {

typedef std::function<void(int)> on_accept;

/**
 * @brief - tcp client instance - created if a client is connected
 */
class tcp_client_instance {
    public:
        explicit tcp_client_instance() { }
        ~tcp_client_instance() { }

        void set_socket(int fd) { fd_ = fd; }
        void set_ipaddr(const std::string ipaddr) { ipaddr_ = ipaddr; }
        void set_port(int port) { port_ = port; }
        void set_event_mgr(auto_os::lib::event_manager *evt_mgr) { evt_mgr_ = evt_mgr; }
        int get_socket() { return fd_; }

        /**
         * @brief - send message to the server
         *
         * @param in data - data to send
         * @param in data_len - length of data
         *
         * @return length of message that is sent -1 otherwise
         */
        int send_msg(uint8_t *data, size_t data_len);

    private:
        int fd_;
        std::string ipaddr_;
        int port_;
        auto_os::lib::event_manager *evt_mgr_;
};

/**
 * @brief - on_receive callback - called when there is a data from the client
 */
typedef std::function<void(tcp_client_instance &inst, uint8_t *, size_t)> on_receive;

/**
 * @brief - impplements tcp managed server
 */
class tcp_managed_server {
    public:
        explicit tcp_managed_server();
        ~tcp_managed_server();

        /**
         * @brief - set event manager instance for loop
         *
         * @param in evt_mgr - event manager instance
         */
        void set_evt_mgr(auto_os::lib::event_manager *evt_mgr) { evt_mgr_ = evt_mgr; }

        /**
         * @brief - create managed tcp server
         *
         * @param in ipaddr - ipaddress of the server
         * @param in port - port number of the server
         * @param in n_conn - number of connections
         *
         * @return 0 on success -1 on failure
         */
        int create_server(const std::string ipaddr, int port, int n_conn);

        /**
         * @brief - delete the server
         */
        void delete_server();

        /**
         * @brief - register callbacks
         *
         * @param in receive_cb - receive callback - called when there is a data from any client
         * @param in accept_cb - accept callback - not used
         */
        void register_callbacks(on_receive receive_cb, on_accept accept_cb = nullptr)
        {
            receive_cb_ = receive_cb;
            accept_cb_ = accept_cb;
        }

    private:
        on_receive receive_cb_;
        on_accept accept_cb_;
        void accept_connections(int fd);
        void receive_data(int fd);
        void remove_client(int fd);
        auto_os::lib::event_manager *evt_mgr_;
        std::string ipaddr_;
        int fd_;
        std::vector<tcp_client_instance> clients_;
};

}

