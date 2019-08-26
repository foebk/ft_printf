/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 15:16:08 by ction             #+#    #+#             */
/*   Updated: 2019/08/23 15:16:09 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_float *getstruct(char *src, t_float *stf)
{
	char    c;
	char    *res;
	int     i;

	i = -1;
	res = ft_strnew(32);
	ft_strcpy(res + 32 - (int)ft_strlen(src), src);
	// while (res[++i] != '0' && (res[i] != '1'))
	// 	res[i] = '0';
	SIGN = res[0] == '0' ? 0 : 1;
	printf("%s\n", res);
	return (stf);
}

t_float	*convertnum(t_specs *st, t_float *stf)
{
	char	*tmp;
	int		texp;

	texp = EXP;
	EXP = EXP + (PREC == 0 ? 0 : PREC);
	tmp = ft_strndup(MANT, EXP + 1);
	tmp[EXP] > '4' ? tmp[EXP - 1]++ : 0;
	MANT = tmp;
	MANT[EXP] = '\0';
	EXP = texp;
	return (stf);
}

void	printflmin(t_specs *st, t_float *stf)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	SIGN == 1 ? write(1, "-", 1) : 0;
	SIGN != 1 && st->fl % 10 == 1 ? write(1, "+", 1) : 0;
	while (++i <= EXP)
		write(1, &MANT[i - 1], 1);
	i--;
	PREC != 0 ? write(1, ".", 1) : 0;
	while ((++i <= ft_strlen(MANT)) && (PREC >= 0) && (PREC + EXP >= i))
		write(1, &MANT[i - 1], 1);
	while (++j < PREC)
		write(1, "0", 1);
	while (++i + j <= WID)
		write(1, " ", 1);
}

int     printfl(t_specs *st, double b, int i)
{
    t_float		*stf;
	uint64_t	*bin;
	unsigned char	*d;

    stf = malloc(sizeof(t_float *));
	SIGN = 1;
	MANT = "12345";
	EXP = 1;
	PREC != 0 ? stf = convertnum(st, stf) : 0;
	if (st->fl % 100 / 10 == 1)
		printflmin(st, stf);
    // stf = getstruct(ft_itoa_base(b, 2), stf);
	// printf("%llu\n", *bin);
    // printf("%d\n", SIGN);
}
