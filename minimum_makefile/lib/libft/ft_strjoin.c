/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:53:30 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/02 16:18:10 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret;
	char *tmp;

	ret = NULL;
	if (s1 &&
		s2 &&
		(ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) &&
		(tmp = ret))
	{
		while (*s1)
			*tmp++ = *s1++;
		while (*s2)
			*tmp++ = *s2++;
	}
	return (ret);
}
