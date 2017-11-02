#ifndef SMD_SORT_PCAP_H
#define SMD_SORT_PCAP_H

#include <iostream>
#include <vector>
#include <string>
#include "struct.h"
#include "ui_mainwindow.h"
#include <pcap.h>


class SMD_Sort_pcap
{
public:
    std::vector <pcap_pkthdr> pack_head;
    std::vector <std::string> pack_body;

    pcap_t * pcap;

    char bufferr[PCAP_ERRBUF_SIZE];
    ip_Head *ip_head;
    const u_char *data;
    int pcount = 0;

    struct pcap_pkthdr *header;

    const struct ethernet_header *eth;
    const struct ip_Head *ip;
    const struct tcp_Head *tcp;

    char *pdata;
    int eth_Size;
    int ip_Size;
    int tcp_Size;
    int z;
    int ms;

public:
    SMD_Sort_pcap();
    void ReadPack(std::string path)
    {
        pcount = 0;

        pack_body.clear();
        pack_head.clear();
        pcap = pcap_open_offline(path.c_str(), bufferr);

        eth_Size = sizeof(struct ethernet_header);
        ip_Size = sizeof(struct ip_Head);
        tcp_Size = sizeof(struct tcp_Head);

        while ((z = pcap_next_ex(pcap, &header, &data)) >= 0)
        {
            ++pcount;
            pack_head.push_back(*header);

            ip = (struct ip_Head*)(data + eth_Size);

            std::string adip;

            adip.append("Src IP: ");

            adip += std::to_string((unsigned int)ip->addr_S.b1);
            adip.append(".");
            adip += std::to_string((unsigned int)ip->addr_S.b2);
            adip.append(".");
            adip += std::to_string((unsigned int)ip->addr_S.b3);
            adip.append(".");
            adip += std::to_string((unsigned int)ip->addr_S.b4);
            adip.append("; ");
            adip.append("Dest IP: ");
            adip += std::to_string((unsigned int)ip->addr_D.b1);
            adip.append(".");
            adip += std::to_string((unsigned int)ip->addr_D.b2);
            adip.append(".");
            adip += std::to_string((unsigned int)ip->addr_D.b3);
            adip.append(".");
            adip += std::to_string((unsigned int)ip->addr_D.b4);

            pack_body.push_back(adip);

        }
        pcap_close(pcap);

    };

    void BubbleSortLen()
    {
        for (int n = 0; n < pack_head.size(); ++n)
        {
            for (int m = pack_head.size()-1; m > n; --m)
            {
                if (pack_head.data()[n].caplen > pack_head.data()[m].caplen)
                {
                    Swapping( pack_head[n], pack_head[m]);
                    Swapping( pack_body[n], pack_body[m]);
                }
            }
        }
    };

    QT_DECLARE_METATYPE(SMD_Sort_pcap);
};

#endif
