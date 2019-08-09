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

// void	printadr(t_specs *st, uint64_t a, int i)
// {
// 	uint64_t	b;
// 	char		*result;

// 	b = a;
// 	while ((a / 16 != 0) && (i++))
// 		a /= 16;
// 	result = ft_memalloc(sizeof(char *) * i + 1);
// 	while (i != 1)
// 	{
// 		result[i] = (b % 16 > 9) ? 'a' + (b % 16 % 10) : '0' + (b % 16);
// 		b /= 16;
// 		i--;
// 	}
// 	ft_putstr(result);
// 	g_returnvalue += ft_strlen(result);
// 	free(result);
// 	return (2);
// }

void	printstr(t_specs *st, char *str, int i)
{
	char	c;

	PREC = ((PREC > ft_strlen(str)) ? ft_strlen(str) : PREC);
	c = (((st->fl / 10000) == 1) ? '0' : ' ');
	if ((st->fl % 100 / 10) == 1)
	{
		if ((st->width == -1) && (g_returnvalue += PREC))
			write(1, str, PREC);
		else if (st->width > 0)
		{
			write(1, str, PREC);
			g_returnvalue += st->width;
			while (++i != st->width - PREC)
				write(1, " ", 1);
		}
		return ;
	}
	g_returnvalue += ((st->width > PREC) ? st->width : PREC);
	while (++i < st->width - PREC)
		write(1, &c, 1);
	write(1, str, PREC);
}

void	printchar(t_specs *st, int letter, int i)
{
	char	c;

	c = (((st->fl / 10000) == 1) ? '0' : ' ');
	if ((st->fl / 10) == 1)
	{
		if ((st->width == -1) && (g_returnvalue += 1))
			write(1, &letter, 1);
		else if (st->width > 0)
		{
			write(1, &letter, 1);
			g_returnvalue += st->width;
			while (++i != st->width - 1)
				write(1, &c, 1);
		}
		return ;
	}
	g_returnvalue += ((st->width == -1) ? 1 : st->width);
	while (++i < st->width - 1)
		write(1, &c, 1);
	write(1, &letter, 1);
}

void	printarg(t_specs *st, va_list vl)
{
	int	i;

	i = -1;
	(st->spec == 'c') ? printchar(st, va_arg(vl, int), i) : 0;
	(st->spec == 's') ? printstr(st, va_arg(vl, char *), i) : 0;
}
