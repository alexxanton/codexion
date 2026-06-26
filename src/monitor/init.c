/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:09:00 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/25 13:36:59 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	*monitor_func(void *arg)
{
	t_data	*data;
	t_coder	*coder;

	data = (t_data *) arg;
	coder = &data->coders[0];
	while (!has_finished(coder))
	{
		//pthread_mutex_lock(&coder->lock);
		//printf("%d\n", coder->compiles_left);
		//pthread_mutex_unlock(&coder->lock);
		usleep(30000);
	}
	(void)data;
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
