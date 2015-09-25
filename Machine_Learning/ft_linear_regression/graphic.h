/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 18:39:26 by emammadz          #+#    #+#             */
/*   Updated: 2015/09/23 16:07:50 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
#define GRAPHIC_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include <fcntl.h>
# include <string.h>

typedef struct s_env
{
	void *mlx;
	void *win;
	char *img;
	void *img_ptr;
	int bpp;
	int size_line;
	int endian;
	int show_lines;
	char **data;
	char **coord;
}			 t_env;


void    draw_line(t_env *e);
void	plot_graph(t_env *e);
#endif
