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

t_data	*parse_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data *));
	(void)argv;
	return (data);
}
