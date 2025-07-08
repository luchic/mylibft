/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:57:32 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/06 17:55:39 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	putnbr(long nb, int fd)
{
	char	out;

	if (nb / 10 == 0)
	{
		out = nb + '0';
		write(fd, &out, 1);
		return ;
	}
	out = nb % 10 + '0';
	nb = nb / 10;
	putnbr(nb, fd);
	write(fd, &out, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	new_int;

	new_int = n;
	if (new_int < 0)
	{
		write(fd, "-", 1);
		putnbr(new_int * -1, fd);
	}
	else
		putnbr(new_int, fd);
}
