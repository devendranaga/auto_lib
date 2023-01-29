/**
 *
 * @brief - implements all includes
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2021-present All rights reserved
 */
#ifndef __AUTO_OS_LIB_MQTT_TRANSPORT_H__
#define __AUTO_OS_LIB_MQTT_TRANSPORT_H__

#include <string>
#include <memory>
#include <functional>

namespace auto_os::lib {

/**
 * @brief - subscription callback
 */
typedef std::function<void(int mid, int qos_count)>  Subscription_Callback;

/**
 * @brief - connect callback
 */
typedef std::function<void(int ret_code)> Connect_Callback;

/**
 * @brief - message callback
 */
typedef std::function<void(void *msg, int msg_len)> Message_Callback;

/**
 * @brief - MQTT Transport
 */
class Mqtt_Transport {
    public:
        explicit Mqtt_Transport() = default;
        ~Mqtt_Transport() = default;

        /*
         * @brief - connect to a broker
         * 
         * @param in ipaddr - ip a ddress
         * @param in port - port
         * 
         * @details
         * connect to broker with given ip:port
         * 
         * @return 0 on success -1 on fail
         */
        virtual int Connect(const std::string ipaddr, int port) = 0;

        /**
         * @brief - connect to a broker
         * 
         * @param in ipaddr - ip a ddress
         * @param in port - port
         * @param in usrname - username
         * @param in passwd - password
         * 
         * @details
         * connect to broker with given ip:port and username password
         * 
         * @return 0 on success -1 on fail
         */
        virtual int Connect(const std::string ipaddr, int port,
                            const std::string usrname, const std::string passwd) = 0;

        /**
         * @brief - publish a message
         * 
         * @param in topic - topic address
         * @param in msg - message to publish
         * @param in msg_len - length of message
         * 
         * @return 0 on success -1 on failure
         */
        virtual int Publish(std::string topic, uint8_t *msg, size_t msg_len) = 0;

        /**
         * @brief - subscribe to a topic
         * 
         * @param in ipaddr - ipaddress
         * @param in port - port
         * @param in sub_cb - subscriber callback
         * @param in topic_name - name of topic
         * @param in con_cb - connect callback
         * @param in msg_cb - message callback
         * 
         * @return 0 on success -1 on failure
         */
        virtual int Subscribe(std::string ipaddr, int port,
                              Subscription_Callback sub_cb, std::string topic_name,
                              Connect_Callback con_cb,
                              Message_Callback msg_cb) = 0;

        /**
         * @brief - run subscriber
         */
        virtual void Run_Subscriber() = 0;

        virtual void Stop() = 0;
};

/**
 * @brief - type of supported mqtt libraries
 */
enum Mqtt_Transport_Type : int {
    // Mosquitto lib
    MQTT_MOSQUITTO,
};

/**
 * @brief - MQTT transport factory - creates mqtt interfaces
 */
class Mqtt_Transport_Factory {
    public:
        static Mqtt_Transport_Factory *Instance() {
            static Mqtt_Transport_Factory fct;
            return &fct;
        }
        ~Mqtt_Transport_Factory() { };
        Mqtt_Transport_Factory(Mqtt_Transport_Factory &) = delete;
        Mqtt_Transport_Factory &operator=(Mqtt_Transport_Factory &) = delete;

        /**
         * @brief - create Mqtt interface
         * 
         * @param in type - type of support mqtt libraries
         * 
         * @return unique_ptr to the Mqtt_Transport
         */
        std::unique_ptr<Mqtt_Transport> Create(Mqtt_Transport_Type type);
    private:
        explicit Mqtt_Transport_Factory() { }
};

}

#endif

