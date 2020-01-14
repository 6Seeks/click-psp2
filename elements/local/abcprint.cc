#include <click/config.h>
#include "abcprint.hh"
#include <click/glue.hh>
#include <click/args.hh>
#include <click/error.hh>
#include <click/straccum.hh>
#include <clicknet/abc.h>
#include <clicknet/ether.h>
#include <clicknet/label.h>
CLICK_DECLS

ABCPrint :: ABCPrint()
{}
ABCPrint :: ~ABCPrint()
{}


int ABCPrint :: configure(Vector<String> &conf, ErrorHandler * errh){
	return 0;
}

Packet * ABCPrint :: simple_action(Packet * p){
	const click_ether * p_ether = reinterpret_cast<const click_ether *>(p->data());


	if(p_ether->ether_type == htons(0x0600))
	{
		printf("\nPSP packet\n");

		printf("\nSrc MAC: ");
		print_mac(p_ether->ether_shost);
		printf("\nDst MAC: ");
		print_mac(p_ether->ether_dhost);
		printf("\n");

		const click_abc * abc = reinterpret_cast<const click_abc *>(p->data() + 14 );
		printf("Src PSP addr: ");
		print_abc(abc->abc_src);

		printf("\nDst PSP addr: ");
		print_abc(abc->abc_dst);
        printf("\n%d",p_ether->ether_type);
		printf("\n");
		printf("TOS = %u\n", abc->abc_resv);
		printf("ID = %u\n", abc->abc_id);
		printf("TTL = %u\n", abc->abc_ttl);
	}
	else if(p_ether->ether_type == htons(0x0602))
	{
		printf("\nARP packet\n");

		const unsigned char *packet_data = p->data();
		const uint8_t *data = (const uint8_t *)(packet_data + 12);
		for(int i=0;i<3;i++)
		{
			printf("%d byte of packet: %d\n", i+13, data[i]);
		}
	}

	else if(p_ether->ether_type == htons(0x0601)){
		printf("\nLABEL packet\n");

        printf("\nETHER LAYER:Src MAC: ");
        print_mac(p_ether->ether_shost);
        printf("\nETHER LAYER:Dst MAC: ");
        print_mac(p_ether->ether_dhost);
        const click_label * label = reinterpret_cast<const click_label *>(p->data() + 14);
		const click_abc * abc = reinterpret_cast<const click_abc *>(p->data() + 14+32 );
		printf("\n2.5 LAYER: ");
        printf("\nlabel_id : ");
        printf("%d",label->label_id);

        printf("\nlabel_qos : ");
		printf("%d",label->label_qos);
		printf("\nlabel_ttl : ");
		printf("%d",label->label_ttl);
		printf("\nETHER LAYER: ");
		printf("\nSrc PSP addr: ");
		print_abc(abc->abc_src);

		printf("\nDst PSP addr: ");
		print_abc(abc->abc_dst);
		printf("\n");
        printf("TOS = %u\n", abc->abc_resv);
        printf("ID = %u\n", abc->abc_id);
        printf("TTL = %u\n", abc->abc_ttl);
	}
	return p;
}

void ABCPrint :: add_handlers(){}

CLICK_ENDDECLS
EXPORT_ELEMENT(ABCPrint)
ELEMENT_MT_SAFE(ABCPrint)
