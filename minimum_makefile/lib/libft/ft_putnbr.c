/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 09:45:39 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/04 15:26:28 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_print(int nb, long div, int exeption)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (div == 1)
		ft_putchar('0');
	else
	{
		while (div > 1)
		{
			div = div / 10;
			ft_putchar(nb / div + '0');
			nb = nb % div;
		}
	}
	if (exeption)
		ft_putchar('8');
}

void		ft_putnbr(int nb)
{
	int		temp;
	long	div;
	int		exeption;

	div = 1;
	exeption = 0;
	temp = nb;
	if (nb == -2147483648)
	{
		nb = nb / 10;
		temp = temp / 10;
		exeption = 1;
	}
	while (temp)
	{
		temp = temp / 10;
		div = div * 10;
	}
	ft_putnbr_print(nb, div, exeption);
}
