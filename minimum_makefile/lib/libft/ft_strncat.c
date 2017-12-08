/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:03:18 by gtertysh          #+#    #+#             */
/*   Updated: 2016/11/30 15:11:23 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s;
	size_t	s1_size;

	s = s1;
	s1_size = sizeof(s1);
	while (*s1)
		s1++;
	while (*s2 && s1_size - 1 && n--)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s);
}
