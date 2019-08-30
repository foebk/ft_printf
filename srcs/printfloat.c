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

int			printfl(t_specs *st, double a, int i)
{
	t_float	*stf;
	int		tmp;

	PREC = (PREC > 0) ? PREC : 0;
	stf = ft_memalloc(sizeof(t_float));
	stf = getbinfloat((float)a, stf, a);
	printf("%s --- MANTISSA\n", MANT);
	printf("%s --- SOLID\n", SOL);
	printf("%d --- SIGN\n", SIGN);
	printf("%d --- EXPONENT\n", SIGN);
	if (st->fl % 100 / 10 == 1)
	{
		PREC = (PREC > 0) ? PREC : 0;
		tmp = PREC;
		((st->fl % 10 == 1) || (st->fl % 10000 / 1000 == 1) || (SIGN == 1)) ?
			fparamsproc(stf, st) : 0;
		write(1, SOL, ft_strlen(SOL));
		(PREC <= 0) && (st->fl % 1000 / 100 != 1) ? 0 : write(1, ".", 1);
		(int)ft_strlen(MANT) < PREC ? write(1, MANT, ft_strlen(MANT)) :
			write(1, MANT, PREC);
		while (--tmp - (int)ft_strlen(MANT) >= 0)
			write(1, "0", 1);
		while (WID - PREC - (int)ft_strlen(SOL) - ++i
			>= 0)
			write(1, " ", 1);
	}
}
