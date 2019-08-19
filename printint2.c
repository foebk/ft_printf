/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:31:20 by ction             #+#    #+#             */
/*   Updated: 2019/08/09 14:31:23 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	widthint(t_specs *st, long long int b, int i, char *r)
{
	((st->fl % 10 == 1) || (st->fl % 10000 / 1000 == 1) || (b < 0)) ?
		i = 0 : 0;
	while (++i < WID - (PREC > (int)ft_strlen(r) ? PREC : (int)ft_strlen(r)))
		write(1, " ", 1);
	((st->fl % 10 == 1) || (st->fl % 10000 / 1000 == 1) || (b < 0)) ?
		paramsproc(0, st, 2, b) : 0;
	i = 0;
	while (++i <= (PREC > (int)ft_strlen(r) ? PREC :
		(int)ft_strlen(r)) - (int)ft_strlen(r))
		write(1, "0", 1);
	ft_putstr(r);
}

void	zeroint(t_specs *st, long long int b, int i, char *r)
{
	char	c;

	((st->fl % 10 == 1) || (st->fl % 10000 / 1000 == 1) || (b < 0)) ?
		paramsproc(0, st, 2, b) : 0;
	while (++i < WID - (PREC > (int)ft_strlen(r) ? PREC : (int)ft_strlen(r)))
		write(1, "0", 1);
	ft_putstr(r);
}
