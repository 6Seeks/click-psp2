#ifndef CLICK_LOOKUPLABELTABLE_HH
#define CLICK_LOOKUPLABELTABLE_HH
#include <click/glue.hh>
#include <click/element.hh>
#include <click/vector.hh>
#include <clicknet/psp.h>
#include <clicknet/label.h>
#include "abcaddress.hh"

CLICK_DECLS

struct LabelEntry {                     //转发表表项
    int32_t labelin;                  //label
    int32_t port;
    int32_t labelout;

    LabelEntry(): labelin(-1),labelout(-1),port(-1) { }

    LabelEntry (int in, int p ,int out): labelin(in),  port(p),labelout(out) { }          //进来的标签，对应端口，输出的标签

    inline void kill()		{ labelin = 0; port = -0x80000000; }
    inline bool contains(int a) const;

    inline bool match(const LabelEntry& r) const;
};

/*
inline bool
LabelEntry::contains(int a) const
{
    return a.matches_prefix(labelin);
}
*/
inline bool
LabelEntry::match(const LabelEntry& r) const
{
    return labelin == r.labelin &&  port == r.port;
}

class LookupLabelTable : public Element {

  public:

    int configure(Vector<String>&, ErrorHandler*);

    const char *class_name() const	{ return "LookupLabelTable"; }
    const char *port_count() const	{ return "1/-"; }
    const char *processing() const	{ return "h/h"; }
    int addLabelEntry(int labelin,int port,int labelout);
    void push(int port, Packet *p);

    uint64_t parseAddr(const char*, int);
    int parsePort(const char*, int);

  private:

    Vector<LabelEntry> _t;                  //转发表结构体

    int lookup_entry(int) const;

};
#endif
