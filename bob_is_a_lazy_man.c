/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bob_is_a_lazy_man.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:02:28 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/28 20:20:36 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

size_t	count_alphanumerics(const char *str)
{
	size_t	counter;

	counter = 0;
	for (size_t i = 0; str[i]; ++i)
		if (ft_isalnum(str[i]))
			++counter;
	return (counter);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	for (int i = 1; i < argc; ++i)
		ft_printf("\"%s\" -> %u\n", argv[i], count_alphanumerics(argv[i]));
	return (0);
}
