/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrissan <akrissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:12:13 by akrissan          #+#    #+#             */
/*   Updated: 2021/04/27 14:23:24 by akrissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		write_width_c(t_flg flg)
{
	int x;

	x = 0;
	if (flg.zero == 1 && flg.align == 0)
	{
		while (flg.before > 1)
		{
			x = x + ft_putchar('0');
			flg.before--;
		}
	}
	else
	{
		while (flg.before > 1)
		{
			x = x + ft_putchar(' ');
			flg.before--;
		}
	}
	return (x);
}

int		write_char(char c, t_flg flg)
{
	int x;

	x = 0;
	if (flg.ast > 0 && flg.before == 0)
		flg.before = flg.ast;
	if (flg.align == 1)
	{
		x = x + ft_putchar(c);
		x = x + write_width_c(flg);
	}
	else
	{
		x = x + write_width_c(flg);
		x = x + ft_putchar(c);
	}
	return (x);
}
