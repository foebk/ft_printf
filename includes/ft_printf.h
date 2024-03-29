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
# define EXP stf->exp
# define MANT stf->mantissa
# define SIGN stf->sign
# define SOL stf->solid

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int					ft_printf(char *str, ...);

typedef struct		s_printf
{
	short int		fl;
	int				width;
	int				precision;
	short int		size;
	char			spec;
}					t_specs;

typedef struct		s_float
{
	short int		sign;
	char			*mantissa;
	char			*solid;
	int				exp;
}					t_float;

t_specs				*specificator(char *s, int *ptr);

void				printstr(t_specs *st, char *str, int i);
void				printadr(t_specs *st, char *adr, int i);
char				*gadr(uint64_t a);
void				printchar(t_specs *st, int letter, int i);

int					printint(t_specs *st, void *a, int i);
void				widthint(t_specs *st, long long int b, int i, char *r);
void				zeroint(t_specs *st, long long int b, int i, char *r);
long long int		paramsproc(void *a, t_specs *st, int flag, long long int d);

int					printoct(t_specs *st, void *a, int i);
void				zerooct(t_specs *st, int i, char *r);
void				widthoct(t_specs *st, int i, char *r);
unsigned long long	paramsprococt(void *a, t_specs *st);

void				printpercent(t_specs *st, int i);

int					printhex(t_specs *st, void *a, int i);
char				*capitalize(char *ret);
void				zerohex(t_specs *st, int i, char *r);
void				widthhex(t_specs *st, int i, char *r);

int					printuns(t_specs *st, void *a, int i);

int					printfl(t_specs *st, double b);
t_float				*getbinfloat(float a, t_float *stf, double d, t_specs *st);
int					printdouble(t_specs *st, double a, int i);
t_float				*getbindouble(double a, t_float *stf, t_specs *st);
int					printlongdouble(t_specs *st, long double a, int i);
t_float				*getbinlongdouble(long double a, t_float *stf, t_specs *st);
void				zeroprecfl2(t_specs *st, t_float *stf, double a);
void				zeroprecfl(t_specs *st, t_float *stf, double a, int i);
void				fparamsproc(t_float *stf, t_specs *st);

#endif
