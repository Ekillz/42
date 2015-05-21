/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:14:06 by emammadz          #+#    #+#             */
/*   Updated: 2015/02/09 19:17:38 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isdigit(int c)
{
	if ((unsigned int)c <= '9' && (unsigned int)c >= '0')
		return (1);
	else if (c < 0)
		return (1);
	else
		return (0);
}
