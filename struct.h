#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <windows.h>
#include <pcap.h>

#define ETH_ADDR 6

struct ethernet_header
{
    u_char  eth_Dh[ETH_ADDR];
    u_char  eth_Sh[ETH_ADDR];
    u_short eth_Type;
};


typedef struct mac_Addr
{
    u_char b1;
    u_char b2;
    u_char b3;
    u_char b4;
    u_char b5;
    u_char b6;
}
mac_Addr;

typedef struct ip_Addr
{
    u_char b1;
    u_char b2;
    u_char b3;
    u_char b4;
}
ip_Addr;

typedef struct ip_Head
{
    u_char ver_ihl;
    u_char tos;
    u_short tlenght;
    u_short ident;
    u_short flags;
    u_char ttl;
    u_char proto;
    u_short Check;
    ip_Addr addr_S;
    ip_Addr addr_D;
}
ip_Head;

typedef struct tcp_Head
{
    u_short port_S;
    u_short port_D;
    u_int seq_Num;
    u_int ack_Num;
    u_char th_off;
    u_char flags;
    u_short win;
    u_short Check;
    u_short urgptr;
}
tcp_Head;

typedef struct udp_Head{
    u_short port_S;
    u_short port_D;
    u_short lenght;
    u_short Check;
}
udp_Head;

template <typename T>

inline void Swapping( T & arg1, T & arg2)
{
    T temp = arg1;
    arg1 = arg2;
    arg2 = temp;
};


#endif
