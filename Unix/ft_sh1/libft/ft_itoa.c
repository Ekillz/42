/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 13:56:22 by emammadz          #+#    #+#             */
/*   Updated: 2014/12/29 17:14:58 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*ret;
	int		size;
	int		conv;
	int		neg;

	if (n == -2147483647 - 1)
		return (ft_strdup("-2147483648"));
	size = 1;
	neg = ((n < 0) ? 1 : 0);
	if (neg && size++)
		n *= -1;
	conv = n;
	while ((n = n / 10))
		size++;
	ret = ft_strnew(size);
	while (size--)
	{
		ret[size] = conv % 10 + '0';
		conv /= 10;
	}
	if (neg)
		ret[0] = '-';
	return (ret);
}
