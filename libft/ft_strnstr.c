/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:59:24 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/19 12:50:32 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i2 < (int)ft_strlen(s2) && i < (int)n)
	{
		if (s1[i] == s2[i2])
			i2++;
		i++;
	}
	if (i2 == (int)ft_strlen(s2))
		return ((char *)s1 + i - i2);
	else
		return (NULL);
}
