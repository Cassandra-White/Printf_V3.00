#include "../ft_printf.h"

int		write_width(long num, t_flg *flg)
{
	int x;
	int size;
	int i;

	x = 0;
	i = flg->before;
    if (flg->after > ft_nb_len(num))
        size = flg->after;
    else
        size = ft_nb_len(num);
	i = i - (size + (num < 0));
	if (num < 0 && flg->align == 0 && flg->zero == 1)
		x = x + ft_putchar('-');
	if (num == 0 && flg->after == 0)
		i++;
	if (flg->zero == 1)
		while (i-- > 0)
			x = x + ft_putchar('0');
	else
		while (i-- > 0)
			x = x + ft_putchar(' ');
	if (num < 0 && flg->align == 0 && flg->zero == 0)
		x = x + ft_putchar('-');
	return (x);
}

int		write_sign(long num)
{
	int x;

	x = 0;
	if (num < 0)
		x = x + ft_putchar('-');
	return (x);
}

int		write_num(long num, t_flg *flg)
{
	int x;

	x = 0;
	if (num < 0)
		num = num * -1;
	if (num == 0 && flg->dot == 1 && flg->after == -1 && flg->ast == 1)
		x = x + ft_putchar('0');
	if (num == 0 && flg->after == 0)
		return (x);
	x = x + ft_putnbr(num);
	return (x);
}

int		write_prec(long num, t_flg *flg)
{
	int x;
	int i;

	i = flg->after;
	x = 0;
	if (num == 0 && flg->dot == 1 && flg->after == 0)
		return (x);
	while (i > ft_nb_len(num))
	{
		x = x + ft_putchar('0');
		i--;
	}
	return (x);
}

int		write_nbr(long num, t_flg flg)
{
	int x;

	x = 0;
	if (flg.dot == 1 && flg.after == -1 && flg.ast != -1)
		flg.after = 0;
	if (flg.after > -1)
		flg.zero = 0;
	if (flg.align == 0)
	{
		x = x + write_width(num, &flg);
		x = x + write_prec(num, &flg);
		x = x + write_num(num, &flg);
	}
	else
	{
		flg.zero = 0;
		x = x + write_sign(num);
		x = x + write_prec(num, &flg);
		x = x + write_num(num, &flg);
		x = x + write_width(num, &flg);
	}
	return (x);
}