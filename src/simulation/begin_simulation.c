/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:35:28 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/17 15:56:43 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

static void	join_threads(t_coder *coders, int n_coders)
{
	int		i;
	int		possible_errors;

	possible_errors = 0;
	i = 0;
	while (i < n_coders)
	{
		possible_errors += pthread_join(coders[i].thread_id, NULL);
		i++;
	}
}

void	begin_simulation(t_data *data)
{
	t_coder		*coders;
	t_monitor	*monitor;

	coders = init_coders(data);
	monitor = init_monitor(data);
	data->coders = coders;
	pthread_join(monitor->thread_id, NULL);
	// todo: check for possible thread joining errors
	join_threads(coders, data->number_of_coders);
	if (!coders)
	{
		printf("Failed to allocate memory\n");
		return ;
	}
}
