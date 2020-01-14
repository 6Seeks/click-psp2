#ifndef CLICK_LOOKUPROUTE_HH
#define CLICK_LOOKUPROUTE_HH
#include <click/glue.hh>
#include <click/element.hh>
#include <click/vector.hh>
#include <clicknet/psp.h>
#include "abcaddress.hh"

CLICK_DECLS

struct ABCRoute {
    ABCAddress addr;
    int32_t port;

    ABCRoute(): port(-1) { }
    ABCRoute(ABCAddress a, int p): addr(a),  port(p) { }

    inline void kill()		{ addr = 0; port = -0x80000000; }
    inline bool contains(ABCAddress a) const;

    inline bool match(const ABCRoute& r) const;
};


inline bool
ABCRoute::contains(ABCAddress a) const
{
    return a.matches_prefix(addr);
}

inline bool
ABCRoute::match(const ABCRoute& r) const
{
    return addr == r.addr &&  port == r.port;
}

class LookupRoute : public Element {

  public:

    int configure(Vector<String>&, ErrorHandler*);

    const char *class_name() const	{ return "LookupRoute"; }
    const char *port_count() const	{ return "1/-"; }
    const char *processing() const	{ return PUSH; }

    void push(int port, Packet *p);

    int add_route(const ABCRoute&, bool, ABCRoute*, ErrorHandler *);
    int remove_route(const ABCRoute&, ABCRoute*, ErrorHandler *);
    int lookup_route(ABCAddress) const;

    uint64_t parseAddr(const char*, int);
    int parsePort(const char*, int);

  private:

    Vector<ABCRoute> _t;

    int lookup_entry(ABCAddress) const;

};
#endif
