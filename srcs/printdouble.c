/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:53:19 by ction             #+#    #+#             */
/*   Updated: 2019/08/30 17:53:23 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printdouble(t_specs *st, double a, int i)
{
	t_float *stf;
	
	stf = ft_memalloc(sizeof(t_float));
	stf = getbindouble(a, stf);
	printf("%s --- MANTISSA\n", MANT);
	printf("%s --- SOLID\n", SOL);
	printf("%d --- SIGN\n", SIGN);
}
