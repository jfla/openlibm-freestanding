/*-
 * Copyright (c) 2003 Mike Barcroft <mike@FreeBSD.org>
 * Copyright (c) 2002 David Schultz <das@FreeBSD.ORG>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: src/lib/libc/include/fpmath.h,v 1.4 2008/12/23 22:20:59 marcel Exp $
 */
#ifndef _FPMATH_H_
#define _FPMATH_H_

// Currently assumes Intel platform
#if defined (__i386__) || defined(__x86_64__)
#ifdef __LP64__
#include "amd64_fpmath.h"
#else 
#include "i386_fpmath.h"
#endif
#endif

#ifdef __linux
#include <features.h>
#include <endian.h>
#define _LITTLE_ENDIAN  __LITTLE_ENDIAN
#define _BIG_ENDIAN     __BIG_ENDIAN
#define _PDP_ENDIAN     __PDP_ENDIAN
#define _BYTE_ORDER     __BYTE_ORDER
#endif

#ifdef __APPLE__
#include <machine/endian.h>
#define _LITTLE_ENDIAN  LITTLE_ENDIAN
#define _BIG_ENDIAN     BIG_ENDIAN
#define _PDP_ENDIAN     PDP_ENDIAN
#define _BYTE_ORDER     BYTE_ORDER
#endif

#ifdef __FreeBSD__
#include <machine/endian.h>
#endif

#ifdef _WIN32
#define _LITTLE_ENDIAN 1234
#define _BIG_ENDIAN    4321
#define _PDP_ENDIAN    3412
#define _BYTE_ORDER       _LITTLE_ENDIAN
#define _FLOAT_WORD_ORDER _LITTLE_ENDIAN
#define LITTLE_ENDIAN  _LITTLE_ENDIAN
#define BIG_ENDIAN     _BIG_ENDIAN
#define PDP_ENDIAN     _PDP_ENDIAN
#define BYTE_ORDER     _BYTE_ORDER
#endif

#ifdef __JAZZ__
#define _LITTLE_ENDIAN 1234
#define _BIG_ENDIAN    4321
#define _PDP_ENDIAN    3412
#define _BYTE_ORDER       _LITTLE_ENDIAN
#define _FLOAT_WORD_ORDER _LITTLE_ENDIAN
#define LITTLE_ENDIAN  _LITTLE_ENDIAN
#define BIG_ENDIAN     _BIG_ENDIAN
#define PDP_ENDIAN     _PDP_ENDIAN
#define BYTE_ORDER     _BYTE_ORDER
#endif

#ifndef _IEEE_WORD_ORDER
#define	_IEEE_WORD_ORDER	_BYTE_ORDER
#endif

union IEEEf2bits {
	float	f;
	struct {
#if _BYTE_ORDER == _LITTLE_ENDIAN
		unsigned int	man	:23;
		unsigned int	exp	:8;
		unsigned int	sign	:1;
#else /* _BIG_ENDIAN */
		unsigned int	sign	:1;
		unsigned int	exp	:8;
		unsigned int	man	:23;
#endif
	} bits;
};

#define	DBL_MANH_SIZE	20
#define	DBL_MANL_SIZE	32

union IEEEd2bits {
	double	d;
	struct {
#if _BYTE_ORDER == _LITTLE_ENDIAN
#if _IEEE_WORD_ORDER == _LITTLE_ENDIAN
		unsigned int	manl	:32;
#endif
		unsigned int	manh	:20;
		unsigned int	exp	:11;
		unsigned int	sign	:1;
#if _IEEE_WORD_ORDER == _BIG_ENDIAN
		unsigned int	manl	:32;
#endif
#else /* _BIG_ENDIAN */
		unsigned int	sign	:1;
		unsigned int	exp	:11;
		unsigned int	manh	:20;
		unsigned int	manl	:32;
#endif
	} bits;
};

#endif
