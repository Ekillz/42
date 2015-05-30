/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:43:41 by emammadz          #+#    #+#             */
/*   Updated: 2015/05/30 16:54:01 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char		**create_map(void)
{
	char **map;

	map = malloc(sizeof(char **) * 22);
	map[0] = ft_strdup("111111111111111111111");
	map[1] = ft_strdup("100000000000000000001");
	map[2] = ft_strdup("100000000000000000001");
	map[3] = ft_strdup("100000000000000000001");
	map[4] = ft_strdup("100000000000000000001");
	map[5] = ft_strdup("100011111000021111001");
	map[6] = ft_strdup("100010000000000001001");
	map[7] = ft_strdup("100010000000000001001");
	map[8] = ft_strdup("100010011111111001001");
	map[9] = ft_strdup("100010010000001001001");
	map[10] = ft_strdup("100010010000001001001");
	map[11] = ft_strdup("100010010000001001001");
	map[12] = ft_strdup("100010010000001001001");
	map[13] = ft_strdup("100010011100111001001");
	map[14] = ft_strdup("100010000000000001001");
	map[15] = ft_strdup("100010000000000001001");
	map[16] = ft_strdup("100011111111111111001");
	map[17] = ft_strdup("100000000000000000001");
	map[18] = ft_strdup("100000000000000000001");
	map[19] = ft_strdup("100000000000000000001");
	map[20] = ft_strdup("111111111111111111111");
	return (map);
}

void			map(t_env *e)
{
	int		w;
	int		h;
	char	**test;

	test = create_map();
	h = 0;
	e->tmp_map = test;
	while (h < MAPWIDTH)
	{
		w = 0;
		while (w < MAPHEIGHT)
		{
			e->worldmap[h][w] = test[h][w] - '0';
			w++;
		}
		h++;
	}
}
