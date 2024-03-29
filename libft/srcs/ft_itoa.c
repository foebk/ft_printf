/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:10:21 by ction             #+#    #+#             */
/*   Updated: 2019/04/15 21:10:22 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_dest(long long int n, int i, char *dest)
{
	while ((n % 10 != 0) || (n / 10 != 0))
	{
		dest[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (dest);
}

static char		*ft_zeroatoi(void)
{
	char	*dest;

	dest = ft_strnew(1);
	dest[0] = '0';
	return (dest);
}

static int		ft_intlen(long long int n)
{
	int	i;

	i = 0;
	while (n / 10 != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(unsigned long long n)
{
	int					i;
	long long int		num;
	char				*dest;

	num = n;
	if ((unsigned long int)n == -9223372036854775808UL)
	{
		if (!(dest = ft_memalloc(sizeof(char) * 21)))
			return (NULL);
		dest = ft_strdup("-9223372036854775808");
		return (dest);
	}
	if (num == 0)
		return (ft_zeroatoi());
	i = ft_intlen(num);
	num < 0 ? i++ : 0;
	if (!(dest = malloc(sizeof(char) * (i + 2))))
		return (NULL);
	if ((num < 0) && (dest[0] = '-'))
		num = num * -1;
	i++;
	dest[i] = '\0';
	i--;
	return (ft_dest(num, i, dest));
}
