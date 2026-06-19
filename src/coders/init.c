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

static t_coder	*allocate_coders(t_data *data)
{
	int			qty;
	t_coder		*coders;
	t_dongle	*dongles;

	qty = data->number_of_coders;
	coders = malloc(sizeof(t_coder) * qty);
	if (!coders)
		return (NULL);
	dongles = malloc(sizeof(t_dongle) * (qty + (qty == 1)));
	if (!dongles)
	{
		// todo: free coders
		return (NULL);
	}
	data->dongles = dongles;
	return (coders);
}

static int	fill_data(t_data *data, t_coder *coders)
{
	int	i;
	int	possible_errors;
	t_dongle	*dongles;

	dongles = data->dongles;
	possible_errors = 0;
	i = 0;
	while (i < data->number_of_coders)
	{
		coders[i].id = i + 1;
		coders[i].data = data;
		coders[i].compiles_left = data->number_of_compiles_required;
		coders[i].right_dongle = &dongles[i];
		coders[i].left_dongle = &dongles[(i - 1) % data->number_of_coders];
		possible_errors += pthread_create(
			&coders[i].thread_id, NULL, func, &coders[i]
		);
		i++;
	}
	return (possible_errors);
}

t_coder	*init_coders(t_data *data)
{
	int		possible_errors;
	t_coder	*coders;

	coders = allocate_coders(data);
	if (!coders)
		return (NULL);
	possible_errors = fill_data(data, coders);
	if (possible_errors > 0)
		return (NULL);
	join_threads(coders, data->number_of_coders);
	// todo: check for possible thread joining errors
	return (coders);
}
