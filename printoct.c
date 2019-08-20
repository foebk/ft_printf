/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printoct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:02:16 by ction             #+#    #+#             */
/*   Updated: 2019/08/14 19:02:17 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_returnvalue;

unsigned long long	paramsprococt(void *a, t_specs *st)
{
	unsigned long long int	b;

	b = ((SIZE == 0) ? (unsigned long int)a : b);
	b = ((SIZE == 1) ? (unsigned long long int)a : b);
	b = ((SIZE == 2) ? (unsigned short int)a : b);
	b = ((SIZE == 3) ? (unsigned char)a : b);
	return (b);
}

void				printoctplus(t_specs *st, long long int b, int i, char *r)
{
	int		sh;
	char	c;

	c = (((st->fl / 10000 == 1) && (PREC == -1)) ? '0' : ' ');
	sh = 0;
	st->fl = b == 0 ? (st->fl % 1000 / 100) : st->fl;
	(st->fl % 1000 / 100 != 1) ? sh = 0 : 0;
	if (PREC > WID)
	{
		PREC = (PREC < (int)ft_strlen(r)) ? (int)ft_strlen(r) : PREC;
		if ((st->fl % 1000 / 100 == 1) && (write(1, "0", 1)))
			sh = 1;
		sh == 1 ? i++ : 0;
		while (i++ < PREC - (int)ft_strlen(r))
			write(1, "0", 1);
		ft_putstr(r);
		sh == 1 && PREC > (int)ft_strlen(r) ? PREC-- : 0;
	}
	else if (c == '0')
		zerooct(st, b, i, r);
	else
		widthoct(st, b, i, r);
	RETV += ((WID > PREC) ? WID : PREC + sh);
	return ;
}

void				printoctminus(t_specs *st, long long int b, int i, char *r)
{
	int	sh;

	sh = 1;
	(st->fl % 1000 / 100 != 1) ? sh = 0 : 0;
	PREC = (int)ft_strlen(r) > PREC ? (int)ft_strlen(r) : PREC;
	(st->fl % 10000 / 1000 == 1) ? PREC = 0 : 0;
	(st->fl % 1000 / 100 == 1) ? write(1, "0", 1) : 0;
	while (i++ < PREC - (int)ft_strlen(r) - sh)
		write(1, "0", 1);
	ft_putstr(r);
	i = 0;
	sh == 1 && PREC > (int)ft_strlen(r) ? i-- : 0;
	while (i++ < WID - PREC - sh)
		write(1, " ", 1);
	RETV += ((WID > PREC) ? WID : PREC + sh);
	return ;
}

void				zeroprecisionoct(t_specs *st, int i)
{
	int		j;
	char	c;

	j = 1;
	c = st->fl / 10000 == 1 ? '0' : ' ';
	if ((PREC == 0) && (st->fl % 100 / 10 != 1))
	{
		while (++i <= WID - (st->fl % 1000 / 100 == 1 ? 1 : 0))
			write(1, " ", 1);
		(st->fl % 1000 / 100 == 1) ? write(1, "0", 1) : j--;
	}
	else if ((st->fl % 100 / 10 == 1) && (write(1, "0", 1)))
		while (++i <= WID - 1)
			write(1, &c, 1);
	else
	{
		while (++i <= WID - 1)
			write(1, &c, 1);
		write(1, "0", 1);
	}
	RETV += (WID <= 0) ? j : WID;
}

int					printoct(t_specs *st, void *a, int i)
{
	unsigned long long int	b;
	char					*ret;
	char					*ptr;

	b = (SIZE != -1 ? paramsprococt(a, st) : (unsigned int)a);
	if (!(ret = ft_itoa_base(b, 8)))
		return (-1);
	if ((PREC <= 0) && ((int)a == 0))
		zeroprecisionoct(st, 0);
	else if (st->fl % 100 / 10 == 1)
		printoctminus(st, b, i, ret);
	else
		printoctplus(st, b, i, ret);
	ft_strdel(&ret);
	return (1);
}
