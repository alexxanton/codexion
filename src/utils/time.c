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

long	timestamp_ms(struct timeval time)
{
	return (time.tv_sec * 1000L + time.tv_usec / 1000);
}

long	get_time_ms(t_data *data)
{
	struct timeval	now;

	now = get_time();
	return (timestamp_ms(now) - timestamp_ms(data->start_time));
}
