#include "../ft_printf.h"

int		ft_print_ptr(long num)
{
	if (num < 10)
		return (ft_putnbr(num));
	else if (num == 10)
		return (ft_putchar('a'));
	else if (num == 11)
		return (ft_putchar('b'));
	else if (num == 12)
		return (ft_putchar('c'));
	else if (num == 13)
		return (ft_putchar('d'));
	else if (num == 14)
		return (ft_putchar('e'));
	else if (num == 15)
		return (ft_putchar('f'));
	return (0);
}