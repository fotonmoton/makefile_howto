/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 10:27:11 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/01 19:51:54 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		numb;
	int		is_negative;

	numb = 0;
	is_negative = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' && str++)
		is_negative = 1;
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		numb = numb * 10 + *str - '0';
		str++;
	}
	if (is_negative)
		return (-numb);
	return (numb);
}
