/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:41:00 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/16 10:45:49 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "libft.h"
#include <stdlib.h>

void	ft_clean(void)
{
	t_list	**memory;

	memory = get_memory();
	ft_lstclear(memory, free);
	*memory = NULL;
}
