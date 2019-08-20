/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printoct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:12:07 by ction             #+#    #+#             */
/*   Updated: 2019/08/19 20:12:08 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	zerooct(t_specs *st, long long int b, int i, char *r)
{
	int		sh;

	sh = 1;
	(st->fl % 1000 / 100 != 1) ? sh = 0 : 0;
	(st->fl % 1000 / 100 == 1) ? write(1, "0", 1) : i--;
	while (++i < WID - (PREC > (int)ft_strlen(r) ? PREC : (int)ft_strlen(r)))
		write(1, "0", 1);
	ft_putstr(r);
	WID = (WID > (int)ft_strlen(r) + sh) ? WID : (int)ft_strlen(r) + sh;
	return ;
}

void	widthoct(t_specs *st, long long int b, int i, char *r)
{
	int		sh;

	sh = 1;
	(st->fl % 1000 / 100 != 1) ? sh = 0 : 0;
	PREC = (PREC > (int)ft_strlen(r) + sh) ? PREC : (int)ft_strlen(r) + sh;
	while (++i <= WID - PREC)
		write(1, " ", 1);
	(st->fl % 1000 / 100 == 1) ? write(1, "0", 1) : i--;
	i = 0;
	while (++i <= PREC - (int)ft_strlen(r) - sh)
		write(1, "0", 1);
	ft_putstr(r);
}
