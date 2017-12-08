/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:51:34 by gtertysh          #+#    #+#             */
/*   Updated: 2016/11/30 18:31:11 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	size;

	new = 0;
	if (s1)
	{
		if ((size = ft_strlen(s1)) != 0)
		{
			if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
				return (0);
			ft_memcpy(new, s1, size);
			*(new + size) = '\0';
		}
	}
	return (new);
}
