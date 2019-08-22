/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:05:36 by ction             #+#    #+#             */
/*   Updated: 2019/08/07 13:05:37 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PREC st->precision
# define SPEC st->spec
# define WID st->width
# define SIZE st->size
# define RETV g_returnvalue

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int				ft_printf(char *str, ...);

typedef struct	s_printf
{
	short int		fl; /* 2^ (1 = '+' 10 = '-' 100 = '#' 1000 = ' ' 10000 = '0') */
	int				width;
	int				precision;
	short int		size; /* 0 = 'l' 1 = 'll' 2 = 'h' 3 = 'hh' 4 = 'L' */
	char			spec;
}				t_specs;

void				printstr(t_specs *st, char *str, int i);
void				printadr(t_specs *st, char *adr, int i);
char				*gadr(uint64_t a);
void				printchar(t_specs *st, int letter, int i);

int 				printint(t_specs *st, void *a, int i);
void				widthint(t_specs *st, long long int b, int i, char *r);
void				zeroint(t_specs *st, long long int b, int i, char *r);
long long int		paramsproc(void *a, t_specs *st, int flag, long long int d);
int					printoct(t_specs *st, void *a, int i);
void				zerooct(t_specs *st, int i, char *r);
void				widthoct(t_specs *st, int i, char *r);
int					printhex(t_specs *st, void *a, int i);

void				printpercent(t_specs *st, int i);
unsigned long long	paramsprococt(void *a, t_specs *st);

char				*capitalize(char *ret);
void				zerohex(t_specs *st, int i, char *r);
void				widthhex(t_specs *st, int i, char *r);


t_specs				*specificator(char *s, int *ptr);

#endif