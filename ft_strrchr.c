/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:23:58 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/07 18:25:24 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char) c)
			last_occurrence = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (last_occurrence);
}

/* #include <stdio.h>
int main()
{
	char *ch = ft_strrchr("hello", '\0');
	printf("Result: %p\n, Value: %d\n", ch, *ch);
} */