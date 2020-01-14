#include <click/config.h>
#include "arpquery.hh"
#include <iostream>

#include <climits>
#include <clicknet/ether.h>
#include <clicknet/arp.h>
#include <clicknet/abc.h>
#include <clicknet/label.h>
#include <click/error.hh>
#include <click/glue.hh>
CLICK_DECLS

ARPQuery ::ARPQuery()
{
}
ARPQuery ::~ARPQuery()
{
}

// Use local address info to configure
int ARPQuery ::configure(Vector<String> &conf, ErrorHandler *errh)
{
	_table.clear();
	_total = 0;

	const char *data1 = conf[0].data();
	const char *data2 = conf[1].data();
	std::cout << "configure ARPquery  "<<std::endl;
	unsigned char *addr = (unsigned char *)&_local_addr;
	int j = 0;
	for (int i = 0; i < 2; i++)
	{
		addr[1 - i] = 16 * parse_char(data1[j]) + parse_char(data1[j + 1]);
		j += 3;
	}

	int k = 0;
	for (int i = 0; i < 6; i++)
	{
		_local_mac[i] = 16 * parse_char(data2[k]) + parse_char(data2[k + 1]);
		k += 3;
	}
	return 0;
}

void ARPQuery ::send_arp(Packet *p, uint64_t dst)
{
	WritablePacket *req = Packet::make(sizeof(click_ether) + sizeof(my_arp));
	if (req == NULL)
	{
		click_chatter("ARPQuery: Cannot make request packet\n");
		p->kill();
		return;
	}

	click_ether *req_ether = reinterpret_cast<click_ether *>(req->data());
	my_arp *req_arp = reinterpret_cast<my_arp *>(req->data() + 14);

	for (int i = 0; i < 6; i++)
	{
		req_ether->ether_shost[i] = _local_mac[i];
		req_ether->ether_dhost[i] = 0xff;
	}
	req_ether->ether_type = htons(0x0602);

	req_arp->op = 0;
	for (int i = 0; i < 6; i++)
	{
		req_arp->arp_sha[i] = _local_mac[i];
		req_arp->arp_tha[i] = 0;
	}
	uint64_t sum_mac = 0;
	for (int i = 0; i < 6; i++)
	{
		sum_mac = sum_mac << 8;
		sum_mac = (sum_mac + uint64_t(_local_mac[i]));
	}
	req_arp->arp_spa = ((_local_addr << 48) + sum_mac);
	req_arp->arp_tpa = dst;
	std::cout << "psp dst " << dst << std::endl;
	printf("No entry found in ARP table\n");
	printf("Generate ARP request packet:\n");

	print_mac(req_arp->arp_sha);
	printf("\n");
	std::cout << "arp spa " << std::hex << req_arp->arp_spa << std::endl;
	std::cout << "arp tpa " << std::hex << req_arp->arp_tpa << std::endl;

	output(0).push(req);
}

void ARPQuery ::handle_abc(Packet *p)
{
	click_chatter("Received an PSP packet\n");
	WritablePacket *tmp = (WritablePacket *)p;
	click_ether *p_ether = reinterpret_cast<click_ether *>(tmp->data());
	click_abc *p_abc = reinterpret_cast<click_abc *>(tmp->data() + 14);

	uint64_t a = p_abc->abc_dst;
	uint8_t *b = (uint8_t *)&a;
	uint8_t dst_addr = b[0];

	Entry *found = NULL;
	for (Vector<Entry>::iterator i = _table.begin(); i != _table.end(); i++)
	{
		if (i->addr == a)
		{
			found = i;
			break;
		}
	}
	if (found != NULL)
	{
		printf("FOUND Dst MAC!!! Forwarding Packet...\n");
		for (int i = 0; i < 6; i++)
		{
			p_ether->ether_shost[i] = _local_mac[i];
			p_ether->ether_dhost[i] = found->mac[i];
		}
		printf("FOUND Dst MAC!!! Forwarding Packet...\n");
		output(0).push(p);
	}
	else
		send_arp(p, a);
}

void ARPQuery ::handle_response(Packet *p)
{
	const my_arp *p_arp = reinterpret_cast<const my_arp *>(p->data() + 14);
	for (int i = 0; i < _table.size(); i++)
	{
		if (_table[i].addr == p_arp->arp_spa)
		{
			_table.erase(&_table[i]);
			break;
		}
	}

	Entry entry;
	entry.addr = p_arp->arp_spa;
	for (int i = 0; i < 6; i++)
	{
		entry.mac[i] = p_arp->arp_sha[i];
	}
	_table.push_back(entry);

	printf("Received ARP Response\n");
	printf("Store ");
	std::cout << entry.addr << std::endl;
	printf(" ");
	std::cout << entry.mac << std::endl;
	printf(" to ARP table\n\n");

	p->kill();
}

//fixme:!!!

void ARPQuery ::push(int port, Packet *p)
{
	_total++;
	WritablePacket *tmp = (WritablePacket *)p;
	click_ether *p_ether = reinterpret_cast<click_ether *>(tmp->data()); //frame header
	printf("NUM of Packets:%d\nFrom Port:%d\n", _total, port);
	if (port == 0)
	{

		handle_abc(p);
	}

	else
	{
		printf("Received ARP Response\n");
		handle_response(p);
	}
}

CLICK_ENDDECLS
EXPORT_ELEMENT(ARPQuery)
ELEMENT_MT_SAFE(ARPQuery)
