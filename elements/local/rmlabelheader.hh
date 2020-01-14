
#ifndef CLICK_RMLABELHEADER_HH
#define CLICK_RMLABELHEADER_HH
#include <click/element.hh>
#include <click/etheraddress.hh>
#include <clicknet/label.h>
CLICK_DECLS
//label head

class RmLabelHeader : public Element{
public:
    RmLabelHeader();
    ~RmLabelHeader();

    const char * class_name() const {return "RmLabelHeader";}
    const char * port_count() const {return "1/1";}
    const char * processing() const {return "h/h";}

    int configure(Vector<String> &, ErrorHandler *);
    //void push(int port, Packet * p);
    Packet *simple_action(Packet *);



};
CLICK_ENDDECLS
#endif
