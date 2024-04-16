/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example_trolling_the_troll.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:05:36 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 07:40:08 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "trolling_the_troll.h"
#include <stdio.h>

int	main(void)
{
	char	s[] = "42 es mucho más que un campus de programación. Es una filosofía, una revolución que viene a romper con todos los paradigmas de la educación donde los estudiantes son los protagonistas de su propio aprendizaje. ¿Y qué se aprende en 42? Se aprende a aprender. Su metodología gamificada permite a los estudiantes ir adquiriendo las competencias técnicas y transversales que están demandando las empresas. La tasa de empleabilidad de las personas que se forman en 42 es del 100%.";
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
