/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:41:57 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/06 17:40:16 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*cur;

	cur = s1;
	while (*cur != '\0')
	{
		cur++;
	}
	while (*s2 != '\0' && n > 0)
	{
		*cur = *s2;
		cur++;
		s2++;
		n--;
	}
	*cur = '\0';
	return (s1);
}
