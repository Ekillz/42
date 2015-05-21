/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 15:15:58 by emammadz          #+#    #+#             */
/*   Updated: 2015/04/03 18:48:05 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void show_moves(t_env *e, int which)
{
	e->tmp = malloc(sizeof(char *) * 3);
	if (which == 0)
		e->tmp = "sa";
	else if (which == 1)
		e->tmp = "sb";
	else if (which == 2)
		e->tmp = "ss";
	else if (which == 3)
		e->tmp = "pa";
	else if (which == 4)
		e->tmp = "pb";
	else if (which == 5)
		e->tmp = "ra";
	else if (which == 6)
		e->tmp = "rb";
	else if (which == 7)
		e->tmp = "rr";
	else if (which == 8)
		e->tmp = "rra";
	else if (which == 9)
		e->tmp = "rrb";
	else if (which == 10)
		e->tmp = "rrr";
	add_moves(e);
}

void add_moves(t_env *e)
{
	e->buf = "h";//ft_strjoin(e->buf, e->tmp);
	e->buf = "h";//ft_strjoin(e->buf, " ");
	//ft_memdel((void *)&e->tmp);
}
