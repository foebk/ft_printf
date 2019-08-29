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

int		printfl(t_specs *st, float a, int i)
{
	t_float	*stf;
	
	stf = ft_memalloc(sizeof(t_float));
	stf = getbinfloat(a, stf);
	printf("%d\n", SIGN);
	printf("%s\n", MANT);
	printf("%s\n", SOL);
	printf("%d\n", EXP);
}
