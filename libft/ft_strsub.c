* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:17:05 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/19 12:49:45 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	int		i;

	i = 0;
	if ((newstr = malloc((len - start) * sizeof(char))) == NULL)
		return (NULL);
	while (len)
	{
		newstr[i] = s[start];
		start++;
		i++;
		len--;
	}
	newstr[i] = '\0';
	return (newstr);
}
