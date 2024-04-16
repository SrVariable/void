/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bob_is_a_lazy_man.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:02:28 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 05:39:07 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "bob_is_a_lazy_man.h"

size_t	bob_is_a_lazy_man(const char *str)
{
	size_t	counter;
	int		i;

	if (!str)
		return (0);
	counter = 0;
	i = -1;
	while (str[++i])
		if (ft_isalnum(str[i]))
			++counter;
	return (counter);
}
