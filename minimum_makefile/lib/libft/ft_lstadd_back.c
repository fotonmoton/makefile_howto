/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:45:28 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/06 20:06:23 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **l, void *content, size_t size)
{
	if (!l)
		return ;
	if (*l == NULL)
		(*l) = ft_lstnew(content, size);
	else
	{
		while ((*l)->next)
			l = &(*l)->next;
		(*l)->next = ft_lstnew(content, size);
	}
}
