/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:03:16 by rabderus          #+#    #+#             */
/*   Updated: 2021/11/11 16:44:45 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*bufer;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	bufer = new_list;
	lst = lst->next;
	while (lst)
	{
		bufer->next = ft_lstnew(f(lst->content));
		if (!bufer->next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		bufer = bufer->next;
		lst = lst->next;
	}
	bufer->next = NULL;
	return (new_list);
}
