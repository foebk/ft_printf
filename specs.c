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

t_specs	*structinit(void)
{
	t_specs	*st;

	if (!(st = malloc(sizeof(t_specs))))
		return (NULL);
	st->fl = 0;
	st->width = -1;
	st->precision = -1;
	st->size = -1;
	st->spec = 0;
	return (st);
}

int		readwidth(char *s, int *i)
{
	int		j;
	int		k;
	char	*width;

	(*i)--;
	j = 0;
	while ((s[++(*i)] >= '0') && (s[*i] <= '9'))
		j++;
	if (!(width = ft_memalloc(sizeof(char) * j + 1)))
		return (-1);
	k = 0;
	(*i) = (*i) - j;
	while (k != j)
	{
		width[k] = s[*i];
		k++;
		(*i)++;
	}
	k = ft_atoi(width);
	free(width);
	return (k);
}

void	readflags(char *s, int *i, t_specs *st, short int flag)
{
	if (flag == 1)
		while ((s[++(*i)] == '-') || (s[(*i)] == '+') || (s[(*i)] == '#') ||
			(s[(*i)] == '0') || (s[(*i)] == ' '))
		{
			st->fl += ((s[(*i)] == '0') && (st->fl / 10000 != 1)) ? 10000 : 0;
			st->fl += ((s[(*i)] == ' ') && (st->fl % 10000
				/ 1000 != 1)) ? 1000 : 0;
			st->fl += ((s[(*i)] == '#') && (st->fl % 1000 /
				100 != 1)) ? 100 : 0;
			st->fl += ((s[(*i)] == '-') && (st->fl % 100 / 10 != 1)) ? 10 : 0;
			st->fl += ((s[(*i)] == '+') && (st->fl % 10 != 1)) ? 1 : 0;
		}
	if (flag == 2)
	{
		st->size = ((s[*i] == 'l') && (s[(*i) + 1] != 'l')) ? 0 : st->size;
		st->size = ((s[*i] == 'l') && (s[(*i) + 1] == 'l')) ? 1 : st->size;
		st->size = ((s[*i] == 'h') && (s[(*i) + 1] != 'h')) ? 2 : st->size;
		st->size = ((s[*i] == 'h') && (s[(*i) + 1] == 'h')) ? 3 : st->size;
		st->size = (s[*i] == 'L') ? 4 : st->size;
		*i = *i + (((st->size == 0) || (st->size % 2 == 0)) ? 1 : 2);
		*i = *i - ((st->size == -1) ? 2 : 0);
	}
}

void	readspec(char *s, int *i, t_specs *st)
{
	st->spec = ((s[*i] == 'c') || (s[*i] == 's') || (s[*i] == 'p')
		|| (s[*i] == 'd') || (s[*i] == 'i') || (s[*i] == 'o')
			|| (s[*i] == 'u') || (ft_toupper(s[*i]) == 'X') ||
				(s[*i] == 'f')) ? s[*i] : st->spec;
}

t_specs	*specificator(char *s, int *ptr)
{
	t_specs		*st;
	int			i;

	i = 0;
	if ((st = structinit()) == NULL)
		return (0);
	readflags(s, &i, st, 1);
	if ((s[i] != '.') && ((s[i] >= '0') && (s[i] <= '9')))
		if ((st->width = readwidth(s, &i)) == -1)
			return (0);
	if (s[i] == '.')
	{
		if ((s[++i] >= '0') && (s[i] <= '9'))
		{
			if ((st->precision = readwidth(s, &i)) == -1)
				return (0);
		}
		else
			st->precision = 0;
	}
	readflags(s, &i, st, 2);
	readspec(s, &i, st);
	*ptr = i + 1;
	// printf("%d --- flags\n", st->fl);
	// printf("%d --- width\n", st->width);
	// printf("%d --- precision\n", st->precision);
	// printf("%hd --- size\n", st->size);
	// printf("%c --- flag\n ------------ \n",st->spec);
	return (st);
}
