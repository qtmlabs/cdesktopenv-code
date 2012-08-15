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
 * License along with these librararies and programs; if not, write
 * to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301 USA
 */
/* $XConsortium: fault.h /main/3 1995/11/01 16:39:48 rswiston $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*        THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF        *
*                    AT&T BELL LABORATORIES                    *
*         AND IS NOT TO BE DISCLOSED OR USED EXCEPT IN         *
*            ACCORDANCE WITH APPLICABLE AGREEMENTS             *
*                                                              *
*                Copyright (c) 1995 AT&T Corp.                 *
*              Unpublished & Not for Publication               *
*                     All Rights Reserved                      *
*                                                              *
*       The copyright notice above does not evidence any       *
*      actual or intended publication of such source code      *
*                                                              *
*               This software was created by the               *
*           Advanced Software Technology Department            *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                    {research,attmail}!dgk                    *
*                                                              *
***************************************************************/

/* : : generated by proto : : */
                  
#ifndef SH_SIGBITS
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

/*
 *	UNIX shell
 *	S. R. Bourne
 *	Rewritten by David Korn
 *
 */

#include	<sig.h>
#include	<setjmp.h>
#include	<error.h>
#include	<sfio.h>
#include	"FEATURE/setjmp"
#include	"FEATURE/sigfeatures"

typedef void (*SH_SIGTYPE) __PROTO__((int,void(*)(int)));

#define SH_FORKLIM		16	/* fork timeout interval */

#define SH_TRAP			0200	/* bit for internal traps */
#define SH_ERRTRAP		0	/* trap for non-zero exit status */
#define SH_KEYTRAP		1	/* trap for keyboard event */
#define SH_DEBUGTRAP		4	/* must be last internal trap */

#define SH_SIGBITS		8
#define SH_SIGFAULT		1	/* signal handler is sh_fault */
#define SH_SIGOFF		2	/* signal handler is SIG_IGN */
#define SH_SIGSET		4	/* pending signal */
#define SH_SIGTRAP		010	/* pending trap */
#define SH_SIGDONE		020	/* default is exit */
#define SH_SIGIGNORE		040	/* default is ingore signal */
#define SH_SIGINTERACTIVE	0100	/* handle interactive specially */
#define SH_SIGTSTP		0200	/* tstp signal received */

/*
 * These are longjmp values
 */

#define SH_JMPDOT	2
#define SH_JMPEVAL	3
#define SH_JMPTRAP	4
#define SH_JMPIO	5
#define SH_JMPCMD	6
#define SH_JMPFUN	7
#define SH_JMPERRFN	8
#define SH_JMPSUB	9
#define SH_JMPERREXIT	10
#define SH_JMPEXIT	11
#define SH_JMPSCRIPT	12

struct openlist
{
	Sfio_t	*strm;
	struct openlist *next;
};

struct checkpt
{
	sigjmp_buf	buff;
	sigjmp_buf	*prev;
	int		topfd;
	int		mode;
	struct openlist	*olist;
	struct errorcontext err;
};

#define sh_pushcontext(bp,n)	( (bp)->mode=(n) , (bp)->olist=0,  \
				  (bp)->topfd=sh.topfd, (bp)->prev=sh.jmplist, \
				  (bp)->err = *ERROR_CONTEXT_BASE, \
					sh.jmplist = (sigjmp_buf*)(bp) \
				)
#define sh_popcontext(bp)	(sh.jmplist=(bp)->prev, errorpop(&((bp)->err)))

extern __MANGLE__ void 	sh_fault __PROTO__((int));
extern __MANGLE__ void 	sh_done __PROTO__((int));
extern __MANGLE__ void 	sh_chktrap __PROTO__((void));
extern __MANGLE__ void 	sh_exit __PROTO__((int));
extern __MANGLE__ void 	sh_sigclear __PROTO__((int));
extern __MANGLE__ void 	sh_sigdone __PROTO__((void));
extern __MANGLE__ void	sh_siginit __PROTO__((void));
extern __MANGLE__ void 	sh_sigtrap __PROTO__((int));
extern __MANGLE__ void 	sh_sigreset __PROTO__((int));
extern __MANGLE__ void 	sh_timetraps __PROTO__((void));
extern __MANGLE__ __V_ 	*kshtimeradd __PROTO__((unsigned long,int ,void (*)(__V_*),__V_*));
extern __MANGLE__ void	timerdel __PROTO__((__V_*));

extern __MANGLE__ const char e_alarm[];

#endif /* !SH_SIGBITS */
