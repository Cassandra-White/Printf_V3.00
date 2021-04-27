#include "../ft_printf.h"

int			check_args(char *str, va_list args, t_flg flg, t_pf *pf)
{
	int i;
	int t;

	i = 0;
	t = 0;
	if (str[i] == 'c')
		t = t + write_char(va_arg(args, int), flg);
	else if (str[i] == 's')
		t = t + write_str(va_arg(args, char*), flg);
	 else if (str[i] == 'd' || str[i] == 'i')
	 	t = t + write_nbr(va_arg(args, int), flg);
	else if (str[i] == 'u')
		t = t + write_unsigned(va_arg(args, unsigned int), flg);
	else if (str[i] == 'x')
	t = t + write_hex(va_arg(args, unsigned int), 0, flg);
	else if (str[i] == 'X')
	t = t + write_hex(va_arg(args, unsigned int), 32, flg);
	else if (str[i] == '%')
	 	t = t + write_char('%', flg);
	 else if (str[i] == 'p')
	 	t = t + write_ptr((unsigned long )va_arg(args, void *), flg);
	else
		pf->none = 1;
	return (t);
}