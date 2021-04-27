#include "../ft_printf.h"

int		ft_hex_len(unsigned int num)
{
	int x;

	x = 0;
	while ((num / 16) != 0)
	{
		x++;
		num /= 16;
	}
	x++;
	return (x);
}