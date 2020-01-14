#include <click/config.h>
#include "checkabcheader.hh"
#include <clicknet/ip.h>
#include <clicknet/abc.h>
#include <click/glue.hh>
#include <click/args.hh>
#include <click/straccum.hh>
#include <click/error.hh>
#include <click/standard/alignmentinfo.hh>
#include<clicknet/ether.h>
#include "rmlabelheader.hh"
CLICK_DECLS

RmLabelHeader::RmLabelHeader()
{
}

RmLabelHeader::~RmLabelHeader()
{
}

int RmLabelHeader :: configure(Vector<String> & conf, ErrorHandler * errh)
{
    /*_table.clear();
    _total = 0;

    const char * data1 = conf[0].data();
    const char * data2 = conf[1].data();

    unsigned char * addr = (unsigned char *) &_local_addr;

    int j = 0;
    for(int i = 0;i < 2;i++)
    {
        addr[1 - i] = 16 * parse_char(data1[j]) + parse_char(data1[j + 1]);
        j += 3;
    }

    int k = 0;
    for(int i = 0;i < 6;i++)
    {
        _local_mac[i] = 16 * parse_char(data2[k]) + parse_char(data2[k + 1]);
        k += 3;
    }
    return 0;*/
}
Packet * RmLabelHeader :: simple_action(Packet *p)
{
    click_chatter("Received a LABEL packet,now rm label header ....\n");
   // WritablePacket * tmp = (WritablePacket *) p;
    WritablePacket *tmp = (WritablePacket *) p;
    /*edited by cx*/
    click_ether * p_ether = reinterpret_cast<click_ether *>(tmp->data());     //frame header

             //p_ether->ether_dhost
    uint8_t	ether_dhost[6];		/* 0-5   Ethernet destination address */
    uint8_t	ether_shost[6];		/* 6-11  Ethernet source address      */
    uint16_t	ether_type;		/* 12-13 Ethernet protocol	      */
    for(int i = 0;i < 6;i++)
    {
        ether_shost[i]=p_ether->ether_shost[i];
        ether_dhost[i]=p_ether->ether_dhost[i];

    }
    ether_type = p_ether->ether_type = htons(0x0601);
    tmp->pull(32);

    if (!tmp)
        return 0;
    tmp->set_mac_header(tmp->data());

    click_ether * p_ether_new = reinterpret_cast<click_ether *>(tmp->data());     //frame header
    for(int i = 0;i < 6;i++)
    {
        p_ether_new->ether_shost[i]=ether_shost[i];
        p_ether_new->ether_dhost[i]=ether_dhost[i];

    }
    p_ether_new->ether_type = htons(0x0600);
    click_chatter("rm finish ,now packet type : 0x0600\n");
    click_abc *abc = reinterpret_cast<click_abc *>(tmp->data()+14);
    unsigned ttl = abc->abc_ttl;
    click_chatter("CheckABCHeader: TTL = %d",ttl);
    if (ttl<=0){
        click_chatter("Packet Dropped for TTL = 0... ");
        p->kill();
    }
    //ttl-1
    abc->abc_ttl = ttl-1;
    return tmp;
}
CLICK_ENDDECLS
EXPORT_ELEMENT(RmLabelHeader)
ELEMENT_MT_SAFE(RmLabelHeader)
