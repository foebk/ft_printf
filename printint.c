/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:31:20 by ction             #+#    #+#             */
/*   Updated: 2019/08/09 14:31:23 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int			g_returnvalue;

long long int		paramsproc(void *a, t_specs *st, int flag, long long int d)
{
	long long int	b;
	char			c;

	if (flag == 1)
	{
		b = ((SIZE == 0) ? (long int)a : b);
		b = ((SIZE == 1) ? (long long int)a : b);
		b = ((SIZE == 2) ? (short int)a : b);
		b = ((SIZE == 3) ? (char)a : b);
		return (b);
	}
	if (flag == 2)
	{
		c = ' ';
		if ((st->fl % 10 == 1) || d < 0)
			c = (d < 0) ? '-' : '+';
		write(1, &c, 1);
		RETV++;
		return (0);
	}
	return (0);
}

void				printintwominus(t_specs *st, long long int b, int i)
{
	if (st->fl / 10000 == 1)
	{
		if (PREC > WID)
			((st->fl % 10 == 1) || (st->fl % 10000 / 1000 == 1) || (b < 0)) ?
				paramsproc(0, st, 2, b) : 0;
		ft_putstr(ft_itoa(b) + ((b < 0) ? 1 : 0));

	}
}

void				printint(t_specs *st, void *a, int i)
{
	long long int	b;

	b = 0;
	b = (SIZE != -1 ? paramsproc(a, st, 1, 0) : (int)a);
	i = (b < 0) ? -2 : -1;
	if (st->fl % 100 / 10 == 1)
	{
		((st->fl % 10 == 1) || (st->fl % 10000 / 1000 == 1) || (b < 0)) ?
			paramsproc(0, st, 2, b) : 0;
		while (++i < PREC - (int)ft_strlen(ft_itoa(b)))
			write(1, "0", 1);
		(b < 0) ? PREC++ : 0;
		printf("%lld\n", b);
		ft_putstr(ft_itoa(b) + ((b < 0) ? 1 : 0));
		i = -1;
		PREC = (PREC > (int)ft_strlen(ft_itoa(b)) ? PREC : (int)ft_strlen(ft_itoa(b)));
		while (++i < WID - PREC)
			write(1, " ", 1);
		RETV += ((WID > PREC) ? WID  : PREC );
	}
	else
		printintwominus(st, b, -1);
	return ;
}
