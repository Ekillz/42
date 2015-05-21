/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:34:34 by emammadz          #+#    #+#             */
/*   Updated: 2014/12/29 18:46:13 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*ptr;

	ptr = NULL;
	if (!size || !(ptr = malloc(size)))
		return (ptr);
	ft_memset(ptr, 0, size);
	return (ptr);
}
