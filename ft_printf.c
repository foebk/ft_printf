/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:04:02 by ction             #+#    #+#             */
/*   Updated: 2019/08/09 14:04:05 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_returnvalue = 0;

void	printarg(t_specs *st, va_list vl)
{
	int	i;

	i = -1;
	(SPEC == 'c') ? printchar(st, va_arg(vl, int), i) : 0;
	(SPEC == 's') ? printstr(st, va_arg(vl, char *), i) : 0;
	(SPEC == 'p') ? printadr(st, gadr((uint64_t)(va_arg(vl, void *))), i) : 0;
	((ft_tolower(SPEC) == 'd') || (SPEC == 'i')) ? 
	printint(st, va_arg(vl, void *), i) : 0;
	(ft_tolower(SPEC) == 'o') ? printoct(st, va_arg(vl, void *), 0) : 0;
	(ft_tolower(SPEC) == 'x') ? printhex(st, va_arg(vl, void *), 0) : 0;
	(SPEC == '%') ? printpercent(st, 0) : 0;
}

char	*ft_printto(char *str)
{
	int i;

	i = 0;
	while ((str[i] != '%') && (str[i]))
		i++;
	write(1, str, i);
	RETV += i;
	return (str + i);
}

int		ft_printf(char *str, ...)
{
	va_list	vl;
	t_specs	*st;
	int		i;

	i = 0;
	st = NULL;
	RETV = 0;
	va_start(vl, str);
	if (str[0] == '\0')
		return (0);
	while ((str[0] != '\0') && (str = ft_printto(str)))
	{
		if (str[0] == '\0')
			break ;
		if (str[0] == '%')
		{
			if (!(st = specificator(str, &i)))
				return (-1);
			printarg(st, vl);
		}
		str += i;
	}
	(st != NULL) ? free(st) : 0;
	return (RETV);
}

int	main()
{
	char	*a = "hello";
	char    *str = "%10.3p";

	printf("| %d - symbol count ft_printf\n", ft_printf("%.5p, %.p", 0, 0));
	printf("| %d - symbol count\n", printf("%.5p, %.p", 0, 0));
	return 0;
}
