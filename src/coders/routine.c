/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:08:20 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/26 15:45:16 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	*routine(void *arg)
{
	t_coder	*self;
	t_data	*data;

	self = (t_coder *) arg;
	data = self->data;
	while (self->compiles_left)
	{
		self->last_compile = get_time_ms(self->data);
		print_log(self, "compiling");
		usleep(data->time_to_compile * 1000);

		print_log(self, "debugging");
		usleep(data->time_to_debug * 1000);

		print_log(self, "refactoring");
		usleep(data->time_to_refactor * 1000);

		pthread_mutex_lock(&self->lock);
		self->compiles_left--;
		pthread_mutex_unlock(&self->lock);
	}
	return (NULL);
}
