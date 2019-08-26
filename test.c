#include <stdint.h>
#include "libft.h"
#include <limits.h>
#include <stdio.h>
int main()
{
	long double	a = 4.424;
	uint64_t	*c;

	c = (uint64_t *)&a;
	printf("%u\n", *(c+1));
	printf("~:%s\n", ft_itoa_base(a, 2));
	printf("-1:%s\n", ft_itoa_base(*(c - 1), 2));
	printf("0:%s\n", ft_itoa_base(*c, 2));
	printf("+1:%s\n", ft_itoa_base(*(c + 1), 2));

}
