/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:09:46 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/01 17:14:53 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ret;

	ret = NULL;
	if ((ret = (char *)malloc(size + 1)))
	{
		ft_bzero(ret, size + 1);
	}
	return (ret);
}
