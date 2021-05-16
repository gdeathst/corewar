/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:58:34 by aromny-w          #+#    #+#             */
/*   Updated: 2021/05/16 19:15:57 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line_realloc(char *old, size_t size)
{
	char	*new;

	if (!old)
		return (ft_strnew(size));
	new = ft_strnew(ft_strlen(old) + size);
	if (!new)
		return (NULL);
	ft_strcpy(new, old);
	ft_strdel(&old);
	return (new);
}

static int	get_line(char **line, char *buff)
{
	char	*nl;
	size_t	len;

	nl = ft_strchr(buff, '\n');
	len = ft_strlen(buff);
	if (nl)
	{
		*line = line_realloc(*line, nl - buff);
		if (!*line)
			return (-1);
		ft_strncat(*line, buff, nl - buff);
		ft_strncpy(buff, nl + 1, ft_strlen(nl));
	}
	else if (len)
	{
		*line = line_realloc(*line, len);
		if (!*line)
			return (-1);
		ft_strncat(*line, buff, len);
		*buff = '\0';
	}
	if (nl)
		return (1);
	return (0);
}

static int	return_gnl(char *line)
{
	if (*line)
		return (1);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	buff[FD_SIZE][BUFF_SIZE + 1];
	ssize_t		ret;

	if (read(fd, 0, 0) == -1 || !line)
		return (-1);
	*line = NULL;
	if (get_line(line, buff[fd]))
		return (return_gnl(*line));
	ret = read(fd, buff[fd], BUFF_SIZE);
	while (ret > 0)
	{
		buff[fd][ret] = '\0';
		if (get_line(line, buff[fd]))
			return (return_gnl(*line));
		ret = read(fd, buff[fd], BUFF_SIZE);
	}
	if (*line)
		return (1);
	return (ret);
}
