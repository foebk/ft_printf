// #include <stdarg.h>
// #include <stdio.h>
// #include <stdint.h>
// #include "libft.h"

// char	*zerozerozero(char *str, size_t i)
// {
// 	size_t	j;
	
// 	j = 0;
// 	while (j != i + 1)
// 	{
// 		str[i] = '0';
// 		j++;
// 	}
// 	return (str);
// }

// char	*test(uint64_t a)
// {
// 	int 		i;
// 	uint64_t	b;
// 	char		*result;
	
// 	i = 2;
// 	b = a;
// 	while ((a / 16 != 0) && (i++))
// 		a /= 16;
// 	result = ft_memalloc(sizeof(char *) * i);
// 	result[0] = '0';
// 	result[1] = 'x';
// 	while (i != 1)
// 	{
// 		result[i] = (b % 16 > 9) ? 'a' + (b % 16 % 10) : '0' + (b % 16);
// 		b /= 16;
// 		i--;
// 	}
// 	return (result);
// }

int main()
{
	printf("%chello", 'c');
}
