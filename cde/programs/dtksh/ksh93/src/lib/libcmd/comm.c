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
/* $XConsortium: comm.c /main/3 1995/11/01 19:04:54 rswiston $ */
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
static const char id[] = "\n@(#)comm (AT&T Bell Laboratories) 04/01/92\0\n";

#include <cmdlib.h>

#define C_FILE1		1
#define C_FILE2		2
#define C_COMMON	4
#define C_ALL		(C_FILE1|C_FILE2|C_COMMON)

static int comm __PARAM__((Sfio_t *in1, Sfio_t *in2, register Sfio_t *out,register int mode), (in1, in2, out, mode)) __OTORP__(Sfio_t *in1; Sfio_t *in2; register Sfio_t *out;register int mode;){
	register char *cp1, *cp2;
	register int n1, n2, n, comp;
	if(cp1 = sfgetr(in1,'\n',0))
		n1 = sfslen();
	if(cp2 = sfgetr(in2,'\n',0))
		n2 = sfslen();
	while(cp1 && cp2)
	{
		n=(n1<n2?n1:n2);
		if((comp=memcmp(cp1,cp2,n-1))==0 && (comp=n1-n2)==0)
		{
			if(mode&C_COMMON)
			{
				if(mode!=C_COMMON)
				{
					sfputc(out,'\t');
					if(mode==C_ALL)
						sfputc(out,'\t');
				}
				if(sfwrite(out,cp1,n) < 0)
					return(-1);
			}
			if(cp1 = sfgetr(in1,'\n',0))
				n1 = sfslen();
			if(cp2 = sfgetr(in2,'\n',0))
				n2 = sfslen();
		}
		else if(comp > 0)
		{
			if(mode&C_FILE2)
			{
				if(mode&C_FILE1)
					sfputc(out,'\t');
				if(sfwrite(out,cp2,n2) < 0)
					return(-1);
			}
			if(cp2 = sfgetr(in2,'\n',0))
				n2 = sfslen();
		}
		else
		{
			if((mode&C_FILE1) && sfwrite(out,cp1,n1) < 0)
				return(-1);
			if(cp1 = sfgetr(in1,'\n',0))
				n1 = sfslen();
		}
	}
	n = 0;
	if(cp2)
	{
		cp1 = cp2;
		in1 = in2;
		n1 = n2;
		if(mode&C_FILE1)
			n = 1;
		mode &= C_FILE2;
	}
	else
		mode &= C_FILE1;
	if(!mode || !cp1)
	{
		if(cp1 && in1==sfstdin)
			sfseek(in1,0L,SEEK_END);
		return(0);
	}
	/* process the remaining stream */
	while(1)
	{
		if(n)
			sfputc(out,'\t');
		if(sfwrite(out,cp1,n1) < 0)
			return(-1);
		if(!(cp1 = sfgetr(in1,'\n',0)))
			return(0);
		n1 = sfslen();
	}
	/* NOT REACHED */
}

int
b_comm __PARAM__((int argc, char *argv[]), (argc, argv)) __OTORP__(int argc; char *argv[];){
	register int n;
	register int mode = C_FILE1|C_FILE2|C_COMMON;
	register char *cp;
	Sfio_t *f1, *f2;

	NoP(id[0]);
	cmdinit(argv);
	while (n = optget(argv, "123 file1 file2")) switch (n)
	{
 	    case '1':
		mode &= ~C_FILE1;
		break;
	    case '2':
		mode &= ~C_FILE2;
		break;
	    case '3':
		mode &= ~C_COMMON;
		break;
	    case ':':
		error(2, opt_info.arg);
		break;
	    case '?':
		error(ERROR_usage(2), opt_info.arg);
		break;
	}
	argv += opt_info.index;
	argc -= opt_info.index;
	if(error_info.errors || argc!=2)
		error(ERROR_usage(2),optusage(NiL));
	cp = *argv++;
	if(streq(cp,"-"))
		f1 = sfstdin;
	else if(!(f1 = sfopen(NiL, cp,"r")))
		error(ERROR_system(1),"%s: cannot open",cp);
	cp = *argv;
	if(streq(cp,"-"))
		f2 = sfstdin;
	else if(!(f2 = sfopen(NiL, cp,"r")))
		error(ERROR_system(1),"%s: cannot open",cp);
	if(mode)
	{
		if(comm(f1,f2,sfstdout,mode) < 0)
			error(ERROR_system(1)," write error");
	}
	else if(f1==sfstdin || f2==sfstdin)
		sfseek(sfstdin,0L,SEEK_END);
	if(f1!=sfstdin)
		sfclose(f1);
	if(f2!=sfstdin)
		sfclose(f2);
	return(error_info.errors);
}
