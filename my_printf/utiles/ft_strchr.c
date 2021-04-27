#include "../ft_printf.h"

char			*ft_strchr(char *s, int c)
{
	int x;

	x = 0;
	while (s[x])
	{
		if (s[x] == c)
			return (s + x);
		x++;
	}
	if (!c && s[x] == '\0')
		return (s + x);
	return (NULL);
}
