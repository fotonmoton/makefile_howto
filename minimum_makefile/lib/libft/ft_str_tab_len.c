/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tab_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:16:52 by gtertysh          #+#    #+#             */
/*   Updated: 2017/11/05 19:17:02 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_tab_len(char **tab)
{
	int		len;

	len = 0;
	if (tab)
		while (*tab)
		{
			tab++;
			len++;
		}
	return (len);
}