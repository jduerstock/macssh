/* client.h
 *
 *
 *
 * $Id: client.h,v 1.3 2001/09/18 16:46:39 chombier Exp $ */

/* lsh, an implementation of the ssh protocol
 *
 * Copyright (C) 1998, 1999, 2000, 2001 Niels M�ller
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef LSH_CLIENT_H_INCLUDED
#define LSH_CLIENT_H_INCLUDED

#include "channel_commands.h"
#include "io.h"
#include "keyexchange.h"

#define GABA_DECLARE
#include "client.h.x"
#undef GABA_DECLARE

/* The argp option group for actions. */
#define CLIENT_ARGP_ACTION_GROUP 100
#define CLIENT_ARGP_MODIFIER_GROUP 200

struct packet_handler *
make_accept_service_handler(UINT32 service,
			    struct command_continuation *c,
			    struct exception_handler *e);

/* GABA:
   (class
     (name request_service)
     (super command)
     (vars
       (service . int)))
*/

void
do_request_service(struct command *s,
		   struct lsh_object *x,
		   struct command_continuation *c,
		   struct exception_handler *e);

#define STATIC_REQUEST_SERVICE(service) \
{ STATIC_COMMAND(do_request_service), service } 

struct command *make_request_service(int service);

/* GABA:
   (class
     (name escape_info)
     (vars
       (escape . UINT8)
       ; Handlers, indexed by character.
       (dispatch array (object lsh_callback) "0x100")))
*/

struct escape_info *make_escape_info(UINT8 escape);
struct abstract_write *
make_handle_escape(struct escape_info *info, struct abstract_write *next);

struct channel_request *make_handle_exit_status(int *exit_code);
struct channel_request *make_handle_exit_signal(int *exit_code);

struct command *make_open_session_command(struct ssh_channel *session);


extern struct channel_request_command request_shell;
#define REQUEST_SHELL (&request_shell.super.super)

extern struct command client_io;
#define CLIENT_START_IO (&client_io.super)

struct ssh_channel *
make_client_session_channel(struct lsh_fd *in,
			    struct lsh_fd *out,
			    struct lsh_fd *err,
			    struct escape_info *escape,
			    UINT32 initial_window,
			    int *exit_status);

struct command *
make_exec_request(struct lsh_string *command);

struct command *
make_pty_request(struct interact *tty);


struct channel_open *
make_channel_open_x11(struct io_backend *backend);

struct command *
make_forward_x11(const char *display_string,
		 struct randomness *random);

struct client_x11_display *
make_client_x11_display(const char *display, struct lsh_string *fake);

/* GABA:
   (class
     (name client_options)
     (vars
       (backend object io_backend)

       ;; Used only by lsh, NULL for lshg.
       (random object randomness_with_poll)

       (tty object interact)

       ; -1 means default.
       (escape . int)
       
       ; For i/o exceptions 
       (handler object exception_handler)

       (exit_code . "int *")

       (not . int)
       (port . "char *")
       (remote object address_info)

       (local_user . "char *")
       (user . "char *")

       (with_remote_peers . int)
       
       ; -1 means default behaviour
       (with_pty . int)
       
       (with_x11 . int)
       
       ; Session modifiers
       (stdin_file . "const char *")
       (stdout_file . "const char *")
       (stderr_file . "const char *")

       ; fork() extra processes for handling stdio file-descriptors,
       ; to avoid setting them in non-blocking mode.
       (stdin_fork . int)
       (stdout_fork . int)
       (stderr_fork . int)

       ; True if the process's stdin or pty (respectively) has been used. 
       (used_stdin . int)
       (used_pty . int)
       (used_x11 . int)

       (start_shell . int)
       (remote_forward . int)
       (actions struct object_queue)))
*/

void
init_client_options(struct client_options *options,
		    struct io_backend *backend,
		    struct randomness_with_poll *random,
		    struct exception_handler *handler,
		    int *exit_code);

struct command *
client_add_action(struct client_options *options,
		  struct command *action);

int
client_parse_forward_arg(char *arg,
			 UINT32 *listen_port,
			 struct address_info **target);

extern struct command client_options2remote;
#define OPTIONS2REMOTE (&client_options2remote.super)

extern struct command client_options2actions;
#define OPTIONS2ACTIONS (&client_options2actions.super)

extern const struct argp client_argp;

#endif /* LSH_CLIENT_H_INCLUDED */
