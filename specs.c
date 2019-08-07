/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:14:36 by ction             #+#    #+#             */
/*   Updated: 2019/08/07 17:14:37 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int		g_returnvalue;

void	readflags(char *s, int *i, t_specs *st, int flag)
{
	if (flag == 1)
		while ((s[++(*i)] == '-') || (s[(*i)] == '+') || (s[(*i)] == '#') || (s[(*i)] == '0') || (s[(*i)] == ' '))
		{
			st->fl += ((s[(*i)] == '0') && (st->fl / 10000 != 1)) ? 10000 : 0;
			st->fl += ((s[(*i)] == ' ') && (st->fl % 10000 / 1000 != 1)) ? 1000 : 0;
			st->fl += ((s[(*i)] == '#') && (st->fl % 1000 / 100 != 1)) ? 100 : 0;
			st->fl += ((s[(*i)] == '-') && (st->fl % 100 / 10 != 1)) ? 10 : 0;
			st->fl += ((s[(*i)] == '+') && (st->fl % 10 != 1)) ? 1 : 0;
		}
}

int		specificator(char *s, va_list vl)
{
	int			retspecvalue; /* перемещение на n-единиц указателя str; */
	t_specs		*st;
	int			i;

	i = 0;
	if ((!(st = malloc(sizeof(t_specs)))))
		return (0);
	readflags(s, &i, st, 1);
	printf("%d\n", i);
    printf("%hd", st->fl);
	return (retspecvalue);
}
