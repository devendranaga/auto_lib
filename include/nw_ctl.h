/**
 * @brief - implements network ioctl
 *
 * @copyright - 2020-present All rights reserved Devendra Naga (devendra.aaru@outlook.com)
 */
#ifndef __AUTO_LIB_NW_CTL_H__
#define __AUTO_LIB_NW_CTL_H__

#include <string>
#include <vector>

namespace auto_os::lib {

/**
 * @brief - convert ipv4 address to string
 * 
 * @param in inetaddr - ipv4 address
 * @param out inetadr_str - converted string
 *
 * @return 0 on success -1 on failure
 */
int to_inet4_str(uint32_t inetaddr, std::string &inetaddr_str);

/**
 * @brief - convert ipv4 string to integer / binary
 * 
 * @param in inetaddr_str - ipv4 string
 * @param out inetaddr - converted binary
 * 
 * @return 0 on success -1 on failure
 */
int to_inet4_bin(std::string inetaddr_str, uint8_t *inetaddr);

/**
 * @brief - convert ipv6 address to string
 * 
 * @param in inet6addr - ipv6 binary
 * @param out inet6addr_str - converted string
 * 
 * @return 0 on success -1 on failure
 */
int to_inet6_str(uint8_t *inet6addr, std::string &inet6addr_str);

/**
 * @brief - convert ipv6 address string to binary
 * 
 * @param in inet6addr_str - ipv6 string
 * @param out inet6addr - ipv6 address binary
 * 
 * @return 0 on success -1 on failure
 */
int to_inet6_bin(std::string inet6addr_str, uint8_t *inet6addr);

/**
 * @brief - check if interface is up or down
 *
 * @param in ifname - interface name
 * @return true if interface is up false if interface is down
 */
bool is_interface_up(const std::string &ifname);

/**
 * @brief - set interface up
 *
 * @param in ifname - interface name
 * @return 0 on success -1 on failure
 */
int set_interface_up(const std::string &ifname);

/**
 * @brief - set interface down
 *
 * @param in ifname - interface name
 * @return 0 on success -1 on failure
 */
int set_interface_down(const std::string &ifname);

/**
 * @brief - get interface list
 *
 * @param out string_list - list of interfaces
 * @return 0 on success -1 on failure
 */
int get_interface_list(std::vector<std::string> &);

/**
 * @brief - get interface index
 *
 * @param in ifname - interface name
 * @param out ifindex - interface index
 *
 * @return 0 on success -1 on failure
 */
int get_interface_index(const std::string &ifname, int &ifindex);

/**
 * @brief - set interface name
 *
 * @param in ifname - interface name
 * @param in new_name - new interface name
 *
 * @return 0 on success -1 on failure
 */
int set_interface_name(const std::string &ifname, std::string new_name);

struct interface_info {
    char ifname[24];
    char ifaddr[80];
};

int get_interfaces(std::vector<interface_info> &info);

/**
 * @brief - get interface mac
 * 
 * @param in ifname - interface name
 * @param out mac - mac address
 * 
 * @return 0 on success -1 on failure
 */
int get_interface_mac(const std::string &ifname, uint8_t *mac);


/**
 * @brief - set interface mac
 *
 */
int set_interface_mac(const std::string &ifname, uint8_t *mac);

/**
 * @brief - get interface ipv4 address
 * 
 * @param in ifname - interface name
 * @param out ipv4_addr - ipv4 address
 * 
 * @return 0 on success -1 on failure
 */
int get_interface_ipv4_addr(const std::string &ifname, std::string &ipv4_addr);

int add_vlan_intf(const std::string &ifname, int vlan_id);
int rem_vlan_intf(const std::string &ifname);

/**
 * @brief - Check if interface is in promiscuous mode.
 *
 * @param [in] ifname - interface name.
 *
 * @return true if in promisc and false if not in promisc.
 */
bool is_in_promisc(const std::string &ifname);

/**
 * @brief - Set the given interface in promiscous mode.
 *
 * @param [in] ifname - interface name.
 *
 * @return 0 on success -1 on failure.
 */
int set_promisc(const std::string &ifname);

}

#endif


