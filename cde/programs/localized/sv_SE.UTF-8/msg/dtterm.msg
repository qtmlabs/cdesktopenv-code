$ $XConsortium: dtterm.msg /main/3 1995/11/08 13:36:18 rswiston $
$ *************************************<+>*************************************
$ *****************************************************************************
$ **
$ **  File:        dtterm.msg
$ **
$ **  Project:     Common Desktop Environment dtterm
$ **
$ **  Description:
$ **  -----------
$ **  This file is the source for the message catalog for dtterm
$ **  Any additional messages are to be added to this file by hand,
$ **  and the associated index number placed in the code.
$ **
$ *****************************************************************************
$ **
$ **     (c) Copyright 1993, 1994 Hewlett-Packard Company
$ **     All Rights reserved
$ **
$ **
$ *****************************************************************************
$ *************************************<+>*************************************

$ *************************************<L>*************************************
$ **  -----------------GENERAL LOCALIZATION NOTES SECTION---------------------
$ * Comment lines begin with a $ except $set which indicates the start of a
$ * new set.
$ *
$ * Do not delete any comments; you may add comments for your use.
$ *
$ **  ----------------GENERAL LOCALIZATION NOTES SECTION END------------------
$ *************************************<L>*************************************

$ *****************************************************************************
$ 
$ ***** NOTE FOR MESSAGE CATALOG TRANSLATORS *****
$ 
$ There may be three types of messages in this file:
$ 
$ 1. Messages that appear in dialogs or are displayed to the user.
$ 
$     These messages are the default and they should ALL BE LOCALIZED.
$     Note that these messages do NOT have any identification (see the
$     comments for type 2 and 3 below).
$ 
$ 2. Messages that only appear in the DT error log file ($HOME?.dt/errorlog).
$ 
$     The localization of these messages is OPTIONAL.  These messages are
$     identified by the following:
$ 
$     MESSAGES xx-yy WILL ONLY APPEAR IN THE DT ERRORLOG FILE
$ 
$ 3. Messages that should not be localized.
$ 
$     These messages are identified by the following:
$ 
$     DO NOT TRANSLATE or CHANGE or LOCALIZE MESSAGES xx-yy
$ 
$ ***** END (NOTE FOR MESSAGE CATALOG TRANSLATORS) *****
$ 
$ ********** PROLOGUE ****************
$  Date    Name               Note
$ ======== =================  ===============================================
$ 03/15/94 B. May             Initial rev
$ 
$ *****************************************************************************

$set 1
$ ****** Module: DtTermMain.c 
$ Message 1 is the window menu addition - do not translate f.separator or
$ f.send_msg.  It will be used as the format string for a sprintf() command,
$ so it is necessary to double up on any percent signs ('%') that you
$ want to keep in the string.
$ Message 2 is an error message

1 \
	Avs             f.separator\n\
	Visa/d??lj\\ meny\\ rad   f.send_msg %d\
	
2 %s: Till??gget -S kan inte anv??ndas tillsammans med till??ggen -server och -serverid\n

$set 2
$ ****** Module: DtTermSyntax.c 
$ These are the usage messages. 
$ DO NOT TRANSLATE Messages 37 or 41 ("End-of-list")

1 -/+132			aktivera/avaktivera Esc-sekvens f??r v??xling mellan 80<->132 kolumner
2 -/+aw				aktivera/avaktivera automatiskt radbyte
3 -bg f??rg			bakgrundsf??rg
4 -/+bs				aktivera/avaktivera terminalbakgrunden som markerad f??rg
5 -display visningsenhet		X-hanterare som ska kontaktas
6 -e kommandoargument		kommando som ska exekveras
7 -fb teckenupps??ttning			fetstilt font
8 -fg f??rg			f??rgrundsf??rg
9 -fn fontupps??ttning			normal font
10 -geometry geom			f??nstrets storlek (antal tecken) och position
11 -help				skriv ut detta meddelande
12 -/+iconic			starta/starta inte ikons??kv??g
13 -/+j				aktivera/avaktivera flerradsbl??ddring
14 -/+kshMode			aktivera/avaktivera ksh-l??ge
15 -/+l				aktivera/avaktivera loggning
16 -lf filnamn			logga filnamn
17 -/+ls				aktivera/avaktivera inloggningsskal
18 -/+map				aktivera/avaktivera mappningsf??nster f??r  pty-utdata
19 -/+mb				aktivera/avaktivera signal vid marginal
20 -ms f??rg			pekarf??rg
21 -n str??ng			ange ikonnamn
22 -name str??ng			str??ngar f??r klientrepresentation, ikon och titel
23 -nb avst??nd			ange avst??nd f??r signal vid h??germarginal
24 -/+rw				aktivera/avaktivera upph??vt radbyte
25 -/+sb				aktivera/avaktivera bl??ddringslist
26 -/+sf				aktivera/avaktivera SUN-funktionstangenter
27 -sl tal[s]			antal bl??ddrade rader [sk??rmar] som ska sparas
28 -ti namn			identifikationsstr??ng i programmet
29 -title str??ng			titelstr??ng f??r f??nster
30 -tm str??ng			nyckelord och tecken i terminall??ge
31 -tn namn			variabelnamn f??r TERM-milj??
32 -/+vb				aktivera/avaktivera synlig signal 
33 -xrm resursstr??ng		extra resursspecifikationer
34 -C				console-l??ge
35 -Sxxd				slavl??ge p?? "ttyxx"-filbeskrivning "d"
36 -Sxxx.d			slavl??ge p?? "ttyxxx"-filbeskrivning "d"
37 End-Of-List
38 Om till??gget -e anv??nds m??ste det placeras i slutet av kommandoraden.
39 I annat fall startas anv??ndarens standardskal. Till??gg som inleds 
40 med ett plustecken (+) ??terst??ller standardvalet.
41 End-Of-List
47 %s:  felaktigt till??gg p?? kommandoraden "%s"\r\n\n
48 syntax:  %s
49 \r\n   
50  [%s]
51 \r\n\nSkriv "%s -help" f??r att f?? en fullst??ndig beskrivning.\r\n\n
52 syntax:\n
53 \t%s [-options ...] [-e kommandoargument]\n\n
54 d??r alternativen omfattar:\n

$set 3
$ ****** Module: TermFunction.c
$ This is a warning message dialog box
1 MINNET ??R FULLT\nTryck p?? OK f??r att ta bort

$set 4
$ ****** Module: TermPrim.c
$ This is the title of a dialog box
1 Terminal - Varning

$set 5
$ ****** Module: TermFunction.c
$ This is a warning message dialog box
1 MINNET ??R FULLT\nTryck p?? OK f??r att ta bort

$set 6
$ ****** Module: TermView.c
$ DO NOT TRANSLATE Message 1
$ Messages 2 and 3 are titles for dialog boxes.
1 80x24 132x24
2 Terminal - Kommandobeskrivning
3 Terminal - Hj??lp

$set 7
$ ****** Module: TermViewGlobalDialog.c
$ These are the user-visible labels in the Global Options dialog box.
$ #1 is the title. 
$ The rest are resource types and values - look at the dialog box and 
$ documentation for full specs. 
$ 
$ DO NOT TRANSLATE MESSAGE 15
$ 
1 Terminal - Globala alternativ
2 OK
3 Avbryt
4 Hj??lp
5 global
6 Mark??rinst??llning
7 Ruta
8 Understrykning
9 Mark??rtyp
10 Aktiverad
11 Avaktiverad
12 Blinkande mark??r
13 Blinkningshastighet (millisekunder)
14 Osynlig
15 blinkRate
16 F??rg
17 Inverterad
18 Normal
19 F??nsterbakgrund
20 Bl??ddringsmetod
21 Avaktiverad
22 Aktiverad
23 Stegl??s bl??ddring
24 Signalinst??llning
25 H??rbar
26 Synlig
27 Signaltyp 
28 Aktiverad
29 Avaktiverad
30 Marginalvarning
31 Marginalavst??nd 
32 Till??mpa
33 ??terst??ll
$set 8
$ ****** Module: TermViewMenu.c
$ These are the menu bar entries and menu pane choices.
$ NOTE TO TRANSLATORS: The Single letter entries are the menu mnemonic
$ for the entry above them (i.e. message 11 "F" is the mnemonic for
$ message 10 "Font Size"). 
$ The items with a "+" in them are the accellerators for an item.
$ The single-character items are the mnemonics for a menu item, where the
$ text of the menu item is specified in the previous message
$ Do not translate messages 24 and 28.
1 Standard
2 F??nsterstorlek
3 ??
4 -iso8859-1
5 %d punkter
6 %.1f punkter
7 %.1f punkter
8 %.2f punkter
9 Standard
10 Fontstorlek
11 F

$   Window Menu
12 Nytt
13 N
14 Skriv ut
15 u
16 Skriv ut...
17 r
18 St??ng
19 S 
20 F??nster
21 ??

$   Edit Menu
22 Kopiera
23 K
24 Ctrl osfInsert
25 Ctrl+Insert
26 Klistra in
27 i
28 Skift osfInsert
29 Skift+Insert
30 Redigera
31 R

$  Option menu

32 Menyrad
33 M
34 Bl??ddringslist
35 l
36 Globalt...
37 G
38 Terminal...
39 T
40 Mjuk ??terst??llning
41 k
42 H??rd ??terst??llning
43 d
44 ??terst??ll
45 l
46 Alternativ
47 v

$ Old Help menu (no longer used for CDE)

48 ??versikt
49 v
50 Steg-f??r-steg-anvisningar
51 t
52 Referens
53 R
54 Objekthj??lp
55 O
56 Anv??nda Hj??lp
57 n
58 Om Terminal
59 m
60 Hj??lp
61 H
62 Alt+F4
63 Terminal

$ Current CDE Help menu

64 ??versikt
65 v
66 Index
67 I
68 Inneh??llsf??rteckning
69 h
70 Steg-f??r-steg-anvisningar
71 t
72 Referens
73 R
74 Tangentbord
75 T
76 Om hj??lpfunktionen
77 h
78 Om Terminal
79 d
80 Hj??lp
81 H

$set 9
$ ****** Module: TermTerminalDialog.c
$ These are the messages for the terminal options dialog
1 Terminal - Alternativ
2 OK
3 Avbryt
4 Hj??lp
5 Tangentbordsinst??llning
6 Normal
7 Program
8 Mark??rtangentl??ge
9 Numeriskt
10 Program
11 L??ge f??r numeriskt tangentbord
12 Endast vagnretur
13 Vagnretur och radmatning
14 Radmatningssekvens
15 L??st
16 Ol??st
17 Anv??ndardefinierade funktionstangenter
18 Sk??rminst??llning
19 Aktiverad
20 Avaktiverad
21 132 kolumner
22 Radbyte
23 Upph??v radbyte
24 Till??mpa
25 ??terst??ll
