/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:49:55 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/06 19:05:20 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = ft_strlen(s) + 1;
	while (i > 0 && s[i - 1] != c)
	{
		i--;
	}
	if (i > 0)
	{
		return ((char*)(s) + i - 1);
	}
	else
	{
		return (NULL);
	}
}
