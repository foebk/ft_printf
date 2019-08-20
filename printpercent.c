/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpercent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:11:51 by ction             #+#    #+#             */
/*   Updated: 2019/08/19 20:11:52 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

extern int	g_returnvalue;

void		printpercent(t_specs *st, int i)
{
	char	c;

	c = st->fl / 10000 == 1 ? '0' : ' ';
	if (st->fl % 100 / 10 == 1)
	{
		write(1, "%%", 1);
		while (++i < WID)
			write(1, " ", 1);
	}
	else
	{
		while (++i < WID)
			write(1, &c, 1);
		write(1, "%%", 1);
	}
	RETV += (WID < 0 ? 1 : WID);
}
