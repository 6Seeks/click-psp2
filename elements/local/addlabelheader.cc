#include <click/config.h>
#include "checkabcheader.hh"
#include <clicknet/ip.h>
#include <clicknet/abc.h>
#include <click/glue.hh>
#include <click/args.hh>
#include <click/straccum.hh>
#include <click/error.hh>
#include <click/standard/alignmentinfo.hh>
#include <clicknet/ether.h>
#include "addlabelheader.hh"
#include <iostream>
#include <string>
CLICK_DECLS

AddLabelHeader::AddLabelHeader()
{
}

AddLabelHeader::~AddLabelHeader()
{
}
// Fixme:Use local address info to configure
int AddLabelHeader ::configure(Vector<String> &conf, ErrorHandler *errh)
{
    std::cout << "configure ! " << std::endl;
    _label = 0;
    std::string data = conf[0].data();
    for (int i = 0; i < data.find(")"); i++)
    {
        _label = _label * 16;
        _label = _label + parse_char(data[i]);
    }
    std::cout << "label  " << std::hex << _label << std::endl;
}
Packet *AddLabelHeader ::simple_action(Packet *p)
{
    click_chatter("Received a psp packet,now add label header to it ....\n");
    // WritablePacket * tmp = (WritablePacket *) p;
    WritablePacket *tmp = (WritablePacket *)p;
    /*edited by cx*/
    click_ether *p_ether = reinterpret_cast<click_ether *>(tmp->data()); //frame header

    //p_ether->ether_dhost
    uint8_t ether_dhost[6]; /* 0-5   Ethernet destination address */
    uint8_t ether_shost[6]; /* 6-11  Ethernet source address      */
    uint16_t ether_type;    /* 12-13 Ethernet protocol	      */
    for (int i = 0; i < 6; i++)
    {
        ether_shost[i] = p_ether->ether_shost[i];
        ether_dhost[i] = p_ether->ether_dhost[i];
    }
    ether_type = p_ether->ether_type = htons(0x0601);
    tmp = tmp->push(32);

    if (!tmp)
        return 0;
    tmp->set_mac_header(tmp->data(), 32 + 14);

    click_ether *p_ether_new = reinterpret_cast<click_ether *>(tmp->data()); //frame header
    for (int i = 0; i < 6; i++)
    {
        p_ether_new->ether_shost[i] = ether_shost[i];
        p_ether_new->ether_dhost[i] = ether_dhost[i];
    }
    p_ether_new->ether_type = ether_type;
    click_abc *p_abc = reinterpret_cast<click_abc *>(tmp->data() + 32 + 14);  //psp header ,modify it  add 2.5 layer
    click_label *p_label = reinterpret_cast<click_label *>(tmp->data() + 14); //psp header ,modify it  add 2.5 layer

    p_label->label_id = _label; //fixed!!!
    p_label->label_qos = p_abc->abc_resv;
    p_label->label_ttl = p_abc->abc_ttl;
    tmp->set_label_header(p_label, sizeof(click_label));
    click_chatter("Received a psp packet,now add label header to it ....\n");
    return tmp;
}
CLICK_ENDDECLS
EXPORT_ELEMENT(AddLabelHeader)
ELEMENT_MT_SAFE(AddLabelHeader)
