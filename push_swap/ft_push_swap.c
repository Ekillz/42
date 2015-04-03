/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 17:53:06 by emammadz          #+#    #+#             */
/*   Updated: 2015/04/03 17:23:14 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	algo_swap(t_env *e)
{
	e->i2 = 0;
	print_tab(e);
	tri(e);
	while (check_tab(e) == 1)
	{
		if (e->tab[e->ac - 2] < e->tab[e->ac - 3]
				&& e->tab[e->ac - 2] < e->tab[0] && e->tab[e->ac - 2] == e->tab_tri[e->i2])
		{
			pb(e);
			e->i++;
			e->i2++;
			//print_tab(e);
		}
		else if (e->tab[e->ac - 2] > e->tab[e->ac - 3])
		{
			sa(e);
			e->i++;
			//print_tab(e);
		}
		else
			algo_swap_2(e);
	}
	algo_swap_show(e);
}

int		check_half(t_env *e)
{
	int tmp;
	int i;

	i = 0;
	tmp = 0;
	if ((e->ac - 2) % 2 == 0)
		tmp = (e->ac - 2) / 2;
	else if ((e->ac - 2) % 2 != 0)
		tmp = ((e->ac - 2) / 2) + 1;
	while (tmp)
	{
		if (e->tab[i] == e->tab_tri[e->i2])
			return (1);
		i++;
		tmp--;
	}
	return (0);
}

void	algo_swap_2(t_env *e)
{
	if (check_half(e) == 0)
	{
		while (e->tab[e->ac - 2] != e->tab_tri[e->i2])
		{
			ra(e);
			e->i++;
			//print_tab(e);
		}
	}
	else
	{
		while (e->tab[e->ac - 2] != e->tab_tri[e->i2])
		{
			rra(e);
			e->i++;
			//print_tab(e);
		}
	}
}

void	algo_swap_show(t_env *e)
{
	int tmp;

	tmp = e->ac2;
	while (tmp)
	{
		pa(e);
		//print_tab(e);
		tmp--;
		e->i++;
	}
	if (e->i > 0)
	{
		ft_putstr(ft_strtrim(e->buf));
		write(1, "\n", 1);
	}
	ft_putstr("\nCoups: ");
	ft_putnbr(e->i);
	write(1, "\n", 1);
}
