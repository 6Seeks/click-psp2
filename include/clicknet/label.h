/* -*- mode: c; c-basic-offset: 4 -*- */
#ifndef CLICKNET_LABEL_H
#define CLICKNET_LABEL_H
/* get struct in_addr */
#include <click/cxxprotect.h>
CLICK_CXX_PROTECT
#if CLICK_LINUXMODULE
# include <net/checksum.h>
# include <linux/in.h>
#else
# include <sys/types.h>
# include <netinet/in.h>
#endif



struct click_label {

    unsigned	label_id:24;
    unsigned	label_qos:4;
    unsigned	label_ttl:4;
};



CLICK_CXX_UNPROTECT
#include <click/cxxunprotect.h>
#endif
