/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:39:51 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/06 19:53:31 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = NULL;
	if (s)
		if ((ret = (char *)ft_strnew(ft_strlen(s))))
			while (*(s + i))
			{
				*(ret + i) = f(*(s + i));
				i++;
			}
	return (ret);
}
