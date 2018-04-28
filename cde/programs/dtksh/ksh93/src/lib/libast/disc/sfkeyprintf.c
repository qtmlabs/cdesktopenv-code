/*
 * CDE - Common Desktop Environment
 *
 * Copyright (c) 1993-2012, The Open Group. All rights reserved.
 *
 * These libraries and programs are free software; you can
 * redistribute them and/or modify them under the terms of the GNU
 * Lesser General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * These libraries and programs are distributed in the hope that
 * they will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with these libraries and programs; if not, write
 * to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301 USA
 */
/* $XConsortium: sfkeyprintf.c /main/2 1996/05/08 19:40:49 drk $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*         THIS IS PROPRIETARY SOURCE CODE LICENSED BY          *
*                          AT&T CORP.                          *
*                                                              *
*                Copyright (c) 1995 AT&T Corp.                 *
*                     All Rights Reserved                      *
*                                                              *
*           This software is licensed by AT&T Corp.            *
*       under the terms and conditions of the license in       *
*       http://www.research.att.com/orgs/ssr/book/reuse        *
*                                                              *
*               This software was created by the               *
*           Software Engineering Research Department           *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                     gsf@research.att.com                     *
*                                                              *
***************************************************************/

/* : : generated by proto : : */

#if !defined(__PROTO__)
#if defined(__STDC__) || defined(__cplusplus) || defined(_proto) || defined(c_plusplus)
#if defined(__cplusplus)
#define __MANGLE__	"C"
#else
#define __MANGLE__
#endif
#define __STDARG__
#define __PROTO__(x)	x
#define __OTORP__(x)
#define __PARAM__(n,o)	n
#if !defined(__STDC__) && !defined(__cplusplus)
#if !defined(c_plusplus)
#define const
#endif
#define signed
#define void		int
#define volatile
#define __V_		char
#else
#define __V_		void
#endif
#else
#define __PROTO__(x)	()
#define __OTORP__(x)	x
#define __PARAM__(n,o)	o
#define __MANGLE__
#define __V_		char
#define const
#define signed
#define void		int
#define volatile
#endif
#if defined(__cplusplus) || defined(c_plusplus)
#define __VARARG__	...
#else
#define __VARARG__
#endif
#if defined(__STDARG__)
#define __VA_START__(p,a)	va_start(p,a)
#else
#define __VA_START__(p,a)	va_start(p)
#endif
#endif
#include <ast.h>
#include <ctype.h>
#include <sfdisc.h>
#include <sfstr.h>
#include <re.h>

#define ESC		'\033'

#define FMT_case	1
#define FMT_edit	2

#define RE_STOP		(1<<(RE_EXTERNAL+0))

static struct
{
	char			args[sizeof(va_list)];
	__V_*			handle;
	char*			format;
	Sf_key_lookup_t		lookup;
	Sf_key_convert_t	convert;
	Sfio_t*			tmp[2];
	int			invisible;
	int			level;
} state;

typedef struct
{
	char*			next;
	int			delimiter;
	int			first;
} Field_t;

typedef union
{
	char**			p;
	char*			s;
	long			l;
	int			i;
	char			c;
} Value_t;

#define initfield(f,s)	((f)->first = (f)->delimiter = *((f)->next = (s)))

static char*
getfield __PARAM__((register Field_t* f, int restore), (f, restore)) __OTORP__(register Field_t* f; int restore;){
	register char*	s;
	register int	n;
	register int	c;
	register int	lp;
	register int	rp;
	char*		b;

	if (!f->delimiter)
		return(0);
	s = f->next;
	if (f->first)
		f->first = 0;
	else if (restore)
		*s = f->delimiter;
	b = ++s;
	lp = rp = n = 0;
	for (;;)
	{
		if (!(c = *s++))
		{
			f->delimiter = 0;
			break;
		}
		else if (c == ESC || c == '\\')
		{
			if (*s) s++;
		}
		else if (c == lp) n++;
		else if (c == rp) n--;
		else if (n <= 0)
		{
			if (c == '(')
			{
				lp = '(';
				rp = ')';
				n = 1;
			}
			else if (c == '[')
			{
				lp = '[';
				rp = ']';
				n = 1;
			}
			else if (c == f->delimiter)
			{
				*(f->next = --s) = 0;
				break;
			}
		}
	}
	return(b);
}

/*
 * sfio %& extended format callout
 */

static int
extend __PARAM__((__V_* val, int fmt, int prec, char** out, int base, char* op, int oplen), (val, fmt, prec, out, base, op, oplen)) __OTORP__(__V_* val; int fmt; int prec; char** out; int base; char* op; int oplen;){
	NoP(fmt);
	NoP(prec);
	NoP(base);
	NoP(op);
	NoP(oplen);
	return(strlen(*out = (char*)val));
}

/*
 * sfio %@ argument callout
 */

static int
getarg __PARAM__((int cc, Value_t* value, char* op, int oplen), (cc, value, op, oplen)) __OTORP__(int cc; Value_t* value; char* op; int oplen;){
	char*		a = 0;
	char*		s = 0;
	long		n = 0;
	int		h = 0;
	int		i = 0;
	int		x = 0;
	char*		v;
	char*		e;
	char*		t;
	int		c;
	int		d;
	Re_program_t*	re;
	Field_t		f;

	state.level++;
	if (op && oplen > 0)
	{
		c = op[oplen];
		op[oplen] = 0;
		v = op;
		for (;;)
		{
			switch (*v++)
			{
			case 0:
				break;
			case '(':
				h++;
				continue;
			case ')':
				h--;
				continue;
			case '=':
			case ':':
			case ',':
				if (h <= 0)
				{
					a = v;
					break;
				}
				continue;
			default:
				continue;
			}
			if (i = *--v)
			{
				*v = 0;
				if (i == ':' && cc == 's' && strlen(a) > 4 && !isalnum(*(a + 4)))
				{
					d = *(a + 4);
					*(a + 4) = 0;
					if (streq(a, "case")) x = FMT_case;
					else if (streq(a, "edit")) x = FMT_edit;
					*(a + 4) = d;
					if (x) a = 0;
				}
			}
			break;
		}
		h = (*state.lookup)(state.handle, op, a, cc, &s, &n);
		if (i) *v++ = i;
		op[oplen] = c;
	}
	switch (cc)
	{
	case 'c':
		value->c = s ? *s : c;
		break;
	case 'd':
		value->i = (int)(s ? strtol(s, NiL, 0) : n);
		break;
	case 'D':
		value->l = (long)(s ? strtol(s, NiL, 0) : n);
		break;
	case 'p':
		value->p = (char**)(s ? strtol(s, NiL, 0) : n);
		break;
	case 's':
		if (!s)
		{
			if (h)
			{
				sfprintf(state.tmp[1], "%ld", n);
				s = sfstruse(state.tmp[1]);
			}
			else s = "";
		}
		if (x)
		{
			c = op[oplen];
			op[oplen] = 0;
			h = 0;
			d = initfield(&f, v + 4);
			switch (x)
			{
			case FMT_case:
				while ((a = getfield(&f, 1)) && (v = getfield(&f, 0)))
				{
					if (strmatch(s, a))
					{
int aha = *f.next;
						s = state.format;
						state.format = v;
						sfprintf(state.tmp[0], "%&%@%:", extend, getarg);
						state.format = s;
						s = sfstruse(state.tmp[0]);
						*(v - 1) = d;
						if (f.delimiter)
							*f.next = d;
						h = 1;
						break;
					}
					*(v - 1) = d;
				}
				break;
			case FMT_edit:
				x = 1;
				while ((a = getfield(&f, 1)) && (v = getfield(&f, 0)))
				{
					x ^= 1;
					i = 0;
					if (t = e = getfield(&f, 0))
					{
						for (;;)
						{
							switch (*t++)
							{
							case 0:
								break;
							case 'g':
								i |= RE_ALL;
								continue;
							case 'l':
								i |= RE_LOWER;
								continue;
							case 's':
								i |= RE_STOP;
								continue;
							case 'u':
								i |= RE_UPPER;
								continue;
							}
							break;
						}
					}
					if (re = recomp(a, RE_EDSTYLE|RE_MATCH))
					{
						if (reexec(re, s)) ressub(re, state.tmp[x], s, v, i);
						else
						{
							i = 0;
							sfputr(state.tmp[x], s, -1);
						}
						refree(re);
						s = sfstruse(state.tmp[x]);
					}
					else i = 0;
					*(v - 1) = d;
					if (e) *(e - 1) = d;
					if (i & RE_STOP)
					{
						if (f.delimiter)
							*f.next = d;
						break;
					}
				}
				h = 1;
				break;
			}
			op[oplen] = c;
			if (!h) s = "";
		}
		value->s = s;
		if (state.level == 1)
			while ((s = strchr(s, ESC)) && *(s + 1) == '[')
				do state.invisible++; while (*s && !islower(*s++));
		break;
	case 'u':
		value->i = (unsigned int)(s ? strtoul(s, NiL, 0) : n);
		break;
	case 'U':
		value->l = (unsigned long)(s ? strtoul(s, NiL, 0) : n);
		break;
	case '\n':
		value->s = "\n";
		break;
	case '1':
		value->s = state.format;
		break;
	case '2':
		value->s = state.args;
		break;
	default:
		if (!state.convert || !(value->s = (*state.convert)(state.handle, a, op, cc, s, n)))
		{
			sfprintf(state.tmp[0], "%%%c", cc);
			value->s = sfstruse(state.tmp[0]);
		}
		break;
	}
	state.level--;
	return(0);
}

int
sfkeyprintf __PARAM__((Sfio_t* sp, __V_* handle, const char* format, Sf_key_lookup_t lookup, Sf_key_convert_t convert), (sp, handle, format, lookup, convert)) __OTORP__(Sfio_t* sp; __V_* handle; const char* format; Sf_key_lookup_t lookup; Sf_key_convert_t convert;){
	register int	i;

	for (i = 0; i < elementsof(state.tmp); i++)
		if (!state.tmp[i] && !(state.tmp[i] = sfstropen()))
			return(0);
	state.handle = handle;
	state.format = (char*)format;
	state.lookup = lookup;
	state.convert = convert;
	state.invisible = 0;
	state.level = 0;
	return(sfprintf(sp, "%&%@%:", extend, getarg) - state.invisible);
}
