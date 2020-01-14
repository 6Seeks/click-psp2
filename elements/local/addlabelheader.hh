
#ifndef CLICK_ADDLABELHEADER_HH
#define CLICK_ADDLABELHEADER_HH
#include <click/element.hh>
#include <click/etheraddress.hh>
#include <clicknet/label.h>
CLICK_DECLS
//label head

class AddLabelHeader : public Element
{
public:
    AddLabelHeader();
    ~AddLabelHeader();

    const char *class_name() const { return "AddLabelHeader"; }
    const char *port_count() const { return "1/1"; }
    const char *processing() const { return "l/l"; }

    int configure(Vector<String> &, ErrorHandler *);
    //void push(int port, Packet * p);
    Packet *simple_action(Packet *);
    int parse_char(char c)
    {
        if ('0' <= c && c <= '9')
        {
            return c - '0';
        }
        else if ('A' <= c && c <= 'F')
        {
            return 10 + c - 'A';
        }
        else
        {
            return 10 + c - 'a';
        }
    }
    int _label;
};
CLICK_ENDDECLS
#endif
