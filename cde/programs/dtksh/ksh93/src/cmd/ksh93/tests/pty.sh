########################################################################
#                                                                      #
#               This software is part of the ast package               #
#          Copyright (c) 1982-2012 AT&T Intellectual Property          #
#                      and is licensed under the                       #
#                 Eclipse Public License, Version 1.0                  #
#                    by AT&T Intellectual Property                     #
#                                                                      #
#                A copy of the License is available at                 #
#          http://www.eclipse.org/org/documents/epl-v10.html           #
#         (with md5 checksum b35adb5213ca9657e911e9befb180842)         #
#                                                                      #
#              Information and Software Systems Research               #
#                            AT&T Research                             #
#                           Florham Park NJ                            #
#                                                                      #
#                  David Korn <dgk@research.att.com>                   #
#                                                                      #
########################################################################
: : generated by mkptytests from "posix-sh-*-c.pty" : :

# These are tests for the interactive shell, run in a pseudoterminal utility
# called 'pty', which allows for scripting interactive sessions and which is
# installed in arch/*/bin while building. To understand these tests, first
# read the pty manual by running: arch/*/bin/pty --man

# The # err_exit # comments are to enable shtests to count the tests.

# the trickiest part of the tests is avoiding typeahead
# in the pty dialogue

function err_exit
{
	print -u2 -n "\t"
	print -u2 -r ${Command}[$1]: "${@:2}"
	(( Errors++ ))
}

alias err_exit='err_exit $lineno'

Command=${0##*/}
integer Errors=0 lineno=1

[[ -d $tmp && -w $tmp && $tmp == "$PWD" ]] || { err\_exit "$LINENO" '$tmp not set; run this from shtests. Aborting.'; exit 1; }
whence -q pty || { err\_exit "$LINENO" "pty command not found -- tests skipped"; exit 0; }

# On FreeBSD, the stty command does not appear to work correctly on a pty pseudoterminal.
# To avoid a couple of false regressions, we have to set 'erase' and 'kill' on the real terminal.
stty_restore=$(stty -g) || { err\_exit "$LINENO" "could not save terminal state -- tests skipped"; exit 0; }
trap 'stty "$stty_restore"' EXIT  # note: on ksh, the EXIT trap is also triggered for termination due to a signal
stty erase ^H kill ^X

bintrue=$(whence -p true)

x=$( $SHELL <<- \EOF
		trap 'exit 0' EXIT
		bintrue=$(whence -p true)
		set -o monitor
		{
			eval $'set -o vi\npty $bintrue'
		} < /dev/null & pid=$!
		#sleep 1
		jobs
		kill $$
	EOF
)
[[ $x == *Stop* ]] && err_exit 'monitor mode enabled incorrectly causes job to stop'

if	[[ -o xtrace ]]
then	debug=--debug=1
else	debug=
fi

function tst
{
	integer lineno=$1 offset
	typeset text

	pty $debug --dialogue --messages='/dev/fd/1' $SHELL |
	while	read -r text
	do	if	[[ $text == *debug* ]]
		then	print -u2 -r -- "$text"
		else	offset=${text/*: line +([[:digit:]]):*/\1}
			err_exit "${text/: line $offset:/: line $(( lineno + offset)):}"
		fi
	done
}

export PS1=':test-!: ' PS2='> ' PS4=': ' ENV=/./dev/null EXINIT= HISTFILE= TERM=dumb VISUAL=vi LC_ALL=C

if	! pty $bintrue < /dev/null
then	err_exit pty command hangs on $bintrue -- tests skipped
	exit 0
fi

# err_exit #
tst $LINENO <<"!"
L POSIX sh 026(C)

# If the User Portability Utilities Option is supported:  When the
# POSIX locale is specified and a background job is suspended by a
# SIGTSTP signal then the <state> field in the output message is set to
# Stopped, Suspended, Stopped(SIGTSTP) or Suspended(SIGTSTP).

I ^\r?\n$
p :test-1:
w sleep 60 &
u [[:digit:]]\r?\n$
s 100
p :test-2:
w kill -TSTP $!
u (Stopped|Suspended)
p :test-3:
w kill -KILL $!
w wait
u (Killed|Done)
!

# err_exit #
tst $LINENO <<"!"
L POSIX sh 028(C)

# If the User Portability Utilities Option is supported:  When the
# POSIX locale is specified and a background job is suspended by a
# SIGTTIN signal then the <state> field in the output message is set to
# Stopped(SIGTTIN) or Suspended(SIGTTIN).

I ^\r?\n$
p :test-1:
w sleep 60 &
u [[:digit:]]\r?\n$
s 100
p :test-2:
w kill -TTIN $!
u (Stopped|Suspended) \(SIGTTIN\)
p :test-3:
w kill -KILL $!
w wait
u (Killed|Done)
!

# err_exit #
tst $LINENO <<"!"
L POSIX sh 029(C)

# If the User Portability Utilities Option is supported:  When the
# POSIX locale is specified and a background job is suspended by a
# SIGTTOU signal then the <state> field in the output message is set to
# Stopped(SIGTTOU) or Suspended(SIGTTOU).

I ^\r?\n$
p :test-1:
w sleep 60 &
u [[:digit:]]\r?\n$
s 100
p :test-2:
w kill -TTOU $!
u (Stopped|Suspended) \(SIGTTOU\)
p :test-3:
w kill -KILL $!
w wait
u (Killed|Done)
!

# err_exit #
tst $LINENO <<"!"
L POSIX sh 091(C)

# If the User Portability Utilities Option is supported and shell
# command line editing is supported:  When in insert mode an entered
# character other than <newline>, erase, interrupt, kill, control-V,
# control-W, backslash \ (followed by erase or kill), end-of-file and
# <ESC> is inserted in the current command line.

c echo h
c ell
w o
u ^hello\r?\n$
!

# err_exit #
tst $LINENO <<"!"
L POSIX sh 093(C)

# If the User Portability Utilities Option is supported and shell
# command line editing is supported:  After termination of a previous
# command, sh is entered in insert mode.

w echo hello
u ^hello\r?\n$
c echo goo
c dby
w e
u ^goodbye\r?\n$
!

# err_exit #
tst $LINENO <<"!"
L POSIX sh 094(C)

# If the User Portability Utilities Option is supported and shell
# command line editing is supported:  When in insert mode an <ESC>
# switches sh into command mode.

c echo he\E
s 400
w allo
u ^hello\r?\n$
!

if	[[ $(id -u) == 0 ]]
then	print -u2 -r "${Command}[$LINENO]: warning: running as root: skipping test POSIX sh 096(C)"
else
# err_exit #
tst $LINENO <<"!"
L POSIX sh 096(C)

# If the User Portability Utilities Option is supported and shell
# command line editing is supported:  When in command mode the
# interrupt character causes sh to terminate command line editing on
# the current command line, re-issue the prompt on the next line of the
# terminal and to reset the command history so that the command that
# was interrupted is not entered in the history.

I ^\r?\n$
p :test-1:
w echo first
p :test-2:
w stty intr ^C
p :test-3:
c echo bad\E
s 400
c \cC
w echo scrambled
p :test-4:
w history
u echo first
r stty intr \^C
r echo
r history
!
fi

# err_exit #
tst $LINENO <<"!"
L POSIX sh 097(C)

# If the User Portability Utilities Option is supported and shell
# command line editing is supported:  When in insert mode a <newline>
# causes the current command line to be executed.

c echo ok\n
u ^ok\r?\n$
!

if	[[ $(id -u) == 0 ]]
then	print -u2 -r "${Command}[$LINENO]: warning: running as root: skipping test POSIX sh 099(C)"
else
# err_exit #
tst $LINENO <<"!"
L POSIX sh 099(C)

# If the User Portability Utilities Option is supported and shell
# command line editing is supported:  When in insert mode the interrupt
# character causes sh to terminate command line editing on the current
# command line, re-issue the prompt on the next line of the terminal
# and to reset the command history so that the command that was
# interrupted is not entered in the history.

I ^\r?\n$
p :test-1:
w echo first
u ^first
p :test-2:
w stty intr ^C
r
p :test-3:
c echo bad\cC
w echo last
p :test-4:
w history
u echo first
r stty intr \^C
r echo last
r history
!
fi

# err_exit #
tst $LINENO <<"!"
L POSIX sh 100(C)

# If the User Portability Utilities Option is supported and shell
# command line editing is supported:  When in insert mode the kill
# character clears all the characters from the input line.

p :test-1:
w stty kill ^X
p :test-2:
c echo bad\cX
w echo ok
u ^ok\r?\n$
!

# err_exit #
tst $LINENO <<"!"
L POSIX sh 101(C)

# If the User Portability Utilities Option is supported and shell
# command line editing is supported:  When in insert mode a control-V
# causes the next character to be inserted even in the case that the
# character is a special insert mode character.
# Testing Requirements: The assertion must be tested with at least the
# following set of characters: <newline>, erase, interrupt, kill,
# control-V, control-W, end-of-file, backslash \ (followed by erase or
# kill) and <ESC>.

d 10
p :test-1:
w stty erase ^H intr ^C kill ^X
p :test-2:
w echo erase=:\cV\cH:
u ^erase=:\r?\n$
p :test-3:
w echo kill=:\cV\cX:
u ^kill=:\cX:\r?\n$
p :test-4:
w echo control-V=:\cV\cV:
u ^control-V=:\cV:\r?\n$
p :test-5:
w echo control-W:\cV\cW:
u ^control-W:\cW:\r?\n$
p :test-6:
w echo EOF=:\cV\cD:
u ^EOF=:\004:\r?\n$
p :test-7:
w echo backslash-erase=:\\\cH:
u ^backslash-erase=:\r?\n$
p :test-8:
w echo backslash-kill=:\\\cX:
u ^backslash-kill=:\cX:\r?\n$
p :test-9:
w echo ESC=:\cV\E:
u ^ESC=:\E:\r?\n$
p :test-10:
w echo interrupt=:\cV\cC:
u ^interrupt=:\cC:\r?\n$
!

# err_exit #
tst $LINENO <<"!"
L POSIX sh 104(C)

# If the User Portability Utilities Option is supported and shell
# command line editing is supported:  When in insert mode an
# end-of-file at the beginning of an input line is interpreted as the
# end of input.

p :test-1:
w trap 'echo done >&2' EXIT
p :test-2:
s 100
c \cD
u ^done\r?\n$
!

if	[[ $(id -u) == 0 ]]
then	print -u2 -r "${Command}[$LINENO]: warning: running as root: skipping test POSIX sh 111(C)"
else
# err_exit #
tst $LINENO <<"!"
L POSIX sh 111(C)

# If the User Portability Utilities Option is supported and shell
# command line editing is supported:  When in command mode, # inserts
# the character # at the beginning of the command line and causes the
# line to be treated as a comment and the line is entered in the
# command history.

p :test-1:
c echo save\E
s 400
c #
p :test-2:
w history
u #echo save
r history
!
fi

# Following test is disabled because it fails on too many systems, either intermittently
# or consistently, through no fault of ksh, because vi(1) somehow fails to write "/tmp/"
# as expected. Testing the POSIX compliance of whatever vi(1) the local system happens
# to have is outside the scope of these tests, which are supposed to be testing ksh.
# It is left here for re-enabling temporarily if related changes in ksh need testing.
: <<\end_disabled
# err_(don't count me)_exit #
TMPDIR=/tmp tst $LINENO <<"!"
L POSIX sh 137(C)

# If the User Portability Utilities Option is supported and shell
# command line editing is supported: When in command mode, then v
# invokes the vi editor to edit the current command line in a temporary
# file. When the editor exits, the commands in the temporary file are
# executed.

p :test-1:
c echo hello\E
s 400
c v
u /tmp/
c A world\E
s 400
w :wq
u ^hello world\r?\n$
!
end_disabled

if	[[ $(id -u) == 0 ]]
then	print -u2 -r "${Command}[$LINENO]: warning: running as root: skipping test POSIX sh 251(C)"
else
# err_exit #
tst $LINENO <<"!"
L POSIX sh 251(C)

# If the User Portability Utilities Option is supported and shell
# command line editing is supported:  When in command mode, then the
# command N repeats the most recent / or ? command, reversing the
# direction of the search.

p :test-1:
w echo repeat-1
u ^repeat-1\r?\n$
p :test-2:
w echo repeat-2
u ^repeat-2\r?\n$
p :test-3:
s 100
c \E
s 400
w /rep
u echo repeat-2
c n
r echo repeat-1
c N
r echo repeat-2
w dd
p :test-3:
w echo repeat-3
u ^repeat-3\r?\n$
p :test-4:
s 100
c \E
s 400
w ?rep
r echo repeat-2
c N
r echo repeat-1
c n
r echo repeat-2
c n
r echo repeat-3
!
fi

# This test freezes the 'less' pager on OpenBSD, which is not a ksh bug.
: <<\disabled
whence -q less &&
TERM=vt100 tst $LINENO <<"!"
L process/terminal group exercise

w m=yes; while true; do echo $m-$m; done | less
u :$|:\E|lines
c \cZ
r Stopped
w fg
u yes-yes
!
disabled

# err_exit #
# Test file name completion in vi mode
mkdir "/tmp/fakehome_$$" && tst $LINENO <<!
L vi mode file name completion

# Completing a file name in vi mode that contains '~' and has a
# base name the same length as the home directory's parent directory
# shouldn't fail.

w set -o vi; HOME=/tmp/fakehome_$$; touch ~/testfile_$$
w echo ~/tes\t
u ^/tmp/fakehome_$$/testfile_$$\r?\n$
!
rm -r "/tmp/fakehome_$$"

# err_exit #
LC_ALL=C tst $LINENO <<"!"
L raw Bourne mode literal tab characters with wide characters disabled

# This gets handled by ed_read() in edit.c; it does not expand tab
# characters on the command line.

d 20
p :test-1:
w set +o vi +o emacs
p :test-2:
w true /de\tv/nu\tl\tl
r ^:test-2: true (/de\tv/nu\tl\tl|/de       v/nu    l       l)\r\n$
p :test-3:
!

# err_exit #
LC_ALL=C.UTF-8 tst $LINENO <<"!"
L raw Bourne mode literal tab characters with wide characters enabled

# This gets handled by ed_viread() in vi.c (even though vi mode is off);
# it expands tab characters to spaces on the command line.

d 20
p :test-1:
w set +o vi +o emacs
p :test-2:
w true /de\tv/nu\tl\tl
r ^:test-2: true /de       v/nu    l       l\r\n$
p :test-3:
!

# err_exit #
LC_ALL=C.UTF-8 tst $LINENO <<"!"
L raw Bourne mode backslash handling

# The escaping backslash feature should be disabled in the raw Bourne mode.
# This is tested with both erase and kill characters.

d 20
p :test-1:
w set +o vi +o emacs; stty erase ^H kill ^X
p :test-2:
w true string\\\\\cH\cH
r ^:test-2: true string\r\n$
p :test-3:
w true incorrect\\\cXtrue correct
r ^:test-3: true correct\r\n$
!

# err_exit #
# err_exit #
for mode in emacs vi; do
tst $LINENO << !
L escaping backslashes in $mode mode

# Backslashes should only be escaped if the previous input was a backslash.
# Other backslashes stored in the input buffer should be erased normally.

d 20
p :test-1:
w set -o $mode; stty erase ^H
p :test-2:
w true string\\\\\\\\\\cH\\cH\\cH
r ^:test-2: true string\\r\\n$
!
done

# err_exit #
tst $LINENO <<"!"
L notify job state changes

# 'set -b' should immediately notify the user about job state changes.

p :test-1:
w set -b; sleep .01 &
u Done
!

# ======
exit $((Errors<125?Errors:125))