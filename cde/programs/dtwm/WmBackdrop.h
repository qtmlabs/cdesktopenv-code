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
 * (c) Copyright 1987, 1988, 1989, 1990, 1992 HEWLETT-PACKARD COMPANY 
 * (c) Copyright 1989, 1990, 1991, 1992 OPEN SOFTWARE FOUNDATION, INC. 
 * ALL RIGHTS RESERVED 
*/ 

/********    Public Function Declarations    ********/

extern void ChangeBackdrop( 
                        WmWorkspaceData *pWS) ;
extern void ProcessBackdropResources( 
                        WmWorkspaceData *pWS,
                        unsigned long callFlags) ;
extern String FullBitmapFilePath( 
                        String pch) ;
extern void SetNewBackdrop( 
                        WmWorkspaceData *pWS,
                        Pixmap pixmap,
                        String bitmapFile,
                        DtWsmBackdropImageType imageType) ;
extern Boolean IsBackdropWindow( 
                        WmScreenData *pSD,
                        Window win) ;

/********    End Public Function Declarations    ********/

/****************************   eof    ***************************/
