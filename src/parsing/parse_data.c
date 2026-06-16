/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:12:35 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/11 12:26:07 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

static t_scheduler	get_scheduler(char *type)
{
	if (strcmp(type, "fifo") == 0)
		return FIFO;
	else if (strcmp(type, "edf") == 0)
		return EDF;
	//printf("Unknown scheduler type `%s` defaulting to `fifo`\n", type);
	return FIFO;
}

t_data	*parse_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->number_of_coders = atoi(argv[1]);
	data->time_to_burnout = atoi(argv[2]);
	data->time_to_compile = atoi(argv[3]);
	data->time_to_debug = atoi(argv[4]);
	data->time_to_refactor = atoi(argv[5]);
	data->number_of_compiles_required = atoi(argv[6]);
	data->dongle_cooldown = atoi(argv[7]);
	data->scheduler = get_scheduler(argv[8]);
	return (data);
}
