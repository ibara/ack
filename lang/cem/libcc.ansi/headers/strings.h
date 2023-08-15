/*
 * strings.h - string handling
 *
 * (c) copyright 1987 by the Vrije Universiteit, Amsterdam, The Netherlands.
 * See the copyright notice in the ACK home directory, in the file "Copyright".
 */
/* $Id$ */

#ifndef _STRINGS_H
#define	_STRINGS_H

#include <stddef.h>

extern int	strcasecmp(const char *_s1, const char *_s2);
extern int	strncasecmp(const char *_s1, const char *_s2, size_t _n);

#endif
