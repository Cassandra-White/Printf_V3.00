/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrissan <akrissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:12:24 by akrissan          #+#    #+#             */
/*   Updated: 2021/04/28 08:46:02 by akrissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_write_hex(unsigned int num, int ascii, t_flg flg)
{
	int x;

	x = 0;
	if (num == 0 && flg.dot == 1 && flg.after == 0)
		return (x);
	if (num > 15)
		x = x + ft_write_hex((num / 16), ascii, flg);
	x = x + ft_print_hex((num % 16), ascii);
	return (x);
}

int		write_width_hex(unsigned int num, t_flg *flg)
{
	int x;
	int size;
	int i;

	x = 0;
	i = flg->before;
	if (flg->after > ft_hex_len(num))
		size = flg->after;
	else
		size = ft_hex_len(num);
	i = i - (size + (num < 0));
	if (num == 0 && flg->after == 0)
		i++;
	if (flg->zero == 1)
		while (i-- > 0)
			x += ft_putchar('0');
	else
		while (i-- > 0)
			x = x + ft_putchar(' ');
	if (num < 0 && flg->align == 0 && flg->zero == 0)
		ft_putchar('-');
	return (x);
}

int		write_sign_hex(unsigned int num)
{
	int x;

	x = 0;
	if (num < 0)
		x = x + ft_putchar('-');
	return (x);
}

int		write_prec_hex(unsigned int num, t_flg *flg)
{
	int x;
	int i;

	i = flg->after;
	x = 0;
	while (i > ft_hex_len(num))
	{
		x = x + ft_putchar('0');
		i--;
	}
	return (x);
}

int		write_hex(unsigned int num, int ascii, t_flg flg)
{
	int x;

	x = 0;
	if (flg.after > -1)
		flg.zero = 0;
	if (flg.align == 0)
	{
		x = x + write_width_hex(num, &flg);
		x = x + write_prec_hex(num, &flg);
		x = x + ft_write_hex(num, ascii, flg);
	}
	else
	{
		flg.zero = 0;
		x = x + write_sign_hex(num);
		x = x + write_prec_hex(num, &flg);
		x = x + ft_write_hex(num, ascii, flg);
		x = x + write_width_hex(num, &flg);
	}
	return (x);
}
