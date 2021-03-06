/* proxy_x11forward.h
 *
 * $Id: proxy_x11forward.h,v 1.1.1.1 2001/03/07 09:53:13 chombier Exp $ */

/* lsh, an implementation of the ssh protocol
 *
 * Copyright (C) 1999 Bal�zs Scheidler
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef LSH_PROXY_X11FORWARD_H_INCLUDED
#define LSH_PROXY_X11FORWARD_H_INCLUDED

struct channel_open *
make_proxy_open_x11(void);

#endif
