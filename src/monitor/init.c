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

static bool	burnout_found(t_data *data)
{
	int		i;
	long	last_compile;

	i = 0;
	while (i < data->number_of_coders)
	{
		last_compile = data->coders[i].last_compile;
		if (get_time_ms(data) >= (last_compile + data->time_to_burnout))
		{
			print_log(&data->coders[i], "burn out");
			return (true);
		}
		i++;
	}
	return (false);
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
	t_data	*data;

	data = (t_data *) arg;
	while (coders_active(data))
	{
		if (burnout_found(data))
		{
			//exit(0);
			break ;
		}
		usleep(1000);
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
