/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:15:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/24 13:07:20 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

void	handle_error(int error_code)
{
	if (error_code == READING)
		display_error("Rarete, hubo un error leyendo\n");
	else if (error_code == INVALID_OPTION)
		display_error("Rarete, la opción se volvió inválida\n");
	else if (error_code == INVALID_MESSAGE)
		display_error("Rarete, el mensaje se volvió inválido\n");
	else if (error_code == INVALID_STRING)
		display_error("Rarete, el string se volvió inválido\n");
	exit(error_code);
}

void	handle_option(char *option, int *challenge)
{
	if (!option)
		handle_error(INVALID_OPTION);
	tolower_str(option);
	if (strncmp(option, "help", 4) == 0)
		command_help();
	else if (strncmp(option, "challenge", 9) == 0)
		display_challenge(*challenge, true);
	else if (strncmp(option, "submit", 6) == 0)
		command_submit(challenge);
	else if (strncmp(option, "hint", 4) == 0)
		command_hint(*challenge);
	else if (strncmp(option, "exit", 4) == 0)
		command_exit();
	else
		display_message("Comando inválido, escribe \"help\" para ver los comandos disponibles\n");
}
