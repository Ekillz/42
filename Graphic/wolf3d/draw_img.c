/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:58:33 by emammadz          #+#    #+#             */
/*   Updated: 2015/05/30 14:21:31 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void mlx_put_pixel_to_img(t_env *e, int x, int y, int color)
{
	ft_memcpy(&e->img[(x * 4) + (y * e->size_line)], &color, (sizeof(size_t)));
}
