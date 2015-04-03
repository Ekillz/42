/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 20:28:09 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/17 18:39:25 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int check_second_redirect(t_env *e)
{
	int redirect;

	redirect = -1;
	e->redirect_index_2 = e->redirect_index;
	e->redirect_index_2++;
	while (e->args[e->redirect_index_2])
	{
		if (ft_strequ(e->args[e->redirect_index_2], ">"))
			redirect = 0;
		else if (ft_strequ(e->args[e->redirect_index_2], ">>"))
			redirect = 1;
		else if (ft_strequ(e->args[e->redirect_index_2], "<"))
			redirect = 2;
		else if (ft_strequ(e->args[e->redirect_index_2], "<<"))
			redirect = 3;
		if (redirect >= 0)
		{
			e->redirect = redirect;
			e->redirect_index = e->redirect_index_2;
			break ;
		}
		e->redirect_index_2++;
	}
	return (-1);
}
