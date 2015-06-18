/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:22:53 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/04 14:24:18 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*t_s1;

	t_s1 = s1;
	while (n && *s2 != '\0')
	{
		*s1++ = *s2++;
		n--;
	}
	while (n--)
		*s1++ = '\0';
	return (t_s1);
}