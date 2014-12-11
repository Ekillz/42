/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:41:36 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/11 11:56:47 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*nstr;

	if (s && f)
	{
		j = ft_strlen((char*)s);
		i = 0;
		nstr = (char*)malloc(j * sizeof(nstr));
		while (s[i] != '\0')
		{
			nstr[i] = f(s[i]);
			i++;
		}
		return (nstr);
	}
	return (NULL);
}
