/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 18:15:15 by gtertysh          #+#    #+#             */
/*   Updated: 2017/03/24 20:41:17 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fd	*new_node(int fd)
{
	t_fd	*new;

	new = NULL;
	if ((new = (t_fd *)malloc(sizeof(t_fd))))
	{
		new->fd = fd;
		new->n = NULL;
		new->next = NULL;
		new->t = 0;
	}
	return (new);
}

t_fd	*find_fd(int fd, t_fd **cur_fd)
{
	if (!*cur_fd)
		return ((*cur_fd = new_node(fd)));
	while ((*cur_fd))
	{
		if ((*cur_fd)->fd == fd)
			return (*cur_fd);
		cur_fd = &((*cur_fd)->next);
	}
	return ((*cur_fd = new_node(fd)));
}

int		check_reminder(t_fd *c, char **line)
{
	char *substr;
	char *old_line;

	old_line = *line;
	if (c->n)
	{
		if ((c->t = ft_strchr(c->n, '\n')))
		{
			substr = ft_strsub(c->n, 0, c->t - c->n);
			*line = ft_strjoin(*line, substr);
			free(substr);
			c->n = ++(c->t);
			return (1);
		}
		else
		{
			*line = ft_strjoin(*line, c->n);
			c->n = 0;
		}
		free(old_line);
	}
	return (0);
}

int		check_buf(t_fd *c, char **line)
{
	char *substr;
	char *old_line;

	old_line = *line;
	while ((c->readed = read(c->fd, c->b, BUFF_SIZE)))
	{
		if (c->readed == -1)
			return (-1);
		c->b[c->readed] = 0;
		if ((c->n = ft_strchr(c->b, '\n')))
		{
			substr = ft_strsub(c->b, 0, c->n++ - c->b);
			old_line = *line;
			*line = ft_strjoin(*line, substr);
			free(substr);
			free(old_line);
			break ;
		}
		old_line = *line;
		*line = ft_strjoin(*line, c->b);
		free(old_line);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_fd		*head_fd;
	t_fd			*c;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	c = find_fd(fd, &head_fd);
	c->readed = 0;
	if (check_reminder(c, line))
		return (1);
	if (check_buf(c, line) == -1)
		return (-1);
	if ((c->readed == 0) && !ft_strlen(*line))
		return (0);
	return (1);
}
