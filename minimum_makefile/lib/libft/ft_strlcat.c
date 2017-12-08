/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:16:55 by gtertysh          #+#    #+#             */
/*   Updated: 2016/11/30 18:13:07 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	while (*dst)
		dst++;
	if (size > dst_size)
	{
		while (*src && (size-- - dst_size - 1))
			*dst++ = *src++;
		*dst = '\0';
		return (src_size + dst_size);
	}
	return (src_size + size);
}
