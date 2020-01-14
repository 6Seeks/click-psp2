#ifndef CLICK_ARPQUERY_HH
#define CLICK_ARPQUERY_HH
#include <click/element.hh>
#include <click/etheraddress.hh>
CLICK_DECLS


struct Entry
{	
	uint64_t addr;
	uint8_t mac[6];
};

class ARPQuery : public Element{
public:
	ARPQuery();
	~ARPQuery();

	const char * class_name() const {return "MyARPQuerier";}
	const char * port_count() const {return "2/1";}
	const char * processing() const {return PUSH;}

	int configure(Vector<String> &, ErrorHandler *);
	void push(int port, Packet * p);
	
private:

	Vector<Entry> _table;
	uint64_t _local_addr;
	uint8_t _local_mac[6];
	int _total;

	void send_arp(Packet *p, uint64_t dst);
    void handle_abc(Packet *p);
    void handle_response(Packet *p);
	
	uint8_t parse_char(char c)
	{
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

	// void print_abc(uint64_t abc)
	// {
	// 	uint64_t * p = (uint64_t *) &abc;
	// 	for(int i = 0;i < 8;i++){
	// 		print_hex(p[i]);
	// 		if(i < 7){
	// 			printf(".");
	// 		}
	// 	}
	// }

	void print_mac(uint8_t * m)
	{
		int i =  0;
		for(i = 0;i < 6;i++){
			print_hex(m[i]);
			if(i < 5){
				printf(":");
			}
		}
	}
};
CLICK_ENDDECLS
#endif
