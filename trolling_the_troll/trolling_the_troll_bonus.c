/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trolling_the_troll_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:15:04 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 12:55:12 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "trolling_the_troll_bonus.h"

char	*trolling_the_troll(char *str, char new_char, char **dict)
{
	int	i;
	int	j;

	if (!dict || !str)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (dict[++j])
		{
			if (ft_strncmp(&str[i], dict[j], ft_strlen(dict[j])) == 0)
			{
				while (str[i] && str[i] != ' ')
				{
					if (ft_strchr("aeiouAEIOU", str[i]))
						str[i] = new_char;
					++i;
				}
			}
		}
	}
	return (str);
}
