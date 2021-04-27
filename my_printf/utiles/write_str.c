
#include "../ft_printf.h"

int		flag_width_str(char *s, t_flg flg)
{
	int		x;
	int		size;

	x = 0;
	size = ft_strlen(s);
	if (flg.after < size && flg.after > -1)
		size = flg.after;
	if (flg.zero == 1 && flg.align == 0 && flg.before > 0)
		while (flg.before > size)
		{
			x = x + ft_putchar('0');
			flg.before--;
		}
	else if (flg.before > 0)
		while (flg.before > size)
		{
			x = x + ft_putchar(' ');
			flg.before--;
		}
	return (x);
}

int		ft_flag_prec_str(char *str, t_flg flg)
{
	int		x;

	x = 0;
	while (x < flg.after && str[x] != '\0')
		x = x + ft_putchar(str[x]);
	return (x);
}


int		write_str(char *s, t_flg flg)
{
	int		x;

	x = 0;
	if (!s)
		s = "(null)";
	if (flg.align == 1)
	{
		if (flg.after > -1)
			x = x + ft_flag_prec_str(s, flg);
		else
			x = x + ft_putstr(s);
		x = x + flag_width_str(s, flg);
	}
	else
	{
		x = x + flag_width_str(s, flg);
		if (flg.after > -1)
			x = x + ft_flag_prec_str(s, flg);
		else
			x = x + ft_putstr(s);
	}
	return (x);
}