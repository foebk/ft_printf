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
    while (res[++i] != '0' && (res[i] != '1'))
		res[i] = '0';
	stf->sign = res[0] == '0' ? 0 : 1;
}

int     printfl(t_specs *st, uint64_t b, int i)
{
    t_float *stf;

    getstruct(ft_itoa_base(b, 2), stf);
}
