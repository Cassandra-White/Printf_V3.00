/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrissan <akrissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:09:01 by akrissan          #+#    #+#             */
/*   Updated: 2021/04/27 14:35:12 by akrissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		read_ast(char *str, va_list args, t_flg **flg)
{
	int	x;

	x = 0;
	(*flg)->ast = -1;
	if (str[x - 1] == '.')
	{
		(*flg)->after = va_arg(args, int);
		if ((*flg)->after < 0)
			(*flg)->after = -1;
	}
	else
	{
		(*flg)->before = va_arg(args, int);
		if ((*flg)->before < 0)
		{
			(*flg)->align = 1;
			(*flg)->before = (*flg)->before * -1;
		}
	}
}

int			ft_charint(char *str)
{
	int	x;
	int	num;

	num = 0;
	x = 0;
	while ((str[x] >= '0' && str[x] <= '9'))
	{
		num = (num * 10) + (str[x] - '0');
		x++;
	}
	return (num);
}

int			read_dot(char *str, t_flg **flg)
{
	int	x;

	x = 0;
	(*flg)->dot = 1;
	if (str[x + 1] >= '0' && str[x + 1] <= '9')
	{
		(*flg)->after = ft_charint(str + 1);
		return (ft_nb_len((*flg)->after));
	}
	else
	{
		(*flg)->after = 0;
		return (x);
	}
}

int			ft_read(char *str, va_list args, t_flg *flg)
{
	int	x;

	x = 0;
	while (ft_strchr("-0.*123456789 ", str[x]) != NULL)
	{
		if (str[x] == '0')
			flg->zero = 1;
		else if (str[x] == '-')
			flg->align = 1;
		else if (str[x] == '*')
			read_ast(str + x, args, &flg);
		else if (str[x] >= '1' && str[x] <= '9' && flg->after == -1)
		{
			flg->before = ft_charint(str + x);
			x = x + (ft_nb_len(flg->before) - 1);
		}
		else if (str[x] == '.')
			x = x + read_dot(str + x, &flg);
		x++;
	}
	return (x);
}

t_pf		ft_flags(char *str, va_list args, t_flg flg, t_pf pf)
{
	int	x;
	int	z;

	x = ft_read((char *)str, args, &flg);
	z = check_args((char *)str + x, args, flg, &pf);
	if (pf.none == 1)
	{
		if (flg.before > 0)
		{
			pf.ret = flg.before - 1;
			pf.x = pf.x + x - 1;
		}
		else
			pf.x = pf.x + x;
	}
	else
	{
		pf.ret = z;
		pf.x = pf.x + x + 1;
	}
	return (pf);
}
