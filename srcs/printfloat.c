/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 15:16:08 by ction             #+#    #+#             */
/*   Updated: 2019/08/23 15:16:09 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_returnvalue;

void		fparamsproc(t_float *stf, t_specs *st)
{
	char	c;

	c = ' ';
	if ((st->fl % 10 == 1) || (SIGN == 1))
		c = (SIGN == 1) ? '-' : '+';
	write(1, &c, 1);
	RETV++;
	WID--;
}

void		floatwminus(t_specs *st, t_float *stf, double a, int i)
{
	(a < 0 || st->fl % 10000 / 1000 == 1 || st->fl % 10 / 1 == 1) ?
		fparamsproc(stf, st) : 0;
	write(1, SOL, (int)ft_strlen(SOL));
	write(1, ".", 1);
	write(1, MANT, PREC > (int)ft_strlen(MANT) ? 52 : PREC);
	while ((int)ft_strlen(MANT) + ++i < PREC)
		write(1, "0", 1);
	i = 0;
	while (++i < WID - PREC - (int)ft_strlen(SOL) && write(1, " ", 1))
		RETV++;
	RETV += (int)ft_strlen(SOL) + PREC + 1;
}

void		floatwominus(t_specs *st, t_float *stf, double a, int i)
{
	i = (a < 0 || st->fl % 10000 / 1000 == 1 || st->fl % 10 / 1 == 1) ?
		0 : -1;
	if (st->fl / 10000 == 1)
	{
		(a < 0 || st->fl % 10000 / 1000 == 1 || st->fl % 10 / 1 == 1) ?
			fparamsproc(stf, st) : 0;
		while ((++i < WID - (int)ft_strlen(SOL) - PREC) && RETV++)
			write(1, "0", 1);
		write(1, SOL, (int)ft_strlen(SOL));
		write(1, ".", 1);
		write(1, MANT, PREC > (int)ft_strlen(MANT) ? 52 : PREC);
		i = -1;
		while ((int)ft_strlen(MANT) + ++i < PREC)
			write(1, "0", 1);
		RETV += (int)ft_strlen(SOL) + PREC + 1;
	}
}

void		zeroprecfl2(t_specs *st, t_float *stf, double a)
{
	int	i;

	i = (a < 0 || st->fl % 10000 / 1000 == 1 || st->fl % 10 / 1 == 1) ?
		0 : -1;
	while (++i < WID - (int)ft_strlen(SOL))
		write(1, " ", 1);
	(a < 0 || st->fl % 10000 / 1000 == 1 || st->fl % 10 / 1 == 1) ?
		fparamsproc(stf, st) : 0;
	write(1, SOL, (int)ft_strlen(SOL));
	RETV = (WID > (int)ft_strlen(SOL) ? RETV + WID : RETV +
		(int)ft_strlen(SOL));
}

void		zeroprecfl(t_specs *st, t_float *stf, double a)
{
	int	i;

	i = -1;
	if (st->fl % 100 / 10 == 1)
	{
		(a < 0 || st->fl % 10000 / 1000 == 1 || st->fl % 10 / 1 == 1) ?
			fparamsproc(stf, st) : 0;
		write(1, SOL, (int)ft_strlen(SOL));
		while (++i < WID - (int)ft_strlen(SOL))
			write(1, " ", 1);
		RETV = (WID > (int)ft_strlen(SOL) ? RETV + WID : RETV +
			(int)ft_strlen(SOL));
	}
	else if (st->fl / 10000 == 1)
	{
		(a < 0 || st->fl % 10000 / 1000 == 1 || st->fl % 10 / 1 == 1) ?
			fparamsproc(stf, st) : 0;
		while (++i < WID - (int)ft_strlen(SOL))
			write(1, "0", 1);
		write(1, SOL, (int)ft_strlen(SOL));
		RETV = (WID > (int)ft_strlen(SOL) ? RETV + WID : RETV +
			(int)ft_strlen(SOL));
	}
	else
		zeroprecfl2(st, stf, a);
}

int			printfl(t_specs *st, double a, int i)
{
	t_float	*stf;
	int		tmp;

	stf = ft_memalloc(sizeof(t_float));
	stf = getbinfloat((float)a, stf, a, st);
	if (PREC == 0)
		zeroprecfl(st, stf, a);
	else if (st->fl % 100 / 10 == 1)
		floatwminus(st, stf, a, -1);
	else
		floatwominus(st, stf, a, 0);
}
