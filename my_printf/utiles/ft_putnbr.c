/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrissan <akrissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:11:14 by akrissan          #+#    #+#             */
/*   Updated: 2021/04/27 14:23:02 by akrissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putnbr(long n)
{
	int x;

	x = 0;
	if (n < 0)
	{
		x += ft_putchar('-');
		if (n <= -10)
			x += ft_putnbr(n / -10);
		x += ft_putchar(-(n % 10) + 48);
	}
	else if (n > 9)
	{
		x += ft_putnbr(n / 10);
		x += ft_putchar((n % 10) + 48);
	}
	else
		x += ft_putchar((n % 10) + 48);
	return (x);
}
