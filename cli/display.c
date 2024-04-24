/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:16:14 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/24 12:15:46 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

static void	display_bob_is_a_lazy_man(void)
{
	display_message("Bob is a lazy man\n");
}

static void	display_trolling_the_troll(void)
{
	display_message("Trolling the troll\n");
}

static void	display_ultramarines_vs_necrones(void)
{
	display_message("Ultramarines vs necrones\n");
}

static void	display_finish(void)
{
	display_message("Congratulations, you solved the challenges!\n");
	exit(0);
}

void	display_challenge(int challenge)
{
	switch (challenge)
	{
		case BOB_IS_A_LAZY_MAN:
			display_bob_is_a_lazy_man();
			break;
		case TROLLING_THE_TROLL:
			display_trolling_the_troll();
			break;
		case ULTRAMARINES_VS_NECRONES:
			display_ultramarines_vs_necrones();
			break;
		case CHALLENGE_AMOUNT:
			display_finish();
			break;
		default:
			handle_error(INVALID_CHALLENGE);
			break;
	}
}

void	display_message_with_delay(const char *message)
{
	bool		is_sleep = true;

	for (int i = 0; message[i]; ++i)
	{
		write(1, &message[i], 1);
		if (message[i] == '\033')
			is_sleep = false;
		if (is_sleep)
			usleep(SLEEP_TIME);
		else
			if (message[i] == 'm')
				is_sleep = true;
	}
}

void	display_error(const char *message)
{
	if (!message)
		handle_error(INVALID_MESSAGE);
	write(2, "[ERROR] ", 8);
	write(2, message, strlen(message));
}

void	display_message(const char *message)
{
	if (!message)
		handle_error(INVALID_MESSAGE);
	write(1, message, strlen(message));
}
