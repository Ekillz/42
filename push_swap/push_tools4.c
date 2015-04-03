/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tools4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:22:58 by emammadz          #+#    #+#             */
/*   Updated: 2015/04/01 14:29:54 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_tab(t_env *e)
{
	int	tmp;

	tmp = e->ac - 2;
	while (tmp)
	{
		if (e->tab[tmp] < e->tab[tmp - 1])
			tmp--;
		else
			return (1);
	}
	return (0);
}

void	print_tab(t_env *e)
{
	int i;
	int tmp;
	int tmp2;

	tmp = e->ac - 1;
	tmp2 = e->ac2;
	i = 0;
	ft_putstr("Pile A: ");
	while (tmp)
	{
		ft_putnbr(e->tab[i]);
		write(1, " ", 1);
		i++;
		tmp--;
	}
	write(1, "\n", 1);
	ft_putstr("Pile B: ");
	i = 0;
	while (tmp2--)
	{
		ft_putnbr(e->tab2[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int		*tri(t_env *e)
{
	t_tri r;

	r.i = 0;
	r.tmp2 = e->ac - 1;
	r.tmp = 0;
	r.tab = malloc(sizeof(int *) * e->ac - 2);
	while (r.tmp2)
	{
		r.tab[r.i] = e->tab[r.i];
		r.i++;
		r.tmp2--;
	}
	r.des = 1;
	tri_algo(&r, e);
	e->tab_tri = malloc(sizeof(int *) * e->ac -2);
	int s;
	int t;

	s = 0;
	t = e->ac - 2;
	while (t)
	{
		e->tab_tri[s] = r.tab[s];
		t--;
		s++;
	}
	e->tab_tri = r.tab;
	return (r.tab);
}

void	tri_algo(t_tri *e, t_env *r)
{
	while (e->des == 1)
	{
		e->des = 0;
		e->j = 0;
		while (e->j < r->ac - 2)
		{
			if (e->tab[e->j] > e->tab[e->j + 1])
			{
				e->tmp = e->tab[e->j + 1];
				e->tab[e->j + 1] = e->tab[e->j];
				e->tab[e->j] = e->tmp;
				e->des = 1;
			}
			e->j++;
		}
	}
}
