/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:12:28 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/19 12:32:48 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 != '\0' && s2 != '\0')
	{
		while (s1 != '\0' && s2 != '\0')
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
			if (s1[i] == '\0' && s2[i] == '\0')
				return (1);
		}
	}
	else if (s1 == '\0' && s2 == '\0')
		return (1);
	else
		return (1);
	return (0);
}
