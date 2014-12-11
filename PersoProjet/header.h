/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 18:21:24 by emammadz          #+#    #+#             */
/*   Updated: 2014/12/11 20:52:29 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct	s_env
{
	float		x1;
	float		y1;
	int		max1;
	int		may1;
	void	*win;
	void	*mlx;
	int		keycode;
	int		x;
	int		y;
	int		max;
	int		may;
	int		add;
	int		c;
	int		add_move_x;
	int		add_move_y;
}				t_env;
void object(t_env *e);
void character_motion_ud(t_env *e);
void left_move(t_env *e);
void up_move(t_env *e);
void down_move(t_env *e);
void right_move(t_env *e);
void character_motion_lf(t_env *e);
void recursive_edge_draw(t_env *e);
void draw_map(t_env *e);
void draw(t_env *e);
#endif
