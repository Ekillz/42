/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:34:34 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/06 18:39:50 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memalloc(size_t size)
{
	void				*memory;
	unsigned int		i;
	char				*explorer;

	i = 0;
	memory = (void *)malloc(size);
	explorer = (char *)memory;
	if (memory != NULL)
	{
		while (i++ < size)
			*explorer++ = 0;
	}
	return (memory);
}
