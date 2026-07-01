/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanton-a <aanton-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:10:21 by aanton-a          #+#    #+#             */
/*   Updated: 2026/06/25 15:55:55 by aanton-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

#define COMPILE		"⚡ \033[38;5;82m"
#define DEBUG		"🐛 \033[38;5;48m"
#define REFACTOR	"🛠️ \033[38;5;39m"
#define DONGLE		"🔌 \033[38;5;214m"
#define RED			"🔥 \033[31m"
#define RESET		"\033[0m"
#define WHITE		"\033[37m"
#define BLUE		"\033[94m"
#define GRAY		"\033[90m"

void	print_log(t_coder *coder, char *msg)
{
    const char *msg_color = WHITE;

	if (strstr(msg, "compiling"))
		msg_color = COMPILE;
	else if (strstr(msg, "debugging"))
		msg_color = DEBUG;
	else if (strstr(msg, "refactoring"))
		msg_color = REFACTOR;
	else if (strstr(msg, "burn out"))
		msg_color = RED;
	else if (strstr(msg, "dongle"))
		msg_color = DONGLE;

	pthread_mutex_lock(&coder->data->burnout_lock);
	pthread_mutex_lock(&coder->data->print_lock);
	if (coder->data->run)
	{
		printf(
				GRAY "%-8ld "
				BLUE "ID: %-5d "
				"%s%s"
				RESET "\n",
				get_time_ms(coder->data),
				coder->id,
				msg_color,
				msg
			  );
	}
	pthread_mutex_unlock(&coder->data->print_lock);
	pthread_mutex_unlock(&coder->data->burnout_lock);
}

/*
void	print_log(t_coder *coder, char *msg)
{

	pthread_mutex_lock(&coder->data->burnout_lock);
	pthread_mutex_lock(&coder->data->print_lock);
	if (coder->data->run)
		printf("%ld %d %s\n", get_time_ms(coder->data), coder->id, msg);
	pthread_mutex_unlock(&coder->data->print_lock);
	pthread_mutex_unlock(&coder->data->burnout_lock);
}
*/
