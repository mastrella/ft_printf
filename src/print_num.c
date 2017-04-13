/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:23:27 by mmastrel          #+#    #+#             */
/*   Updated: 2017/03/18 01:21:43 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_num(const char *format, va_list *ap, t_format flags, int ret)
{
	char	*arg;

	arg = NULL;
	if (*format == 'd' || *format == 'D' || *format == 'i')
	{
		if (flags.hh == 1)
			arg = ft_itoa_base((signed char)(va_arg(*ap, int)), 10, 0);
		else if (flags.h == 1)
			arg = ft_itoa_base((short int)(va_arg(*ap, int)), 10, 0);
		else if (flags.l == 1 || *format == 'D')
			arg = ft_itoa_base(va_arg(*ap, long int), 10, 0);
		else if (flags.ll == 1)
			arg = ft_itoa_base(va_arg(*ap, long long int), 10, 0);
		else if (flags.j == 1)
			arg = ft_itoa_base(va_arg(*ap, intmax_t), 10, 0);
		else if (flags.z == 1)
			arg = ft_itoa_base(va_arg(*ap, size_t), 10, 0);
		else
			arg = ft_itoa_base(va_arg(*ap, int), 10, 0);
	}
	else if (*format == 'u' || *format == 'U')
	{
		if (flags.hh == 1)
			arg = ft_uitoa_base((unsigned char)(va_arg(*ap, int)), 10, 0);
		else if (flags.h == 1)
			arg = ft_uitoa_base((unsigned short int)(va_arg(*ap, int)), 10, 0);
		else if (flags.l == 1 || *format == 'U')
			arg = ft_uitoa_base(va_arg(*ap, unsigned long int), 10, 0);
		else if (flags.ll == 1)
			arg = ft_uitoa_base(va_arg(*ap, unsigned long long int), 10, 0);
		else if (flags.j == 1)
			arg = ft_uitoa_base(va_arg(*ap, uintmax_t), 10, 0);
		else if (flags.z == 1)
			arg = ft_uitoa_base(va_arg(*ap, size_t), 10, 0);
		else
			arg = ft_uitoa_base(va_arg(*ap, unsigned int), 10, 0);
	}
	else if (*format == 'o' || *format == 'O')
	{
		if (flags.hh == 1)
			arg = ft_uitoa_base((unsigned char)(va_arg(*ap, int)), 8, 0);
		else if (flags.h == 1)
			arg = ft_uitoa_base((unsigned short int)(va_arg(*ap, int)), 8, 0);
		else if (flags.l == 1)
			arg = ft_uitoa_base(va_arg(*ap, unsigned long int), 8, 0);
		else if (flags.ll == 1)
			arg = ft_uitoa_base(va_arg(*ap, unsigned long long int), 8, 0);
		else if (flags.j == 1)
			arg = ft_uitoa_base(va_arg(*ap, uintmax_t), 8, 0);
		else if (flags.z == 1)
			arg = ft_uitoa_base(va_arg(*ap, size_t), 8, 0);
		else
			arg = ft_uitoa_base(va_arg(*ap, unsigned int), 8, 0);
	}
	else if (*format == 'x')
	{
		if (flags.hh == 1)
			arg = ft_uitoa_base((unsigned char)(va_arg(*ap, int)), 16, 0);
		else if (flags.h == 1)
			arg = ft_uitoa_base((unsigned short int)(va_arg(*ap, int)), 16, 0);
		else if (flags.l == 1)
			arg = ft_uitoa_base(va_arg(*ap, unsigned long int), 16, 0);
		else if (flags.ll == 1)
			arg = ft_uitoa_base(va_arg(*ap, unsigned long long int), 16, 0);
		else if (flags.j == 1)
			arg = ft_uitoa_base(va_arg(*ap, uintmax_t), 16, 0);
		else if (flags.z == 1)
			arg = ft_uitoa_base(va_arg(*ap, size_t), 16, 0);
		else
			arg = ft_uitoa_base(va_arg(*ap, unsigned int), 16, 0);
	}
	else if (*format == 'X')
	{
		if (flags.hh == 1)
			arg = ft_uitoa_base((unsigned char)(va_arg(*ap, int)), 16, 1);
		else if (flags.h == 1)
			arg = ft_uitoa_base((unsigned short int)(va_arg(*ap, int)), 16, 1);
		else if (flags.l == 1)
			arg = ft_uitoa_base(va_arg(*ap, unsigned long int), 16, 1);
		else if (flags.ll == 1)
			arg = ft_uitoa_base(va_arg(*ap, unsigned long long int), 16, 1);
		else if (flags.j == 1)
			arg = ft_uitoa_base(va_arg(*ap, uintmax_t), 16, 1);
		else if (flags.z == 1)
			arg = ft_uitoa_base(va_arg(*ap, size_t), 16, 1);
		else
			arg = ft_uitoa_base(va_arg(*ap, unsigned int), 16, 1);
	}
	else if (*format == 'b')
	{
		if (flags.hh == 1)
			arg = ft_uitoa_base((unsigned char)(va_arg(*ap, int)), 2, 1);
		else if (flags.h == 1)
			arg = ft_uitoa_base((unsigned short int)(va_arg(*ap, int)), 2, 1);
		else if (flags.l == 1)
			arg = ft_uitoa_base(va_arg(*ap, unsigned long int), 2, 1);
		else if (flags.ll == 1)
			arg = ft_uitoa_base(va_arg(*ap, unsigned long long int), 2, 1);
		else if (flags.j == 1)
			arg = ft_uitoa_base(va_arg(*ap, uintmax_t), 2, 1);
		else if (flags.z == 1)
			arg = ft_uitoa_base(va_arg(*ap, size_t), 2, 1);
		else
			arg = ft_uitoa_base(va_arg(*ap, unsigned int), 2, 1);
	}
	ret = handle_num(arg, flags, format, ret);
	return (ret);
}
