/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:03:52 by ribana-b          #+#    #+#             */
/*   Updated: 2024/03/24 14:41:29 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

int	ft_putstr_fd(const char *str, int fd)
{
	int	bytes_written;
	int	counter;
	int	success;

	if (fd < 0)
		return (-1);
	if (!str)
	{
		success = write(fd, "(null)", 6);
		if (success < 0)
			return (-1);
		return (success);
	}
	counter = 0;
	bytes_written = 0;
	while (str[counter] != '\0')
	{
		success = ft_putchar_fd(str[counter], fd);
		if (success < 0)
			return (-1);
		bytes_written += success;
		counter++;
	}
	return (bytes_written);
}
