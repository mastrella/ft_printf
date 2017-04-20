/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:23:27 by mmastrel          #+#    #+#             */
/*   Updated: 2017/04/19 06:20:27 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	right_just(t_format flags, int size, int ret)
{
	if (flags.neg == 0)
	{
		while (flags.width_value > size && flags.width_value > flags.prec_value)
		{
			if (flags.zero == 1)
				ret += write(1, "0", 1);
			else
				ret += write(1, " ", 1);
			flags.width_value--;
		}
	}
	return (ret);
}

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

int	print_pre(char *curr_arg, t_format flags, const char *format, int ret)
{
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
	if (CHECK_HASH)
		ret = print_hash(format, ret);
	return (ret);
}

int	check_size(int size, char *curr_arg, t_format *flags, const char *format)
{
	size = ft_strlen(curr_arg);
	if (flags->prec == 1)
		flags->zero = 0;
	if (curr_arg[0] == '0' && flags->prec_value == 0 && flags->prec == 1)
		size--;
	else if (curr_arg[0] == '-')
	{
		size--;
		flags->width_value--;
	}
	else if ((flags->plus == 1 || flags->space == 1) && *format != 'u')
		flags->width_value--;
	if (flags->num == 1 && (curr_arg[0] != '0' ||
		((*format == 'o' || *format == 'O') && curr_arg[0] == '0'
		&& flags->prec == 1 && flags->prec_value == 0)))
	{
		if (*format == 'o' || *format == 'O')
			size++;
		else if (*format == 'x' || *format == 'X')
			flags->width_value -= 2;
	}
	return (size);
}

int	handle_num(char *curr_arg, t_format flags, const char *format, int ret)
{
	int	size;
	int zero_just;

	zero_just = 0;
	size = check_size(0, curr_arg, &flags, format);
	if (*format != 'u' && flags.neg == 0 && flags.zero == 1
		&& flags.width_value > size && flags.width_value > flags.prec_value)
	{
		RIGHT_JUST;
	}
	ret = right_just(flags, size, ret);
	if (*format != 'u' && zero_just == 0)
	{
		ret = print_pre(curr_arg, flags, format, ret);
		MOVE_NEG;
	}
	PRINT;
	if (flags.neg == 1)
	{
		while (flags.width_value-- > size)
			ret += write(1, " ", 1);
	}
	ret += size;
	return (ret);
}
