/*
 * SPDX-FileCopyrightText: 2005-2020 Rich Felker, et al.
 *
 * SPDX-License-Identifier: MIT
 * 
 * Taken from musl/src/network/inet_ntoa.c
 */

#include <arpa/inet.h>
#include <stdio.h>

char *inet_ntoa(struct in_addr in)
{
	static char buf[16];
	unsigned char *a = (void *)&in;
	snprintf(buf, sizeof buf, "%d.%d.%d.%d", a[0], a[1], a[2], a[3]);
	return buf;
}
