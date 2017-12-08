/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:56:43 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/06 19:47:14 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfind(t_list *lst, void *data, size_t size)
{
	while (lst)
	{
		if ((ft_memcmp(lst->content, data, size) == 0))
			return (lst);
		lst = lst->next;
	}
	return (0);
}
