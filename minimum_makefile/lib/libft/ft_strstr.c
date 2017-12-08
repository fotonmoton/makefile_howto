/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:32:43 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/06 14:23:54 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	l;

	l = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big)
	{
		if (!(ft_memcmp(big, little, l)))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
