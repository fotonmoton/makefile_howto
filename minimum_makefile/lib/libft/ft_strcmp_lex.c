/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:58:52 by gtertysh          #+#    #+#             */
/*   Updated: 2017/04/02 06:47:00 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp_lex(const char *s1, const char *s2)
{
	int	s1_low;
	int	s2_low;

	s1_low = ft_tolower(*(unsigned char *)s1);
	s2_low = ft_tolower(*(unsigned char *)s2);
	while (*s1 && *s2 && s1_low == s2_low)
	{
		s1++;
		s2++;
		s1_low = ft_tolower(*(unsigned char *)s1);
		s2_low = ft_tolower(*(unsigned char *)s2);
	}
	if (s1_low != s2_low)
		return (s1_low - s2_low);
	return (0);
}
