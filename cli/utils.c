/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:17:12 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/24 12:07:35 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

void	tolower_str(char *str)
{
	if (!str)
		handle_error(INVALID_STRING);
	for (int i = 0; str[i]; ++i)
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
}
