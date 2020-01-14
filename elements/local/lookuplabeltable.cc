
#include <click/config.h>
#include <click/ipaddress.hh>
#include <click/args.hh>
#include <click/error.hh>
#include <click/glue.hh>
#include <click/straccum.hh>

#include "lookuplabeltable.hh"

CLICK_DECLS
//fixme:!!
int
LookupLabelTable::configure(Vector<String> &conf, ErrorHandler *errh)
{
    click_chatter("LookupLabelTable: configure the label_table ...");
    int r = 0, r1, eexist = 0;
    uint64_t addr;
    int port;
    int labelin;
    int labelout;

    for (int i = 0; i < conf.size(); i+=3)
	{
	 labelin = parsePort(conf[i].c_str(), conf[i].length());
	 port = parsePort(conf[i+1].c_str(), conf[i+1].length());
	 labelout = parsePort(conf[i+2].c_str(), conf[i+2].length());
	 addLabelEntry(labelin,port,labelout);
    }

    if (eexist)
	errh->warning("%d %s replaced by later versions", eexist, eexist > 1 ? "routes" : "route");
    return r;
}
int
LookupLabelTable::addLabelEntry(int labelin ,int port,int labelout)
{

	click_chatter("LookupRoute: Adding an entry to the label_table.");
	click_chatter("%d   %d    %d",labelin,port,labelout);

	int found = _t.size();

	LabelEntry entrytemp(labelin,port,labelout);

	_t.push_back(entrytemp);

	return 0;
}
//core!!
int
LookupLabelTable::lookup_entry(int label) const
{
//    click_chatter("Start searching...");

	for (int i = 0; i < _t.size(); i++)
	if (_t[i].labelin==label)
	{
	    int found = i;
	    return found;
	}
    return -1;
}

void
LookupLabelTable::push(int, Packet *q)
{
    click_chatter("\nLookupLabel PUSH...");
    WritablePacket *p = (WritablePacket *) q;
    click_ether *peth = reinterpret_cast<click_ether *>(p->data()) ;
    click_label *label = reinterpret_cast<click_label *>(p->data()+14);

	int labelin = label->label_id;
    click_chatter("packet label_in: %d",labelin);

    int ei = lookup_entry(labelin);

    if (ei >= 0) {
        click_chatter("Find a labelentry for a label Packet");
    }
	else
	{
		static int complained = 0;
		if (++complained <= 5)
			click_chatter("LinearLabelLookup: no labelentry");
		p->kill();
		return;
    }

    const LabelEntry &e = _t[ei];
    click_chatter("the output port is %d", e.port);
	click_chatter("the modified label is %d", e.labelout);
	//modify_header(p);
    label->label_id = e.labelout;					//modify label
	output(e.port).push(p);
}



int LookupLabelTable::parsePort(const char* str, int l){
        int result = 0;
        const char *t = str;
        if (l == 1){
                result = *t -'0';
        }else{
                int part = *t - '0';
                int i = 1;
                for( t++; i < l && isdigit((unsigned char) *t); t++){
                        part = part * 16 + *t -'0';
                        i++;
                }
                result = part;
        }

       	if(result < 0)
        	result = 0;

        return result;
}


CLICK_ENDDECLS
EXPORT_ELEMENT(LookupLabelTable)
ELEMENT_MT_SAFE(LookupLabelTable)
