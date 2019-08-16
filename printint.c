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
	if ((flag == 2) && (WID--))
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

void				printwminus(t_specs *st, long long int b, int i, char *ret)
{
	((st->fl % 10 == 1) || (st->fl % 10000 / 1000 == 1) || (b < 0)) ?
		paramsproc(0, st, 2, b) : 0;
	while (++i < PREC - (int)ft_strlen(ret))
		write(1, "0", 1);
	ft_putstr(ret);
	i = -1;
	PREC = (PREC > (int)ft_strlen(ret) ? PREC : (int)ft_strlen(ret));
	while (++i < WID - PREC)
		write(1, " ", 1);
	RETV += ((WID > PREC) ? WID : PREC);
}

void				printwominus(t_specs *st, long long int b, int i, char *ret)
{
	char c;

	i = 0;
	c = (((st->fl / 10000 == 1) && (PREC == -1)) ? '0' : ' ');
	if ((PREC >= WID) || (c == '0'))
	{
		((st->fl % 10 == 1) || (st->fl % 10000 / 1000 == 1) || (b < 0)) ?
			paramsproc(0, st, 2, b) : 0;
		i--;
	}
	(b < 0) ? 0 : i--;
	while (++i < WID - (PREC > (int)ft_strlen(ret) ? PREC :
		(int)ft_strlen(ret)))
		write(1, &c, 1);
	if ((PREC < WID) && (c != '0'))
		((st->fl % 10 == 1) || (st->fl % 10000 / 1000 == 1) || (b < 0)) ?
			paramsproc(0, st, 2, b) : 0;
	i = -1;
	while (++i < PREC - (int)ft_strlen(ret))
		write(1, "0", 1);
	ft_putstr(ret);
	PREC = (PREC > (int)ft_strlen(ret) ? PREC : (int)ft_strlen(ret));
	RETV += ((WID > PREC) ? WID : PREC);
}

int					printint(t_specs *st, void *a, int i)
{
	long long int	b;
	char			*ret;
	char			*ptr;

	b = 0;
	b = (SIZE != -1 ? paramsproc(a, st, 1, 0) : (int)a);
	if ((ret = ft_itoa(b)) == 0)
		return (-1);
	ptr = ret;
	ret = (b < 0) ? ret + 1 : ret;
	if (st->fl % 100 / 10 == 1)
		printwminus(st, b, i, ret);
	else
		printwominus(st, b, i, ret);
	ft_strdel(&ptr);
	return (1);
}
