/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 13:56:22 by emammadz          #+#    #+#             */
/*   Updated: 2014/11/09 13:57:22 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char		*ret;
	int			size;
	int			conv;
	int			neg;

	size = 1;
	neg = ((n < 0) ? 1 : 0);
	if (neg)
	{
		n *= -1;
		size++;
	}
	conv = n;
	while ((n = n / 10))
		size++;
	ret = ft_strnew(size);
	while (size--)
	{
		ret[size] = conv % 10 + '0';
		conv = conv / 10;
	}
	if (neg)
		ret[0] = '-';
	return (ret);
}
