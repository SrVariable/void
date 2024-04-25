/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bob_is_a_lazy_man_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 05:10:02 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/25 12:22:04 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#define SUCCESS printf("Test %d: \033[32mOK\033[0m\n", test_counter);
#define FAILURE(E ,O) do													\
{																			\
	printf("Test %d: \033[31mKO\033[0m\n", test_counter);					\
	printf("Expected: %ld\n", E);											\
	printf("Your output: %ld\n", O);										\
	exit(test_counter);														\
} while (0);

#include "bob_is_a_lazy_man_bonus.h"
#include <stdio.h>
#include <stdlib.h>

static int	test_counter = 1;

static void	empty_string(void)
{
	const char	*s = "";
	size_t		output = bob_is_a_lazy_man(s);
	size_t		expected = 0;

	if (expected == output)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}
static void	zero_alphanumerics(void)
{
	const char	*s = "|@#&&\"";
	size_t		output = bob_is_a_lazy_man(s);
	size_t		expected = 0;

	if (expected == output)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	zero_alphanumerics_one_tab_one_space(void)
{
	const char	*s = "\"\"@@!!# .-\t";
	size_t		output = bob_is_a_lazy_man(s);
	size_t		expected = 0;

	if (expected == output)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	zero_alphanumerics_zero_tabs_one_space(void)
{
	const char	*s = "@&%!.. .-";
	size_t		output = bob_is_a_lazy_man(s);
	size_t		expected = 0;

	if (expected == output)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	one_alphanumeric(void)
{
	const char	*s = ".@&\"\'a!!";
	size_t		output = bob_is_a_lazy_man(s);
	size_t		expected = 1;

	if (expected == output)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	one_alphanumeric_one_tab_one_space(void)
{
	const char	*s = ">>)>.<(<<a- -\t..";
	size_t		output = bob_is_a_lazy_man(s);
	size_t		expected = 3;

	if (expected == output)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	three_alphanumerics(void)
{
	const char	*s = "123%";
	size_t		output = bob_is_a_lazy_man(s);
	size_t		expected = 3;

	if (expected == output)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	ten_alphanumerics(void)
{
	const char	*s = "abcdefghi@%\t\t\r0";
	size_t		output = bob_is_a_lazy_man(s);
	size_t		expected = 10;

	if (expected == output)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	one_hundred_alphanumerics(void)
{
	const char	*s = "\t\n\v\f\r!#$%&'*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQ\
RSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~\t\n\v\f\r!#$%&'*+,-./0123456789:;\
<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`ab";
	size_t		output = bob_is_a_lazy_man(s);
	size_t		expected = 100;

	if (expected == output)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	test(void)
{
	empty_string();
	zero_alphanumerics();
	zero_alphanumerics_one_tab_one_space();
	zero_alphanumerics_zero_tabs_one_space();
	one_alphanumeric();
	one_alphanumeric_one_tab_one_space();
	three_alphanumerics();
	ten_alphanumerics();
	one_hundred_alphanumerics();
}

int	main(void)
{
	test();
	return (0);
}
