/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:05:52 by ction             #+#    #+#             */
/*   Updated: 2019/04/20 14:05:53 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_printable(char *c)
{
	int		i;

	i = 0;
	while (c[i] != '\0')
	{
		if (!((c[i] >= 32) && (c[i] < 127)))
			return (0);
		i++;
	}
	return (1);
}