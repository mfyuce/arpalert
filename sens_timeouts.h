/*
 * Copyright (c) 2005-2010 Thierry FOURNIER
 * $Id: sens_timeouts.h 578 2007-08-27 13:57:26Z thierry $
 *
 */

#ifndef __SENS_TIMEOUTS_H__
#define __SENS_TIMEOUTS_H__

#include "data.h"

// initialize data structures
void sens_timeout_init(void);

// add new detection timour tracking
void sens_timeout_add(struct ether_addr *, struct in_addr,
                      struct capt *idcap);

// return TRUE if timeout is not expired
int  sens_timeout_exist(struct ether_addr *, struct in_addr,
                        struct capt *idcap);

// return the next timeout and the functionn to call
void *sens_timeout_next(struct timeval *tv);

// cleanup timeout expireds
void sens_timeout_clean(void);

#endif

