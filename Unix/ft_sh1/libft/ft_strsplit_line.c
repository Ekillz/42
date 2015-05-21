/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 17:30:38 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/25 15:57:45 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_nb(char const *s)
{
	size_t	word_nb;

	word_nb = ((*s == ' ' || *s == '\t') ? (0) : (1));
	while (*s)
	{
		if ((*s == ' ' || *s == '\t') && (*(s + 1) != ' ' || *(s + 1) != '\t')\
				&& *(s + 1))
			word_nb++;
		s++;
	}
	return (word_nb);
}

static size_t	ft_word_len(char const *s)
{
	size_t	word_len;

	word_len = 0;
	while (*s != ' ' && *s != '\t' && *s)
	{
		s++;
		word_len++;
	}
	return (word_len);
}

static void		ft_free_tab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

char			**split_it(char const *s)
{
	char	**tab;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(tab = malloc(ft_word_nb(s) * sizeof(char *) + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		if (*s)
		{
			if (!(tab[i] = ft_strsub(s, 0, ft_word_len(s))))
			{
				ft_free_tab(tab, i);
				return (NULL);
			}
			s += ft_word_len(s);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
