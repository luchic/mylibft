/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:40:05 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/14 11:42:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft.h"

static int	putnbr(unsigned long nb, int fd)
{
	char	out;
	int		res;

	if (nb / 10 == 0)
	{
		out = nb + '0';
		return (write(fd, &out, 1));
	}
	out = nb % 10 + '0';
	nb = nb / 10;
	res = putnbr(nb, fd);
	if (res == -1)
		return (-1);
	if (write(fd, &out, 1) == -1)
		return (-1);
	return (res + 1);
}

int	ft_putlnbr_fd(long n, int fd)
{
	int				res;
	unsigned long	nbr;

	nbr = n;
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		res = putnbr(nbr, fd);
		if (res == -1)
			return (-1);
		return (res + 1);
	}
	else
		return (putnbr(nbr, fd));
}

// #include <stdio.h>
// #include <limits.h>
// #include <string.h>
// int main()
// {
// 	int res = ft_putlnbr_fd(LONG_MIN, 1);
// 	printf("\nRes: %d\n", res);
// 	printf("Strlen: %d\n", strlen("-9223372036854775808"));
// }