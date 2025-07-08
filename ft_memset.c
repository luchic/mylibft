/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:16:21 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/07 17:50:31 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
	I've noticed when i make: byte << 24, then unsigne long fill with ones 
* 	i got 0xffffffff80808080 that value.
*/

static size_t	fill_long(void *b, int c, size_t len)
{
	size_t			i;
	unsigned int	byte;
	unsigned long	value;
	unsigned long	*memory;

	i = 0;
	value = 0;
	byte = c & 0xFF;
	value = ((byte | (byte << 8) | (byte << 16)));
	value |= ((unsigned long)byte) << 24;
	value |= value << 32;
	memory = (unsigned long *) b;
	while (i + 8 < len)
	{
		*memory = value;
		++memory;
		i += 8;
	}
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	val;
	unsigned char	*mem;

	i = fill_long(b, c, len);
	val = (unsigned char)c;
	mem = (unsigned char *)(b + i);
	while (i < len)
	{
		*mem = val;
		++mem;
		++i;
	}
	return (b);
}
/* 
#include <stdio.h>
#include <string.h>

int main()
{
	const int size = 22;
	char b1[0xF];
	char b2[0xF];

	memset(b1, 'B', 0xF);
	memset(b2, 'B', 0xF);

	memset(b1, '\200', 0xF);
	ft_memset(b2, '\200', 0xF);
	if (!memcmp(b1, b2, 0xF))
		printf("ft_memset works correctly!\n");
	else
	{
		printf("ft_memset does not work correctly!\n");
	}

} */