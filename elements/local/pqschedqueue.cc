#include <click/config.h>
#include <click/error.hh>
#include <clicknet/abc.h>
#include <clicknet/ether.h>
#include "pqschedqueue.hh"
CLICK_DECLS

PQSchedQueue::PQSchedQueue()
{
}

PQSchedQueue::~PQSchedQueue()
{
}


int PQSchedQueue::configure(Vector<String> &conf, ErrorHandler *errh)
{
	unsigned rate;
  	if (Args(conf, this, errh).read_mp("RATE", rate).complete() < 0)
		return -1;
	if(rate != 0)
	{
	    _rate_limited = true;
	    _rate.set_rate(rate, errh);
	}
	else
	    _rate_limited = false;
}

void PQSchedQueue::push(int port, Packet *p)
{
	WritablePacket * tmp = (WritablePacket *) p;
	click_ether * p_ether = reinterpret_cast<click_ether *>(tmp->data());
	click_abc * p_abc = reinterpret_cast<click_abc *>(tmp->data() + 14);

	if(port == 0)
	{
		//From ARPQuery: ABC Packets
		if(p_ether->ether_type == htons(0x0600))
		{
			click_chatter("Push an PSP Packet to Queue...\n");
			switch(p_abc->abc_resv)
			{	case 1:
					_qqq[0].push(p);
					break;
				case 2:
					_qqq[1].push(p);
					break;
				case 3:
					_qqq[2].push(p);
					break;
				case 4:
					_qqq[3].push(p);
					break;
				case 5:
					_qqq[4].push(p);
					break;
				case 6:
					_qqq[5].push(p);
					break;
				case 7:
					_qqq[6].push(p);
					break;
				case 8:
					_qqq[7].push(p);
					break;
				default:
					p->kill();
			}
		}
		//From ARPQuery: ARP Requests
		else
		{
			click_chatter("Push an ARP Request to Queue...\n\n");
			_qqq[0].push(p);
		}
	}
	//From ARPResp: ARP Responses
	else
	{
		click_chatter("Push an ARP Response to Queue...\n");
		_qqq[0].push(p);
	}
}

Packet* PQSchedQueue::pull(int)
{
    	Packet *p;
	int i = 0;
	if(_rate_limited)
	{
    		if (_rate.need_update(Timestamp::now()))
		{
      			_rate.update();
			//Priority Queue Realization
			while(i < 8)
			{
				if(p = _qqq[i].pull())
					return p;
				else
					i++;
			}
		}
		return 0;
	}
	else
	{
		while(i < 8)
		{
			if(p = _qqq[i].pull())
				return p;
			else
				i++;
		}
		return 0;
	}
}

CLICK_ENDDECLS
EXPORT_ELEMENT(PQSchedQueue)
ELEMENT_MT_SAFE(PQSchedQueue)
