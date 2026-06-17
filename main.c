/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:07:40 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/17 11:34:23 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 9)
	{
		printf("All the following arguments must to be provided:\n");
		printf("\tnumber_of_coders time_to_burnout time_to_compile\n");
		printf("\ttime_to_debug time_to_refactor ");
		printf("number_of_compiles_required\n\tdongle_cooldown scheduler\n");
		return (1);
	}
	data = parse_data(argv);
	if (!data)
	{
		printf("Error parsing arguments!\n");
		return (1);
	}
	begin_simulation(data);
}
