#include <stdint.h>
#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

void	*getmantfloat(char *str, t_float *stf)
{
	int		i;
	int		j;
	float	a;

	i = -1;
	j = 1;
	printf("%s\n", str);
	while (str[++i] != '\0')
	{
		str[i] != '0' ? a += ft_powerneg(2, j) : 0;
		ft_powerneg(2, j) / 0.1 == 0 ? a *= 10 : 0;
		j++;
	}
	printf("%.20f\n", a);
	return (NULL);
}

void	*getsolidfloat(char *str, t_float *stf)
{
	int					exp;
	char				tmp;
	char				*res;
	int					j;
	char				*result;

	j = -1;
	tmp = str[8];
	str[8] = '\0';
	exp = ft_btoi(str) - 127;
	EXP = exp;
	str[8] = tmp;
	res = ft_strnew(exp + 1);
	res[0] = '1';
	while (++j != exp)
		res[j + 1] = str[8 + j];
	SOL = ft_itoa(ft_btoi(res));
	free(res);
}

t_float	*getbinfloat(float a, t_float *stf)
{
	uint32_t	*c;
	char		*str;
	int			i;
	char		*tmp;

	i = -1;
	c = (uint32_t *)&a;
	str = ft_strnew(32);
	tmp = ft_itoa_base(*c, 2);
	str = str + 32 - ft_strlen(tmp);
	str = ft_strcpy(str, tmp);
	str = str - (32 - ft_strlen(tmp));
	while ((str[++i] != '0') && (str[i] != '1'))
		str[i] = '0';
	SIGN = (str[0] == '0') ? 0 : 1;
	getsolidfloat(str + 1, stf);
	MANT = getmantfloat(str + 9 + EXP, stf);
	return (stf);
}
