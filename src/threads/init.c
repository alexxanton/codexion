/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:09:24 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/25 12:26:43 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->print_lock, NULL);
	while (i < data->number_of_coders)
	{
		pthread_mutex_init(&data->coders[i].lock, NULL);
		pthread_mutex_init(&data->dongles[i].lock, NULL);
		i++;
	}
}

void	init_threads(t_data *data)
{
	int		i;
	int		errors;

	errors = 0;
	i = 0;
	pthread_create(&data->monitor->thread_id, NULL, monitor_func, data);
	while (i < data->number_of_coders)
	{
		errors += pthread_create(
				&data->coders[i].thread_id, NULL, routine, &data->coders[i]);
		i++;
	}
}

void	join_threads(t_data *data)
{
	int		i;
	int		errors;

	errors = 0;
	i = 0;
	pthread_join(data->monitor->thread_id, NULL);
	while (i < data->number_of_coders)
	{
		errors += pthread_join(data->coders[i].thread_id, NULL);
		i++;
	}
}
