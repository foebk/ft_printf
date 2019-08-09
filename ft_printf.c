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
	if (st != NULL)
		free(st);
	return (RETV);
}

int	main()
{
	printf("| %d - symbol count ft_printf\n", ft_printf("%3c", 'c'));
	printf("| %d - symbol count\n", printf("%3c", 'c'));
	return 0;
}
