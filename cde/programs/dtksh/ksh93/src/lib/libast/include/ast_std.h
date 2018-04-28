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
/* $XConsortium: ast_std.h /main/3 1995/11/01 17:35:19 rswiston $ */
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
                  
/*
 * Advanced Software Technology Department
 * AT&T Bell Laboratories
 *
 * a union of the following standard headers that works
 *
 *	<limits.h>
 *	<stdarg.h>
 *	<stddef.h>
 *	<stdlib.h>
 *	<sys/types.h>
 *	<string.h>
 *	<unistd.h>
 *	<fcntl.h>
 *	<locale.h>
 *
 * the following ast implementation specific headers are also included
 * these do not stomp on the std namespace
 *
 *	<ast_botch.h>
 *	<ast_fcntl.h>
 *	<ast_hdr.h>
 *	<ast_lib.h>
 *	<ast_types.h>
 *	<ast_unistd.h>
 *
 * NOTE: the C++ versions of most ANSI and POSIX files are fubar
 */

#ifndef _AST_STD_H
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

#define _AST_STD_H

#include <ast_hdr.h>

#ifndef	_ast_info
#if _DLL_INDIRECT_DATA && !_DLL
#define _ast_info	(*_ast_state)
#else
#define _ast_info	_ast_state
#endif
#endif

#ifdef	_SFSTDIO_H
#define _SKIP_SFSTDIO_H
#else
#define _SFSTDIO_H
#if !defined(linux)
#define FILE	int
#endif
#if defined(__STDPP__directive) && defined(__STDPP__hide)
#if !_std_def_calloc
__STDPP__directive pragma pp:hide calloc
#endif
#if !_std_def_free
__STDPP__directive pragma pp:hide free
#endif
#if !_std_def_malloc
__STDPP__directive pragma pp:hide malloc
#endif
#if !_std_def_realloc
__STDPP__directive pragma pp:hide realloc
#endif
__STDPP__directive pragma pp:hide bcopy bzero execl execle execlp execv
__STDPP__directive pragma pp:hide execvp getcwd putenv setenv setpgrp sleep
__STDPP__directive pragma pp:hide spawnve spawnveg strdup
__STDPP__directive pragma pp:hide vfprintf vprintf vsprintf
#else
#if !_std_def_calloc
#define calloc		______calloc
#endif
#if !_std_def_free
#define free		______free
#endif
#if !_std_def_malloc
#define malloc		______malloc
#endif
#if !_std_def_realloc
#define realloc		______realloc
#endif
#define bcopy		______bcopy
#define bzero		______bzero
#define execl		______execl
#define execle		______execle
#define execlp		______execlp
#define execv		______execv
#define execvp		______execvp
#define getcwd		______getcwd
#define putenv		______putenv
#define setenv		______setenv
#define setpgrp		______setpgrp
#define sleep		______sleep
#define spawnve		______spawnve
#define spawnveg	______spawnveg
#define strdup		______strdup
#define vfprintf	______vfprintf
#define vprintf		______vprintf
#define vsprintf	______vsprintf
#endif
#endif

#if defined(__STDPP__directive) && defined(__STDPP__note)
__STDPP__directive pragma pp:note clock_t dev_t div_t gid_t ino_t ldiv_t mode_t
__STDPP__directive pragma pp:note nlink_t off_t pid_t ptrdiff_t size_t ssize_t
__STDPP__directive pragma pp:note time_t uid_t wchar_t
#endif

#include <sys/types.h>
#if !defined(va_start)
#if defined(__STDARG__)
#include <stdarg.h>
#else
#include <varargs.h>
#endif
#endif


#if defined(__STDPP__directive) && defined(__STDPP__initial)
__STDPP__directive pragma pp:initial
#endif
#include <limits.h>
#if defined(__STDPP__directive) && defined(__STDPP__initial)
__STDPP__directive pragma pp:noinitial
#endif

#if defined(_std_stddef) || defined(__STDC__) || defined(__cplusplus)

#include <stddef.h>

#endif

#ifndef offsetof
#define offsetof(type,member) ((size_t)&(((type*)0)->member))
#endif

#if !defined(__cplusplus) && (defined(_std_stdlib) || defined(__STDC__))

#include <stdlib.h>

#else

#define EXIT_FAILURE	1
#define EXIT_SUCCESS	0
#define MB_CUR_MAX	1
#define RAND_MAX	32767

#endif

#ifdef	_SKIP_SFSTDIO_H
#undef	_SKIP_SFSTDIO_H
#else
#undef	_SFSTDIO_H
#undef	FILE
#if defined(__STDPP__directive) && defined(__STDPP__hide)
#if !_std_def_calloc
__STDPP__directive pragma pp:nohide calloc
#endif
#if !_std_def_free
__STDPP__directive pragma pp:nohide free
#endif
#if !_std_def_malloc
__STDPP__directive pragma pp:nohide malloc
#endif
#if !_std_def_realloc
__STDPP__directive pragma pp:nohide realloc
#endif
__STDPP__directive pragma pp:nohide bcopy bzero execl execle execlp execv
__STDPP__directive pragma pp:nohide execvp getcwd putenv setenv setpgrp sleep
__STDPP__directive pragma pp:nohide strdup spawnve spawnveg
__STDPP__directive pragma pp:nohide vfprintf vprintf vsprintf
#else
#if !_std_def_calloc
#undef	calloc	
#endif
#if !_std_def_free
#undef	free	
#endif
#if !_std_def_malloc
#undef	malloc	
#endif
#if !_std_def_realloc
#undef	realloc	
#endif
#undef	bcopy
#undef	bzero
#undef	execl
#undef	execle
#undef	execlp
#undef	execv
#undef	execvp
#undef	getcwd
#undef	putenv
#undef	setenv
#undef	setpgrp
#undef	sleep
#undef	spawnve
#undef	spawnveg
#undef	strdup
#undef	vfprintf
#undef	vprintf
#undef	vsprintf
#endif
#endif

#if defined(__STDPP__directive) && defined(__STDPP__note)
#if !noticed(dev_t)
typedef short dev_t;
#endif
#if !noticed(div_t)
typedef struct { int quot; int rem; } div_t;
#endif
#if !noticed(gid_t)
typedef unsigned short gid_t;
#endif
#if !noticed(ino_t)
typedef unsigned long ino_t;
#endif
#if !noticed(ldiv_t)
typedef struct { long quot; long rem; } ldiv_t;
#endif
#if !noticed(mode_t)
typedef unsigned short mode_t;
#endif
#if !noticed(nlink_t)
typedef short nlink_t;
#endif
#if !noticed(off_t)
typedef long off_t;
#endif
#if !noticed(pid_t)
typedef int pid_t;
#endif
#if !noticed(ptrdiff_t)
typedef long ptrdiff_t;
#endif
#if !noticed(size_t)
typedef unsigned int size_t;
#endif
#if !noticed(ssize_t)
typedef int ssize_t;
#endif
#if !noticed(uid_t)
typedef unsigned short uid_t;
#endif
#if !noticed(wchar_t)
typedef unsigned short wchar_t;
#endif
#else
#include <ast_types.h>
#endif

#if defined(__cplusplus) || !defined(_std_stdlib) && !defined(__STDC__)

/* <stdlib.h> */

extern __MANGLE__ double		atof __PROTO__((const char*));
extern __MANGLE__ int		atoi __PROTO__((const char*));
extern __MANGLE__ long		atol __PROTO__((const char*));
extern __MANGLE__ double		strtod __PROTO__((const char*, char**));
extern __MANGLE__ long		strtol __PROTO__((const char*, char**, int));
extern __MANGLE__ unsigned long	strtoul __PROTO__((const char*, char**, int));

extern __MANGLE__ int		rand __PROTO__((void));
extern __MANGLE__ void		srand __PROTO__((unsigned int));

extern __MANGLE__ void		abort __PROTO__((void));
extern __MANGLE__ int		atexit __PROTO__((void(*)(void)));
extern __MANGLE__ void		exit __PROTO__((int));
extern __MANGLE__ char*		getenv __PROTO__((const char*));
extern __MANGLE__ int		system __PROTO__((const char*));

extern __MANGLE__ __V_*		bsearch __PROTO__((const __V_*, const __V_*, size_t, size_t,
		 		int(*)(const __V_*, const __V_*)));
extern __MANGLE__ void		qsort __PROTO__((__V_*, size_t, size_t,
				int(*)(const __V_*, const __V_*)));

extern __MANGLE__ int		abs __PROTO__((int));
extern __MANGLE__ div_t		div __PROTO__((int, int));
extern __MANGLE__ long		labs __PROTO__((long));
extern __MANGLE__ ldiv_t		ldiv __PROTO__((long, long));

extern __MANGLE__ int		mblen __PROTO__((const char*, size_t));
extern __MANGLE__ int		mbtowc __PROTO__((wchar_t*, const char*, size_t));
extern __MANGLE__ int		wctomb __PROTO__((char*, wchar_t));
extern __MANGLE__ size_t		mbstowcs __PROTO__((wchar_t*, const char*, size_t));
extern __MANGLE__ size_t		wcstombs __PROTO__((char*, const wchar_t*, size_t));

#endif

#if !_std_def_calloc
extern __MANGLE__ __V_*		calloc __PROTO__((size_t, size_t));
#endif
#if !_std_def_free
extern __MANGLE__ void		free __PROTO__((__V_*));
#endif
#if !_std_def_malloc
extern __MANGLE__ __V_*		malloc __PROTO__((size_t));
#endif
#if !_std_def_realloc
extern __MANGLE__ __V_*		realloc __PROTO__((__V_*, size_t));
#endif

/* <string.h> */

extern __MANGLE__ __V_*		memchr __PROTO__((const __V_*, int, size_t));
extern __MANGLE__ int		memcmp __PROTO__((const __V_*, const __V_*, size_t));
extern __MANGLE__ __V_*		memcpy __PROTO__((__V_*, const __V_*, size_t));
extern __MANGLE__ __V_*		memmove __PROTO__((__V_*, const __V_*, size_t));
extern __MANGLE__ __V_*		memset __PROTO__((__V_*, int, size_t));
extern __MANGLE__ char*		strcat __PROTO__((char*, const char*));
extern __MANGLE__ char*		strchr __PROTO__((const char*, int));
extern __MANGLE__ int		strcmp __PROTO__((const char*, const char*));
extern __MANGLE__ int		strcoll __PROTO__((const char*, const char*));
extern __MANGLE__ char*		strcpy __PROTO__((char*, const char*));
extern __MANGLE__ size_t		strcspn __PROTO__((const char*, const char*));
extern __MANGLE__ size_t		strlen __PROTO__((const char*));
extern __MANGLE__ char*		strncat __PROTO__((char*, const char*, size_t));
extern __MANGLE__ int		strncmp __PROTO__((const char*, const char*, size_t));
extern __MANGLE__ char*		strncpy __PROTO__((char*, const char*, size_t));
extern __MANGLE__ char*		strpbrk __PROTO__((const char*, const char*));
extern __MANGLE__ char*		strrchr __PROTO__((const char*, int));
extern __MANGLE__ size_t		strspn __PROTO__((const char*, const char*));
extern __MANGLE__ char*		strstr __PROTO__((const char*, const char*));
extern __MANGLE__ char*		strtok __PROTO__((char*, const char*));
extern __MANGLE__ size_t		strxfrm __PROTO__((char*, const char*, size_t));

#if defined(__STDPP__directive) && defined(__STDPP__ignore)

__STDPP__directive pragma pp:ignore "libc.h"
__STDPP__directive pragma pp:ignore "malloc.h"
__STDPP__directive pragma pp:ignore "memory.h"
__STDPP__directive pragma pp:ignore "stdlib.h"
__STDPP__directive pragma pp:ignore "string.h"

#else

#ifndef _libc_h
#define _libc_h
#endif
#ifndef _libc_h_
#define _libc_h_
#endif
#ifndef __libc_h
#define __libc_h
#endif
#ifndef __libc_h__
#define __libc_h__
#endif
#ifndef _LIBC_H
#define _LIBC_H
#endif
#ifndef _LIBC_H_
#define _LIBC_H_
#endif
#ifndef __LIBC_H
#define __LIBC_H
#endif
#ifndef __LIBC_H__
#define __LIBC_H__
#endif
#ifndef _LIBC_INCLUDED
#define _LIBC_INCLUDED
#endif
#ifndef __LIBC_INCLUDED
#define __LIBC_INCLUDED
#endif
#ifndef _H_LIBC
#define _H_LIBC
#endif
#ifndef __H_LIBC
#define __H_LIBC
#endif

#ifndef _malloc_h
#define _malloc_h
#endif
#ifndef _malloc_h_
#define _malloc_h_
#endif
#ifndef __malloc_h
#define __malloc_h
#endif
#ifndef __malloc_h__
#define __malloc_h__
#endif
#ifndef _MALLOC_H
#define _MALLOC_H
#endif
#ifndef _MALLOC_H_
#define _MALLOC_H_
#endif
#ifndef __MALLOC_H
#define __MALLOC_H
#endif
#ifndef __MALLOC_H__
#define __MALLOC_H__
#endif
#ifndef _MALLOC_INCLUDED
#define _MALLOC_INCLUDED
#endif
#ifndef __MALLOC_INCLUDED
#define __MALLOC_INCLUDED
#endif
#ifndef _H_MALLOC
#define _H_MALLOC
#endif
#ifndef __H_MALLOC
#define __H_MALLOC
#endif

#ifndef _memory_h
#define _memory_h
#endif
#ifndef _memory_h_
#define _memory_h_
#endif
#ifndef __memory_h
#define __memory_h
#endif
#ifndef __memory_h__
#define __memory_h__
#endif
#ifndef _MEMORY_H
#define _MEMORY_H
#endif
#ifndef _MEMORY_H_
#define _MEMORY_H_
#endif
#ifndef __MEMORY_H
#define __MEMORY_H
#endif
#ifndef __MEMORY_H__
#define __MEMORY_H__
#endif
#ifndef _MEMORY_INCLUDED
#define _MEMORY_INCLUDED
#endif
#ifndef __MEMORY_INCLUDED
#define __MEMORY_INCLUDED
#endif
#ifndef _H_MEMORY
#define _H_MEMORY
#endif
#ifndef __H_MEMORY
#define __H_MEMORY
#endif

#ifndef _stdlib_h
#define _stdlib_h
#endif
#ifndef _stdlib_h_
#define _stdlib_h_
#endif
#ifndef __stdlib_h
#define __stdlib_h
#endif
#ifndef __stdlib_h__
#define __stdlib_h__
#endif
#ifndef _STDLIB_H
#define _STDLIB_H
#endif
#ifndef _STDLIB_H_
#define _STDLIB_H_
#endif
#ifndef __STDLIB_H
#define __STDLIB_H
#endif
#ifndef __STDLIB_H__
#define __STDLIB_H__
#endif
#ifndef _STDLIB_INCLUDED
#define _STDLIB_INCLUDED
#endif
#ifndef __STDLIB_INCLUDED
#define __STDLIB_INCLUDED
#endif
#ifndef _H_STDLIB
#define _H_STDLIB
#endif
#ifndef __H_STDLIB
#define __H_STDLIB
#endif

#ifndef _string_h
#define _string_h
#endif
#ifndef _string_h_
#define _string_h_
#endif
#ifndef __string_h
#define __string_h
#endif
#ifndef __string_h__
#define __string_h__
#endif
#ifndef _STRING_H
#define _STRING_H
#endif
#ifndef _STRING_H_
#define _STRING_H_
#endif
#ifndef __STRING_H
#define __STRING_H
#endif
#ifndef __STRING_H__
#define __STRING_H__
#endif
#ifndef _STRING_INCLUDED
#define _STRING_INCLUDED
#endif
#ifndef __STRING_INCLUDED
#define __STRING_INCLUDED
#endif
#ifndef _H_STRING
#define _H_STRING
#endif
#ifndef __H_STRING
#define __H_STRING
#endif

#endif

#include <ast_fcntl.h>

/* <unistd.h> */

#ifdef _WIN32
#include <unistd.h>
#else
#include <ast_unistd.h>
#endif
#include <ast_botch.h>

#ifndef STDIN_FILENO
#define	STDIN_FILENO	0
#define	STDOUT_FILENO	1
#define	STDERR_FILENO	2
#endif

#ifndef NULL
#define	NULL		0
#endif

#ifndef SEEK_SET
#define	SEEK_SET	0
#define	SEEK_CUR	1
#define	SEEK_END	2
#endif

#ifndef	F_OK
#define	F_OK		0
#define	X_OK		1
#define	W_OK		2
#define	R_OK		4
#endif

extern __MANGLE__ void		_exit __PROTO__((int));
extern __MANGLE__ int		access __PROTO__((const char*, int));
extern __MANGLE__ unsigned		alarm __PROTO__((unsigned));
extern __MANGLE__ int		chdir __PROTO__((const char*));
extern __MANGLE__ int		chown __PROTO__((const char*, uid_t, gid_t));
extern __MANGLE__ int		close __PROTO__((int));
extern __MANGLE__ size_t		confstr __PROTO__((int, char*, size_t));
extern __MANGLE__ int		dup __PROTO__((int));
extern __MANGLE__ int		dup2 __PROTO__((int, int));
extern __MANGLE__ int		execl __PROTO__((const char*, const char*, ...));
extern __MANGLE__ int		execle __PROTO__((const char*, const char*, ...));
extern __MANGLE__ int		execlp __PROTO__((const char*, const char*, ...));
extern __MANGLE__ int		execv __PROTO__((const char*, char* const[]));
extern __MANGLE__ int		execve __PROTO__((const char*, char* const[], char* const[]));
extern __MANGLE__ int		execvp __PROTO__((const char*, char* const[]));
extern __MANGLE__ pid_t		fork __PROTO__((void));
extern __MANGLE__ long		fpathconf __PROTO__((int, int));
extern __MANGLE__ char*		getcwd __PROTO__((char*, size_t));
extern __MANGLE__ gid_t		getegid __PROTO__((void));
extern __MANGLE__ uid_t		geteuid __PROTO__((void));
extern __MANGLE__ gid_t		getgid __PROTO__((void));
extern __MANGLE__ int		getgroups __PROTO__((int, gid_t[]));
extern __MANGLE__ char*		getlogin __PROTO__((void));
extern __MANGLE__ pid_t		getpgrp __PROTO__((void));
extern __MANGLE__ pid_t		getpid __PROTO__((void));
extern __MANGLE__ pid_t		getppid __PROTO__((void));
extern __MANGLE__ uid_t		getuid __PROTO__((void));
extern __MANGLE__ int		isatty __PROTO__((int));
extern __MANGLE__ int		link __PROTO__((const char*, const char*));
extern __MANGLE__ off_t		lseek __PROTO__((int, off_t, int));
extern __MANGLE__ long		pathconf __PROTO__((const char*, int));
extern __MANGLE__ int		pause __PROTO__((void));
extern __MANGLE__ int		pipe __PROTO__((int[]));
extern __MANGLE__ ssize_t		read __PROTO__((int, __V_*, size_t));
extern __MANGLE__ int		rmdir __PROTO__((const char*));
extern __MANGLE__ int		setgid __PROTO__((gid_t));
extern __MANGLE__ int		setpgid __PROTO__((pid_t, pid_t));
extern __MANGLE__ pid_t		setsid __PROTO__((void));
extern __MANGLE__ int		setuid __PROTO__((uid_t));
extern __MANGLE__ unsigned		sleep __PROTO__((unsigned int));
extern __MANGLE__ pid_t		spawnve __PROTO__((const char*, char* const[], char* const[]));
extern __MANGLE__ pid_t		spawnveg __PROTO__((const char*, char* const[], char* const[], pid_t));
extern __MANGLE__ long		sysconf __PROTO__((int));
extern __MANGLE__ pid_t		tcgetpgrp __PROTO__((int));
extern __MANGLE__ int		tcsetpgrp __PROTO__((int, pid_t));
extern __MANGLE__ char*		ttyname __PROTO__((int));
extern __MANGLE__ int		unlink __PROTO__((const char*));
extern __MANGLE__ ssize_t		write __PROTO__((int, const __V_*, size_t));

#ifndef _WIN32

/*
 * yes, we don't trust anyone's interpretation but our own
 */

#undef	confstr
#define confstr		_ast_confstr
#undef	fpathconf
#define fpathconf	_ast_fpathconf
#undef	pathconf
#define pathconf	_ast_pathconf
#undef	sysconf
#define sysconf		_ast_sysconf

extern __MANGLE__ size_t		confstr __PROTO__((int, char*, size_t));
extern __MANGLE__ long		fpathconf __PROTO__((int, int));
extern __MANGLE__ long		pathconf __PROTO__((const char*, int));
extern __MANGLE__ long		sysconf __PROTO__((int));

#endif

#if defined(__STDPP__directive) && defined(__STDPP__ignore)

__STDPP__directive pragma pp:ignore "unistd.h"
__STDPP__directive pragma pp:ignore "sys/unistd.h"

#else

#ifndef _unistd_h
#define _unistd_h
#endif
#ifndef _unistd_h_
#define _unistd_h_
#endif
#ifndef __unistd_h
#define __unistd_h
#endif
#ifndef __unistd_h__
#define __unistd_h__
#endif
#ifndef _UNISTD_H
#define _UNISTD_H
#endif
#ifndef _UNISTD_H_
#define _UNISTD_H_
#endif
#ifndef __UNISTD_H
#define __UNISTD_H
#endif
#ifndef __UNISTD_H__
#define __UNISTD_H__
#endif
#ifndef _UNISTD_INCLUDED
#define _UNISTD_INCLUDED
#endif
#ifndef __UNISTD_INCLUDED
#define __UNISTD_INCLUDED
#endif
#ifndef _H_UNISTD
#define _H_UNISTD
#endif
#ifndef __H_UNISTD
#define __H_UNISTD
#endif
#ifndef _SYS_UNISTD_H
#define _SYS_UNISTD_H
#endif

#endif

#if defined(__cplusplus)

#if defined(__STDPP__directive) && defined(__STDPP__ignore)

__STDPP__directive pragma pp:ignore "sysent.h"

#else

#ifndef _sysent_h
#define _sysent_h
#endif
#ifndef _sysent_h_
#define _sysent_h_
#endif
#ifndef __sysent_h
#define __sysent_h
#endif
#ifndef __sysent_h__
#define __sysent_h__
#endif
#ifndef _SYSENT_H
#define _SYSENT_H
#endif
#ifndef _SYSENT_H_
#define _SYSENT_H_
#endif
#ifndef __SYSENT_H
#define __SYSENT_H
#endif
#ifndef __SYSENT_H__
#define __SYSENT_H__
#endif
#ifndef _SYSENT_INCLUDED
#define _SYSENT_INCLUDED
#endif
#ifndef __SYSENT_INCLUDED
#define __SYSENT_INCLUDED
#endif
#ifndef _H_SYSENT
#define _H_SYSENT
#endif
#ifndef __H_SYSENT
#define __H_SYSENT
#endif

#endif

#endif

#include <ast_lib.h>

/* locale stuff */

#if _hdr_locale

#include <locale.h>

#if _sys_localedef

#include <sys/localedef.h>

#endif

#endif

#undef	setlocale
extern __MANGLE__ char*		_ast_setlocale __PROTO__((int, const char*));
#ifdef LC_ALL
#define setlocale	_ast_setlocale
#else
#define setlocale(a,b)	_ast_setlocale(0,b)
#endif

#undef	strcoll
#if _std_strcoll
#define strcoll		_ast_info.collate
#else
#define strcoll		strcmp
#endif

#define LC_SET_COLLATE	(1<<0)
#define LC_SET_CTYPE	(1<<1)
#define LC_SET_MESSAGES	(1<<2)
#define LC_SET_MONETARY	(1<<3)
#define LC_SET_NUMERIC	(1<<4)
#define LC_SET_TIME	(1<<5)

typedef struct
{

	struct
	{
	unsigned int	serial;
	unsigned int	set;
	}		locale;

	long		tmp_long;
	size_t		tmp_size;
	int		tmp_int;
	short		tmp_short;
	char		tmp_char;
	wchar_t		tmp_wchar;

	int		(*collate) __PROTO__((const char*, const char*));

	__V_*		tmp_pointer;

} _Ast_info_t;

extern __MANGLE__ _Ast_info_t	_ast_info;

/* stuff from std headers not used by ast, e.g., <stdio.h> */

extern __MANGLE__ __V_*		memzero __PROTO__((__V_*, size_t));
extern __MANGLE__ int		remove __PROTO__((const char*));
extern __MANGLE__ int		rename __PROTO__((const char*, const char*));

/* direct macro access for bsd crossover */

#if !defined(memcpy) && !defined(_lib_memcpy) && defined(_lib_bcopy)
extern __MANGLE__ void		bcopy __PROTO__((__V_*, __V_*, size_t));
#define memcpy(t,f,n)	(bcopy(f,t,n),(t))
#endif

#if !defined(memzero)
#if defined(_lib_bzero)
extern __MANGLE__ void		bzero __PROTO__((__V_*, size_t));
#if defined(FD_ZERO)
#undef	FD_ZERO
#define FD_ZERO(p)	memzero(p,sizeof(*p))
#endif
#define memzero(b,n)	(bzero(b,n),(b))
#else
#define memzero(b,n)	memset(b,0,n)
#endif
#endif

#if !defined(remove) && !defined(_lib_remove)
extern __MANGLE__ int		unlink __PROTO__((const char*));
#define remove(p)	unlink(p)
#endif

#if !defined(strchr) && !defined(_lib_strchr) && defined(_lib_index)
extern __MANGLE__ char*		index __PROTO__((const char*, int));
#define strchr(s,c)	index(s,c)
#endif

#if !defined(strrchr) && !defined(_lib_strrchr) && defined(_lib_rindex)
extern __MANGLE__ char*		rindex __PROTO__((const char*, int));
#define strrchr(s,c)	rindex(s,c)
#endif

/* and now introducing prototypes botched by the standard(s) */

#undef	getpgrp
#define	getpgrp()	_ast_getpgrp()
extern __MANGLE__ int		_ast_getpgrp __PROTO__((void));

#endif
