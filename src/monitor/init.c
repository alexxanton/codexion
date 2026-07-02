/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:09:00 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/26 16:34:32 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

static int	find_burnout(t_data *data)
{
	int		i;
	long	last_compile;

	i = 0;
	while (i < data->number_of_coders)
	{
		pthread_mutex_lock(&data->coders[i].lock);
		last_compile = data->coders[i].last_compile;
		pthread_mutex_unlock(&data->coders[i].lock);

		// todo: determine whether to use > or >=
		if (get_time_ms(data) > (last_compile + data->time_to_burnout))
			return (data->coders[i].id);
		i++;
	}
	return (0);
}

static bool	coders_active(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_coders)
	{
		if (!has_finished(&data->coders[i]))
			return (true);
		i++;
	}
	return (false);
}

void	*monitor_func(void *arg)
{
	int		burnout_id;
	t_data	*data;

	data = (t_data *) arg;
	while (coders_active(data))
	{
		burnout_id = find_burnout(data);
		if (burnout_id)
		{
			pthread_mutex_lock(&data->burnout_lock);
			data->run = false;
			pthread_mutex_unlock(&data->burnout_lock);
			print_log(&data->coders[burnout_id - 1], "burned out");
			break ;
		}
		usleep(100);
	}
	return (NULL);
}

t_monitor	*init_monitor(t_data *data)
{
	t_monitor	*monitor;

	monitor = malloc(sizeof(t_monitor));
	if (!monitor)
		return (NULL);
	(void)data;
	return (monitor);
}
