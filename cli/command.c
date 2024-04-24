/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:14:27 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/24 12:19:15 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

void	command_help(void)
{
	display_message("These are the commands available:\n"\
"\thelp - Show help information\n"\
"\tsubmit - Submit your exercise to run the tests\n"\
"\thint - Display a hint for the current exercise\n"\
"\texit - Exit the CLI\n");
}

void	command_exit(void)
{
	display_message("Bye bye\n");
	exit(0);
}

void	command_submit(int *challenge)
{
	++(*challenge);
	return ;
}

void	command_hint(int challenge)
{
	return ;
}
