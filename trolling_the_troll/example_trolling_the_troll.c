/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example_trolling_the_troll.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:05:36 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 22:17:05 by ribana-b         ###   ########.com      */
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
	return (0);
}
