/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:03:41 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/06 17:48:02 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strlcat_aux(const char *s, char *d, int free_space)
{
	while (*s != '\0')
	{
		if (free_space != 1)
		{
			*d = *s;
			d++;
			free_space--;
		}
		s++;
	}
	*d = '\0';
}

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*d;
	const char		*s;
	size_t			len;
	size_t			free_space;

	d = dest;
	s = src;
	free_space = size;
	while (free_space && *d != '\0')
	{
		d++;
		free_space--;
	}
	len = d - dest;
	free_space = size - len;
	if (!free_space)
		return (len + ft_strlen(src));
	ft_strlcat_aux(s, d, free_space);
	return (len + ft_strlen(src));
}
