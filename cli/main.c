/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:47:59 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/25 10:08:08 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

static void	unlock_cli(void)
{
	static char	password[16];
	int			tries = 0;

	display_message_with_delay("Welcome to the \033[1;35mVoid \033[0mchallenges!\n"\
"Antes de empezar, introduce la contraseña: ");
	while (true)
	{
		if (!fgets(password, sizeof(password), stdin))
			handle_error(READING);
		++tries;
		if (tries == 0xA)
		{
			display_message_with_delay("Increíble, has llegado a los 10 \
intentos, en lugar de a los típicos 3, y tres dieces en binario es... ¡42!\n");
			sleep(1);
			break;
		}
		else if (tries == 05)
		{
			display_message("¡Contraseña incorrecta! Inténtalo de nuevo\n");
			display_message_with_delay("Una pistilla: Es la respuesta a todo\n");
			display_message("Introduce la contraseña: ");
		}
		else if (atoi(password) != 0b101010)
		{
			display_message("¡Contraseña incorrecta! Inténtalo de nuevo\n"\
"Introduce la contraseña: ");
		}
		else
			break;
	}
	display_message_with_delay("¡Buen trabajo! Esperemos que disfrutes de los retos c:");
	sleep(1);
	clear_screen();
}

static void	create_directory(int challenge)
{
	switch (challenge)
	{
		case BOB_IS_A_LAZY_MAN:
			system("./scripts/create_bialm.sh");
			break;
		case TROLLING_THE_TROLL:
			system("./scripts/create_ttt.sh");
			break;
		case ULTRAMARINES_VS_NECRONES:
			system("./scripts/create_uvn.sh");
			break;
		default:
			break;
	}
}

static void	cli(void)
{
	static char	option[16];
	int			challenge = BOB_IS_A_LAZY_MAN;

	unlock_cli();
	while (true)
	{
		display_challenge(challenge, false);
		create_directory(challenge);
		display_message(">> ");
		if (!fgets(option, sizeof(option), stdin))
			handle_error(READING);
		option[strlen(option) - 1] = '\0';
		handle_option(option, &challenge);
	}
}

int	main(void)
{
	cli();
	return (0);
}
