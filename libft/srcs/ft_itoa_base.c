/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:13:20 by ction             #+#    #+#             */
/*   Updated: 2019/08/14 19:13:23 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long long value, int base)
{
	int						i;
	unsigned long long int	val;
	char					*res;

	val = value;
	i = 0;
	if (base > 16)
		return (NULL);
	while ((value / base != 0) && ++i)
		value /= base;
	if ((res = malloc(sizeof(char) * (i + 2))) == 0)
		return (NULL);
	res[i + 1] = '\0';
	while (val / base)
	{
		res[i] = (val % base > 9 ? ft_abs(val % base % 10) +
			97 : ft_abs(val % base) + '0');
		val /= base;
		i--;
	}
	res[i] = (val % base > 9 ? ft_abs(val % base % 10)
		+ 97 : ft_abs(val % base) + '0');
	return (res);
}
