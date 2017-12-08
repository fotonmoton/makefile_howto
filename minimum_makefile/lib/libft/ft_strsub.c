/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:02:56 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/02 16:21:00 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*tmp;

	ret = NULL;
	if (s)
		if ((ret = ft_strnew(len)) &&
			(tmp = ret))
			while (len--)
				*tmp++ = *(s++ + start);
	return (ret);
}
