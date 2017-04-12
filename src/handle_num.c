/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:23:27 by mmastrel          #+#    #+#             */
/*   Updated: 2017/03/18 01:21:43 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_hash(const char *format, int ret)
{
	if (*format == 'o' || *format == 'O')
		write(1, "0", 1);
	else if (*format == 'x')
		ret += write(1, "0x", 2);
	else if (*format == 'X')
		ret += write(1, "0X", 2);
	return (ret);
}

int handle_num(char *curr_arg, t_format flags, const char *format, int ret)
{
	int	size;
	int zero_just;

	zero_just = 0;
	size = ft_strlen(curr_arg);
	if (flags.precision == 1)
		flags.zero = 0;
	if (curr_arg[0] == '0' && flags.precision_value == 0 && flags.precision == 1)
		size--;
	else if (curr_arg[0] == '-')
	{
		size--;
		flags.width_value--;
	}
	else if ((flags.plus == 1 || flags.space == 1) && *format != 'u')
		flags.width_value--;
	if (flags.num == 1 && (curr_arg[0] != '0' || ((*format == 'o' || *format == 'O')
					&& curr_arg[0] == '0' && flags.precision == 1 && flags.precision_value == 0)))
	{
		if (*format == 'o' || *format == 'O')
			size++;
		else if (*format == 'x' || *format == 'X')
			flags.width_value -= 2;
	}
	if (*format != 'u' && flags.neg == 0 && flags.zero == 1
			&& flags.width_value > size && flags.width_value > flags.precision_value)
	{
		zero_just = 1;
		if (curr_arg[0] == '-')
		{
			ret += write(1, "-", 1);
			curr_arg++;
		}
		else
		{
			if (flags.plus == 1)
				ret += write(1, "+", 1);
			else if (flags.space == 1)
				ret += write(1, " ", 1);
		}
		if (flags.num == 1 && (curr_arg[0] != '0' || ((*format == 'o' || *format == 'O')
						&& curr_arg[0] == '0' && flags.precision == 1 && flags.precision_value == 0)))
    		ret = print_hash(format, ret);
	}
	if (flags.neg == 0)
	{
		while(flags.width_value > size && flags.width_value > flags.precision_value)
		{
			if (flags.zero == 1)
				ret += write(1, "0", 1);
			else
				ret += write(1, " ", 1);
			flags.width_value--;
		}
	}
	if (*format != 'u' && zero_just == 0)
	{
		//put curr_arg != 0 here
		if (curr_arg[0] == '-')
		{
			ret += write(1, "-", 1);
			curr_arg++;
		}
		else
		{
			if (flags.plus == 1)
				ret += write(1, "+", 1);
			else if (flags.space == 1)
				ret += write(1, " ", 1);
		}
		if (flags.num == 1 && (curr_arg[0] != '0' || ((*format == 'o' || *format == 'O') 
						&& curr_arg[0] == '0' && flags.precision == 1 && flags.precision_value == 0)))
			ret = print_hash(format, ret);
	}
	while (flags.precision_value > size)
		size += write(1, "0", 1);
	if (curr_arg[0] != '0' || flags.precision != 1 || flags.precision_value != 0)
		ft_putstr(curr_arg);
	if (flags.neg == 1)
	{
		while(flags.width_value-- > size)
			ret += write(1, " ", 1);
	}
	ret += size;
	return (ret);
}
