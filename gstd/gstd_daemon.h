/*
 * GStreamer Daemon - Gst Launch under steroids
 * Copyright (c) 2015-2017 Ridgerun, LLC (http://www.ridgerun.com)
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */
#ifndef __GSTD_DAEMON_H__
#define __GSTD_DAEMON_H__

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <glib.h>

/**
 * Initializes the resources necessary to daemonize or kill a 
 * a process.
 *
 * \param argc The amount of parameters given in argv 
 * \param argv The array of cmdline arguments given to 
 * the process in the application's main
 **/
void gstd_daemon_init (gint argc, gchar * argv[]);

/**
 * Daemonizes the current process using the given process name
 *
 * \param parent A memory location to hold either the fork belongs to
 * the parent of the child.
 *
 * \return TRUE if the process was sucessfully daemonized, FALSE
 * otherwise.
 */
gboolean gstd_daemon_start (gboolean * parent);

/**
 * Closes the resources associated with the daemon, if any.
 *
 * \return TRUE if the daemon was successfully closed, FALSE
 * otherwise.
 */
gboolean gstd_daemon_stop ();

#endif // __GSTD_DAEMON_H__
