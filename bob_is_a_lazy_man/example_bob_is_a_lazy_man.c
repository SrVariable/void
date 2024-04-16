/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example_bob_is_a_lazy_man.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:01:15 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/16 07:04:39 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "bob_is_a_lazy_man.h"
#include <stdio.h>

int	main(void)
{
	const char	*s = "Hell0 W@rld";
	printf("%s: %ld\n", s, bob_is_a_lazy_man(s));
	return (0);
}
