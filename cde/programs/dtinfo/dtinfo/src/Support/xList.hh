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
 * $TOG: xList.hh /main/14 1998/04/17 11:40:11 mgreess $
 *
 * Copyright (c) 1993 HAL Computer Systems International, Ltd.
 * All rights reserved.  Unpublished -- rights reserved under
 * the Copyright Laws of the United States.  USE OF A COPYRIGHT
 * NOTICE IS PRECAUTIONARY ONLY AND DOES NOT IMPLY PUBLICATION
 * OR DISCLOSURE.
 * 
 * THIS SOFTWARE CONTAINS CONFIDENTIAL INFORMATION AND TRADE
 * SECRETS OF HAL COMPUTER SYSTEMS INTERNATIONAL, LTD.  USE,
 * DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE
 * PRIOR EXPRESS WRITTEN PERMISSION OF HAL COMPUTER SYSTEMS
 * INTERNATIONAL, LTD.
 * 
 *                         RESTRICTED RIGHTS LEGEND
 * Use, duplication, or disclosure by the Government is subject
 * to the restrictions as set forth in subparagraph (c)(l)(ii)
 * of the Rights in Technical Data and Computer Software clause
 * at DFARS 252.227-7013.
 *
 *          HAL COMPUTER SYSTEMS INTERNATIONAL, LTD.
 *                  1315 Dell Avenue
 *                  Campbell, CA  95008
 * 
 */

#ifndef _xList_hh
#define _xList_hh

#include "List_base.hh"

template <class T> class xList;
template <class T> class List_Iterator;


template <class T>
class Link : private Link_base
{
friend class xList<T>;
friend class List_Iterator<T>;

private:
  Link (const T &element)
    : f_element (element)
    { }
  
  T     f_element;
};

template <class T>
class xList : public List_base
{
// NOTE: This friend declaration is too general because cfront
// barfs when I do it the correct way.  22:05 22-Jul-93 DJB
#ifdef SC3
friend class List_Iterator<T>;
#endif
public:
  xList() { } 
  ~xList();

  void insert (const T &element)
    { List_base::insert (new Link<T> (element)); }

  void insert_before (List_Iterator<T> &iterator, const T &element);

  void insert_after (List_Iterator<T> &iterator, const T &element);

  void append (const T &element);

  // Element must have an operator == that works. 
  void remove (T &element);

  void remove (List_Iterator<T> &iterator);


  unsigned int length() const
    { return (List_base::length()); }

  // Another hack.  CC gets a bus error if we pass a reference to
  // to List_Iter constructor.  So we add an automatic conversion
  // here to avoid the hassle of taking the address of a List.
  operator const xList<T> *() const
    { return (this); }

};


template <class T>
class List_Iterator : public List_Iterator_base
{
friend class xList<T>;
public:
  List_Iterator()
    { }

  List_Iterator (const xList<T> *list)
    : List_Iterator_base (list)
    { }

  void reset()
    { List_Iterator_base::reset(); }

  void last()
    { List_Iterator_base::last(); }

  void operator= (const xList<T> *list)
    { List_Iterator_base::operator= (list); }

#ifndef DEC
  int operator!= (int i)
    { return (List_Iterator_base::operator!= (i)); }
#endif

  T& item() const
    { return (((Link<T> *) List_Iterator_base::item())->f_element); }

  void *operator++ ()
    { return (List_Iterator_base::operator++ ()); }

  void *operator++ (int)
    { return (List_Iterator_base::operator++ ()); }

  operator void *() const
    { return (List_Iterator_base::operator void *()); }
};

#ifdef EXPAND_TEMPLATES
#include "xList.C"
#endif

#endif /* _xList_hh */
/* DO NOT ADD ANY LINES AFTER THIS #endif */
