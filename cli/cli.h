/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:04:15 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/24 12:18:38 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

# define SLEEP_TIME 50000
# define clear_screen() printf("\033[H\033[J");

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>
# include <stdbool.h>
# include <stdlib.h>

enum e_error
{
	READING,
	INVALID_OPTION,
	INVALID_MESSAGE,
	INVALID_STRING,
	INVALID_CHALLENGE,
};

enum e_challenge
{
	BOB_IS_A_LAZY_MAN,
	TROLLING_THE_TROLL,
	ULTRAMARINES_VS_NECRONES,
	CHALLENGE_AMOUNT,
};

void	display_challenge(int challenge);
void	display_message_with_delay(const char *message);
void	display_message(const char *message);
void	display_error(const char *message);
void	tolower_str(char *str);
void	handle_error(int error_code);
void	command_help(void);
void	command_submit(int *challenge);
void	command_hint(int challenge);
void	command_exit(void);
void	handle_option(char *option, int *challenge);

#endif // CLI_H