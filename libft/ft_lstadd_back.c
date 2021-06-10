/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:11:46 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/10 19:29:39 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	if (lst && new)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			a = *lst;
			while (a->next)
				a = a->next;
			a->next = new;
		}
	}
}
