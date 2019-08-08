#include "ft_printf.h"

int		g_returnvalue = 0;

int		pstr(char *str) /* вывод строки */
{
	if (str == NULL)
	{
		ft_putstr("(null)");
		g_returnvalue += 6;
		return (2);
	}
	ft_putstr(str);
	g_returnvalue += ft_strlen(str);
	return (2);
}

int		pchar(char letter) /* вывод символа  */
{
	write(1, &letter, 1);
	g_returnvalue++;
	return (2);
}

int		padr(uint64_t a) /* вывод адреса */
{
	int			i;
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
	g_returnvalue += ft_strlen(result);
	free(result);
	return (2);
}

char	*ft_printto(char *str)
{
	int i;

	i = 0;
	while ((str[i] != '%') && (str[i]))
		i++;
	write(1, str, i);
	g_returnvalue += i;
	return (str + i);
}

int		ft_printf(char *str, ...)
{
	va_list	vl;
	int		i;

	va_start(vl, str);
	if (str[0] == '\0')
		return (0);
	while (str[0] != '\0')
	{
		str = ft_printto(str);
		if (str[0] == '\0') /* если строка закончилась */
			break ;
		if (str[0] == '%') /* если встретился спецификатор */
			i = specificator(str, vl);
		if (i == 0)
			return (0);
		str += i;
	}
	return (g_returnvalue);
}

int main()
{
	// printf("%d\n", printf("aasdasd %p asdasd %ca\n", 4, 0));
	// printf("%d\n", ft_printf("%-+#p", 3));
	ft_printf("%+-# 030.1000hhx", 3);
	return 0;
}
