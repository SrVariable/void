/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example_trolling_the_troll.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:05:36 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 08:57:42 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "trolling_the_troll.h"
#include <stdio.h>

int	main(void)
{
	char	s[] = "Hello World";
	char	c = '#';

	printf("Original string: %s\n", s);
	printf("Modified string: %s\n", trolling_the_troll(s, c));

	char	s2[] = "Hello world";
	char	c2 = '@';
	char	**dict = ft_split("world", ' ');

	if (!dict)
		return (0);
	printf("Bonus Original string: %s\n", s2);
	printf("Bonus Modified string: %s\n", trolling_the_troll_bonus(s2, c2, dict));
	ft_free(&dict, 2);
	return (0);
}
