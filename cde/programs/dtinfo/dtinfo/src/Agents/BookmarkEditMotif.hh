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
/*
 * $XConsortium: BookmarkEditMotif.hh /main/4 1996/07/10 09:34:51 rcs $
 *
 * Copyright (c) 1992 HaL Computer Systems, Inc.  All rights reserved.
 * UNPUBLISHED -- rights reserved under the Copyright Laws of the United
 * States.  Use of a copyright notice is precautionary only and does not
 * imply publication or disclosure.
 * 
 * This software contains confidential information and trade secrets of HaL
 * Computer Systems, Inc.  Use, disclosure, or reproduction is prohibited
 * without the prior express written permission of HaL Computer Systems, Inc.
 * 
 *                         RESTRICTED RIGHTS LEGEND
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(l)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 *                        HaL Computer Systems, Inc.
 *                  1315 Dell Avenue, Campbell, CA  95008
 * 
 */

#include <WWL/wwl.h>
#include "UAS.hh"

class WTopLevelShell;
class WXmTextField;
class WXmText;
#include <WWL/WXmPushButtonGadget.h>
class Mark;
struct MarkMoved;

class BookmarkEdit : public Dialog, public UAS_Receiver<MarkMoved>
{
public:
  BookmarkEdit (UAS_Pointer<Mark> &mark)
    : f_mark_ptr (mark),
      f_shell (NULL),
      f_name_text(NULL),
      f_notes_text(NULL),
      f_modified (FALSE),
      f_wm_delete_callback(NULL)
    {
      MarkMgr::request ((UAS_Receiver<MarkMoved> *) this);
    }
  ~BookmarkEdit();

  void display();
  UAS_Pointer<Mark> &mark_ptr()
    { return (f_mark_ptr); }

  static int modified_count()
    { return g_modified_count; }

protected: // functions
  void create_ui();

  void ok();
  void view();
  void cancel();
  void modified (WCallback *wcb);
  void changed (WCallback *wcb);

  void receive (MarkMoved &message, void *client_data);

protected: // variables
  UAS_Pointer<Mark>   f_mark_ptr;

  WTopLevelShell *f_shell;
  WXmTextField   *f_name_text;
  WXmText        *f_notes_text;
  WXmPushButtonGadget   f_ok;
  bool            f_modified;
  WCallback      *f_wm_delete_callback;
  static List     g_editor_list;
  static int	  g_modified_count;
};
