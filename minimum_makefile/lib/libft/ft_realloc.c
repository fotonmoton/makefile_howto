/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:57:55 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/07 17:16:48 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old, unsigned int new_size, unsigned int old_size)
{
	void	*new;

	new = NULL;
	if ((new = ft_memalloc(new_size)))
	{
		if (old)
		{
			if (old_size)
				ft_memcpy(new, old, old_size);
			free(old);
			old = NULL;
		}
		return (new);
	}
	return (old);
}
