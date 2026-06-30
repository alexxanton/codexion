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

static void	execute_task(t_coder *coder, long time)
{
	char	*msg;

	msg = "";
	coder->state++;
	if (coder->state == COMPILE)
		msg = "is compiling";
	else if (coder->state == DEBUG)
		msg = "is debugging";
	else if (coder->state == REFACTOR)
		msg = "is refactoring";
	print_log(coder, msg);
	usleep(time * 1000);
	if (coder->state >= REFACTOR)
		coder->state = WAIT;
}

void	*routine(void *arg)
{
	t_coder	*self;
	t_data	*data;

	self = (t_coder *) arg;
	data = self->data;
	while (self->compiles_left)
	{
		pthread_mutex_lock(&self->lock);
		self->last_compile = get_time_ms(self->data);
		pthread_mutex_unlock(&self->lock);

		execute_task(self, data->time_to_compile);
		execute_task(self, data->time_to_debug);
		execute_task(self, data->time_to_refactor);

		pthread_mutex_lock(&self->lock);
		self->compiles_left--;
		pthread_mutex_unlock(&self->lock);
	}
	return (NULL);
}
