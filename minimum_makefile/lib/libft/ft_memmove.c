/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:55:05 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/01 16:38:06 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp;

	tmp = dst;
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len--)
			*((char *)--dst) = *((const char *)--src);
	}
	else
	{
		while (len--)
			*(char *)dst++ = *(const char *)src++;
	}
	return (tmp);
}
