/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getbinldouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:59:48 by ction             #+#    #+#             */
/*   Updated: 2019/08/30 19:59:49 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		getmantlongdouble(long double d, t_float *stf, t_specs *st)
{
	char		*res;
	int			i;
	long double	j;

	i = -1;
	j = 0.1;
	PREC = (PREC == -1 ? 6 : PREC);
	while (++i != PREC)
		j *= 0.1;
	d = d + j * 5;
	i = -1;
	res = ft_strnew(112);
	res[112] = '\0';
	while (++i != 112)
	{
		d = d - (int)d;
		d *= 10;
		res[i] = '0' + ft_abs((int)d);
	}
	MANT = res;
}

void		getsolidlongdouble(long double a, t_float *stf)
{
	long int	b;

	b = (long int)a;
	SOL = ft_itoa(b);
}

t_float		*getbinlongdouble(long double a, t_float *stf, t_specs *st)
{
	__uint128_t	*c;

	c = (__uint128_t *)&a;
	getsolidlongdouble(a, stf);
	getmantlongdouble(a, stf, st);
	return (stf);
}
