#include "../ft_printf.h"

int		ft_putstr(char *s)
{
	int x;

	x = 0;
	while (*s != '\0')
	{
		write(1, &*s, 1);
		s++;
		x++;
	}
	return (x);
}