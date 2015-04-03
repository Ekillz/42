/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:10:39 by emammadz          #+#    #+#             */
/*   Updated: 2015/02/23 20:09:07 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void pb(t_env *e)
{
	if (e->ac - 2 != 0)
	{
		e->tab2[e->ac2] = e->tab[e->ac - 2];
		e->tab[e->ac - 2] = 0;
		e->ac--;
		e->ac2++;
//		ft_putstr("pb\n");
		show_moves(e, 4);
	}
}

void copy_tmp_i(t_env *e, int *tmp_i, int which_rotate)
{
	int tmp;
	int i;

	i = 0;
	if (which_rotate == 0)
	{
		tmp = e->ac - 1;
		while (tmp)
		{
			tmp_i[i] = e->tab[i];
			i++;
			tmp--;
		}
	}
	else if (which_rotate == 1)
	{
		tmp = e->ac2;
		while (tmp)
		{
			tmp_i[i] = e->tab2[i];
			i++;
			tmp--;
		}
	}
}

void ra(t_env *e)
{
	int tmp;
	int i;
	int *tmp_i;

	tmp_i = malloc(sizeof(int *) * e->ac - 1);
	i = 1;
	tmp = e->ac - 1;
	copy_tmp_i(e, tmp_i, 0);
	e->tab[0] = tmp_i[e->ac - 2];
	while (tmp)
	{
		e->tab[i] = tmp_i[i - 1];
		i++;
		tmp--;
	}
	if (e->which == 0)
	{
//		ft_putstr("ra\n");
		show_moves(e, 5);
	}
}

void rb(t_env *e)
{
	int tmp;
	int i;
	int *tmp_i;

	tmp_i = malloc(sizeof(int *) * e->ac - 1);
	i = 1;
	tmp = e->ac2;
	copy_tmp_i(e, tmp_i, 1);
	e->tab2[0] = tmp_i[e->ac2 - 1];
	while (tmp)
	{
		e->tab2[i] = tmp_i[i - 1];
		i++;
		tmp--;
	}
	if (e->which == 0)
	{
		ft_putstr("rb\n");
//		show_moves(e, 6);
	}
}

void rr(t_env *e)
{
	e->which = 1;
	ra(e);
	rb(e);
//	ft_putstr("rr\n");
	show_moves(e, 7);
	e->which = 0;
}
