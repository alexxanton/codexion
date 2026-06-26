/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:05:47 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/25 16:56:38 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

struct timeval	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time);
}

long	get_time_ms(t_data *data)
{
	struct timeval	current_time;
	long			time;
	long			micro;

	current_time = get_time();
	time = current_time.tv_sec - data->start_time.tv_sec;
	micro = current_time.tv_usec - data->start_time.tv_usec;
	return ((time * 1000) + (micro / 1000));
}
