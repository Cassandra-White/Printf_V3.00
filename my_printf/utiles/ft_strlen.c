#include "../ft_printf.h"

unsigned int	ft_strlen(const char *str)
{
	int x;

	x = 0;
	while (*str != '\0')
	{
		x++;
		str++;
	}
	return (x);
}
