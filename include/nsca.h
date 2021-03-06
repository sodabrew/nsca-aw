/************************************************************************
 *
 * NSCA.H - NSCA Include File
 * Copyright (c) 1999-2009 Ethan Galstad (nagios@nagios.org)
 *
 * License:
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 ************************************************************************/

struct conn_entry {
	int sock;
	char ipaddr[IPv4_ADDRESS_SIZE];
	int port;
	struct sockaddr_in addr;
};

struct handler_entry {
	void (*handler)(struct conn_entry, void *);
	void *data;
	struct conn_entry conn_entry;
	time_t keepalive;
	int alive;
};

static void handle_events(void);
static void wait_for_connections(void);
static void handle_connection(struct conn_entry, void *);
static void accept_connection(struct conn_entry, void *);
static void handle_connection_read(struct conn_entry, void *);
static void install_child_handler(void);

static int process_arguments(int, char **);
static int read_config_file(char *);

int get_log_facility(char *);

static int open_command_file(struct conn_entry);
static void close_command_file(void);
static int write_checkresult_file(struct conn_entry, char *, char *, int, char *, time_t);
static int write_check_result(struct conn_entry, char *, char *, int, char *, time_t);

static int get_user_info(const char *, uid_t *);
static int get_group_info(const char *, gid_t *);
static int drop_privileges(const char *, uid_t, gid_t);
static void do_chroot(void);
static void do_exit(int);
static void free_memory(void);

static int write_pid_file(uid_t, gid_t);
static int remove_pid_file(void);

void sighandler(int);
