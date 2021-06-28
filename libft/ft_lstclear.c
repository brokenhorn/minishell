/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:29:35 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/11 21:14:52 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*nxt;

	tmp = *lst;
	while (tmp)
	{
		nxt = tmp;
		tmp = nxt->next;
		del(nxt->content);
		free(nxt);
	}
	(*lst) = NULL;
}
