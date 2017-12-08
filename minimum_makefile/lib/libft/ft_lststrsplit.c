/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:32:39 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/06 20:07:14 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lststrsplit(const char *s, char c)
{
	char	**arr_table;
	t_list	*lst_table;
	t_list	*tmp;
	int		i;

	i = 0;
	lst_table = NULL;
	arr_table = ft_strsplit(s, c);
	if (arr_table[i])
	{
		lst_table = ft_lstnew(arr_table[i], ft_strlen(arr_table[i]) + 1);
		tmp = lst_table;
		i++;
		while (arr_table[i])
		{
			tmp->next = ft_lstnew(arr_table[i], ft_strlen(arr_table[i]) + 1);
			tmp = tmp->next;
			i++;
		}
	}
	return (lst_table);
}
