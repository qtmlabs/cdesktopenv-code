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
// $XConsortium: cc_povec.cc /main/3 1996/06/11 16:56:44 cde-hal $

#include "dti_cc/cc_povec.h"
#include "dti_cc/cc_pvect.h"

template <class T>
dlist_array<T>::dlist_array(const dlist_array<T>& da) 
{
   cerr << "Warning: dlist_array(const dlist_array&) called" << endl ;
   exit (-1);
}

template <class T>
dlist_array<T>::dlist_array(size_t)
{
}

template <class T>
dlist_array<T>::~dlist_array()
{
}

