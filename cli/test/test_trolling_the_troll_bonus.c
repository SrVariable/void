/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_trolling_the_troll_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 05:10:02 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/25 12:22:13 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#define SUCCESS printf("Test %d: \033[32mOK\033[0m\n", test_counter);
#define FAILURE(E, O) do													\
{																			\
	printf("Test %d: \033[31mKO\033[0m\n", test_counter);					\
	printf("Expected: %s\n", E);											\
	printf("Your output: %s\n", O);											\
	ft_free(&dict, 2);														\
	exit(test_counter);														\
} while (0);

#include "trolling_the_troll_bonus.h"
#include <stdio.h>
#include <string.h>

static int	test_counter = 1;

static void	empty_string(void)
{
	char		s[] = "";
	char		c = '!';
	char		**dict = ft_split("Nothing to remove lol", ' ');
	if (!dict)
		return ;
	char		*output = trolling_the_troll(s, c, dict);
	const char	*expected = "";

	if (strcmp(expected, output) == 0)
		SUCCESS
	else
		FAILURE(expected, output);
	++test_counter;
	ft_free(&dict, 2);
}

static void	hello_world(void)
{
	char		s[] = "Hello World I'm here";
	char		c = '!';
	char		**dict = ft_split("World here", ' ');
	if (!dict)
		return ;
	char		*output = trolling_the_troll(s, c, dict);
	const char	*expected = "Hello W!rld I'm h!r!";

	if (strcmp(expected, output) == 0)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	lorem_ipsum(void)
{
	char	s[] = "Lorem ipsum dolor sit amet";
	char	c = '.';
	char		**dict = ft_split("Lorem ipsum", ' ');
	if (!dict)
		return ;
	char		*output = trolling_the_troll(s, c, dict);
	const char	*expected = "L.r.m .ps.m dolor sit amet";

	if (strcmp(expected, output) == 0)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	forty_two(void)
{
	char		s[] = "42 es mucho más que un campus de programación. Es una \
				filosofía, una revolución que viene a romper con todos \
				los paradigmas de la educación donde los estudiantes \
				son los protagonistas de su propio aprendizaje. ¿Y qué \
				se aprende en 42? Se aprende a aprender. Su metodología \
				gamificada permite a los estudiantes ir adquiriendo las \
				competencias técnicas y transversales que están demandando \
				las empresas. La tasa de empleabilidad de las personas que \
				se forman en 42 es del 100%.";
	char		c = '-';
	char		**dict = ft_split("aprende estudiantes", ' ');
	if (!dict)
		return ;
	char		*output = trolling_the_troll(s, c, dict);
	const char	*expected = "42 es mucho más que un campus de programación. Es una \
				filosofía, una revolución que viene a romper con todos \
				los paradigmas de la educación donde los -st-d--nt-s \
				son los protagonistas de su propio aprendizaje. ¿Y qué \
				se -pr-nd- en 42? Se -pr-nd- a -pr-nd-r. Su metodología \
				gamificada permite a los -st-d--nt-s ir adquiriendo las \
				competencias técnicas y transversales que están demandando \
				las empresas. La tasa de empleabilidad de las personas que \
				se forman en 42 es del 100%.";

	if (strcmp(expected, output) == 0)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	test(void)
{
	empty_string();
	hello_world();
	lorem_ipsum();
	forty_two();
}

int	main(void)
{
	test();
	return (0);
}
