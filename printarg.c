/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:39:58 by ction             #+#    #+#             */
/*   Updated: 2019/08/08 18:40:01 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_returnvalue;

void	printstr(t_specs *st, char *str, int i)
{
	char	c;

	// printf("%d \n ----\n", PREC);
	PREC = ((PREC > ft_strlen(str)) ? ft_strlen(str) : PREC);
	c = (((st->fl / 10000) == 1) ? '0' : ' ');
	if ((st->fl / 10) == 1)
	{
		if ((st->width == -1) && (g_returnvalue = PREC))
			write(1, str, PREC);
		else if (st->width > 0)
		{
			write(1, str, PREC);
			g_returnvalue += st->width;
			while (++i != st->width - PREC)
				write(1, &c, 1);
		}
	}
	// if (st->width > 0)
	// {
	// 	g_returnvalue += st->width;
	// 	while (++i != st->width - 1)
	// 		write(1, &c, 1);
	// 	write(1, &letter, 1);
	// }
}

void	printchar(t_specs *st, int letter, int i)
{
	char	c;

	c = (((st->fl / 10000) == 1) ? '0' : ' ');
	if ((st->fl / 10) == 1)
	{
		if ((st->width == -1) && (g_returnvalue = 1))
			write(1, &letter, 1);
		else if (st->width > 0)
		{
			write(1, &letter, 1);
			g_returnvalue += st->width;
			while (++i != st->width - 1)
				write(1, &c, 1);
		}
	}
	if (st->width > 0)
	{
		g_returnvalue += st->width;
		while (++i != st->width - 1)
			write(1, &c, 1);
		write(1, &letter, 1);
	}
}

void	printarg(t_specs *st, va_list vl)
{
	int	i;

	i = -1;
	if (st->spec == 'c')
		printchar(st, va_arg(vl, int), i);
	(st->spec == 's') ? printstr(st, va_arg(vl, char *), i) : 0;
}
