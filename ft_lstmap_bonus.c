/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:01:12 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/08 11:59:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**new_list;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = (t_list **)ft_calloc(1, sizeof(t_list *));
	if (!new_list)
		return (NULL);
	*new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
			return (ft_lstclear(new_list, del), NULL);
		ft_lstadd_back(new_list, new_node);
		lst = lst->next;
	}
	new_node = *new_list;
	free(new_list);
	return (new_node);
}

/*
#include <stdio.h>
#include <stdlib.h>
void	ft_print_result(t_list *elem)
{
	while (elem)
	{
		printf("%d ", *(int *)(elem->content));
		elem = elem->next;
	}
}

void *ft_map(void *content)
{
	int *value = (int *)content;
	*value *= 2; // Example operation: double the value
	return value;
}


int main()
{
	t_list **array;
	array = (t_list **)malloc(sizeof(t_list *));
	*array = NULL;
	int a = 42;
	int b = 84;
	int c = 126;

	ft_lstadd_back(array, ft_lstnew(&a));
	ft_lstadd_back(array, ft_lstnew(&b));
	ft_lstadd_back(array, ft_lstnew(&c));

	ft_print_result(*array);
	printf("\n");

	t_list *new_list = ft_lstmap(*array, ft_map, free);
	ft_print_result(new_list);
} */