/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:01:01 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/05 17:06:29 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		lens1;
	int		lens2;
	int		e;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	e = 0;
	if ((str = malloc((lens1 + lens2 + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	while (e < lens2)
	{
		str[i] = s2[e];
		e++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
