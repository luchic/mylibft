/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:40:05 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/14 13:24:55 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlnbr_fd(long n, int fd)
{
	int				res;
	unsigned long	nbr;
	char			*base;

	nbr = n;
	if (n < 0)
	{
		if(ft_putchar_fd('-', fd) == -1)
			return (-1);
	}
	base = "0123456789";
	res = ft_putulnbr_base_fd(nbr, base, fd);
	if (res == -1)
		return (-1);
	return (res + 1);
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