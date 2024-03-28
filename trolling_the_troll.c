/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trolling_the_troll.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:57:45 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/28 21:46:24 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

char	*replace_vowels(char *str, char new_vowel)
{
	int	i;

	i = -1;
	if (!str)
		return (NULL);
	while (str[++i])
		if (ft_strchr("aeiouAEIOU", str[i]))
			str[i] = new_vowel;
	return (str);
}

char	*replace_vowels_bonus(char *str, char new_vowel, char **dict)
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
						str[i] = new_vowel;
					++i;
				}
			}
		}
	}
	return (str);
}

int	main(int argc, char **argv)
{
	char	*dup;
	char	**dict;

	if (argc != 2 && argc != 3)
		return (1);
	else if (argc == 2)
	{
		dup = ft_strdup(argv[1]);
		ft_printf("%s\n", replace_vowels(dup, 'i'));
	}
	else if (argc == 3)
	{
		dup = ft_strdup(argv[1]);
		dict = ft_split(argv[2], ' ');
		ft_printf("%s\n", replace_vowels_bonus(dup, 'i', dict));
	}
	ft_free(&dup, 1);
	ft_free(&dict, 2);
	return (0);
}
