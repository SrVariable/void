/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bob_is_a_lazy_man.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 05:10:02 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 07:20:14 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#define SUCCESS printf("Test %d: \033[32mOK\n\033[0m", test_counter);
#define FAILURE do															\
{																			\
	printf("Test %d: \033[31mKO\n\033[0m", test_counter);					\
	exit(test_counter);														\
} while (0);

#include "bob_is_a_lazy_man.h"
#include <stdio.h>
#include <stdlib.h>

static int	test_counter = 1;

static void	empty_string(void)
{
	if (bob_is_a_lazy_man("") == 0)
		SUCCESS
	else
		FAILURE
	++test_counter;
}

static void	zero_alphanumerics(void)
{
	if (bob_is_a_lazy_man("|@#&&\"") == 0)
		SUCCESS
	else
		FAILURE
	++test_counter;
}

static void	one_alphanumerics(void)
{
	if (bob_is_a_lazy_man("1@&\"\'!!") == 1)
		SUCCESS
	else
		FAILURE
	++test_counter;
}

static void	three_alphanumerics(void)
{
	if (bob_is_a_lazy_man("123%") == 3)
		SUCCESS
	else
		FAILURE
	++test_counter;
}

static void	ten_alphanumerics(void)
{
	if (bob_is_a_lazy_man("abcdefghi@%\t\t\r0") == 10)
		SUCCESS
	else
		FAILURE
	++test_counter;
}

static void	one_hundred_alphanumerics(void)
{
	if (bob_is_a_lazy_man("\t\n\v\f\r!#$%&'*+,-./0123456789:;<=>?@ABCDEFGHI\
				JKL MNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~\t\n\v\
				\f\r!#$%&'*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ\
				[]^_`ab") == 100)
		SUCCESS
	else
		FAILURE
	++test_counter;
}

static void	test(void)
{
	empty_string();
	zero_alphanumerics();
	one_alphanumerics();
	three_alphanumerics();
	ten_alphanumerics();
	one_hundred_alphanumerics();
	printf("\033[1;32mCongratulations, all tests passed!\n\033[0m");
}

int	main(void)
{
	test();
	return (0);
}
