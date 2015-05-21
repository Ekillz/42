/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:35:08 by emammadz          #+#    #+#             */
/*   Updated: 2014/12/29 16:43:12 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalpha(int c)
{
	if ((unsigned int)c >= 'A' && (unsigned int)c <= 'Z')
		return (1);
	else if ((unsigned int)c >= 'a' && (unsigned int)c <= 'z')
		return (1);
	else
		return (0);
	return (0);
}
