/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:06:44 by emammadz          #+#    #+#             */
/*   Updated: 2014/12/11 14:15:13 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct	s_cord
{
	char *new_buff;
}				t_cord;

int				get_next_line(int fd, char **line);
#endif
