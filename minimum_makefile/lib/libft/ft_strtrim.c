/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:25:11 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/06 14:24:05 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*ret;
	char		*tmp;
	const char	*start;
	const char	*end;

	ret = NULL;
	if (s)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		start = s;
		while (*s && *(s + 1))
			s++;
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s--;
		end = s;
		if (!(ret = ft_strnew(end - start + 1)))
			return (ret);
		tmp = ret;
		while (start <= end)
			*tmp++ = *start++;
	}
	return (ret);
}
