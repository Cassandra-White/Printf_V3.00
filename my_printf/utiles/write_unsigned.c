#include "../ft_printf.h"

int		write_unsigned(long n, t_flg flg)
{
	unsigned long num;

	num = n;
	return (write_nbr((long)num, flg));
}