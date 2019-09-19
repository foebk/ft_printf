/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getbinfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:26:47 by ction             #+#    #+#             */
/*   Updated: 2019/08/30 18:26:50 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		getmantfloat(double d, t_float *stf, t_specs *st)
{
	char		*res;
	int			i;
	long double	j;

	i = -1;
	j = 0.1;
	PREC = (PREC < 0 ? 6 : PREC);
	while (++i != PREC)
		j *= 0.1;
	d = d + j * 5;
	i = -1;
	res = ft_strnew(52);
	res[52] = '\0';
	while (++i != 52)
	{
		d = d - (int)d;
		d *= 10;
		res[i] = '0' + ft_abs((int)d);
	}
	MANT = res;
}

void		getsolidfloat(char *str, t_float *stf)
{
	int					exp;
	char				tmp;
	char				*res;
	int					j;
	char				*result;

	j = -1;
	tmp = str[8];
	str[8] = '\0';
	exp = ft_btoi(str) - 127;
	EXP = exp;
	str[8] = tmp;
	if ((exp == -127) && (SOL = ft_strnew(1)))
	{
		SOL[0] = '0';
		return ;
	}
	res = ft_strnew(exp + 1);
	res[0] = '1';
	while (++j != exp)
		res[j + 1] = str[8 + j];
	SOL = ft_itoa(ft_btoi(res));
	free(res);
}

t_float		*getbinfloat(float a, t_float *stf, double d, t_specs *st)
{
	uint32_t	*c;
	char		*str;
	int			i;
	char		*tmp;

	i = -1;
	c = (uint32_t *)&a;
	str = ft_strnew(32);
	tmp = ft_itoa_base(*c, 2);
	str = str + 32 - ft_strlen(tmp);
	str = ft_strcpy(str, tmp);
	str = str - (32 - ft_strlen(tmp));
	while ((str[++i] != '0') && (str[i] != '1'))
		str[i] = '0';
	SIGN = (str[0] == '0') ? 0 : 1;
	getsolidfloat(str + 1, stf);
	getmantfloat(d, stf, st);
	return (stf);
}
