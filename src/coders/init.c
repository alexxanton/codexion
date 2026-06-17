/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:29:48 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/17 16:20:56 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	*func()
{
	printf("e");
	return (NULL);
}

t_coder	*init_coders(t_data *data)
{
	int		i;
	t_coder	*coders;

	i = 0;
	coders = malloc(sizeof(t_coder) * data->number_of_coders);
	if (!coders)
		return (NULL);
	while (i < data->number_of_coders)
	{
		coders[i].id = i + 1;
		coders[i].data = data;
		pthread_create(&coders[i].thread_id, NULL, func, NULL);
		i++;
	}
	i = 0;
	while (i < data->number_of_coders)
	{
		pthread_join(coders[i].thread_id, NULL);
		i++;
	}
	return coders;
}
