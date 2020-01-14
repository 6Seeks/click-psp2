#include <click/config.h>
#include <click/error.hh>
#include <clicknet/abc.h>
#include <clicknet/ether.h>
#include "labelqueue.hh"

CLICK_DECLS

LabelQueue::LabelQueue()
{
}

LabelQueue::~LabelQueue()
{
}


int LabelQueue::configure(Vector<String> &conf, ErrorHandler *errh)
{
	/*unsigned rate;
  	if (Args(conf, this, errh).read_mp("RATE", rate).complete() < 0)
		return -1;
	if(rate != 0)
	{
	    _rate_limited = true;
	    _rate.set_rate(rate, errh);
	}
	else
	    _rate_limited = false;*/
}

void LabelQueue::push(int port, Packet *p)
{
	WritablePacket * tmp = (WritablePacket *) p;
	click_ether * p_ether = reinterpret_cast<click_ether *>(tmp->data());

	click_label * p_label = reinterpret_cast<click_label *>(tmp->data() + 14);
	click_psp * p_psp = reinterpret_cast<click_psp *>(tmp->data() + 32+14);
	if(port == 0)
	{
		// label Packets
		if(p_ether->ether_type == htons(0x0601))
		{
			click_chatter("Push an label Packet to Queue...\n");

			switch(p_label->label_qos)
			{
				case 1:
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
		//From ARPQuery: PSP Packets
		else if(p_ether->ether_type == htons(0x0600))
		{
			click_chatter("Push an err...\n");
			/*switch(p_psp->psp_resv)
			{
				case 1:
					_qqq[0].push(p);
					break;
				case 2:
					_qqq[1].push(p);
					break;
				case 3:
					_qqq[2].push(p);
					break;
				default:
					p->kill();
			}*/
		}
			//From ARPQuery: ARP Requests
		else
		{
			click_chatter("Push an err...\n");
			_qqq[0].push(p);
		}

	}

		//From ARPResp: ARP Responses
	else
	{
		click_chatter("Push an err...\n");
		_qqq[0].push(p);
	}
}

Packet* LabelQueue::pull(int)
{
    Packet *p;
	int i = 0;

		while(i < 8)
		{
			if(p = _qqq[i].pull())
				return p;
			else
				i++;
		}
		return 0;

}

CLICK_ENDDECLS
EXPORT_ELEMENT(LabelQueue)
ELEMENT_MT_SAFE(LabelQueue)
