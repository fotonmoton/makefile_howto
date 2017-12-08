/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:59:03 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/27 18:01:33 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_file(const int fd)
{
	long	readed;
	long	old_size;
	char	buf[BUFF_SIZE + 1];
	char	*string;

	string = ft_memalloc(sizeof(char) * BUFF_SIZE);
	while ((readed = read(fd, buf, BUFF_SIZE)))
	{
		buf[readed] = '\0';
		old_size = ft_strlen(string);
		string = ft_realloc(string, old_size + readed + 1, old_size);
		ft_strcat(string, buf);
	}
	return (string);
}
