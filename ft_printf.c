#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include <stdint.h>

int		returnvalue = 0;

int		pstr(char *str) // вывод строки
{
	if (str == NULL)
	{
		ft_putstr("(null)");
		returnvalue += 6;
		return (2);
	}
	ft_putstr(str);
	returnvalue += ft_strlen(str);
	return (2);
}

int		pchar(char letter) // вывод символа
{
	write(1, &letter, 1);
	returnvalue++;
	return (2);
}

int		padr(uint64_t a) // вывод адреса
{
	int 		i;
	uint64_t	b;
	char		*result;
	
	i = 2;
	b = a;
	while ((a / 16 != 0) && (i++))
		a /= 16;
	result = ft_memalloc(sizeof(char *) * i);
	result[0] = '0';
	result[1] = 'x';
	while (i != 1)
	{
		result[i] = (b % 16 > 9) ? 'a' + (b % 16 % 10) : '0' + (b % 16);
		b /= 16;
		i--;
	}
	ft_putstr(result);
	returnvalue += ft_strlen(result);
	free(result);
	return (2);
}

int		specificator(char *s, va_list vl)
{
	int	retspecvalue; // перемещение на n-единиц указателя str;

	(s[1] == 's') ? retspecvalue = pstr(va_arg(vl, char *)) : 0;
	(s[1] == 'c') ? retspecvalue = pchar(va_arg(vl, int)) : 0;
	(s[1] == 'p') ? retspecvalue = padr((uint64_t)(va_arg(vl, void *))) : 0;
	return (retspecvalue);
}

char	*ft_printto(char *str)
{
	int i;

	i = -1;
	while ((str[++i] != '%') && (str[i]));
	write(1, str, i);
	returnvalue += i;
	return (str + i);
}

int    ft_printf(char *str, ...)
{
	va_list	vl;
	int		i;

	va_start(vl, str);
	if (str[0] == '\0')
		return (0);
	while (str[0] != '\0')
	{
    	str = ft_printto(str);
		if (str[0] == '\0') // если строка закончилась
			break;
		if (str[0] == '%') // если встретился спецификатор
			i = specificator(str, vl);
		if (i == 0)
			return (0);
		str += i;
	}
	return (returnvalue);
}

int main()
{
	printf("%d\n", printf("aasdasd %p asdasd %ca\n", 4, 0));
	printf("%d\n", ft_printf("aasdasd %p asdasd %ca\n", 4, 0));
	return 0;
}
