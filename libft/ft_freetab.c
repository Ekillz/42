/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 19:53:45 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/23 16:29:49 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_memdel((void *)&tab[i++]);
	ft_memdel((void *)&tab);
}
