/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 11:07:45 by xlongfel          #+#    #+#             */
/*   Updated: 2019/11/26 13:40:04 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*check_mind(char **mind, char **line, int fd)
{
	char	*p_n;
	char	*point;

	p_n = NULL;
	point = mind[fd];
	if (point)
	{
		if ((p_n = ft_strchr(point, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(point);
			p_n++;
			ft_strcpy(point, p_n);
		}
	}
	return (p_n);
}

static int			ft_out(char **line, int byte_was_read, char **mind, int fd)
{
	if (byte_was_read < 0)
		return (-1);
	if (byte_was_read == 0)
	{
		if (mind[fd] && mind[fd][0])
		{
			*line = mind[fd];
			mind[fd] = NULL;
			return (1);
		}
		free(mind[fd]);
		mind[fd] = 0;
		return (0);
	}
	return (1);
}

static int			ft_ura(int fd, char *p_n, char **mind, char **line)
{
	int		byte_was_read;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	byte_was_read = 0;
	while (!p_n && (byte_was_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		*line = mind[fd];
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n++ = '\0';
			tmp = ft_strdup(p_n);
			*line = ft_strjoin(*line, buf);
		}
		else
			tmp = ft_strjoin(*line, buf);
		free(mind[fd]);
		mind[fd] = tmp;
	}
	return (byte_was_read);
}

int					get_next_line(int fd, char **line)
{
	static char	*mind[10240];
	int			byte_was_read;
	char		*p_n;

	if (fd < 0 || line == NULL || fd > 10239)
		return (-1);
	if (!mind[fd])
		mind[fd] = ft_strnew(0);
	*line = 0;
	p_n = check_mind(mind, line, fd);
	if (p_n)
		return (1);
	byte_was_read = ft_ura(fd, p_n, mind, line);
	return (ft_out(line, byte_was_read, mind, fd));
}
