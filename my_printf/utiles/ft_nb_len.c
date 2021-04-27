#include "../ft_printf.h"

int		ft_nb_len(long n)
{
	int size;

	size = 0;
	if (n == 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}
