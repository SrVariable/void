/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trolling_the_troll.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:57:45 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 12:14:58 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "trolling_the_troll.h"

char	*trolling_the_troll(char *str, char new_char)
{
	int	i;

	i = -1;
	if (!str)
		return (NULL);
	while (str[++i])
		if (ft_strchr("aeiouAEIOU", str[i]))
			str[i] = new_char;
	return (str);
}
