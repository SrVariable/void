/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:47:59 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/24 12:17:18 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

static void	unlock_cli(void)
{
	static char	password[16];

	display_message_with_delay("Welcome to the \033[1;35mVoid \033[0mchallenges!\n"\
"Before beginning, enter the password: ");
	while (true)
	{
		if (!fgets(password, sizeof(password), stdin))
			handle_error(READING);
		if (atoi(password) != 0b101010)
		{
			display_message("Invalid password, try again!\n\
Enter the password: ");
		}
		else
			break;
	}
	display_message_with_delay("Good job, we hope you enjoy the challenges! c:\n");
	sleep(1);
	display_message("\033[H\033[J");
}

static void	cli(void)
{
	static char	option[16];
	int			challenge = BOB_IS_A_LAZY_MAN;

	unlock_cli();
	while (true)
	{
		display_challenge(challenge);
		if (!fgets(option, sizeof(option), stdin))
			handle_error(READING);
		option[strlen(option) - 1] = '\0';
		handle_option(option, &challenge);
	}
}

int	main(int argc, char **argv)
{
	cli();
	return (0);
}
