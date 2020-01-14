#ifndef CLICK_ABCPRINT_HH
#define CLICK_ABCPRINT_HH
#include <click/element.hh>
#include <click/string.hh>
CLICK_DECLS

class ABCPrint : public Element{
public:
	ABCPrint();
	~ABCPrint();


	const char * class_name() const {return "ABCPrint";}
	const char * port_count() const {return PORTS_1_1;}

	int configure(Vector<String> &, ErrorHandler *);
	bool can_live_reconfigure() const {return true;}
	void add_handlers();

	Packet * simple_action(Packet *);

	void print_hex(uint8_t value){
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

	void print_abc(uint64_t abc)
	{
		uint8_t * p = (uint8_t *) &abc;
		for(int i = 0;i < 8;i++){
			print_hex(p[7-i]);
			if(i < 7){
				printf(".");
			}
		}
	}

	void print_mac(const uint8_t * m)
	{
		int i =  0;
		for(i = 0;i < 6;i++){
			print_hex(m[i]);
			if(i < 5){
				printf(":");
			}
		}
	}
    /*void print_label(uint64_t label)
    {
        uint8_t * p = (uint8_t *) &label;
        for(int i = 0;i < 8;i++){
            print_hex(p[7-i]);
            if(i < 7){
                printf(".");
            }
        }
    }*/
};
CLICK_ENDDECLS
#endif
