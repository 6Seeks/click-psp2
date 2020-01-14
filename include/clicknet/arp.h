#ifndef CLICK_ARP_H
#define CLICK_ARP_H


struct my_arp {
    uint8_t op;      	/* 0-7   (14-21)  fixed-size ARP header	     */
    uint8_t	arp_sha[6];	/* 8-13  (22-27)  sender hardware address    */
    uint64_t arp_spa;	/* 14-15 (28-29)  sender protocol address    */
    uint8_t	arp_tha[6];	/* 16-21 (30-35)  target hardware address    */
    uint64_t arp_tpa;	/* 22-23 (36-37)  target protocol address    */
};

#endif
