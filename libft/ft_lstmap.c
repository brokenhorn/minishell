/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:14:27 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/14 15:06:26 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newtmp;

	if (lst == NULL)
		return (NULL);
	newtmp = ft_lstnew(f(lst->content));
	if (!(newtmp))
		return (NULL);
	newlst = newtmp;
	lst = lst->next;
	while (lst)
	{
		newtmp->next = ft_lstnew(f(lst->content));
		if (newtmp->next)
		{
			newtmp = newtmp->next;
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
	}
	return (newlst);
}
