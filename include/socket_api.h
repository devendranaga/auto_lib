/**
 *
 * @brief - implements socket api
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - All rights reserved 2020-present Devendra Naga (devnaga@tuta.io)
 */
#ifndef __AUTO_LIB_SOCKET_API_H__
#define __AUTO_LIB_SOCKET_API_H__

#include <string>
#include <memory>
#include <functional>

namespace auto_os::lib {

/**
 * @brief - socket utilities
 */
class socket_utils {
    public:
        explicit socket_utils() = default;
        ~socket_utils() = default;

        /**
         * @brief - reuse address
         *
         * @param in fd - file descriptor
         *
         * @return 0 on success -1 on failure
         */
        int reuse_addr(int fd);

        /**
         * @brief - set send buffer size
         *
         * @param in fd - file descriptor
         * @param in size - send buffer size
         *
         * @return 0 on success -1 on failure
         */
        int set_sndbuf_size(int fd, size_t size);

        /**
         * @brief - set receive buffer size
         *
         * @param in fd - file descriptor
         *
         * @param in fd - file descriptor
         * @param in size - receive buffer size
         *
         * @return 0 on success -1 on failure
         */
        int set_rcvbuf_size(int fd, size_t size);
        int set_direct_broadcast(int fd);
        int set_multicast(int fd, const std::string &mcast_group, const std::string &if_ip);
};

/**
 * @brief - implements tcp connection class
 */
class tcp_conn {
    public:
        /**
         * @brief - instance of tcp connection returned by accept_conn call, when a client is connected to the server
         *
         * @param in fd - file description
         * @param in ipaddr - ipaddress of server
         * @param in port - port of server
         */
        explicit tcp_conn(int fd, const std::string ipaddr, const int port);
        /**
         * @brief - close tcp connection
         */
        ~tcp_conn();

        /**
         * @brief - return linux socket descriptor
         *
         * @returns linux socket desriptor
         */
        int get_socket() const;

        /**
         * @brief - return the ipaddress in string format
         */
        std::string &get_ipaddr();

        /**
         * @brief - return the port
         */
        int get_port() const;

        /**
         * @brief - send message of given bfufer and length
         *
         * @param in data - data to send
         * @param in data_len - length of data to send
         *
         * @return number of bytes on success -1 on failure
         */
        int send_msg(uint8_t *data, size_t data_len);

        /**
         * @brief - receive message of given buffer and length
         * 
         * @param in data - data to send
         * @param in data_len - length of data to send
         * 
         * @return number of bytes on success -1 on failure
         */
        int send_msg(char *data, size_t data_len);

        /**
         * @brief - receive message from the socket
         * 
         * @param out data - data to receive
         * @param in data_len - length of data buffer
         * 
         * @return number of bytes on success -1 on failure
         */
        int recv_msg(uint8_t *data, size_t data_len);

        /**
         * @brief - receive message from the socket
         * 
         * @param out data - data to receive
         * @param in data_len - length of data buffer
         * 
         * @return number of bytes on success -1 on failure
         */
        int recv_msg(char *data, size_t data_len);
    private:
        int fd_;
        std::string ipaddr_;
        int port_;
};

/**
 * @brief - implements tcp server
 */
class tcp_server {
    public:
        explicit tcp_server(const std::string ip, int port, int n_conn);
        ~tcp_server();

        int get_socket() const;
        std::unique_ptr<tcp_conn> accept_conn();

    private:
        int fd_;
};

/**
 * @brief - implements tcp client
 */
class tcp_client {
    public:
        explicit tcp_client(const std::string ip, int port);
        ~tcp_client();

        int get_socket() const;
        int send_msg(uint8_t *data, size_t data_len);
        int send_msg(char *data, size_t data_len);
        int recv_msg(uint8_t *data, size_t data_len);
        int recv_msg(char *data, size_t data_len);
    private:
        int fd_;
};

/**
 * @brief - implements udp server
 */
class udp_server {
    public:
        explicit udp_server(const std::string ipaddr, int port);
        ~udp_server();

        int get_socket() const noexcept;
        int send_msg(const std::string addr, int port, uint8_t *data, size_t data_len) noexcept;
        int recv_msg(std::string &addr, int &port, uint8_t *data, size_t data_len) noexcept;
    private:
        int fd_;
};

/**
 * @brief - implements udp client
 */
class udp_client {
    public:
        explicit udp_client();
        ~udp_client();

        /**
         * @brief - returns the underlying socket for events
         */
        int get_socket() const noexcept;

        /**
         * @brief - send message on udp connection
         *
         * @param in addr - target address
         * @param in port - target port
         * @param in data - data to forward
         * @param in data_len - length of data
         *
         * @return number of bytes on success -1 on failure
         */
        int send_msg(const std::string addr,
                     int port, uint8_t *data, size_t data_len) noexcept;

        /**
         * @brief - receive message on udp connection
         *
         * @param out addr - sender address (filled by the API)
         * @param out port - sender port (filled by the API)
         * @param in data - data buffer to receive packet
         * @param in data_len - length of data buffer
         *
         * @return number of bytes on success -1 on failure
         */
        int recv_msg(std::string &addr,
                     int &port, uint8_t *data, size_t data_len) noexcept;
    private:
        int fd_;
};

/**
 * @brief - Implements raw socket
 */
class raw_socket {
    public:
        /**
         * @brief - Create raw socket object.
         *
         * @param [in] - dev Interface name (shown in ifconfig).
         * @param [in] - ethertype Set 0 as default.
         *
         * This constructor will throw exception.
         */
        explicit raw_socket(const std::string dev, uint16_t ethertype);
        ~raw_socket();

        /**
         * @brief - Get socket from the raw socket object.
         *
         * @return socket id on success.
         * @return -1 on failure.
         */
        int get_socket() const noexcept;

        int send_msg(uint8_t *mac, uint16_t ethertype, uint8_t *data, size_t data_len) noexcept;
        /**
         * @brief - Send message via the raw socket.
         *
         * @param [in] - dest Destination mac address.
         * @param [in] - data Transmit buffer.
         * @param [in] - data_len Transmit buffer length.
         *
         * @return Length of transmitted data on success.
         * @return -1 on failure.
         */
        int send_msg(uint8_t *dest, uint8_t *data, size_t data_len) noexcept;
        int recv_msg(uint8_t *mac, uint16_t &ethertype, uint8_t *data, size_t data_len) noexcept;

        /**
         * @brief - Receive message via the raw socket.
         *
         * @param [in] - mac Sender's mac address.
         * @param [in] - data Receive buffer.
         * @param [in] - data_len Length of received buffer.
         *
         * @return Length of received data on success.
         * @return -1 on failure.
         */
        int recv_msg(uint8_t *mac, uint8_t *data, size_t data_len) noexcept;
    private:
        int fd_;
        std::string dev_;
        int ifindex_;
        uint8_t devmac_[6];
};

class unix_tcp_conn {
    public:
        explicit unix_tcp_conn(int fd, const std::string path);
        ~unix_tcp_conn();

        int get_socket() const noexcept;
        std::string get_path() noexcept;

        int send_msg(uint8_t *data, size_t data_len) noexcept;
        int recv_msg(uint8_t *data, size_t data_len) noexcept;
    private:
        int fd_;
        std::string path_;
};

class unix_tcp_server {
    public:
        explicit unix_tcp_server(const std::string path, int n_conn);
        ~unix_tcp_server();

        int get_socket() const noexcept;
        std::unique_ptr<unix_tcp_conn> accept_conn() noexcept;

    private:
        int fd_;
        std::string path_;
};

class unix_tcp_client {
    public:
        explicit unix_tcp_client(const std::string path);
        ~unix_tcp_client();

        int get_socket() const noexcept;
        int send_msg(uint8_t *data, size_t data_len) noexcept;
        int recv_msg(uint8_t *data, size_t data_len) noexcept;
    private:
        int fd_;
        std::string path_;
};

struct unix_udp_server {
    public:
        explicit unix_udp_server(const std::string path);
        ~unix_udp_server();

        int get_socket() const noexcept;
        int send_msg(const std::string path, uint8_t *data, size_t data_len) noexcept;
        int recv_msg(std::string &path, uint8_t *data, size_t data_len) noexcept;
    private:
        int fd_;
        std::string path_;
};

struct unix_udp_client {
    public:
        explicit unix_udp_client(const std::string path);
        ~unix_udp_client();

        int get_socket() const noexcept;
        int send_msg(const std::string path, uint8_t *data, size_t data_len) noexcept;
        int recv_msg(std::string &path, uint8_t *data, size_t data_len) noexcept;
    private:
        int fd_;
        std::string path_;
};

}

#endif


