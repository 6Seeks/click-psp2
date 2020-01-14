
#ifndef CLICKNET_ABC_H
#define CLICKNET_ABC_H

#include <click/cxxprotect.h>
CLICK_CXX_PROTECT
#if CLICK_LINUXMODULE
# include <net/checksum.h>
# include <linux/in.h>
#else
# include <sys/types.h>
# include <netinet/in.h>
#endif


struct click_abc {
#if CLICK_BYTE_ORDER == CLICK_BIG_ENDIAN
    unsigned	abc_v : 4;		/* 0     version == 1		     */
    unsigned	abc_resv : 4;		/*      reserve field		     */
#elif CLICK_BYTE_ORDER == CLICK_LITTLE_ENDIAN
    unsigned	abc_resv : 4;		
    unsigned	abc_v : 4;		
#else
#   error "unknown byte order"
#endif
    unsigned	abc_id:24;			/* start from 1     packet sequence number	     */
    uint16_t	abc_len;			/*16 bits  psp packet data len, doesn't include psp header	     */
    uint8_t	abc_next;			/* protocol type in psp data field    */
    uint8_t	abc_ttl;			/* hops limits		     */
    uint64_t abc_src;		/* 12-15 source address		     */
    uint64_t abc_dst;		/* 16-19 destination address	     */
};

#define ABC_ICMP                 (1)
#define ABC_UDP                  (2)


CLICK_CXX_UNPROTECT
#include <click/cxxunprotect.h>
#endif
