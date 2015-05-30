/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:37:20 by emammadz          #+#    #+#             */
/*   Updated: 2015/05/30 16:37:16 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include <math.h>
# include "libft/libft.h"
# define MAPWIDTH 21
# define MAPHEIGHT 21

typedef struct	s_env
{
	int		color;
	float	speed;
	int		minimap;
	void	*mlx;
	void	*win;
	char	*img;
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
	void	*tmp_map;
	int		worldmap[MAPHEIGHT][MAPWIDTH];
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	olddirx;
	double	oldplanex;
	double	planey;
	double	camerax;
	double	cameray;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		mapx;
	int		mapy;
	int		x;
	int		y;
	int		w;
	int		h;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		xx;
}				t_env;
void			down(t_env *e);
int				up(t_env *e);
void			lf_move(t_env *e, int keycode);
void			select_color_and_draw(t_env *e);
void			calculate_mouvement(t_env *e);
void			first_declarations(t_env *e);
void			dda_algorithm(t_env *e);
void			draw_wall_1(t_env *e);
void			draw_wall_2(t_env *e);
void			map(t_env *e);
void			draw_fov(t_env *e, int which);
void			draw_map(t_env *e, int x, int y, int which);
void			mini_map(t_env *e);
void			raycaster(t_env *e);
void			declare_and_check_mlx_error(t_env *e);
void			mlx_put_pixel_to_img(t_env *e, int x, int y, int color);
int				expose_hook(t_env *e);
void			declarations_mlx(t_env *e, int which);
#endif
