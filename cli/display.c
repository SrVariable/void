/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:16:14 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/05/13 09:40:45 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"
extern struct termios	og_term;
extern struct termios	new_term;

static void	display_bob_is_a_lazy_man(void)
{
	display_message("Bob is a lazy man\n\n"\
"Descripción:\n"\
"El único trabajo de Bob es contar cuántas letras y números existen en una\n"\
"cadena de texto. Como es perezoso, os pide ayuda para que le creéis una función\n"\
"que le permita automatizar su trabajo.\n\n"\
"La definición de la función debe ser:\n"\
"size_t bob_is_a_lazy_man(const char *str)\n\n"\
"El nombre del archivo debe ser: bob_is_a_lazy_man.c\n"\
"Debe estar dentro del directorio bob_is_a_lazy_man\n");
}

static void	display_trolling_the_troll(void)
{
	display_message("Trolling the troll\n\n"\
"Descripción:\n"\
"Estoy enviando mensajes, pero parece que alguien los está interceptando y no\n"\
"se envían correctamente. He enviado unos cuantos mensajes más y tiene pinta de\n"\
"que solo hay problemas cuando envío el mensaje literal...\n\n"\
"Necesito que alguien me ayude a cifrar mis mensajes, sustituyendo las vocales\n"\
"por otro carácter que os pida.\n\n"\
"La definición de la función debe ser:\n"\
"char *trolling_the_troll(char *str, char new_char)\n\n"\
"El nombre del archivo debe ser: trolling_the_troll.c\n"\
"Debe estar dentro del directorio trolling_the_troll\n");
}

static void	display_ultramarines_vs_necrones(void)
{
	display_message("Ultramarines vs necrones\n"\
"Descripción\n"\
"Hay dos ejércitos que quieren luchar, sin embargo dicen que son pacifistas\n"\
"(no sé yo si creerles) así que no lo pueden hacer. Es por eso que necesitan simular\n"\
"una guerra y decidir quién ganaría. ¿Se podrá crear una función que lo consiga?\n"\
"La definición de la función debe ser:\n"\
"int ultramarines_vs_necrones(t_army *ultramarine, t_army *necrone)\n\n"\
"El nombre del archivo debe ser: ultramarines_vs_necrones.c\n"\
"Debe estar dentro del directorio ultramarines_vs_necrones\n");
}

static void	display_finish(void)
{
	display_message("\033[1;32m¡Enhorabuena, has completado todos los retos!\033[0m\n");
	exit(0);
}

void	display_challenge(int challenge, bool force_display)
{
	static int	current_challenge;

	if (current_challenge == challenge && !force_display)
		return ;
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
	current_challenge = challenge;
}

void	display_message_with_delay(const char *message)
{
	bool			is_sleep = true;

	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
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
	tcsetattr(STDIN_FILENO, TCSANOW, &og_term);
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
