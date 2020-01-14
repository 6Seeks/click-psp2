#ifndef CLICK_CHECKABCHEADER_HH
#define CLICK_CHECKABCHEADER_HH
#include <click/element.hh>
#include <click/atomic.hh>
CLICK_DECLS

class CheckABCHeader : public Element { public:

  CheckABCHeader();
  ~CheckABCHeader();


  const char *class_name() const		{ return "MyCheckHeader"; }
  const char *port_count() const		{ return PORTS_1_1X2; }
  const char *processing() const		{ return PROCESSING_A_AH; }


  Packet *simple_action(Packet *);

};

CLICK_ENDDECLS
#endif
