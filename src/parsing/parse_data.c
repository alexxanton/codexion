/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:12:35 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/17 14:36:15 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

static bool	is_numeric(char *str)
{
	if (!*str)
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

static bool	valid_args(char **argv)
{
	int	count;
	int	len;

	count = 0;
	while (*argv++ && count++ < 7)
	{
		if (!is_numeric(*argv))
		{
			printf("Argument #%d `%s` must only be numeric.\n", count, *argv);
			return (false);
		}
		while (**argv == '0')
			(*argv)++;
		len = strlen(*argv);
		if (len > 10 || (len == 10 && strcmp(*argv, "2147483647") > 0))
		{
			printf("The number `%s` overflows so it's invalid.\n", *argv);
			return (false);
		}
	}
	if (strcmp(*argv, "fifo") != 0 && strcmp(*argv, "edf") != 0)
	{
		printf("Unknown scheduler type `%s`\n", *argv);
		return (false);
	}
	return (true);
}

static t_scheduler	get_scheduler(char *type)
{
	if (strcmp(type, "fifo") == 0)
		return (FIFO);
	else if (strcmp(type, "edf") == 0)
		return (EDF);
	return (FIFO);
}

t_data	*parse_data(char **argv)
{
	t_data	*data;

	if (!valid_args(argv))
		return (NULL);
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
