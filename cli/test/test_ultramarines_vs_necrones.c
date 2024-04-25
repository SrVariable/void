/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ultramarines_vs_necrones.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 05:10:02 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/25 12:19:00 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#define SUCCESS printf("Test %d: \033[32mOK\033[0m\n", test_counter);
#define FAILURE(E, O) do													\
{																			\
	printf("Test %d: \033[31mKO\033[0m\n", test_counter);					\
	printf("Expected: %d\n", E);											\
	printf("Your output: %d\n", O);											\
	exit(test_counter);														\
} while (0);

#include "ultramarines_vs_necrones.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

static int	test_counter = 1;

static void	necrone_win(void)
{
	t_army	ultramarine;
	t_army	necrone;
	int		output;
	int		expected = NECRONE;

	initialise_info(&ultramarine, ULTRAMARINE);
	initialise_info(&necrone, NECRONE);
	ultramarine.soldier[0].attack_damage = 1;
	ultramarine.soldier[0].health_points = 50;
	necrone.soldier[0].attack_damage = 10;
	necrone.soldier[0].health_points = 50;
	output = ultramarines_vs_necrones(&ultramarine, &necrone);
	if (expected == NECRONE)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	ultramarine_win(void)
{
	t_army	ultramarine;
	t_army	necrone;
	int		output;
	int		expected = ULTRAMARINE;

	initialise_info(&ultramarine, ULTRAMARINE);
	initialise_info(&necrone, NECRONE);
	ultramarine.soldier[0].attack_damage = 25;
	ultramarine.soldier[0].health_points = 50;
	necrone.soldier[0].attack_damage = 10;
	necrone.soldier[0].health_points = 50;
	output = ultramarines_vs_necrones(&ultramarine, &necrone);
	if (expected == output)
		SUCCESS
	else
		FAILURE(expected, output)
	++test_counter;
}

static void	test(void)
{
	necrone_win();
	ultramarine_win();
}

int	main(void)
{
	srand(time(NULL));
	test();
	return (0);
}
