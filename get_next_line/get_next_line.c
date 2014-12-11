/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:06:21 by emammadz          #+#    #+#             */
/*   Updated: 2014/12/11 14:46:01 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		fd_read(int fd, char *buf)
{
	static int ret;

	ret = read(fd, buf, BUFF_SIZE + 2000000);
	if (ret == -1)
	{
		free(buf);
		return (-1);
	}
	else if (ret == 0)
		return (0);
	buf[ret] = '\0';
	return (0);
}

static int		return_int(char *buf)
{
	static int i = 0;

	while (buf[i] != '\0')
	{
		if (buf[i] == '\n' && buf[i + 1] == '\0')
		{
			free(buf);
			i++;
			return (1);
		}
		else if (buf[i] == '\n')
		{
			free(buf);
			i = i + 1;
			return (1);
		}
		else if (buf[0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

static int		count_line(char *buf)
{
	int	i;
	int	e;

	e = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i + 1] == '\0')
			e++;
		else if (buf[i] == '\n')
			e++;
		i++;
	}
	return (e);
}

static char		*buf_line(char *buf, t_cord *r)
{
	int			i;
	static int	t = 0;

	i = 0;
	r->new_buff = malloc((BUFF_SIZE + 2000000) * sizeof(char));
	while (buf[t] != '\0')
	{
		if (buf[t] == '\n')
			break ;
		r->new_buff[i] = buf[t];
		t++;
		i++;
	}
	t++;
	return (r->new_buff);
}

int				get_next_line(const int fd, char **line)
{
	t_cord		r;
	char		*buf;
	static int	e = 1;
	static int	s = 1;

	if (line != NULL && s == 1)
	{
		buf = malloc(sizeof(char *) * (BUFF_SIZE + 2000000));
		if (fd_read(fd, buf) == -1)
			return (-1);
		if (e++ <= count_line(buf))
		{
			*line = buf_line(buf, &r);
			if (return_int(buf) == 1)
				return (1);
			else if (e == count_line(buf))
				s = 0;
		}
	}
	return (0);
}
