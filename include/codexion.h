/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:34:41 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/11 15:42:33 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>

typedef enum e_scheduler_types
{
	FIFO,
	EDF
}	t_scheduler;

typedef struct s_data
{
	long		number_of_coders;
	long long	time_to_burnout;
	long long	time_to_compile;
	long long	time_to_debug;
	long long	time_to_refactor;
	long		number_of_compiles_required;
	long		dongle_cooldown;
	t_scheduler	scheduler;
}				t_data;

typedef struct s_dongle
{
}		t_dongle;

typedef struct s_coder
{
	int			id;
	pthread_t	thread_id;
	t_data		*data;
	t_dongle	*right_dongle;
	t_dongle	*left_dongle;
}				t_coder;

t_data	*parse_data(char **argv);
void	begin_simulation(t_data *data);

#endif
