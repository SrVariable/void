/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example_trolling_the_troll_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:05:36 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 22:21:15 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "trolling_the_troll_bonus.h"
#include <stdio.h>

int	main(void)
{
	char	s[] = "Hello World";
	char	c = '#';
	char	**dict = ft_split("World", ' ');
	if (!dict)
		return (1);

	printf("Original string: %s\n", s);
	printf("Modified string: %s\n", trolling_the_troll(s, c, dict));
	ft_free(&dict, 2);
	return (0);
}
