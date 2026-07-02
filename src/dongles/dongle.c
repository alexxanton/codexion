/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:50:20 by aanton-a          #+#    #+#             */
/*   Updated: 2026/07/02 14:44:50 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	take_dongle(t_coder *coder, t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->lock);
	//if (dongle->is_taken)
	//{
	//	pthread_mutex_unlock(&dongle->lock);
	//	return ;
	//}
	while (dongle->is_taken)
		pthread_cond_wait(&dongle->available, &dongle->lock);
	dongle->is_taken = true;
	pthread_mutex_unlock(&dongle->lock);
	print_log(coder, "has taken a dongle");
}

void	release_dongle(t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->lock);
	dongle->is_taken = false;
	pthread_cond_signal(&dongle->available);
	pthread_mutex_unlock(&dongle->lock);
}
