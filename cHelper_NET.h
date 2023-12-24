#ifndef __CHELPER_NET_H__
#define __CHELPER_NET_H__

#include <cHelper_GEN.h>

#define MAC_CON(x)  ((NetMAC ){.byte[0]=x[0], .byte[1]=x[1], .byte[2]=x[2], .byte[3]=x[3], .byte[4]=x[4], .byte[5]=x[5]})
#define MAC_DEC(x)  ((uint8_t[6]){x.byte[0], x.byte[1], x.byte[2], x.byte[3], x.byte[4], x.byte[5]})

#define IPV4_CON(x) ((NetIPv4){.byte[0]=x[0], .byte[1]=x[1], .byte[2]=x[2], .byte[3]=x[3]})
#define IPV4_DEC(x) ((uint8_t[4]){x.byte[0], x.byte[1], x.byte[2], x.byte[3]})

    typedef union {
        uint8_t  byte[6];
        uint64_t mono : 48;
    }   NetMAC;

    typedef union {
        uint8_t  byte[4];
        uint32_t mono : 32;
    }   NetIPv4;

    typedef struct {
        NetMAC  mac;
        NetIPv4 ip;
        NetIPv4 sm;
        NetIPv4 gw;
        NetIPv4 dns;
        state_t dhcp;
    }   NetConf;

    typedef struct {
        uint8_t  selfSocket;
        uint16_t selfPort;
        NetIPv4  targetIP;
        uint16_t targetPort;
    }   NetLink;

#endif
