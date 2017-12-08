/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:59:03 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/04 15:12:59 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	help_help(int *n, char *ret, int *i)
{
	if (*n < 0)
	{
		ret[0] = '-';
		*i = *i + 1;
		*n = -(*n);
	}
	if (*n == 0)
		ret[0] = '0';
}

static char	*help(int n, long *div)
{
	int		len;
	char	*ret;

	ret = NULL;
	len = 0;
	while (n)
	{
		n /= 10;
		*div = *div * 10;
		len++;
	}
	if (n < 0 || n == 0)
		len++;
	ret = ft_strnew(len);
	return (ret);
}

char		*ft_itoa(int n)
{
	char	*ret;
	long	div;
	int		i;
	int		exception;

	exception = 0;
	div = 1;
	i = 0;
	if (n == -2147483648)
	{
		n = n / 10;
		exception = 1;
	}
	if (!(ret = help(n, &div)))
		return (NULL);
	help_help(&n, ret, &i);
	while (div > 1)
	{
		div /= 10;
		ret[i++] = n / div + '0';
		n = n % div;
	}
	if (exception)
		ret[i] = '8';
	return (ret);
}
