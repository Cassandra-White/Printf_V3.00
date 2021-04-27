/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrissan <akrissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:13:16 by akrissan          #+#    #+#             */
/*   Updated: 2021/04/27 14:17:28 by akrissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		write_unsigned(long n, t_flg flg)
{
	unsigned long num;

	num = n;
	return (write_nbr((long)num, flg));
}
