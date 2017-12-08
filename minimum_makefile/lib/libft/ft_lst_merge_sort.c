/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_merge_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 06:44:41 by gtertysh          #+#    #+#             */
/*   Updated: 2017/04/02 06:44:43 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*merge(t_list *a, t_list *b, int (*cmp)())
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (cmp(a->content, b->content))
	{
		result = a;
		result->next = merge(a->next, b, cmp);
	}
	else
	{
		result = b;
		result->next = merge(a, b->next, cmp);
	}
	return (result);
}

static void		split(t_list *source, t_list **front_ptr, t_list **back_ptr)
{
	t_list *fast;
	t_list *slow;

	if (source == NULL || source->next == NULL)
	{
		*front_ptr = source;
		*back_ptr = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front_ptr = source;
		*back_ptr = slow->next;
		slow->next = NULL;
	}
}

void			ft_lst_merge_sort(t_list **head_ptr, int (*cmp)())
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *head_ptr;
	if ((head == NULL) || (head->next == NULL))
		return ;
	split(head, &a, &b);
	ft_lst_merge_sort(&a, cmp);
	ft_lst_merge_sort(&b, cmp);
	*head_ptr = merge(a, b, cmp);
}
