/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printldouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:59:20 by ction             #+#    #+#             */
/*   Updated: 2019/08/30 19:59:21 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printlongdouble(t_specs *st, long double a, int i)
{
    t_float *stf;
	
	stf = ft_memalloc(sizeof(t_float));
	stf = getbinlongdouble(a, stf, st);
	printf("%s --- MANTISSA\n", MANT);
	printf("%s --- SOLID\n", SOL);
	printf("%d --- SIGN\n", SIGN);
	printf("%d --- EXP\n", EXP);
}
