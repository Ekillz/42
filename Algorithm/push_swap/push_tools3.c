/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tools3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:47:05 by emammadz          #+#    #+#             */
/*   Updated: 2015/02/23 20:10:01 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void rra(t_env *e)
{
	int tmp;
	int i;
	int *tmp_i;

	tmp_i = malloc(sizeof(int *) * e->ac - 1);
	i = e->ac - 3;
	tmp = e->ac - 1;
	copy_tmp_i(e, tmp_i, 0);
	e->tab[e->ac - 2] = tmp_i[0];
	while (tmp)
	{
		e->tab[i] = tmp_i[i + 1];
		i--;
		tmp--;
	}
	if (e->which == 0)
	{
//		ft_putstr("rra\n");
		show_moves(e, 8);
	}
}

void rrb(t_env *e)
{
	int tmp;
	int i;
	int *tmp_i;

	tmp_i = malloc(sizeof(int *) * e->ac - 1);
	i = 1;
	tmp = e->ac2;
	copy_tmp_i(e, tmp_i, 1);
	e->tab2[2] = tmp_i[0];
	while (tmp)
	{
		e->tab2[i] = tmp_i[i + 1];
		i--;
		tmp--;
	}
	if (e->which == 0)
	{
//		ft_putstr("rrb\n");
		show_moves(e, 9);
	}
}

void rrr(t_env *e)
{
	e->which = 1;
	rra(e);
	rrb(e);
//	ft_putstr("rrr\n");
	show_moves(e, 10);
	e->which = 0;
}
