/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:10:21 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/25 15:55:55 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	print_log(t_coder *coder, char *msg)
{
	pthread_mutex_lock(&coder->data->print_lock);
	printf("%ld %d %s\n", get_time_ms(coder->data), coder->id, msg);
	pthread_mutex_unlock(&coder->data->print_lock);
}
