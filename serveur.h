/*
 * Copyright (c) 2005-2010 Thierry FOURNIER
 * $Id: serveur.h 423 2006-11-04 11:50:24Z  $
 *
 */

#ifndef __SERVER_H
#define __SERVER_H

// run program as daemon
void daemonize(void);

// set security option (user separation, etc ...)
void separe(void);

#endif

