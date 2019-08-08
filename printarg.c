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

int	printchar(t_specs *st, int letter, int i)
{
	char	c;

	c = (((st->fl / 10000) == 1) ? '0' : ' ');
	if ((st->fl / 100) == 1)
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

int	printarg(t_specs *st, va_list vl)
{
	int	i;

	i = -1;
	if (st->spec == 'c')
		printchar(st, va_arg(vl, int), i);
}
