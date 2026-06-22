/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:34:41 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/17 16:07:58 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <string.h>

typedef enum e_scheduler_types
{
	FIFO,
	EDF
}	t_scheduler;

typedef enum	e_coder_states
{
	WAIT,
	COMPILE,
	DEBUG,
	REFACTOR,
	BURNED_OUT
}	t_state;

typedef struct s_dongle
{
}	t_dongle;

typedef struct s_data
{
	int			number_of_coders;
	int			number_of_compiles_required;
	long		start_time;
	long		time_to_burnout;
	long		time_to_compile;
	long		time_to_debug;
	long		time_to_refactor;
	long		dongle_cooldown;
	t_scheduler	scheduler;
	t_dongle	*dongles;
}				t_data;

typedef struct s_coder
{
	int			id;
	int			compiles_left;
	pthread_t	thread_id;
	t_data		*data;
	t_dongle	*right_dongle;
	t_dongle	*left_dongle;
	t_state		state;
}				t_coder;

typedef struct	s_heap
{
	int	id;
}		t_heap;

t_data	*parse_data(char **argv);
t_coder	*init_coders(t_data *data);
void	begin_simulation(t_data *data);

#endif
