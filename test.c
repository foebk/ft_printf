#include <stdint.h>
#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	double a = 4.24;
	
	printf("%f\n", a - (int)a);
}
