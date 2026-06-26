/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:34:41 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/25 15:55:38 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_coder	t_coder;

typedef enum e_scheduler_types
{
	FIFO,
	EDF
}	t_scheduler;

typedef enum e_coder_states
{
	WAIT,
	COMPILE,
	DEBUG,
	REFACTOR,
	BURNED_OUT
}	t_state;

typedef struct s_monitor
{
	pthread_t	thread_id;
}				t_monitor;

typedef struct s_dongle
{
	pthread_mutex_t	lock;
	pthread_cond_t	available;
	bool			is_taken;
	long			cooldown;
}					t_dongle;

typedef struct s_data
{
	int				number_of_coders;
	int				number_of_compiles_required;
	struct timeval	start_time;
	long			time_to_burnout;
	long			time_to_compile;
	long			time_to_debug;
	long			time_to_refactor;
	long			dongle_cooldown;
	t_scheduler		scheduler;
	t_dongle		*dongles;
	t_coder			*coders;
	t_monitor		*monitor;
	pthread_mutex_t	print_lock;
}					t_data;

typedef struct s_coder
{
	int				id;
	int				compiles_left;
	pthread_t		thread_id;
	t_data			*data;
	t_dongle		*right_dongle;
	t_dongle		*left_dongle;
	t_state			state;
	pthread_mutex_t	lock;
}					t_coder;

typedef struct s_request
{
	int		id;
	long	priority;
}			t_request;

typedef struct s_heap
{
	t_request	*requests;
}				t_heap;

t_monitor	*init_monitor(t_data *data);
bool		has_finished(t_coder *coder);

void		init_mutexes(t_data *data);
void		init_threads(t_data *data);
void		join_threads(t_data *data);
void		*routine(void *arg);
void		*monitor_func(void *arg);

t_data		*parse_data(char **argv);
t_coder		*init_coders(t_data *data);
void		begin_simulation(t_data *data);
void		print_log(t_coder *coder, char *msg);
long		get_time_ms(t_data *data);
struct timeval	get_time(void);

#endif
