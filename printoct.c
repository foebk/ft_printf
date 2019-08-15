/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printoct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:02:16 by ction             #+#    #+#             */
/*   Updated: 2019/08/14 19:02:17 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_returnvalue;

unsigned long long int		paramsprococt(void *a, t_specs *st)
{
	unsigned long long int	b;

	b = ((SIZE == 0) ? (unsigned long int)a : b);
	b = ((SIZE == 1) ? (unsigned long long int)a : b);
	b = ((SIZE == 2) ? (unsigned short int)a : b);
	b = ((SIZE == 3) ? (unsigned char)a : b);
	return (b);
}

int							printoct(t_specs *st, void *a, int i)
{
	unsigned long long int	b;
	char					*ret;
	char					*ptr;

	b = 0;
	b = (SIZE != -1 ? paramsprococt(a, st) : 0);
	if ((ret = ft_itoa_base(b, 8)) == 0)
		return (-1);
	ft_putstr(ret);
	ft_strdel(&ret);
	return (1);
}
