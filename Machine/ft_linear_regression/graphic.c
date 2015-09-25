/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 18:41:37 by emammadz          #+#    #+#             */
/*   Updated: 2015/09/23 17:33:57 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static int    ft_strpos(char *str, char c)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == c)
			break;
		i++;
	}
	return (i);
}

static int    key_press_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit (0);
	else if (keycode == 1)
	{
		bzero(e->img, e->bpp * 1000 + 1000 * e->size_line);
		e->show_lines += 1;
		draw_line(e);		
	}
	else if (keycode == 2)
	{
		plot_graph(e);
	}
	return (0);
}

static int     expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return 0;
}

static void mlx_put_pixel_to_img(t_env *e, int x, int y, int color)
{
	memcpy(&e->img[(x * 4) + (y * e->size_line)], &color, (sizeof(size_t)));
}

static void mlx_put_pixel(t_env *e, int x, int y, int color)
{
	if ((x < 1000 && x  >= 0 ) && (y < 1000 && y >= 0))
		mlx_put_pixel_to_img(e, x, y, color);
}

static void    draw_tmp_line(t_env *e, double theta0, double theta1)
{
	int i = 2;
	double result;

	while (i < 500)
	{
		result = -(((theta1 * i) + theta0) / 1000);
		mlx_put_pixel(e, i, (int)result, 0xff0000);
		i++;
	}
}

void    draw_line(t_env *e)
{

	draw_tmp_line(e, 8006.29, -4650.92);
	if (e->show_lines % 2 == 0)
	{
		int i = 0;
		while (e->data[i])
		{
			if (e->data[i + 1])
				draw_tmp_line(e, atoi(e->data[i]), atoi(e->data[i + 1]));
			i += 2;
		}
	}
	expose_hook(e);
}

static void	   draw_points(t_env *e, int s)
{
	int i = -5;
	int x = atoi(e->coord[s]) / 1000;
	int y = 1000 - (atoi(e->coord[s + 1]) / 10);
	while (i < 5)
	{
		mlx_put_pixel(e, x + i, y, 0xffffff);
		mlx_put_pixel(e, x, y + i, 0xffffff);
		i++;
	}
}

void	   plot_graph(t_env *e)
{
	int s = 0;

	while (e->coord[s])
	{
		draw_points(e, s);
		s += 2;
	}
	expose_hook(e);
}

static void    get_coord(t_env *e)
{
	int r;
	FILE *fd = fopen("data.csv", "r");
	char *str;
	int s = 0;
	size_t len = 0;
	int pos;

	if (!fd)
		exit(0);
	e->coord = malloc(sizeof(char *) * (200 + 2));
	getline(&str, &len, fd);
	while ((r = getline(&str, &len, fd)) != -1)
	{
		str[r - 1] = '\0';
		pos  = ft_strpos(str, ',');
		e->coord[s] = malloc(sizeof(char) * r + 1);
		strncpy(e->coord[s], str, pos);
		e->coord[s][pos] = '\0';
		s++;
		e->coord[s] = malloc(sizeof(char) * r + 1);
		strncpy(e->coord[s], &str[pos + 1],  strlen(str) - pos - 1);
		e->coord[s][strlen(str) - pos - 1] = '\0';
		s++;
	}
	e->coord[s] = NULL;
	fclose(fd);
}

static void	   get_data(t_env *e)
{
	int r;
	FILE *fd = fopen("thetas.txt", "r");
	char *str;
	int s = 0;
	size_t len = 0;
	
	if (!fd)
		exit(0);
	str = malloc(sizeof(char) * 20);
	e->data = malloc(sizeof(char *) * (3000 + 2));
	while ((r = getline(&str, &len, fd)) != -1)
	{
		str[r] = '\0';
		e->data[s] = malloc(sizeof(char) * r + 1);
		strcpy(e->data[s], str);
		e->data[s][ft_strpos(e->data[s], '\n')] = '\0';
		s++;
	}
	e->data[s] = NULL;
	fclose(fd);
}

static void    declarations_mlx(t_env *e)
{
	e->show_lines = 1;
	e->img_ptr = mlx_new_image(e->mlx, 1000, 1000);
	e->img = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->size_line, &e->endian);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, 1L << 0, &key_press_hook, e);
}

static void declare_and_check_mlx_error(t_env *e)
{
	if (!(e->mlx = mlx_init()))
	{
		write(2, "mlx init error\n", 15);
		exit(0);
	}
	else if (!(e->win = mlx_new_window(e->mlx, 1000, 1000, "Graph")))
	{
		write(2, "mlx win error\n", 14);
		exit(0);
	}
}

int main(void)
{
	t_env e;

	declare_and_check_mlx_error(&e);
	declarations_mlx(&e);
	get_data(&e);
	get_coord(&e);
	plot_graph(&e);
	draw_line(&e);
	mlx_loop(e.mlx);
	return (0);
}
