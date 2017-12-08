/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:19:18 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/04 15:25:42 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_print(int nb, long div, int exeption, int fd)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	if (div == 1)
		ft_putchar_fd('0', fd);
	else
	{
		while (div > 1)
		{
			div = div / 10;
			ft_putchar_fd(nb / div + '0', fd);
			nb = nb % div;
		}
	}
	if (exeption)
		ft_putchar_fd('8', fd);
}

void		ft_putnbr_fd(int nb, int fd)
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
	ft_putnbr_print(nb, div, exeption, fd);
}
