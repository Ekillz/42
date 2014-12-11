/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:06:42 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/09 17:34:49 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
	t_ui i;

	i = 0;
	if (n == 0)
		return (1);
	else if (s1 != '\0' && s2 != '\0')
	{
		while ((s1 != '\0' || s2 != '\0') || (i <= n))
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
			if (s1[i] == '\0' && s2[i] == '\0')
				return (1);
			else if ((s1[i - 1] == s2[i - 1]) && i == n)
				return (1);
		}
	}
	else if (s1 == '\0' || s2 == '\0')
		return (1);
	else
		return (0);
	return (0);
}
