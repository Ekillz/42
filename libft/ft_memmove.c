/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:50:14 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/07 18:37:22 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*t_s1;
	const char	*t_s2;

	t_s2 = s2;
	t_s1 = s1;
	if (s1 <= s2)
		return (ft_memcpy(s1, s2, n));
	t_s2 += n;
	t_s1 += n;
	while (n--)
		*--t_s1 = *--t_s2;
	return (s1);
}
