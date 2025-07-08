/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:01:12 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/07 19:39:09 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**new_list;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_node = NULL;
	new_list = &new_node;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
			return (ft_lstclear(new_list, del), NULL);
		ft_lstadd_back(new_list, new_node);
		lst = lst->next;
	}
	return (*new_list);
}
