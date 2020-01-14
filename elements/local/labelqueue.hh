#ifndef CLICK_LABELQUEUE_HH
#define CLICK_LABELQUEUE_HH
#include <click/element.hh>
#include <click/gaprate.hh>
#include <click/glue.hh>
#include "queue.hh"

CLICK_DECLS


class LabelQueue : public Element {

  public:



    LabelQueue();
    ~LabelQueue();

    const char *class_name() const		{ return "LabelQueue"; }
    const char *port_count() const		{ return "1/1"; }
    const char *processing() const		{ return "h/lh"; }

    int configure(Vector<String> &, ErrorHandler *);

    void push(int port, Packet*);
    Packet* pull(int port);

  private:


	Queue _qqq[8];

};


CLICK_ENDDECLS
#endif
