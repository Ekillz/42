/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 17:58:54 by emammadz          #+#    #+#             */
/*   Updated: 2015/04/01 13:39:11 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void copy_tab(t_env *e)
{
	int *tab;
	int *tab2;
	int tmp;
	int i;

	tmp = e->ac - 1;
	i = 1;
	tab = malloc(sizeof(int *) * e->ac - 1);
	tab2 = malloc(sizeof(int *) * e->ac - 1);
	while (tmp)
	{
		tab[i - 1] = ft_atoi(e->av[tmp]);
		tmp--;
		i++;
	}
	e->tab = tab;
	e->tab2 = tab2;
}

void sa(t_env *e)
{
	int tmp_tab;

	if (e->ac > 2)
	{
		tmp_tab = e->tab[e->ac - 2];
		e->tab[e->ac - 2] = e->tab[e->ac - 3];
		e->tab[e->ac - 3] = tmp_tab;
		if (e->which == 0)
		{
	//		ft_putstr("sa\n");
			show_moves(e, 0);
		}
	}
}

void sb(t_env *e)
{
	int tmp_tab;

	if (e->ac2 > 1)
	{
		tmp_tab = e->tab2[e->ac2 - 2];
		e->tab2[e->ac2 - 2] = e->tab2[e->ac2 - 1];
		e->tab2[e->ac2 - 1] = tmp_tab;
		if (e->which == 0)
		{
			ft_putstr("sb\n");
			show_moves(e, 1);
		}
	}
}

void ss(t_env *e)
{
	e->which = 1;
	sa(e);
	sb(e);
	ft_putstr("ss\n");
	show_moves(e, 2);
	e->which = 0;
}

void pa(t_env *e)
{
	if (e->ac2 > 0)
	{
		e->ac++;
		e->ac2--;
		e->tab[e->ac - 2] = e->tab2[e->ac2];
		e->tab2[e->ac2] = 0;
		//ft_putstr("pa\n");
		show_moves(e, 3);
	}
}
