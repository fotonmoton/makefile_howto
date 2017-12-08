/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:26:05 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/06 13:22:59 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l;
	size_t	b;

	l = ft_strlen(little);
	b = ft_strlen(big);
	if (*little == '\0')
		return ((char *)big);
	while (len >= l && b)
	{
		if (ft_memcmp(big, little, l) == 0)
			return ((char *)big);
		big++;
		len--;
		b--;
	}
	return (NULL);
}
