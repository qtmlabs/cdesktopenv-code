$ *************************************<+>************************************* 
$ ***************************************************************************** 
$ ** 
$ **  File:        DtWidget.vmsg 
$ ** 
$ **  Project:     DT 
$ ** 
$ **  Description: 
$ **  ----------- 
$ **  This file is the source for the message catalog for the Dt widget 
$ **  library. 
$ ** 
$ ** 
$ ***************************************************************************** 
$ ** 
$ **  (c) Copyright 1993, 1994 Hewlett-Packard Company 
$ **  (c) Copyright 1993, 1994 International Business Machines Corp. 
$ **  (c) Copyright 1993, 1994 Sun Microsystems, Inc. 
$ **  (c) Copyright 1993, 1994 Novell, Inc. 
$ ** 
$ ***************************************************************************** 
$ ** 
$ ** 
$ **  $XConsortium: DtWidget.msg /main/6 1996/10/19 14:26:16 rws $ 
$ ***************************************************************************** 
$ ***************************************************************************** 
$ ***************************************************************************** 
$  
$ ***** NOTE FOR MESSAGE CATALOG TRANSLATORS ***** 
$  
$ There MAY be three types of messages in this file: 
$  
$  1. Messages that appear in dialogs or are displayed to the user. 
$  
$     These messages are the default and they should ALL BE LOCALIZED. 
$     Note that these messages do NOT have any identification (see the 
$     comments for type 2 and 3 below). 
$  
$  2. Messages that only appear in the DT error log file ($HOME/.dt/errorlog). 
$  
$     The localization of these messages is OPTIONAL.  These messages are 
$     identified by the following: 
$  
$  MESSAGES xx-yy IN SET zz WILL ONLY APPEAR IN THE DT ERRORLOG FILE 
$  
$  3. Messages that should not be localized. 
$  
$     These messages are identified by the following: 
$  
$  DO NOT TRANSLATE or CHANGE or LOCALIZE MESSAGES xx-yy from set zz 
$  
$ ***** END (NOTE FOR MESSAGE CATALOG TRANSLATORS) ***** 
$  
$ ****************************************************************************** 
$quote "

$set 2
$ ************************************************************* 
$ ** \t\t\t\t\t\t\t     **  
$ ** Common messages shared by all DT widgets                ** 
$ ** \t\t\t\t\t\t\t     **  
$ ************************************************************* 
$ Default value for DtNdialogCloseButtonLabel resource. 
$ This string is used for all "Close" buttons in all dialogs. 

1 "Schlie??en"
$ Default value for DtNdialogHelpButtonLabel resource. 
$ This string is used for all "Help" buttons in all dialogs. 

2 "Hilfe"

$set 3        Redefine set#

$ ************************************************************* 
$ ** \t\t\t\t\t\t\t     **  
$ **  This set of messages is used by the DtEditor widget.  ** 
$ ** \t\t\t\t\t\t\t     **  
$ ************************************************************* 
$ ********************************************** 
$ **                         module: Editor.c ** 
$ **  Messages for the Format/Settings dialog ** 
$ ********************************************** 
$ Default value for DtNformatSettingsDialogTitle resource, 
$ title of format settings dialog 

1 "Formateinstellungen"
$ Default values for DtNlMarginFieldLabel and DtNrMarginFieldLabel resources, 
$ labels for margin fields in Format Settings dialog 

2 "Rechter Rand:"

3 "Linker Rand:"
$ Default values for DtNlAlignToggleLabel, DtNrAlignToggleLabel, 
$ DtNjustifyToggleLabel, and DtNcenterToggleLabel resources, 
$ labels for justification radio buttons in Format Settings dialog 

4 "Ausrichtung links"

5 "Ausrichtung rechts"

6 "Ausrichtung"

7 "Zentriert"
$ Default values for DtNformatParagraphButtonLabel and  
$ DtNformatAllButtonLabel resources, 
$ labels for paragraph and all buttons in Format Settings dialog 

8 "Absatz"

9 "Alles"
$ ****************************************************************** 
$ **                                              module Editor.c ** 
$ ** Strings used in the spell checking and find/change dialogs.  ** 
$ ****************************************************************** 
$ Default value for DtNspellDialogTitle resource, 
$ title of the Spell dialog 

20 "Rechtschreibpr??fung"
$ Default value for DtNfindDialogTitle resource, 
$ title of the Find/Change dialog 

21 "Suchen/??ndern"
$ Default value for DtNmisspelledListLabel resource, 
$ label for list of unrecognized and misspelled words 

22 "Rechtschreibfehler:"
$ Default value for DtNfindFieldLabel resource, 
$ label of field in which user types string for which to search. 

23 "Suchen:"
$ Default value for DtNchangeFieldLabel resource, 
$ label of field in which user types the replacement string 

24 "??ndern in:"
$ Default values for DtNfindButtonLabel, DtNchangeButtonLabel, and 
$ DtNchangeAllButtonLabel resources, 
$ labels for find, change, and change all buttons in Find/Change dialog 

25 "Suchen"

26 "??ndern"

27 "Alles ??ndern"
$ ****************************************************************** 
$ ** \t\t\t\t\t      module: SearchDlg.  ** 
$ ** Message displayed when Find/Replace/Spell fails to find the  ** 
$ ** specified string or word.                                    ** 
$ ****************************************************************** 
$ Used to display "Unable to find the string FOO in the current document." 
$ Note: Do not localize the characters %s. 

30 "Zeichenfolge %s kann im aktuellen Dokument nicht gefunden werden."
$ Title for general information dialog (e.g. "Find/Change dialog can't  
$ find word in document."). 

31 "Information"
$ *********************************************************** 
$ **                                       module Editor.c ** 
$ ** Messages and strings associated with the status line. ** 
$ *********************************************************** 
$ Default value for DtNcurrentLineLabel resource, 
$ label for the display showing the current insert cursor line  

40 "Zeile:"
$ Default value for DtNtotalLineCountLabel resource, 
$ label for the display showing the total number of lines in the document 

41 "Summe:"
$ Default value for DtNoverstrikeLabel resource, 
$ label used to indicate Editor is in overstrike (overtype) mode.  

42 "??berschreiben"
$ Default value for DtNinsertLabel resource, 
$ label used to indicate Editor is in insert mode.  
$ The default value is a blank string. 

43 ""

$ ******************************************************************
$ **                                          module: SearchCalls **
$ ** Message displayed when Find/Replace/Spell fails to execute   **
$ ** the spell filter.                                            **
$ ******************************************************************

$quote

$ Error message if there is a problem running the spell filter
$ Message 34 and 35 are part of the same message for the error
$ dialog.
$ do not translate %s
50 Fehler bei der Ausf??hrung des Rechtschreibfilters.
51 ??berpr??fen, ob Filter %s installiert ist und sich im Pfad befindet.

$ Title for Error dialog
52 Editor-Fehler

$set 4        Redefine set#

$ ************************************************************* 
$ ** \t\t\t\t\t\t\t     **  
$ ** MenuButton messages \t\t\t\t     ** 
$ ** \t\t\t\t\t\t\t     **  
$ ************************************************************* 
$ Warning messsage 
$ Note: do not localize the chars XmNmenuPost 

$quote "
1 "XmNmenuPost besitzt einen ung??ltigen Wert."
$ Error messsages 
$ Note: do not localize the chars DtMenuButtonWidget in messages 2 and 3 

2 "DtMenuButtonWidget: Ung??ltiges ??bergeordnetes Objekt (Parent)."

3 "DtMenuButtonWidget: Ung??ltiges Untermen??."

$set 5        Redefine set#

$ ************************************************************* 
$ ** \t\t\t\t\t\t\t     **  
$ ** ComboBox  \tmessages \t\t\t\t     ** 
$ ** \t\t\t\t\t\t\t     **  
$ ************************************************************* 
$ Warning messsages 
$ Note: do not localize the chars DtComboBoxWidget in messages 1 - 11 
$ Note: do not localize the chars alignment and DtALIGNMENT_CENTER 

1 "DtComboBoxWidget: Ung??ltige alignment-Ressource (auf Standardwert DtALIGNMENT_CENTER gesetzt)."
$ Note: do not localize the chars marginHeight  

2 "DtComboBoxWidget: Ung??ltige marginHeight-Ressource (auf Standardwert 2 gesetzt)."
$ Note: do not localize the chars marginWidth 

3 "DtComboBoxWidget: Ung??ltige marginWidth-Ressource (auf Standardwert 2 gesetzt)."
$ Note: do not localize the chars horizontalSpacing 

4 "DtComboBoxWidget: Ung??ltige horizontalSpacing-Ressource (auf Standardwert 0 gesetzt)."
$ Note: do not localize the chars verticalSpacing 

5 "DtComboBoxWidget: Ung??ltige verticalSpacing-Ressource (auf Standardwert 0 gesetzt)."
$ Note: do not localize the chars orientation and DtRIGHT 

6 "DtComboBoxWidget: Ung??ltige orientation-Ressource (auf Standardwert DtRIGHT gesetzt)."
$ Note: do not localize the chars itemCount 

7 "DtComboBoxWidget: Ung??ltige itemCount-Ressource (auf Standardwert 0 gesetzt)."
$ Note: do not localize the chars selectedPosition 

8 "DtComboBoxWidget: Ung??ltige selectedPosition-Ressource (auf Standardwert 0 gesetzt)."
$ Note: do not localize the chars textField 

9 "DtComboBoxWidget: Festlegen der textField-Ressource nicht m??glich."
$ Note: do not localize the chars DtComboBoxSetItem 

10 "DtComboBoxWidget: Element f??r Festlegung nicht gefunden (DtComboBoxSetItem)."
$ Note: do not localize the chars DtComboBoxSelectItem 

11 "DtComboBoxWidget: Element f??r Auswahl nicht gefunden (DtComboBoxSelectItem)."

12 "Gr????en??nderung gescheitert. M??glicherweise ist das l??ngste Element gr????er als der zul??ssige Platz."
$ Label value 

13 "ComboBox"
$ Error message 
$ Note: do not localize the chars String and XmRType 

14 "cvtStringToType: ung??ltige Parameter, Zeichenfolge f??r XmRType-Umwandlung ben??tigt keine zus??tzlichen Argumente"
$ Warning message 

15 "DtComboBoxDeletePos: ung??ltige Parameter, Positionswert ung??ltig"

$set 6        Redefine set#

$ ************************************************************* 
$ ** \t\t\t\t\t\t\t     **  
$ ** SpinBox   \tmessages \t\t\t\t     ** 
$ ** \t\t\t\t\t\t\t     **  
$ ************************************************************* 
$ Warning messsages 
$ Note: do not localize the chars DtSpinBoxWidget in messages 1 - 14 
$ Note: do not localize the chars arrowSensitivity and DtARROWS_SENSITIVE 

1 "DtSpinBoxWidget: Ung??ltige arrowSensitivity-Ressource (auf Standardwert DtARROWS_SENSITIVE gesetzt)."
$ Note: do not localize the chars alignment and DtALIGNMENT_CENTER 

2 "DtSpinBoxWidget: Ung??ltige alignment-Ressource (auf Standardwert DtALIGNMENT_CENTER gesetzt)."
$ Note: do not localize the chars intialDelay  

3 "DtSpinBoxWidget: Ung??ltige initialDelay-Ressource (auf Standardwert 250 gesetzt)."
$ Note: do not localize the chars marginHeight 

4 "DtSpinBoxWidget: Ung??ltige marginHeight-Ressource (auf Standardwert 2 gesetzt)."
$ Note: do not localize the chars marginWidth 

5 "DtSpinBoxWidget:  Ung??ltige marginWidth-Ressource (auf Standardwert 2 gesetzt)."
$ Note: do not localize the chars arrowLayout and DtARROWS_BEGINNING 

6 "DtSpinBoxWidget: Ung??ltige arrowLayout-Ressource (auf Standardwert DtARROWS_BEGINNING gesetzt)."
$ Note: do not localize the chars repeatDelay 

7 "DtSpinBoxWidget: Ung??ltige repeatDelay-Ressource (auf Standardwert 200 gesetzt)."
$ Note: do not localize the chars itemCount 

8 "DtSpinBoxWidget: Ung??ltige itemCount-Ressource (auf Standardwert 0 gesetzt)."
$ Note: do not localize the chars position in messages 9 and 10 

9 "DtSpinBoxWidget: Ung??ltige position-Ressource (auf Standardwert 0 gesetzt)."

10 "DtSpinBoxWidget: Ung??ltige position-Ressource (auf Minimum gesetzt)."
$ Note: do not localize the chars decimalPoints 

11 "DtSpinBoxWidget: Ung??ltige decimalPoints-Ressource (auf Standardwert 0 gesetzt)."
$ Note: do not localize the chars minimum 

12 "DtSpinBoxWidget: Ung??ltige minimum-Ressource (auf Maximum gesetzt)."
$ Note: do not localize the chars textField 

13 "DtSpinBoxWidget: Festlegen der textField-Ressource nicht m??glich."
$ Note: do not localize the chars DtSpinBoxSetItem 

14 "DtSpinBoxWidget: Element f??r Festlegung nicht gefunden (DtSpinBoxSetItem)."
$ Label value 

15 "Durchlaufliste"
