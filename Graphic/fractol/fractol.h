/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 17:30:38 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/26 16:18:49 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"

typedef struct	s_env
{
	double	c_re_new;
	int		color;
	double	c_re_julia;
	double	c_im_julia;
	int		iteration_add;
	float	move_x;
	float	move_y;
	void	*mlx;
	void	*win;
	int		row;
	int		col;
	int		width;
	int		height;
	int		max;
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	int		iteration;
	double	x_new;
	char	**av;
	char	*img;
	void	*img_ptr;
	float	mouse;
	int		bpp;
	int		size_line;
	int		endian;
	double	mouse_x;
	double	mouse_y;
	int		color_add;
	double	adapt_zoom;
}				t_env;
void			burning_ship_algo(t_env *e, int j, int i, double range);
void			draw_fractol_burning_ship(t_env *e);
void			key_4(t_env *e, int keycode);
void			adapt_zoom_infini(t_env *e);
void			declare_and_check_mlx_error(t_env *e);
void			show_info(t_env *e);
void			declarations_mlx(t_env *e);
int				key_press_hook(int keycode, t_env *e);
int				mouse_move_hook(int x, int y, t_env *e);
void			key_3(t_env *e, int keycode);
void			check_fractol(t_env *e);
void			algo_julia(t_env *e);
void			draw_fractol_julia(t_env *e);
void			redraw_fractol(t_env *e, int fractol);
void			mlx_put_pixel_to_img(t_env *e, int x, int y, int color);
int				check_valid_argument(t_env *e);
void			error_arguments(void);
void			key_2(t_env *e, int keycode);
void			key(t_env *e, int keycode);
void			draw_mandelbrot(t_env *e);
void			algo_mandelbrot(t_env *e);
void			declarations(t_env *e);
void			draw_fractol_mandelbrot(t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);

#endif
