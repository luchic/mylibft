/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:40:13 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/08 15:31:59 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	_size(const char *str, char del)
{
	int	strings;
	int	c;

	strings = 0;
	c = 0;
	if (*str != del)
		strings++;
	while (str[c])
	{
		if (str[c] != del && c - 1 >= 0 && str[c - 1] == del)
			strings++;
		c++;
	}
	return (strings);
}

static int	wl(const char *str, char del)
{
	int	c;

	c = 0;
	while (*str && *str != del)
	{
		c++;
		str++;
	}
	return (c);
}

static char	*str_cp(const char *str, int n)
{
	char	*cpy;
	int		count;

	count = 0;
	cpy = malloc(sizeof(char) * (n + 1));
	if (!cpy)
		return (NULL);
	while (count < n)
	{
		cpy[count] = str[count];
		count++;
	}
	cpy[count] = '\0';
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	**copy;
	int		cw;

	if (!s)
		return (NULL);
	res = (char **)malloc((_size(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	copy = res;
	while (*s)
	{
		cw = wl(s, c);
		if (*s == c)
		{
			s++;
			continue ;
		}
		*copy = str_cp(s, cw);
		if (!*copy)
			return (copy);
		copy++;
		s += cw;
	}
	*copy = NULL;
	return (res);
}
