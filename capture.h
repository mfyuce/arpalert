/*
 * Copyright (c) 2005-2010 Thierry FOURNIER
 * $Id: capture.h 690 2008-03-31 18:36:43Z  $
 *
 */

#ifndef __CAPTURE_H__
#define __CAPTURE_H__

#include "macname.h"

#define FLAG_IPCHG      0x00000001 // 0
#define FLAG_ALLOW      0x00000002 // 1
#define FLAG_DENY       0x00000004 // 2
#define FLAG_NEW        0x00000008 // 3
#define FLAG_UNAUTH_RQ  0x00000010 // 4
#define FLAG_ABUS       0x00000020 // 5
#define FLAG_BOGON      0x00000040 // 6
#define FLAG_FLOOD      0x00000080 // 7
#define FLAG_NEWMAC     0x00000100 // 8
#define FLAG_MACCHG     0x00000200 // 9
#define FLAG_MACEXPIRE  0x00000400 // 10

// constantes
extern struct ether_addr null_mac;
extern struct in_addr null_ip;
extern struct in_addr broadcast;
extern struct timeval next_abus_reset;

// init capture system
void cap_init(void);

// get device name and return pointeur to her struct capt
struct capt *cap_get_interface(char *device);
		  
// set bitfield with the capture descriptors
int cap_gen_bitfield(fd_set *bf);

// launch capture system
void cap_sniff(fd_set *bf);

// reset global flood detection
void cap_abus(void);

// return the next timeout
void *cap_next(struct timeval *tv);
		
void send_alert(struct ether_addr *mac_sender,
                struct in_addr ip_sender,
                U_INT32_T flag,
                struct ether_addr *ref_mac,
                struct in_addr ref_ip,
                char *interface);

#endif
