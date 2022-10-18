/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:12:11 by rabderus          #+#    #+#             */
/*   Updated: 2021/11/10 14:17:18 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*d;

	d = (t_list *)malloc(sizeof(t_list));
	if (!d)
		return (NULL);
	d->content = content;
	d->next = NULL;
	return (d);
}
