#include "ft_printf.h"

extern int	g_returnvalue;

void				printhexplus(t_specs *st, long long int b, int i, char *r)
{
	int		sh;
	char	c;
	char	*zx;

	zx = (SPEC == 'X' ? "0X" : "0x");
	c = (((st->fl / 10000 == 1) && (PREC == -1)) ? '0' : ' ');
	sh = 2;
	st->fl = b == 0 ? (st->fl % 1000 / 100) : st->fl;
	(st->fl % 1000 / 100 != 1) ? sh = 0 : 0;
	if (PREC > WID)
	{
		sh = 0;
		PREC = (PREC < (int)ft_strlen(r)) ? (int)ft_strlen(r) : PREC;
		if ((st->fl % 1000 / 100 == 1) && (write(1, zx, 2)))
			sh = 2;
		while (i++ < PREC - (int)ft_strlen(r))
			write(1, "0", 1);
		ft_putstr(r);
		sh == 1 && PREC > (int)ft_strlen(r) ? PREC-- : 0;
	}
	else if (c == '0')
		zerohex(st, i, r);
	else
		widthhex(st, i, r);
	RETV += ((WID > PREC) ? WID : PREC + sh);
	return ;
}

void				printhexminus(t_specs *st, int i, char *r)
{
	int		sh;
	char	*zx;

	zx = (SPEC == 'X' ? "0X" : "0x");
	sh = 2;
	(st->fl % 1000 / 100 != 1) ? sh = 0 : 0;
	PREC = (int)ft_strlen(r) > PREC ? (int)ft_strlen(r) : PREC;
	(st->fl % 10000 / 1000 == 1) ? PREC = 0 : 0;
	(st->fl % 1000 / 100 == 1) ? write(1, zx, 2) : 0;
	while (i++ < PREC - (int)ft_strlen(r))
		write(1, "0", 1);
	ft_putstr(r);
	i = 0;
	sh == 1 && PREC > (int)ft_strlen(r) ? i-- : 0;
	while (i++ < WID - PREC - sh)
		write(1, " ", 1);
	RETV += ((WID > PREC) ? WID : PREC + sh);
	return ;
}

void				zeroprecisionhex(t_specs *st, int i)
{
	int		j;
	char	c;

	j = 0;
	c = st->fl / 10000 == 1 ? '0' : ' ';
	if ((PREC == 0) && (st->fl % 100 / 10 != 1))
		while (++i <= WID)
			write(1, " ", 1);
	else if (st->fl % 100 / 10 == 1)
		while (++i <= WID)
			write(1, " ", 1);
	else
	{
		while (++i <= WID - 1)
			write(1, &c, 1);
		write(1, "0", 1);
		j = 1;
	}
	RETV += (WID <= 0) ? j : WID;
}

int					printhex(t_specs *st, void *a, int i)
{
	unsigned long long int	b;
	char					*ret;

	b = (SIZE != -1 ? paramsprococt(a, st) : (unsigned int)a);
	if (!(ret = ft_itoa_base(b, 16)))
		return (-1);
	SPEC == 'X' ? ret = capitalize(ret) : 0;
	if ((PREC <= 0) && ((unsigned long long)a == 0))
		zeroprecisionhex(st, 0);
	else if (st->fl % 100 / 10 == 1)
		printhexminus(st, i, ret);
	else
		printhexplus(st, b, i, ret);
	ft_strdel(&ret);
	return (1);
}
