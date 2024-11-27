/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/22 18:46:24 by salieri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*list;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	node = NULL;
	while (lst)
	{
		node = ft_lstnew(NULL);
		if (!node)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		node->content = f(lst->content);
		ft_lstadd_back(&list, node);
		lst = lst->next;
	}
	return (list);
}
