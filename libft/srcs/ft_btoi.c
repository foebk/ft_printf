/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:11:32 by ction             #+#    #+#             */
/*   Updated: 2019/08/27 14:11:35 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_btoi(char *str)
{
	unsigned long long	res;
	int					i;
	int					pow;

	i = -1;
	pow = 0;
	res = 0;
	while (str[++i] != '\0')
		if (str[i] != '0' && str[i] != '1')
			return (0);
	while (--i != -1)
	{
		(str[i] == '1') ? res += ft_power(2, pow) : 0;
		pow++;
	}
	return (res);
}
