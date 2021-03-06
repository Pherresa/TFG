/* VisualOS is an educational visual simulator of an operating system.   
   Copyright (C) 2000,2004 Manuel Estrada Sainz <ranty@debian.org>
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <gtk/gtk.h>

#include <MEM/MEM.h>

typedef struct {					/* This struct is all
							   that we know about
							   each algorithm */
	gchar * name;
	void (*select) (void);
	void (*unselect) (void);			/* These two functions
							   will be called before
							   and after the use of
							   an algorithm to let
							   it keep a low memory
							   usage when not in
							   use.*/
	GtkWidget * properties;				/* Each algorithm will
							   maintain it's own
							   properties widget.
							   NULL means "no
							   properties".  It
							   should be set to NULL
							   when destroyed. If
							   not destroyed in
							   "unselect" the system
							   will destroy it.*/
	void (*page_access) (gint pid, gint page);	/* lets the algorithm
							   keep track of page
							   accesses */
	gint (*select_frame) (void);			/* it should return a
							   frame to be assigned
							   when out of memory */
} mem_algorithm_t;

GSList * init_MEM_algorithms(void);
void register_MEM_algorithm (mem_algorithm_t * algorithm);
#endif
