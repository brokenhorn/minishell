/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:04:03 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/12 22:10:46 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	if (lst && *lst)
	{
		a = *lst;
		while (a)
		{
			b = a;
			a = a->next;
			del(b->content);
			free(b);
		}
		*lst = 0;
	}
}
