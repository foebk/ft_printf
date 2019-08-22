/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtxt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:39:58 by ction             #+#    #+#             */
/*   Updated: 2019/08/08 18:40:01 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_returnvalue;

char	*gadr(uint64_t a)
{
	uint64_t	b;
	char		*result;
	int			i;

	i = 0;
	b = a;
	while ((a / 16 != 0) && (++i))
		a = a / 16;
	result = ft_memalloc(sizeof(char *) * i + 2);
	while (i != -1)
	{
		result[i] = (b % 16 > 9) ? 'a' + (b % 16 % 10) : '0' + (b % 16);
		b /= 16;
		i--;
	}
	return (result);
}

void	printadrwominus(t_specs *st, char *adr, int i)
{
	PREC = (PREC > (int)ft_strlen(adr) ? PREC : (int)ft_strlen(adr));
	while (++i < WID - PREC - 2)
		write(1, " ", 1);
	write(1, "0x", 2);
	i = -1;
	while (++i < PREC - (int)ft_strlen(adr))
		write(1, "0", 1);
	ft_putstr(adr);
	RETV += ((WID > PREC ? WID : PREC + 2));
	free(adr);
}

void	printadr(t_specs *st, char *adr, int i)
{
	char	c;

	if ((st->fl % 100 / 10) == 1)
	{
		write(1, "0x", 2);
		PREC = (PREC > (int)ft_strlen(adr) ? PREC : (int)ft_strlen(adr));
		while (++i < PREC - (int)ft_strlen(adr))
			write(1, "0", 1);
		ft_putstr(adr);
		i = -1;
		while (++i < WID - PREC - 2)
			write(1, " ", 1);
		RETV += ((WID > PREC ? WID : PREC + 2));
		free(adr);
		return ;
	}
	printadrwominus(st, adr, i, c);
}

void	printstr(t_specs *st, char *str, int i)
{
	char	c;

	if (str == NULL)
		str = "(null)";
	PREC = ((PREC > (int)ft_strlen(str) && (PREC > 0)) ?
		(int)ft_strlen(str) : PREC);
	PREC = (PREC < 0) ? (int)ft_strlen(str) : PREC;
	c = (((st->fl / 10000) == 1) ? '0' : ' ');
	if ((st->fl % 100 / 10) == 1)
	{
		if ((WID == -1) && (RETV += PREC))
			write(1, str, PREC);
		else if ((WID > 0) && (i = -1))
		{
			write(1, str, PREC);
			RETV += (WID > PREC ? WID : PREC);
			while (++i < WID - PREC)
				write(1, " ", 1);
		}
		return ;
	}
	RETV += ((WID > PREC) ? WID : PREC);
	while (++i < WID - PREC)
		write(1, &c, 1);
	write(1, str, PREC);
}

void	printchar(t_specs *st, int letter, int i)
{
	char	c;

	c = (((st->fl / 10000) == 1) ? '0' : ' ');
	if ((st->fl % 100 / 10) == 1)
	{
		if ((WID == -1) && (RETV += 1))
			write(1, &letter, 1);
		else if (WID > 0)
		{
			write(1, &letter, 1);
			RETV += WID;
			while (++i != WID - 1)
				write(1, &c, 1);
		}
		return ;
	}
	RETV += ((WID == -1) ? 1 : WID);
	while (++i < WID - 1)
		write(1, &c, 1);
	write(1, &letter, 1);
}
