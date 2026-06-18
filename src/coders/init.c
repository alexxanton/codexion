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

void	*func(void *arg)
{
	t_coder	*self;

	self = (t_coder *) arg;
	//printf("%d\n", self->compiles_left);
	while (self->compiles_left)
	{
		printf("Coder <%d>: %d\n", self->id, self->compiles_left);
		self->compiles_left--;
	}
	return (NULL);
}

t_coder	*init_coders(t_data *data)
{
	int		i;
	int		possible_errors;
	t_coder	*coders;

	coders = malloc(sizeof(t_coder) * data->number_of_coders);
	if (!coders)
		return (NULL);
	possible_errors = 0;
	i = 0;
	while (i < data->number_of_coders)
	{
		coders[i].id = i + 1;
		coders[i].data = data;
		coders[i].compiles_left = data->number_of_compiles_required;
		possible_errors += pthread_create(
			&coders[i].thread_id, NULL, func, &coders[i]
		);
		i++;
	}
	if (possible_errors > 0)
	{
		printf("eee%d\n", possible_errors);
		return (NULL);
	}
	i = 0;
	while (i < data->number_of_coders)
	{
		pthread_join(coders[i].thread_id, NULL);
		i++;
	}
	return coders;
}
