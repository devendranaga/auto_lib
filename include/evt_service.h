#ifndef __AUTO_LIB_EVT_SERVICE_H__
#define __AUTO_LIB_EVT_SERVICE_H__

#include <vector>
#include <memory>
#include <socket_api.h>
#include <event_manager.h>

namespace auto_os::lib {


typedef std::function<void(int fd, uint8_t *buff, size_t buff_size)> on_receive;


struct tcp_conn_context;

class evt_tcp_service {
    public:
        explicit evt_tcp_service(auto_os::lib::event_manager *evt_mgr,
                                 std::string ipaddr, int port, int n_conn);
        ~evt_tcp_service();

        void register_on_receive(on_receive cb) { on_rx_cb_ = cb; }

    private:
        void accept_conns(int fd);
        std::string  ipaddr_;
        int port_;
        int n_conn_;
        std::unique_ptr<tcp_server> tcp_serv_;
        auto_os::lib::event_manager *evt_mgr_;
        std::vector<tcp_conn_context> conn_list_;
        on_receive on_rx_cb_;
};

}

#endif


