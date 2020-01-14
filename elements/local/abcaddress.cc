
#include <click/config.h>
#include <click/glue.hh>
#include "abcaddress.hh"
#include <click/args.hh>
#include <click/straccum.hh>
#include <click/integers.hh>
#if !CLICK_TOOL
# include <click/nameinfo.hh>
# include <click/standard/addressinfo.hh>
#elif HAVE_NETDB_H
# include <netdb.h>
#endif
CLICK_DECLS



ABCAddress::ABCAddress(const String &str)
{

}


StringAccum &
operator<<(StringAccum &sa, ABCAddress ipa)
{
    const unsigned char *p = ipa.data();
    char buf[20];
    int amt;
    amt = sprintf(buf, "%d.%d.%d.%d.%d.%d.%d.%d", p[0], p[1], p[2], p[3],p[4], p[5], p[6], p[7]);
    sa.append(buf, amt);
    return sa;
}


CLICK_ENDDECLS
