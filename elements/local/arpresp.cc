#include <click/config.h>
#include "arpresp.hh"
#include <clicknet/arp.h>
#include <clicknet/ether.h>
#include <click/args.hh>
#include <click/error.hh>
#include <click/glue.hh>
#include <click/straccum.hh>
#include <click/packet_anno.hh>
#include <iostream>
CLICK_DECLS

ARPResp :: ARPResp()
{}
ARPResp :: ~ARPResp()
{}


// Use local address info to configure
// 123.12  ff:ff:ff:ff:ff:ff
int ARPResp :: configure(Vector<String> & conf, ErrorHandler * errh)
{
	std::cout<<"configure ARPresponse"<<std::endl;
	const char * data1 = conf[0].data();
	const char * data2 = conf[1].data();

	unsigned char * addr = (unsigned char *) &_local_addr;

	int j = 0;
	for(int i = 0;i < 2;i++){
		addr[1 - i] = 16 * parse_char(data1[j]) + parse_char(data1[j + 1]);
		j += 3;
	}

	int k = 0;
	for(int i = 0;i < 6;i++){
		_local_mac[i] = 16 * parse_char(data2[k]) + parse_char(data2[k + 1]);
		k += 3;
	}
	return 0;
}

Packet * ARPResp :: simple_action(Packet * p)
{
	WritablePacket * tmp1 = (WritablePacket *) p;
	click_ether * p_ether = reinterpret_cast<click_ether *>(tmp1->data());
	my_arp * p_arp = reinterpret_cast<my_arp *>(tmp1->data() + 14);

	click_chatter("Receiving ARP request:\n");
	printf("arp_sha  ");
	print_mac(p_arp->arp_sha);
	printf("\narp_tha  ");
	print_mac(p_arp->arp_tha);
	printf("\n_local_mac  ");
	print_mac(_local_mac);
	printf("\n");
	std::cout<<"arp_spa  "<<std::hex<<p_arp->arp_spa<<std::endl;
	
	std::cout<<"arp_tpa  "<<std::hex<<p_arp->arp_tpa<<std::endl;
	std::cout<<"local_addr "<<_local_addr<<std::endl;
	uint64_t sum_mac=0;
	for(int i=0;i<6;i++){
		sum_mac=sum_mac<<8;
		sum_mac=sum_mac+_local_mac[i];
	}
	std::cout<<"sum_mac  "<<sum_mac<<std::endl;
	std::cout<<"real local_addr  "<<std::hex<<((uint64_t(_local_addr) <<48)+sum_mac)<<std::endl;	
	if(p_arp->arp_tpa == (uint64_t(_local_addr)<<48)+sum_mac)
	{
		WritablePacket * resp = Packet::make(sizeof(click_ether) + sizeof(my_arp));
		if(resp == NULL)
		{
			printf("ARPResp: can not make respond packet!");
			return NULL;
		}
		WritablePacket * tmp2 = (WritablePacket *) resp;
		click_ether * resp_ether = reinterpret_cast<click_ether *>(tmp2->data());
		my_arp * resp_arp = reinterpret_cast<my_arp *>(tmp2->data() + 14);

		// set the arp response's ether header
		for(int i = 0;i < 6;i++)
		{
			resp_ether->ether_dhost[i] = p_ether->ether_shost[i];
			resp_ether->ether_shost[i] = _local_mac[i];
		}
		resp_ether->ether_type = htons(0x0602);

		// set the arp response's arp header
		resp_arp->op = 1;
		for(int i = 0;i < 6;i++)
		{
			resp_arp->arp_sha[i] = _local_mac[i];
			resp_arp->arp_tha[i] = p_arp->arp_sha[i];
		}
		uint64_t sum_mac=0;
		for(int i=0;i<6;i++){
			sum_mac=sum_mac<<8;
			sum_mac=sum_mac+_local_mac[i];
		}
		resp_arp->arp_spa = (uint64_t(_local_addr)<<48)+sum_mac;
		resp_arp->arp_tpa = p_arp->arp_spa;


		printf("Generating ARP response:\n");
		printf("arp_sha  ");
		print_mac(resp_arp->arp_sha);
		printf("\narp_tha  ");
		print_mac(resp_arp->arp_tha);
		printf("\n");
		std::cout<<"arp_spa  "<<std::hex<<resp_arp->arp_spa<<std::endl;
	
		std::cout<<"arp_tpa  "<<std::hex<<resp_arp->arp_tpa<<std::endl;
		return resp;
	}
	else
	{
		return NULL;
	}
	p->kill();
}

EXPORT_ELEMENT(ARPResp)
CLICK_ENDDECLS
