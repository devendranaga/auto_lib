#ifndef __AUTO_OS_LIB_MQTT_MOSQUITTO_TRANSPORT_H__
#define __AUTO_OS_LIB_MQTT_MOSQUITTO_TRANSPORT_H__

#include <functional>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "mqtt_transport.h"
#include <mosquitto.h>

namespace auto_os::lib {

class Mqtt_Mosquitto_Transport : public Mqtt_Transport {
    public:
        explicit Mqtt_Mosquitto_Transport();
        ~Mqtt_Mosquitto_Transport();

        int Connect(const std::string ipaddr, int port);
        int Connect(const std::string ipaddr, int port,
                    const std::string usrname, const std::string passwd);
        int Publish(std::string topic, uint8_t *msg, size_t msg_len);
        int Subscribe(std::string ipaddr, int port,
                      Subscription_Callback sub_cb, std::string topic_name,
                      Connect_Callback con_cb,
                      Message_Callback msg_cb);
        void Run_Subscriber();
        void Stop();

    private:
        std::unique_ptr<std::thread> sub_thr_;
        mosquitto *mosq_;
        Subscription_Callback sub_cb_;
        Connect_Callback con_cb_;
        Message_Callback msg_cb_;
        void on_subscribe(int mid, int qos_count, int *granted_qos);
        void on_connect(int ret_code);
        void on_message(const struct mosquitto_message *msg);
        void Receive_Function();
};

}


#endif

