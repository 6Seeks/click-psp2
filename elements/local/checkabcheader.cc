#include <click/config.h>
#include "checkabcheader.hh"
#include <clicknet/ip.h>
#include <clicknet/abc.h>
#include <click/glue.hh>
#include <click/args.hh>
#include <click/straccum.hh>
#include <click/error.hh>
#include <click/standard/alignmentinfo.hh>
CLICK_DECLS


CheckABCHeader::CheckABCHeader()
{
}

CheckABCHeader::~CheckABCHeader()
{
}



Packet *
CheckABCHeader::simple_action(Packet *p)
{
  //new code//
  WritablePacket *q = (WritablePacket *) p;

  click_abc *abc = reinterpret_cast<click_abc *>(q->data()+14);
  unsigned ttl = abc->abc_ttl;
  click_chatter("CheckABCHeader: TTL = %d",ttl);
  if (ttl<=0){
     	click_chatter("Packet Dropped for TTL = 0... ");
	p->kill();
  }
  //ttl-1
  abc->abc_ttl = ttl-1;
//  q->set_psp_header(abc, p->length() - abc->abc_len);

  return q;
}

CLICK_ENDDECLS
EXPORT_ELEMENT(CheckABCHeader)
