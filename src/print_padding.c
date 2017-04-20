/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:23:27 by mmastrel          #+#    #+#             */
/*   Updated: 2017/04/19 02:59:24 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_padding(t_format flags, int size, int ret, int right)
{
	if (flags.neg == 0 && right == 1)
	{
		while (flags.width_value > size &&
				flags.width_value > flags.prec_value)
		{
			if (flags.zero == 1)
				ret += write(1, "0", 1);
			else
				ret += write(1, " ", 1);
			flags.width_value--;
		}
		flags.neg = 2;
	}
	if (flags.neg == 1 && right == 0)
	{
		while (flags.width_value-- > size)
			ret += write(1, " ", 1);
		flags.neg = 2;
	}
	return (ret);
}
