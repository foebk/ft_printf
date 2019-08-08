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

int		readwidth(char *s, int *i, t_specs *st)
{
	int		j;
	int		k;
	char	*width;

	(*i)--;
	j = 0;
	while ((s[++(*i)] >= '0') && (s[*i] <= '9'))
		j++;
	if (!(width = ft_memalloc(sizeof(char) * j)))
		return (-1);
	k = 0;
	(*i) = (*i) - j;
	while (k != j)
	{
		width[k] = s[*i];
		k++;
		(*i)++;
	}
	return (ft_atoi(width));
}

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
	if (!(st = malloc(sizeof(t_specs))))
		return (0);
	st->width = 0;
	readflags(s, &i, st, 1);
	if (s[i] == '.')
	{
		i++;
		if ((st->precision = readwidth(s, &i, st)) == -1)
			return (0);
	}
	else
		if ((st->width = readwidth(s, &i, st)) == -1)
			return (0);
	printf("%d\n", st->width);
    printf("%d", st->precision);
	return (retspecvalue);
}
