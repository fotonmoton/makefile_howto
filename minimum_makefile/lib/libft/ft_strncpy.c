/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:12:41 by gtertysh          #+#    #+#             */
/*   Updated: 2016/11/30 14:39:28 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *new_dest;

	new_dest = dst;
	while (len && *src)
	{
		*new_dest++ = *src++;
		if (!len)
			return (dst);
		len--;
	}
	while (len-- > 0)
		*(new_dest++) = '\0';
	return (dst);
}
