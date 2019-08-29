#include <stdint.h>
#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	double a;
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i != 20)
	{
		a += ft_powerneg(2, j);
		ft_powerneg(2, j) / 0.1 == 0 ? a *= 10 : 0;
		j++;
		printf("%f\n", ft_powerneg(2, j));
	}
}
