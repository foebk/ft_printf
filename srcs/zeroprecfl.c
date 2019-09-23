/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeroprecfl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:49:39 by ction             #+#    #+#             */
/*   Updated: 2019/09/23 20:49:40 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


extern int  g_returnvalue;

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

void		zeroprecfl(t_specs *st, t_float *stf, double a, int i)
{
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
	if ((st->fl % 1000 / 100 == 1) && write(1, ".", 1))
		RETV++;
}
