#ifndef CLICK_ARPRESP_HH
#define CLICK_ARPRESP_HH
#include <click/element.hh>
#include <click/etheraddress.hh>
#include <click/ipaddress.hh>
#include <click/vector.hh>
CLICK_DECLS


class ARPResp : public Element{


public:
	ARPResp();
	~ARPResp();

	const char * class_name() const {return "MyARPResponder";}
	const char * port_count() const {return "1/1";}
	const char * processing() const {return PROCESSING_A_AH;}

	int configure(Vector<String> &, ErrorHandler *);
	Packet * simple_action(Packet *);

	uint8_t parse_char(char c){
		if('0' <= c && c <= '9'){
			return c - '0';
		} else if('A' <= c && c <= 'F'){
			return 10 + c - 'A';
		} else {
			return 10 + c - 'a';
		}
	}
	void print_hex(uint8_t value)
	{
		uint8_t a = value / 16;
	 	char c = '0';
	  	if(0 <= a && a <= 9){
	    	printf("%d", a);
		} else {
		 	c = 'A' + a - 10;
		 	printf("%c", c);
		}
		a = value % 16;
		if(0 <= a && a <= 9){
			printf("%d", a);
		} else {
			c = 'A' + a - 10;
		   	printf("%c", c);
		}
	}

	// void print_abc(uint16_t abc)
	// {
	// 	uint8_t * p = (uint8_t *) &abc;
	// 	for(int i = 0;i < 2;i++){
	// 		print_hex(p[1-i]);
	// 		if(i < 1){
	// 			printf(".");
	// 		}
	// 	}
	// }

	void print_mac(uint8_t *m)
	{
		int i = 0;
		for(i = 0;i < 6;i++){
			print_hex(m[i]);
			if(i < 5){
				printf(":");
			}
		}
	}
private:
	uint16_t _local_addr;
	uint8_t _local_mac[6];

};
CLICK_ENDDECLS
#endif



