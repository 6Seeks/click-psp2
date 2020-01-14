#ifndef CLICK_QUEUE_HH
#define CLICK_QUEUE_HH
#include <click/element.hh>
#include <click/glue.hh>
#include <click/config.h>
#include <click/args.hh>
#include <click/error.hh>
CLICK_DECLS

class Queue
{
  public:


    Queue()
    {
	_head = 0;
	_tail = 0;
	_capacity = 1000;
        _q = (Packet **) CLICK_LALLOC(sizeof(Packet *) * (_capacity + 1));
        if (_q == 0)
		click_chatter("Allocating Queue: Out of Memory");
    	_drops = 0;
    	_highwater_length = 0;
    }

    ~Queue()
    {
        for (int i = _head; i != _tail; i = next(i))
	    _q[i]->kill();
        CLICK_LFREE(_q, sizeof(Packet *) * (_capacity + 1));
        _q = 0;
    }

    void push(Packet *p)
{
    int h = _head, t = _tail, nt = next(t);
    if (nt != h)
	{
		_q[t] = p;
		_tail = nt;
		int s = size();
		if (s > _highwater_length)
			_highwater_length = s;
    }
	else
	{
		if (_drops == 0 && _capacity > 0)
			click_chatter("%{element}: overflow", this);
		_drops++;
    }
}

    Packet* pull()
{
    int h = _head, t = _tail;
    if (h != t)
	{
		Packet *p = _q[h];
		_head = next(h);
		return p;
    }
	else
		return 0;
}

    int size()
    {
		int x = _tail - _head;
		return (x >= 0 ? x : _capacity + x + 1);
    }

    int drops() const				{ return _drops; }
    int highwater_length() const		{ return _highwater_length; }
	int capacity() const		{ return _capacity; }
	int head() const		{ return _head; }
    int tail() const		{ return _tail; }

    int next(int i) const
	{
		return (i!=_capacity ? i+1 : 0);
    }
    int prev(int i) const
	{
		return (i!=0 ? i-1 : _capacity);
    }

  private:

    Packet* volatile * _q;
    volatile int _drops;
    int _highwater_length;
	int _capacity;
	int _head;
	int _tail;
};


CLICK_ENDDECLS
#endif
