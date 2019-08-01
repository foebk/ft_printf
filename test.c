#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include "libft.h"

char	*zerozerozero(char *str, size_t i)
{
	size_t	j;
	
	j = 0;
	while (j != i + 1)
	{
		str[i] = '0';
		j++;
	}
	return (str);
}

int test(uint64_t a)
{
	int 		i;
	uint64_t	b;
	char		*result;
	
	i = 2;
	b = a;
	while (a / 16 != 0)
	{
		a /= 16;
		i++;
	}
	result = ft_memalloc(sizeof(char *) * i);
	result[0] = '0';
	result[1] = 'x';
	while (i != 2)
	{
		if (b % 16 > 9)
		{
			printf("1");
			result[i] = 'a' + (b % 16 % 10);
		}
		else
			result[i] = '0' + (b % 16);
		b /= 16;
		i--;
	}
	printf("%s\n", result);
}

int main()
{
    uint64_t a;
    char *b = "hello";
    a = (uint64_t)b;
    // printf("%p\n", b);
    // printf("%ld\n", a);
	test(144);
}
