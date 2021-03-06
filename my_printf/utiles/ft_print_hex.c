/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrissan <akrissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:09:50 by akrissan          #+#    #+#             */
/*   Updated: 2021/04/27 14:28:37 by akrissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_print_hex(unsigned int num, int ascii)
{
	if (num < 10)
		return (ft_putnbr(num));
	else if (num == 10)
		return (ft_putchar('a' - ascii));
	else if (num == 11)
		return (ft_putchar('b' - ascii));
	else if (num == 12)
		return (ft_putchar('c' - ascii));
	else if (num == 13)
		return (ft_putchar('d' - ascii));
	else if (num == 14)
		return (ft_putchar('e' - ascii));
	else if (num == 15)
		return (ft_putchar('f' - ascii));
	return (0);
}
