$ $TOG: dtterm.msg /main/6 1999/09/17 13:28:36 mgreess $
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
$quote "

$set 1
$ ****** Module: DtTermMain.c
$ Message 1 is the window menu addition - do not translate f.separator or
$ f.send_msg.  It will be used as the format string for a sprintf() command,
$ so it is necessary to double up on any percent signs ('%') that you
$ want to keep in the string.
$ Message 2 is an error message

1 "Sep             f.separator\n\
\tBascule\\ barre\\ de\\ menus f.send_msg %d\t"

2 "%s: L'option -S ne peut pas ??tre utilis??e avec les options -server ou -serverid\n"

3 "Terminal"

$set 2        Redefine set#

$ ****** Module: DtTermSyntax.c
$ These are the usage messages.
$ DO NOT TRANSLATE Messages 37 or 41 ("End-of-list")

1 "-/+132\t\t\t\tactiver/d??sactiver 80<->132 s??q ??chap colonne"

2 "-/+aw\t\t\t\tactiver/d??sactiver boucle auto"

3 "-bg couleur\t\t\tcouleur arri??re-plan"

4 "-/+bs\t\t\t\tarri??re-plan Term pour couleur s??lect??e EF/HF."

5 "-display nom_??cran\t\tServeur X auquel acc??der"

6 "-e args commande\t\tcommande ?? ex??cuter"

7 "-fb police\t\t\tpolice texte gras"

8 "-fg couleur\t\t\tcouleur premier plan"

9 "-fn police\t\t\tpolice texte normal"

10 "-geometry g??om\t\t\ttaille (en caract??res) et position de la fen??tre"

11 "-help\t\t\t\timpression du message"

12 "-/+iconic\t\t\td??marrer/ne pas d??marrer iconic"

13 "-/+j\t\t\t\tactiver/d??sactiver d??filement par saut"

14 "-/+kshMode\t\t\tactiver/d??sactiver mode ksh"

15 "-/+l\t\t\t\tactiver/d??sactiver consignation"

16 "-lf nom_fichier\t\t\tconsignation nom_fichier"

17 "-/+ls\t\t\t\tactiver/d??sactiver shell connexion"

18 "-/+map\t\t\t\tactiver/d??sactiver fen??tre mappe sur sortie pty"

19 "-/+mb\t\t\t\tactiver/d??sactiver signal margin bell"

20 "-ms couleur\t\t\tcouleur pointeur"

21 "-n cha??ne\t\t\tindique nom ic??ne"

22 "-name cha??ne\t\t\tinstance client, ic??ne et cha??nes de titre"

23 "-nb distance\t\t\tindique distance pour signal margin bell droit"

24 "-/+rw\t\t\t\tactiver/d??sactiver boucle inverse"

25 "-/+sb\t\t\t\tactiver/d??sactiver barre d??filement"

26 "-/+sf\t\t\t\tactiver/d??sactiver touches de fonction SUN"

27 "-sl nombre[s]\t\t\tnombre de lignes de d??filement [??crans] ?? sauvegarder"

28 "-ti nom\t\t\tcha??ne utilis??e pour l'identification programme"

29 "-title cha??ne\t\t\tcha??ne de titre pour fen??tre"

30 "-tm cha??ne\t\t\tmots cl??s et caract??res de mode terminal"

31 "-tn nom\t\t\tnom de variable d'environnement TERM"

32 "-/+vb\t\t\t\tactiver/d??sactiver signal visual bell"

33 "-xrm cha??ne_ressource\t\tsp??cifications ressource suppl??mentaire"

34 "-C\t\t\t\tmode console"

35 "-Sxxd\t\t\t\tmode esclave sur descripteur de fichier \"ttyxx\" \"d\""

36 "-Sxxx.d\t\t\tmode esclave sur descripteur de fichier \"ttyxxx\" \"d\""

37 "End-Of-List"

38 "L'option -e doit appara??tre ?? la fin de la ligne de commande,"

39 "autrement, le shell utilisateur par d??faut est lanc??. Les options de lancement"

40 "comportant un signe plus (+) restaurent les valeurs par d??faut."

41 "End-Of-List"

47 "%s:  Option de ligne de commande incorrecte \"%s\"\r\n\n"

48 "Syntaxe:  %s"

49 "\r\n\
   "

50 "[%s]"

51 "\r\n\n\
Entrez \"%s -help\" pour une description d??taill??e.\r\n\n"

52 "Syntaxe:\n"

53 "\t%s [-options ...] [-e arguments de commande]\n\n"

54 "Les options comprennent:\n"

$set 3        Redefine set#

$ ****** Module: TermFunction.c
$ This is a warning message dialog box

1 "MEMOIRE SATUREE\n\
Appuyez sur OK pour effacer le message"

$set 4        Redefine set#

$ ****** Module: TermPrim.c
$ This is the title of a dialog box

$ 1 OBS- "Dtterm - Avertissement"

$ This is the title of a dialog box
2 "Terminal - Avertissement"

$set 5        Redefine set#

$ ****** Module: TermFunction.c
$ This is a warning message dialog box

1 "MEMOIRE SATUREE\n\
Appuyez sur OK pour effacer le message"

$set 6        Redefine set#

$ ****** Module: TermView.c
$ DO NOT TRANSLATE Message 1
$ Messages 2 and 3 are titles for dialog boxes.

1 "80x24 132x24"

$ 2 OBS- "Dtterm - Page Man"

$ 3 OBS- "Dtterm - Aide"

$ Messages 4 and 5 are titles for dialog boxes.
4 "Terminal - page de manuel"

5 "Terminal - Aide"

$set 7        Redefine set#

$ ****** Module: TermViewGlobalDialog.c
$ These are the user-visible labels in the Global Options dialog box.
$ #1 is the title.
$ The rest are resource types and values - look at the dialog box and
$ documentation for full specs.
$ 
$ DO NOT TRANSLATE MESSAGE 15
$ 

1 "dtterm - Options g??n??rales"

2 "OK"

3 "Annuler"

4 "Aide"

5 "g??n??rale"

6 "Caract??ristiques du curseur"

7 "Bo??te"

8 "Soulignement"

9 "Style curseur"

10 "Activ??"

11 "D??sactiv??"

12 "Curseur clignotant"

13 "Vitesse clignotement (ms)"

14 "Invisible"

15 "Vitesse_clignt"

16 "Couleurs"

17 "Inverse"

18 "Normal"

19 "Arri??re-plan fen??tre"

20 "Mode de d??filement"

21 "D??sactiv??"

22 "Activ??"

23 "D??filement continu"

24 "Param??tres du signal"

25 "Audible"

26 "Visible"

27 "Type signal"

28 "Activ??"

29 "D??sactiv??"

30 "Avertissement marge"

31 "Distance marge"

32 "Appliquer"

33 "Restaurer"

34 "Terminal - Options globales"

$set 8        Redefine set#

$ ****** Module: TermViewMenu.c
$ These are the menu bar entries and menu pane choices.
$ NOTE TO TRANSLATORS: The Single letter entries are the menu mnemonic
$ for the entry above them (i.e. message 11 "F" is the mnemonic for
$ message 10 "Font Size").
$ The items with a "+" in them are the accellerators for an item.
$ The single-character items are the mnemonics for a menu item, where the
$ text of the menu item is specified in the previous message
$ Do not translate messages 24 and 28.

1 "Valeurs par d??faut"

2 "Taille fen??tre"

3 "a"

4 "-iso8859-1"

5 "%d points"

6 "%.1f points"

7 "%.1f points"

8 "%.2f points"

9 "D??faut"

10 "Taille police"

11 "p"
$   Window menu

12 "Nouveau"

13 "N"

14 "Imprimer"

15 "I"

16 "Imprimer..."

17 "r"

18 "Fermer"

19 "m"

20 "Fen??tre"

21 "n"
$   Edit menu

22 "Copier"

23 "o"

24 "Ctrl osfInsert"

25 "Ctrl+Inser"

26 "Coller"

27 "l"

28 "Shift osfInsert"

29 "Maj+Inser"

30 "Editer"

31 "E"
$   Option menu

32 "Barre de menus"

33 "e"

34 "Barre de d??filement"

35 "t"

36 "G??n??ral..."

37 "G"

38 "Terminal..."

39 "T"

40 "R??initialisation logiciel "

41 "l"

42 "R??initialisation mat??riel"

43 "m"

44 "R??initialisation"

45 "i"

46 "Options"

47 "O"
$ Old Help menu (no longer used for CDE)

48 "G??n??ralit??s"

49 "G"

50 "T??ches"

51 "T"

52 "R??f??rence"

53 "f"

54 "Sur l'??l??ment"

55 "S"

56 "Utiliser l'aide"

57 "U"

58 "A propos de dtterm"

59 "A"

60 "Aide"

61 "d"

62 "Alt+F4"

63 "dtterm"
$ Current CDE Help menu

64 "G??n??ralit??s"

65 "t"

66 "Index"

67 "I"

68 "Table des mati??res"

69 "m"

70 "T??ches"

71 "T"

72 "R??f??rence"

73 "R"

74 "Clavier"

75 "C"

76 "Aide sur l'aide"

77 "i"

78 "A propos de dtterm"

79 "A"

80 "Aide"

81 "d"

82 "A propos du terminal"

83 " A propos du terminal "

$set 9        Redefine set#

$ ****** Module: TermTerminalDialog.c
$ These are the messages for the terminal options dialog

1 "dtterm - Options de terminal"

2 "OK"

3 "Annuler"

4 "Aide"

5 "Param??tres du clavier"

6 "Normal"

7 "Application"

8 "S??quence d'??chappement curseur"

9 "Num??rique"

10 "Application"

11 "Mode clavier num??rique"

12 "Retour chariot seulement"

13 "Retour chariot et avance ligne"

14 "S??quence d'interligne"

15 "Verrouill??"

16 "D??verrouill??"

17 "Touches de fonction utilisateur"

18 "Param??tres de l'??cran"

19 "Activ??"

20 "D??sactiv??"

21 "S??lecteur de mode 132 colonnes"

22 "Passage du curseur ?? la ligne suivante"

23 "Passage du curseur ?? la ligne pr??c??dente"

24 "Appliquer"

25 "Restaurer"

26 "Terminal - Options du terminal"

$set 10
$ ****** Module: sunDtTermServer.c
$ These are the messages for the ToolTalk error dialog
$ "-NEW"
1 Terminal - Error
$ "-NEW"
2 "Could not connect to ToolTalk:\n%s\nExiting ..."
$ "-NEW"
3 OK
