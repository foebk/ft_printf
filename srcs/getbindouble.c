/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getbindouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:53:04 by ction             #+#    #+#             */
/*   Updated: 2019/08/30 17:53:05 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		getmantdouble(double d, t_float *stf, t_specs *st)
{
	char		*res;
	int			i;
	long double	j;

	i = -1;
	j = 0.1;
	PREC = (PREC <= 0 ? 6 : PREC);
	while (++i != PREC)
		j *= 0.1;
	if (d > 0)
		d = d + j * 5;
	else
		d = d - j * 5;
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

void		getsoliddouble(char *str, t_float *stf)
{
	int					exp;
	char				tmp;
	char				*res;
	int					j;

	j = -1;
	tmp = str[11];
	str[11] = '\0';
	exp = ft_btoi(str) - 1023;
	EXP = exp;
	str[11] = tmp;
	res = ft_strnew(exp + 1);
	res[0] = '1';
	while (++j != exp)
		res[j + 1] = str[11 + j];
	SOL = ft_itoa(ft_btoi(res));
	free(res);
}

t_float		*getbindouble(double a, t_float *stf, t_specs *st)
{
	uint64_t	*c;
	char		*str;
	int			i;
	char		*tmp;

	i = -1;
	c = (uint64_t *)&a;
	str = ft_strnew(64);
	tmp = ft_itoa_base(*c, 2);
	str = str + 64 - ft_strlen(tmp);
	str = ft_strcpy(str, tmp);
	str = str - (64 - ft_strlen(tmp));
	while ((str[++i] != '0') && (str[i] != '1'))
		str[i] = '0';
	SIGN = (str[0] == '0') ? 0 : 1;
	getsoliddouble(str + 1, stf);
	getmantdouble(a, stf, st);
	return (stf);
}
