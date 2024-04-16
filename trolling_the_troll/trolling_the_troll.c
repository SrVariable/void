/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trolling_the_troll.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:57:45 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 06:13:17 by ribana-b         ###   ########.com      */
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

char	*trolling_the_troll_bonus(char *str, char new_char, char **dict)
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
				while (str[i + 1] && str[i] != ' ')
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
