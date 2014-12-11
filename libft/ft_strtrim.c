/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:44:51 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/21 16:38:13 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_debut(char const *s, t_ui le)
{
	t_ui	i;
	int		e;

	e = 0;
	i = -1;
	while (++i < le && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		if (s[i] == '\t')
			e = e + 1;
		else
			e++;
	}
	return (e);
}

static int	ft_fin(char const *s, t_ui le)
{
	int n;

	n = 0;
	while (le && (s[le - 1] == ' ' || s[le - 1] == '\t' || s[le - 1] == '\n'))
	{
		if (s[le - 1] == '\t')
		{
			n = n + 5;
			le = le - 4;
		}
		else
		{
			n++;
			le--;
		}
	}
	return (n);
}

char		*ft_strtrim(char const *s)
{
	char	*temp_str;
	char	*new_str;
	t_ui	le;
	t_ui	i;
	int		en[2];

	le = ft_strlen(s);
	en[1] = ft_fin(s, le);
	en[0] = ft_debut(s, le);
	i = -1;
	if ((temp_str = malloc((le) * sizeof(char))) == NULL)
		return (NULL);
	temp_str = ft_strcpy(temp_str, s);
	if (en[0] == 0 || en[1] == 0)
		return (temp_str);
	if ((new_str = malloc((le - en[0] - en[1]) * sizeof(char))) == NULL)
		return (NULL);
	i = -1;
	while (++i <= ft_strlen(s) - en[1] - en[0])
		new_str[i] = s[i + en[0]];
	return (new_str);
}
