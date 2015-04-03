/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:22:50 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/23 17:26:08 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_lst_len(t_list *lst)
{
	t_list	*tmp;
	size_t	len;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*prev;
	t_list	*first;

	first = NULL;
	prev = NULL;
	while (lst != NULL)
	{
		new = (*f)(lst);
		if (new == NULL)
			return (NULL);
		if (!first)
		{
			first = new;
			first->next = NULL;
		}
		else if (first && first->next == NULL)
			first->next = new;
		if (prev)
			prev->next = new;
		prev = new;
		lst = lst->next;
	}
	return (first);
}
