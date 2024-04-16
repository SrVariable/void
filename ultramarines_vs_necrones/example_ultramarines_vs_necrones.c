/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example_ultramarines_vs_necrones.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 06:55:12 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 06:59:10 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "ultramarines_vs_necrones.h"
#include <time.h>

int	main(void)
{
	t_army ultramarine;
	t_army necrone;

	srand(time(NULL));
	initialise_info(&ultramarine, ULTRAMARINE);
	initialise_info(&necrone, NECRONE);
	ultramarines_vs_necrones(&ultramarine, &necrone);
	return (0);
}
