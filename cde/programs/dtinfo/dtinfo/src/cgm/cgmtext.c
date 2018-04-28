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
/* $XConsortium: cgmtext.c /main/5 1996/06/11 16:09:46 cde-hal $ */
/* this is a set of Hershey font routines. No attempt is made to copyright
   this code, we use only one font: simplex Roman */
/* optimised for calling XLib commands */
#include <X11/Xlib.h>     /* XLib stuff */
#include "cgm.h"		/* our defs */
/* how many characters */
#define MAX_HCHARS 128
/* pointers into main array */
static int h_array[MAX_HCHARS] = {
- -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
- -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
0,4,24,38,64,120,186,258,266,290,314,334,348,368,376,390,
398,436,448,480,514,530,568,618,632,694,744,770,802,812,826,836,
- -1,880,900,950,990,1024,1050,1070,1118,1138,1146,1170,1190,1204,1230,1250,
1296,1326,1378,1414,1458,1472,1496,1510,1536,1550,1566,-1,1586,-1,1594,-1,
1608,1624,1662,1700,1732,1770,1808,1828,1876,1900,1920,1946,1966,1974,2014,2038,
2076,2114,2152,2172,2210,2230,2254,2268,2294,2308,2330,-1,2350,-1,-1,-1};

/* main data array */
#define MAX_OFFSET 2358
static unsigned char hf_array[MAX_OFFSET] = {
120,136,0,0,123,133,128,116,128,130,0,128,128,135,127,136,128,137,129,136,
128,135,0,0,120,136,124,116,124,123,0,128,132,116,132,123,0,0,118,139,
129,112,122,144,0,128,135,112,128,144,0,128,122,125,136,125,0,128,121,131,
135,131,0,0,118,138,126,112,126,141,0,128,130,112,130,141,0,128,135,119,
133,117,130,116,126,116,123,117,121,119,121,121,122,123,123,124,125,125,131,127,
133,128,134,129,135,131,135,134,133,136,130,137,126,137,123,136,121,134,0,0,
116,140,137,116,119,137,0,128,124,116,126,118,126,120,125,122,123,123,121,123,
119,121,119,119,120,117,122,116,124,116,126,117,129,118,132,118,135,117,137,116,
0,128,133,130,131,131,130,133,130,135,132,137,134,137,136,136,137,134,137,132,
135,130,133,130,0,0,115,141,138,125,138,124,137,123,136,123,135,124,134,126,
132,131,130,134,128,136,126,137,122,137,120,136,119,135,118,133,118,131,119,129,
120,128,127,124,128,123,129,121,129,119,128,117,126,116,124,117,123,119,123,121,
124,124,126,127,131,134,133,136,135,137,137,137,138,136,138,135,0,0,124,132,
128,116,128,123,0,0,121,135,132,112,130,114,128,117,126,121,125,126,125,130,
126,135,128,139,130,142,132,144,0,0,121,135,124,112,126,114,128,117,130,121,
131,126,131,130,130,135,128,139,126,142,124,144,0,0,120,136,128,122,128,134,
0,128,123,125,133,131,0,128,133,125,123,131,0,0,115,141,128,119,128,137,
0,128,119,128,137,128,0,0,123,133,129,136,128,137,127,136,128,135,129,136,
129,138,128,140,127,141,0,0,115,141,119,128,137,128,0,0,123,133,128,135,
127,136,128,137,129,136,128,135,0,0,117,139,137,112,119,144,0,0,118,138,
127,116,124,117,122,120,121,125,121,128,122,133,124,136,127,137,129,137,132,136,
134,133,135,128,135,125,134,120,132,117,129,116,127,116,0,0,118,138,124,120,
126,119,129,116,129,137,0,0,118,138,122,121,122,120,123,118,124,117,126,116,
130,116,132,117,133,118,134,120,134,122,133,124,131,127,121,137,135,137,0,0,
118,138,123,116,134,116,128,124,131,124,133,125,134,126,135,129,135,131,134,134,
132,136,129,137,126,137,123,136,122,135,121,133,0,0,118,138,131,116,121,130,
136,130,0,128,131,116,131,137,0,0,118,138,133,116,123,116,122,125,123,124,
126,123,129,123,132,124,134,126,135,129,135,131,134,134,132,136,129,137,126,137,
123,136,122,135,121,133,0,0,118,138,134,119,133,117,130,116,128,116,125,117,
123,120,122,125,122,130,123,134,125,136,128,137,129,137,132,136,134,134,135,131,
135,130,134,127,132,125,129,124,128,124,125,125,123,127,122,130,0,0,118,138,
135,116,125,137,0,128,121,116,135,116,0,0,118,138,126,116,123,117,122,119,
122,121,123,123,125,124,129,125,132,126,134,128,135,130,135,133,134,135,133,136,
130,137,126,137,123,136,122,135,121,133,121,130,122,128,124,126,127,125,131,124,
133,123,134,121,134,119,133,117,130,116,126,116,0,0,118,138,134,123,133,126,
131,128,128,129,127,129,124,128,122,126,121,123,121,122,122,119,124,117,127,116,
128,116,131,117,133,119,134,123,134,128,133,133,131,136,128,137,126,137,123,136,
122,134,0,0,123,133,128,123,127,124,128,125,129,124,128,123,0,128,128,135,
127,136,128,137,129,136,128,135,0,0,123,133,128,123,127,124,128,125,129,124,
128,123,0,128,129,136,128,137,127,136,128,135,129,136,129,138,128,140,127,141,
0,0,116,140,136,119,120,128,136,137,0,0,115,141,119,125,137,125,0,128,
119,131,137,131,0,0,116,140,120,119,136,128,120,137,0,0,119,137,122,121,
122,120,123,118,124,117,126,116,130,116,132,117,133,118,134,120,134,122,133,124,
132,125,128,127,128,130,0,128,128,135,127,136,128,137,129,136,128,135,0,0,
119,137,128,116,120,137,0,128,128,116,136,137,0,128,123,130,133,130,0,0,
117,138,121,116,121,137,0,128,121,116,130,116,133,117,134,118,135,120,135,122,
134,124,133,125,130,126,0,128,121,126,130,126,133,127,134,128,135,130,135,133,
134,135,133,136,130,137,121,137,0,0,118,139,136,121,135,119,133,117,131,116,
127,116,125,117,123,119,122,121,121,124,121,129,122,132,123,134,125,136,127,137,
131,137,133,136,135,134,136,132,0,0,117,138,121,116,121,137,0,128,121,116,
128,116,131,117,133,119,134,121,135,124,135,129,134,132,133,134,131,136,128,137,
121,137,0,0,118,137,122,116,122,137,0,128,122,116,135,116,0,128,122,126,
130,126,0,128,122,137,135,137,0,0,118,136,122,116,122,137,0,128,122,116,
135,116,0,128,122,126,130,126,0,0,118,139,136,121,135,119,133,117,131,116,
127,116,125,117,123,119,122,121,121,124,121,129,122,132,123,134,125,136,127,137,
131,137,133,136,135,134,136,132,136,129,0,128,131,129,136,129,0,0,117,139,
121,116,121,137,0,128,135,116,135,137,0,128,121,126,135,126,0,0,124,132,
128,116,128,137,0,0,120,136,132,116,132,132,131,135,130,136,128,137,126,137,
124,136,123,135,122,132,122,130,0,0,117,138,121,116,121,137,0,128,135,116,
121,130,0,128,126,125,135,137,0,0,118,135,122,116,122,137,0,128,122,137,
134,137,0,0,116,140,120,116,120,137,0,128,120,116,128,137,0,128,136,116,
128,137,0,128,136,116,136,137,0,0,117,139,121,116,121,137,0,128,121,116,
135,137,0,128,135,116,135,137,0,0,117,139,126,116,124,117,122,119,121,121,
120,124,120,129,121,132,122,134,124,136,126,137,130,137,132,136,134,134,135,132,
136,129,136,124,135,121,134,119,132,117,130,116,126,116,0,0,117,138,121,116,
121,137,0,128,121,116,130,116,133,117,134,118,135,120,135,123,134,125,133,126,
130,127,121,127,0,0,117,139,126,116,124,117,122,119,121,121,120,124,120,129,
121,132,122,134,124,136,126,137,130,137,132,136,134,134,135,132,136,129,136,124,
135,121,134,119,132,117,130,116,126,116,0,128,129,133,135,139,0,0,117,138,
121,116,121,137,0,128,121,116,130,116,133,117,134,118,135,120,135,122,134,124,
133,125,130,126,121,126,0,128,128,126,135,137,0,0,118,138,135,119,133,117,
130,116,126,116,123,117,121,119,121,121,122,123,123,124,125,125,131,127,133,128,
134,129,135,131,135,134,133,136,130,137,126,137,123,136,121,134,0,0,120,136,
128,116,128,137,0,128,121,116,135,116,0,0,117,139,121,116,121,131,122,134,
124,136,127,137,129,137,132,136,134,134,135,131,135,116,0,0,119,137,120,116,
128,137,0,128,136,116,128,137,0,0,116,140,118,116,123,137,0,128,128,116,
123,137,0,128,128,116,133,137,0,128,138,116,133,137,0,0,118,138,121,116,
135,137,0,128,135,116,121,137,0,0,119,137,120,116,128,126,128,137,0,128,
136,116,128,126,0,0,118,138,135,116,121,137,0,128,121,116,135,116,0,128,
121,137,135,137,0,0,121,135,121,116,135,140,0,0,120,136,128,114,120,128,
0,128,128,114,136,128,0,0,122,134,126,116,131,122,0,128,126,116,125,117,
131,122,0,0,119,138,134,123,134,137,0,128,134,126,132,124,130,123,127,123,
125,124,123,126,122,129,122,131,123,134,125,136,127,137,130,137,132,136,134,134,
0,0,118,137,122,116,122,137,0,128,122,126,124,124,126,123,129,123,131,124,
133,126,134,129,134,131,133,134,131,136,129,137,126,137,124,136,122,134,0,0,
119,137,134,126,132,124,130,123,127,123,125,124,123,126,122,129,122,131,123,134,
125,136,127,137,130,137,132,136,134,134,0,0,119,138,134,116,134,137,0,128,
134,126,132,124,130,123,127,123,125,124,123,126,122,129,122,131,123,134,125,136,
127,137,130,137,132,136,134,134,0,0,119,137,122,129,134,129,134,127,133,125,
132,124,130,123,127,123,125,124,123,126,122,129,122,131,123,134,125,136,127,137,
130,137,132,136,134,134,0,0,123,135,133,116,131,116,129,117,128,120,128,137,
0,128,125,123,132,123,0,0,119,138,134,123,134,139,133,142,132,143,130,144,
127,144,125,143,0,128,134,126,132,124,130,123,127,123,125,124,123,126,122,129,
122,131,123,134,125,136,127,137,130,137,132,136,134,134,0,0,119,138,123,116,
123,137,0,128,123,127,126,124,128,123,131,123,133,124,134,127,134,137,0,0,
124,132,127,116,128,117,129,116,128,115,127,116,0,128,128,123,128,137,0,0,
123,133,128,116,129,117,130,116,129,115,128,116,0,128,129,123,129,140,128,143,
126,144,124,144,0,0,119,136,123,116,123,137,0,128,133,123,123,133,0,128,
127,129,134,137,0,0,124,132,128,116,128,137,0,0,113,143,117,123,117,137,
0,128,117,127,120,124,122,123,125,123,127,124,128,127,128,137,0,128,128,127,
131,124,133,123,136,123,138,124,139,127,139,137,0,0,119,138,123,123,123,137,
0,128,123,127,126,124,128,123,131,123,133,124,134,127,134,137,0,0,119,138,
127,123,125,124,123,126,122,129,122,131,123,134,125,136,127,137,130,137,132,136,
134,134,135,131,135,129,134,126,132,124,130,123,127,123,0,0,118,137,122,123,
122,144,0,128,122,126,124,124,126,123,129,123,131,124,133,126,134,129,134,131,
133,134,131,136,129,137,126,137,124,136,122,134,0,0,119,138,134,123,134,144,
0,128,134,126,132,124,130,123,127,123,125,124,123,126,122,129,122,131,123,134,
125,136,127,137,130,137,132,136,134,134,0,0,121,134,125,123,125,137,0,128,
125,129,126,126,128,124,130,123,133,123,0,0,120,137,134,126,133,124,130,123,
127,123,124,124,123,126,124,128,126,129,131,130,133,131,134,133,134,134,133,136,
130,137,127,137,124,136,123,134,0,0,123,135,128,116,128,133,129,136,131,137,
133,137,0,128,125,123,132,123,0,0,119,138,123,123,123,133,124,136,126,137,
129,137,131,136,134,133,0,128,134,123,134,137,0,0,120,136,122,123,128,137,
0,128,134,123,128,137,0,0,117,139,120,123,124,137,0,128,128,123,124,137,
0,128,128,123,132,137,0,128,136,123,132,137,0,0,120,137,123,123,134,137,
0,128,134,123,123,137,0,0,120,136,122,123,128,137,0,128,134,123,128,137,
126,141,124,143,122,144,121,144,0,0,120,137,134,123,123,137,0,128,123,123,
134,123,0,128,123,137,134,137,0,0,124,132,128,112,128,144,0,0};

/* external entry point */
/* NB this is X-specific, Y points down */
void draw_cgm_text(Display *inDis,  Drawable inDraw, GC inGC, 
		   cgm_s_type *cgm_s, int inX, int inY, int inW, int inH,
		   partialText *inText)
{
  XPoint myPts[128]; /* should be plenty */
  int offset, noPts, w1, w2, x, y, w = 0;
  unsigned char *hPtr;
  char *inS;
  float charSize, cMod = 1;
  partialText *myText;
  int doDraw;
  x = inX;
  y = inY;
  for (doDraw = 0; doDraw < 2; ++doDraw) { /* always go through twice */
    myText = inText;
    if (doDraw) { /* done a measurement, now about to draw */
      if (inW && inH) { /* restricted text */
      w = (x > inX) ? x - inX : inX - x;
      if (w && (w > inW)) cMod = ((float) inW) / w;
      }
      switch (cgm_s->talign[0].i) { /* horizontal alignment */
      default: /* don't worry about continuous horizontal for now */
      case 0: /* normal */
      case 1: /* left */
	x = inX;
	break;
      case 2: /* centre */
	x = inX - (int) (0.5 * (x - inX));
	  break;
      case 3: /* right */
	x = inX - (x - inX);
	break;
      } 
    }
    while (myText) {
      switch (cgm_s->talign[1].i) { /* vertical alignment */
      default: /* don't worry about continuous vertical for now */
      case 0: /* normal */
      case 5: /* bottom */
	y = inY;
	break;
      case 1: /* top */
	y = inY + (int) (cMod * myText->cheight);
	break;
      case 2: /* cap */
	y = inY + (int) (0.9 * cMod * myText->cheight);
	  break;
      case 3: /* half */
	y = inY + (int) (0.5 * cMod * myText->cheight);
	break;
      case 4: /* base */
	y = inY + (int) (0.1 * cMod * myText->cheight);
	break;
      } 
      if (doDraw) XSetForeground(inDis, inGC, myText->tcolr);
      inS = myText->text;
      charSize = cMod * myText->cheight / 24.0; /* chars are in a 24 pt box */
      while (*inS) { /* step thru the string */
	if ((*inS < 0) || ((offset = h_array[(int)*inS]) < 0))
	  { /* illegal character */
	    ++inS; /* step over */	  
	    continue; 
	  }
	hPtr = hf_array + offset;
	/* pick up the character widths */
	w1 = (int) ((charSize * (128 - (int) *hPtr++)) * myText->cexpfac);
	w2 = (int) ((charSize * ((int) *hPtr++ - 128)) * myText->cexpfac);
	/* need to step before beginning character */
	switch (cgm_s->tpath) {
	default: /* shouldn't happen */
	case 0: /* right */
	  x += w1;
	  break;
	case 1: /* left */
	  x -= w2;
	  break;
	case 2: /* up */
	  x = inX + w1;
	  break;
	case 3: /* down */
	  x = inX + w1;
	  y += myText->cheight;
	  break;
	}
	/* now draw the character, polyline by polyline */
	noPts = 0;
	if (doDraw) do {
	  /* what sort of point are we at ? */
	  if (!hPtr[2 * noPts] &&
	      (!hPtr[2 * noPts + 1] || (hPtr[2 * noPts + 1] == 128))) {
	    /* either pen up or end of char description */
	    /* need to take care of points so far */
	    if (noPts) XDrawLines(inDis, inDraw, inGC, myPts, noPts,
				  CoordModeOrigin);
	    /* is there another segment ? */
	    if (hPtr[2 * noPts + 1]) {
	      hPtr += 2 * noPts + 2;
	      noPts = 0;
	    } else break; /* finished this char */
	  } else { /* normal point */
	    myPts[noPts].x = x +
	      (int) ((charSize * ((int) hPtr[2 * noPts] - 128))
		* myText->cexpfac);
	    myPts[noPts].y = y -
	      (int) (charSize * (140 - (int) hPtr[2 * noPts + 1]));
	    ++noPts;
	  }
	} while ((hPtr + noPts * 2) <= (hf_array + MAX_OFFSET)); /* legal */
	/* need to step for next character */
	switch (cgm_s->tpath) {
	default: /* shouldn't happen */
	case 0: /* right */
	  x += w2 + myText->cspace;
	  break;
	case 1: /* left */
	  x -= w1 + myText->cspace;
	  break;
	case 2: /* up */
	  y -= myText->cheight;
	  break;
	case 3: /* down */
	  break;
	}
	++inS; /* next character */
      } /* end of string */
      myText = myText->next; 
    } /* end of partial text */
  } /* end of dodraw loop */
}
