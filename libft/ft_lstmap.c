/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:07:02 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/17 17:52:08 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmap_clear(t_list *begin, void (*del)(void *))
{
	ft_lstclear(&begin, del);
	return (0);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*begin;
	t_list		*a;

	if (!lst)
		return (0);
	a = 0;
	while (lst)
	{
		f(lst->content);
		if (!a)
		{
			if (!(a = ft_lstnew(f(lst->content))))
				return (ft_lstmap_clear(begin, del));
			begin = a;
		}
		else
		{
			if (!(a->next = ft_lstnew(f(lst->content))))
				return (ft_lstmap_clear(begin, del));
			a = a->next;
		}
		lst = lst->next;
	}
	return (begin);
}
