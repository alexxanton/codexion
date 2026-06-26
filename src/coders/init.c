/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:29:48 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/26 16:30:24 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

static t_coder	*allocate_coders(t_data *data)
{
	int			qty;
	t_coder		*coders;
	t_dongle	*dongles;

	qty = data->number_of_coders;
	coders = malloc(sizeof(t_coder) * qty);
	if (!coders)
		return (NULL);
	dongles = malloc(sizeof(t_dongle) * qty);
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
	int			i;
	int			n_coders;
	int			possible_errors;
	t_dongle	*dongles;

	n_coders = data->number_of_coders;
	dongles = data->dongles;
	possible_errors = 0;
	i = 0;
	while (i < n_coders)
	{
		coders[i].id = i + 1;
		coders[i].data = data;
		coders[i].compiles_left = data->number_of_compiles_required;
		coders[i].last_compile = 0;
		coders[i].right_dongle = &dongles[i];
		coders[i].left_dongle = &dongles[(i + n_coders - 1) % n_coders];
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
	return (coders);
}
