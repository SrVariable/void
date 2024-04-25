/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_trolling_the_troll.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 05:10:02 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/25 09:23:03 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#define SUCCESS printf("Test %d: \033[32mOK\033[0m\n", test_counter);
#define FAILURE(E, O) do													\
{																			\
	printf("Test %d: \033[31mKO\033[0m\n", test_counter);					\
	printf("Expected: %s\n", E);											\
	printf("Your output: %s\n", O);											\
	exit(test_counter);														\
} while (0);

#include "trolling_the_troll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	test_counter = 1;

static void	empty_string(void)
{
	char		s[] = "";
	char		c = '!';
	char		*output = trolling_the_troll(s, c);
	const char	*expected = "";

	if (strcmp(expected, output) == 0)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	hello_world(void)
{
	char		s[] = "Hello World";
	char		c = '!';
	char		*output = trolling_the_troll(s, c);
	const char	*expected = "H!ll! W!rld";

	if (strcmp(expected, output) == 0)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	lorem_ipsum(void)
{
	char		s[] = "Lorem ipsum";
	char		c = '.';
	char		*output = trolling_the_troll(s, c);
	const char	*expected = "L.r.m .ps.m";

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
	char		c = '#';
	char		*output = trolling_the_troll(s, c);
	const char	*expected = "42 #s m#ch# más q## #n c#mp#s d# pr#gr#m#c#ón. #s #n# \
f#l#s#fí#, #n# r#v#l#c#ón q## v##n# # r#mp#r c#n t#d#s \
l#s p#r#d#gm#s d# l# #d#c#c#ón d#nd# l#s #st#d##nt#s \
s#n l#s pr#t#g#n#st#s d# s# pr#p## #pr#nd#z#j#. ¿Y q#é \
s# #pr#nd# #n 42? S# #pr#nd# # #pr#nd#r. S# m#t#d#l#gí# \
g#m#f#c#d# p#rm#t# # l#s #st#d##nt#s #r #dq##r##nd# l#s \
c#mp#t#nc##s técn#c#s y tr#nsv#rs#l#s q## #stán d#m#nd#nd# \
l#s #mpr#s#s. L# t#s# d# #mpl##b#l#d#d d# l#s p#rs#n#s q## \
s# f#rm#n #n 42 #s d#l 100%.";

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
	printf("\033[1;32mCongratulations, all tests passed!\n\033[0m");
}

int	main(void)
{
	test();
	return (0);
}
