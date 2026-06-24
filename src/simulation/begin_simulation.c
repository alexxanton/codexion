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

void	begin_simulation(t_data *data)
{
	t_coder		*coders;
	t_monitor	*monitor;

	coders = init_coders(data);
	monitor = init_monitor(data);
	if (!coders)
	{
		printf("Failed to allocate memory\n");
		return ;
	}
	data->coders = coders;
	data->monitor = monitor;
	init_mutexes(data);
	init_threads(data);
	join_threads(data);
	// todo: check for possible thread joining errors
}
