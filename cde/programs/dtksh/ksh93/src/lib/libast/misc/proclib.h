/***********************************************************************
*                                                                      *
*               This software is part of the ast package               *
*          Copyright (c) 1985-2012 AT&T Intellectual Property          *
*          Copyright (c) 2020-2022 Contributors to ksh 93u+m           *
*                      and is licensed under the                       *
*                 Eclipse Public License, Version 2.0                  *
*                                                                      *
*                A copy of the License is available at                 *
*      https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html      *
*         (with md5 checksum 84283fa8859daf213bdda5a9f8d1be1d)         *
*                                                                      *
*                 Glenn Fowler <gsf@research.att.com>                  *
*                  David Korn <dgk@research.att.com>                   *
*                   Phong Vo <kpv@research.att.com>                    *
*                  Martijn Dekker <martijn@inlv.org>                   *
*                                                                      *
***********************************************************************/
/*
 * Glenn Fowler
 * AT&T Research
 *
 * process library definitions
 */

#ifndef _PROCLIB_H
#define _PROCLIB_H

#include <ast.h>
#include <errno.h>
#include <sig.h>
#include <wait.h>

#if _lib_sigprocmask
typedef sigset_t Sig_mask_t;
#else
typedef unsigned long Sig_mask_t;
#endif

struct Mods_s;

#define _PROC_PRIVATE_ \
	struct Mod_s*	mods;		/* process modification state	*/ \
	long		flags;		/* original PROC_* flags	*/ \
	Sig_mask_t	mask;		/* original blocked sig mask	*/ \
	Sig_handler_t	sigchld;	/* PROC_FOREGROUND SIG_DFL	*/ \
	Sig_handler_t	sigint;		/* PROC_FOREGROUND SIG_IGN	*/ \
	Sig_handler_t	sigquit;	/* PROC_FOREGROUND SIG_IGN	*/

#include <proc.h>

#define proc_default	_proc_info_	/* hide external symbol		*/

extern Proc_t		proc_default;	/* first proc			*/

#ifndef errno
extern int		errno;
#endif

#endif
