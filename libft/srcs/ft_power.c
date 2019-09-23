/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:20:12 by ction             #+#    #+#             */
/*   Updated: 2019/08/27 14:20:13 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_power(int a, int b)
{
	int pow;

	pow = a;
	if (b == 0)
		return (1);
	while (--b != 0)
		a *= pow;
	return (a);
}
