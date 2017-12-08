/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:35:32 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/05 13:12:20 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((char *)dst + i) = *((const char *)src + i);
		if (*((unsigned char *)src + i) == (unsigned char)c)
			return ((dst + i + 1));
		i++;
	}
	return (NULL);
}
