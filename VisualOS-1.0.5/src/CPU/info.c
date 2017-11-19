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

#include <gtk/gtk.h>

#include "info.h"

static GtkWidget *window = NULL;
static GSList *algorithms = NULL;
static cpu_algorithm_t *current_algorithm = NULL;


GtkWidget *get_CPU_window (void) 
{
	return window;
}
void set_CPU_window (GtkWidget *new_window) 
{
	window = new_window;
}

GSList *get_CPU_algorithms (void) 
{
	return algorithms;
}
void set_CPU_algorithms (GSList *new_algorithms) 
{
	algorithms = new_algorithms;
}

/**
 * get_CPU_current_algorithm:
 *
 * Find out which is the current algorithm.
 *
 * returns: the struct which descrives the current algorithm.
 */
cpu_algorithm_t *get_CPU_current_algorithm (void) 
{
	return current_algorithm;
}
void set_CPU_current_algorithm (cpu_algorithm_t *new_current_algorithm) 
{
	current_algorithm = new_current_algorithm;
}
