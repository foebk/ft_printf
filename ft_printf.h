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

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(char *str, ...);
int		specificator(char *s, va_list vl);

typedef struct	s_printf
{
	short int		fl; /* 2^ (0 = '+' 1 = '-' 2 = '#' 3 = ' ' 4 = '0') */
	int				width;
	int				precision;
	short int		size; /* 0 = 'l' 1 = 'll' 2 = 'h' 3 = 'hh' 4 = 'L' */
	char			spec;
}				t_specs;

#endif
