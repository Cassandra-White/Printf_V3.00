#include "../ft_printf.h"

int		ft_write_ptr(long ptr, t_flg flg)
{
	int x;

	x = 0;
	if (ptr == 0 && flg.dot == 1 && flg.after == 0)
		return (x);
    if (ptr == -2147483648)
        printf("je suis le meilleur");
	if (ptr > 15)
		x += ft_write_ptr((ptr / 16), flg);
	x += ft_print_ptr(ptr % 16);
	return (x);
}


int		write_width_ptr(unsigned long num, t_flg *flg)
{
	int x;
	int size;
	int i;

	x = 0;
	i = flg->before;
	size = (flg->after > ft_ptr_len(num)) ? flg->after : ft_ptr_len(num);
	i -= size;
	if (num == 0 && flg->after == 0)
		i++;
	if (flg->zero == 1)
		while (i-- > 0)
			x += ft_putchar('0');
	else
		while (i-- > 0)
			x += ft_putchar(' ');
	return (x);
}

int		write_prec_ptr(long num, t_flg *flg)
{
	int x;
	int i;

	i = flg->after;
	x = 0;
	while (i > (ft_ptr_len(num) - 2))
	{
		x += ft_putchar('0');
		i--;
	}
	return (x);
}

int		write_ptr(unsigned long ptr, t_flg flg)
{
	int x;

	x = 0;
	if (flg.dot == 1 && flg.after == -1 && flg.ast != -1)
		flg.after = 0;
	if (flg.after > -1)
		flg.zero = 0;
	if (flg.align == 0)
	{
		x += write_width_ptr((unsigned long)ptr, &flg);
		x += ft_putstr("0x");
		x += write_prec_ptr((unsigned long)ptr, &flg);
		x += ft_write_ptr((unsigned long)ptr, flg);
	}
	else
	{
		flg.zero = 0;
		x += ft_putstr("0x");
		x += write_prec_ptr((unsigned long)ptr, &flg);
		x += ft_write_ptr((unsigned long)ptr, flg);
		x += write_width_ptr((unsigned long)ptr, &flg);
	}
	return (x);
}