/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:09:37 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/25 12:10:08 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

bool	has_finished(t_coder *coder)
{
	bool	finished;

	pthread_mutex_lock(&coder->lock);
	finished = coder->compiles_left <= 0;
	pthread_mutex_unlock(&coder->lock);
	return (finished);
}
