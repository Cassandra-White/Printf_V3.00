#include "../ft_printf.h"

int		ft_ptr_len(long num)
{
	int x;

	x = 0;
	if (num >= 0)
		x = 2;
	while ((num / 16) != 0)
	{
		x++;
		num /= 16;
	}
	x++;
	return (x);
}