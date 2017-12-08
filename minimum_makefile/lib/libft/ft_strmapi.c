/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:47:40 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/02 16:18:37 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	i = 0;
	ret = NULL;
	if (s)
		if ((ret = (char *)ft_strnew(ft_strlen(s))))
			while (*(s + i))
			{
				*(ret + i) = f(i, *(s + i));
				i++;
			}
	return (ret);
}
