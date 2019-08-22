/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:12:15 by ction             #+#    #+#             */
/*   Updated: 2019/08/22 12:12:18 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zerohex(t_specs *st, int i, char *r)
{
	int		sh;
	char	*zx;

	zx = (SPEC == 'X' ? "0X" : "0x");
	sh = 2;
	(st->fl % 1000 / 100 != 1) ? sh = 0 : 0;
	(st->fl % 1000 / 100 == 1) ? write(1, zx, 2) : 0;
	i = (st->fl % 1000 / 100 == 1) ? 1 : -1;
	while (++i < WID - (PREC > (int)ft_strlen(r) ? PREC : (int)ft_strlen(r)))
		write(1, "0", 1);
	ft_putstr(r);
	WID = (WID > (int)ft_strlen(r) + sh) ? WID : (int)ft_strlen(r) + sh;
	return ;
}

void	widthhex(t_specs *st, int i, char *r)
{
	int		sh;
	char	*zx;

	zx = (SPEC == 'X' ? "0X" : "0x");
	sh = 2;
	(st->fl % 1000 / 100 != 1) ? sh = 0 : 0;
	PREC = (PREC > (int)ft_strlen(r)) ? PREC : (int)ft_strlen(r);
	while (++i <= WID - PREC - sh)
		write(1, " ", 1);
	(st->fl % 1000 / 100 == 1) ? write(1, zx, 2) : 0;
	i = (st->fl % 1000 / 100 == 1) ? -2 : 0;
	while (++i <= PREC - (int)ft_strlen(r) - sh)
		write(1, "0", 1);
	ft_putstr(r);
}

char	*capitalize(char *ret)
{
	int	i;

	i = -1;
	while (ret[++i] != '\0')
		if (ret[i] >= 97 && ret[i] <= 122)
			ret[i] = ft_toupper(ret[i]);
	return (ret);
}
