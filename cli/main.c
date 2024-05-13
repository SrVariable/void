/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:47:59 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/05/13 11:45:26 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

struct termios	og_term;
struct termios	new_term;

char			path[PATH_SIZE];

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
	static int	current_challenge;

	if (current_challenge == challenge)
		return ;
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
	current_challenge = challenge;
}

static void	cli(void)
{
	static char	option[16];
	int			challenge = BOB_IS_A_LAZY_MAN;

	unlock_cli();
	while (true)
	{
		create_directory(challenge);
		display_challenge(challenge, false);
		display_message(">> ");
		if (!fgets(option, sizeof(option), stdin))
			handle_error(READING);
		option[strlen(option) - 1] = '\0';
		handle_option(option, &challenge);
	}
}

static void	get_path(void)
{
	int		slash_counter = 0;
	static char	temp[PATH_SIZE];
	int		j = 1;

	getcwd(path, PATH_SIZE);
	temp[0] = '~';
	for (int i = 0; path[i]; ++i)
	{
		if (path[i] == '/')
			++slash_counter;
		if (slash_counter >= 3)
			temp[j++] = path[i];
	}
	temp[strlen(temp) - 3] = '\0';
	memset(path, 0, strlen(path));
	memcpy(path, temp, strlen(temp));
}

int	main(void)
{
	tcgetattr(STDIN_FILENO, &og_term);
	new_term = og_term;
	new_term.c_lflag &= ~(ECHO);
	get_path();
	cli();
	return (0);
}
