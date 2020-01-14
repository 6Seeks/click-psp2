#include <iostream>
#include <click/config.h>
#include <click/ipaddress.hh>
#include <click/args.hh>
#include <click/error.hh>
#include <click/glue.hh>
#include <click/straccum.hh>
#include <click/router.hh>
#include "lookuproute.hh"

CLICK_DECLS

int
LookupRoute::configure(Vector<String> &conf, ErrorHandler *errh)
{
    click_chatter("LookupRoute: configure the PSP_route_table ...");
    int r = 0, r1, eexist = 0;
    uint64_t addr;
    int port;
	for (int i = 0; i < conf.size(); i+=2){
		std::cout<<conf[i].c_str()<<std::endl;
		std::cout<<conf[i+1].c_str()<<std::endl;
	}
	for (int i = 0; i < conf.size(); i+=2){
		std::cout<<conf[i].c_str()<<std::endl;
	}

    for (int i = 0; i < conf.size(); i+=2)
	{
	 addr = parseAddr(conf[i].c_str(), conf[i].length());
	 port = parsePort(conf[i+1].c_str(), conf[i+1].length());
	 std::cout<<addr<<"  "<<port<<std::endl;
	 ABCAddress addrTmp(addr);
	 ABCRoute routeTmp(addrTmp, port);
	 if ((r1 = add_route(routeTmp, false, 0, errh)) < 0)
	 {
	    if (r1 == 1)
			++eexist;
	    else
			r = r1;
	 }
    }

    if (eexist)
	errh->warning("%d %s replaced by later versions", eexist, eexist > 1 ? "routes" : "route");
    return r;
}

int
LookupRoute::add_route(const ABCRoute &r, bool allow_replace, ABCRoute* replaced, ErrorHandler *)
{

    click_chatter("LookupRoute: Adding an entry to the PSP_route_table.");
    click_chatter("%llx   %d",r.addr.addr(),r.port);

    int found = _t.size();

	for (int i = 0; i < _t.size(); i++)
		if (_t[i].addr == r.addr)
		{
			if (replaced)
				*replaced = _t[i];
			if (allow_replace)
			{
				_t[i].port = r.port;
				return 1;
			}
			return 0;
		}

    _t.push_back(r);

    return 0;
}

int
LookupRoute::remove_route(const ABCRoute &r, ABCRoute* old_route, ErrorHandler *errh)
{
    for (int i = 0; i < _t.size(); i++)
		if (r.match(_t[i])) {
			if (old_route)
				*old_route = _t[i];
			_t[i].kill();

			return 0;
		}
    return -ENOENT;
}

int
LookupRoute::lookup_entry(ABCAddress a) const
{
//    click_chatter("Start searching...");

	for (int i = 0; i < _t.size(); i++)
	if (_t[i].contains(a))
	{
	    int found = i;
	    return found;
	}
    return -1;
}

int
LookupRoute::lookup_route(ABCAddress a) const
{
    int ei = lookup_entry(a);
    if (ei >= 0)
	{
		return _t[ei].port;
    }
	else
		return -1;
}


void
LookupRoute::push(int, Packet *p)
{
    click_chatter("\nLookupRoute PUSH...");

    const click_ether *peth = reinterpret_cast<const click_ether *>(p->data()) ;
    const click_abc *abc = reinterpret_cast<const click_abc *>(p->data()+14);
    const click_udp *udp = reinterpret_cast<const click_udp *>(abc + 1);
    unsigned char *p_abcaddr = 0;

    click_chatter("Dst addr: %llx",abc->abc_dst);
    ABCAddress a(abc->abc_dst);
    int ei = lookup_entry(a);

    if (ei >= 0) {
        click_chatter("Find a Route for a PSP Packet");
    }
	else
	{
		static int complained = 0;
		if (++complained <= 5)
			click_chatter("LinearLookup: no route");
		p->kill();
		return;
    }

    const ABCRoute &e = _t[ei];
    click_chatter("the output port is %d", e.port);

    output(e.port).push(p);
}


uint64_t LookupRoute::parseAddr(const char* str, int l)
{
	uint64_t result=0;
	const char *s = str;
	int value1=0,value2=0;
	int pos=0,len1=0,len2=0;

	for(int i=0;i<l;i++)
	{
		if(s[i]=='.')
			pos=i;
	}

	len1=pos;
	len2=l-pos-1;
	if(len1==1)
		value1=s[0]-'0';
	if(len1==2)
		value1=10*(s[0]-'0')+(s[1]-'0');
	if(len1==3)
		value1=100*(s[0]-'0')+10*(s[1]-'0')+(s[2]-'0');

	if(len2==1)
		value2=s[pos+1]-'0';
	if(len2==2)
		value2=10*(s[pos+1]-'0')+(s[pos+2]-'0');
	if(len2==3)
		value2=100*(s[pos+1]-'0')+10*(s[pos+2]-'0')+(s[pos+3]-'0');

	click_chatter("value1=%d, value2=%d",value1,value2);
	result=value1*256+value2;
	return result;
}

int LookupRoute::parsePort(const char* str, int l){
        int result = 0;
        const char *t = str;
        if (l == 1){
                result = *t -'0';
        }else{
                int part = *t - '0';
                int i = 1;
                for( t++; i < l && isdigit((unsigned char) *t); t++){
                        part = part * 10 + *t -'0';
                        i++;
                }
                result = part;
        }

       	if(result < 0)
        	result = 0;

        return result;
}


CLICK_ENDDECLS
EXPORT_ELEMENT(LookupRoute)
ELEMENT_MT_SAFE(LookupRoute)
