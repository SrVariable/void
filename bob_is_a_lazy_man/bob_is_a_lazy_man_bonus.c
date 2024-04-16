/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bob_is_a_lazy_man_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:02:28 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 23:40:14 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "bob_is_a_lazy_man_bonus.h"

size_t	bob_is_a_lazy_man(const char *str)
{
	size_t	counter;
	int		i;
	int		spaces;
	int		tabs;

	if (!str)
		return (0);
	counter = 0;
	spaces = 0;
	tabs = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_isalnum(str[i]))
			++counter;
		else if (str[i] == ' ')
			++spaces;
		else if (str[i] == '\t')
			++tabs;
	}
	if (counter && spaces && tabs)
		return (counter + spaces + tabs);
	return (counter);
}
