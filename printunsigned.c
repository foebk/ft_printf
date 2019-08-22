/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:29:02 by ction             #+#    #+#             */
/*   Updated: 2019/08/22 14:29:03 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int          g_returnvalue;

char                *ft_utoa(unsigned long long n)
{
    unsigned long long  val;
    int                 i;
    char                *res;

    i = 0;
    val = n;
    while ((val / 10 != 0) && ++i)
		val /= 10;
    if ((res = malloc(sizeof(char) * (i + 2))) == 0)
		return (NULL);
    res[i + 1] = '\0';
    while (n / 10)
	{
		res[i] = (n % 10 + 48);
		n /= 10;
		i--;
	}
    res[i] = (n + '0');
    return (res);
}

void				printunsplus(t_specs *st, long long int b, int i, char *r)
{
	char	c;

    c = st->fl / 10000 == 1 && PREC == -1 ? '0' : ' ';
	st->fl = b == 0 ? (st->fl % 1000 / 100) : st->fl;
    PREC = ((PREC == -1) && (st->fl / 10000 == 1)) ? WID : PREC;
	PREC = (PREC < (int)ft_strlen(r)) ? (int)ft_strlen(r) : PREC;
	if ((PREC > WID) || (c == '0'))
	{
		while (i++ < PREC - (int)ft_strlen(r))
			write(1, "0", 1);
		ft_putstr(r);
	}
	else
	{  
        while (i++ < WID - PREC)
            write(1, " ", 1);
        i = 0;
        while (i++ < PREC - (int)ft_strlen(r))
            write(1, "0", 1);
        ft_putstr(r);
    }
	RETV += ((WID > PREC) ? WID : PREC);
	return ;
}

void				printunsminus(t_specs *st, int i, char *r)
{
	PREC = (int)ft_strlen(r) > PREC ? (int)ft_strlen(r) : PREC;
	while (i++ < PREC - (int)ft_strlen(r))
		write(1, "0", 1);
	ft_putstr(r);
	i = 0;
	while (i++ < WID - PREC)
		write(1, " ", 1);
	RETV += ((WID > PREC) ? WID : PREC);
	return ;
}

void				zeroprecisionuns(t_specs *st, int i)
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

int					printuns(t_specs *st, void *a, int i)
{
	unsigned long long int	b;
	char					*ret;

	b = (SIZE != -1 ? paramsprococt(a, st) : (unsigned int)a);
	if (!(ret = ft_utoa(b)))
		return (-1);
	if ((PREC <= 0) && ((unsigned long long)a == 0))
		zeroprecisionuns(st, 0);
	else if (st->fl % 100 / 10 == 1)
		printunsminus(st, i, ret);
	else
		printunsplus(st, b, i, ret);
	ft_strdel(&ret);
	return (1);
}
