/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:08:54 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/07 16:33:13 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s)
{
	char *temp_str;
	char *new_str;
	int len;
	int i;
	int e;

	e = 0;
	i = -1;
	len = ft_strlen(s);
	if ((temp_str = malloc((len) * sizeof(char))) == NULL)
		return (NULL);
	temp_str = ft_strcpy(temp_str, s);
	while (++i < len)
	{
		if (s[i] == ' ' || s[i]  == '\t' || s[i] == '\n')
			e++;
	}
	if (e == 0)
		return (temp_str);
	if ((new_str = malloc((len - e) * sizeof(char))) == NULL)
		return (NULL);
	i = -1;
	e = 0;
	while (++i <= len)
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			e++;
		else
			new_str[i - e] = s[i];
	}
	return (new_str);
}

int main(void)
{
	ft_putstr(ft_strtrim("h \ne \ty du  \t d   \n e"));
	return (0);
}
