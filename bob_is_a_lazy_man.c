/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bob_is_a_lazy_man.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:02:28 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/28 21:40:23 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

size_t	count_alphanumerics(const char *str)
{
	size_t	counter;
	int		i;

	if (!str)
		return (0);
	counter = 0;
	i = -1;
	while (str[++i])
		if (ft_isalnum(str[i]))
			++counter;
	return (counter);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (1);
	i = 0;
	while (++i < argc)
		ft_printf("\"%s\" -> %u\n", argv[i], count_alphanumerics(argv[i]));
	return (0);
}
