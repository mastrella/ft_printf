/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:23:27 by mmastrel          #+#    #+#             */
/*   Updated: 2017/04/19 00:15:41 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*octal_to_a(va_list *ap, t_format flags, char *arg)
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
	return (arg);
}

char	*hexlow_to_a(va_list *ap, t_format flags, char *arg)
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
	return (arg);
}

char	*hexup_to_a(va_list *ap, t_format flags, char *arg)
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
	return (arg);
}

char	*binary_to_a(va_list *ap, t_format flags, char *arg)
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
	return (arg);
}

int		print_num(const char *format, va_list *ap, t_format flags, int ret)
{
	char	*arg;

	arg = NULL;
	if (*format == 'd' || *format == 'D' || *format == 'i')
		arg = int_to_a(format, ap, flags, arg);
	else if (*format == 'u' || *format == 'U')
		arg = uint_to_a(format, ap, flags, arg);
	else if (*format == 'o' || *format == 'O')
		arg = octal_to_a(ap, flags, arg);
	else if (*format == 'x')
		arg = hexlow_to_a(ap, flags, arg);
	else if (*format == 'X')
		arg = hexup_to_a(ap, flags, arg);
	else if (*format == 'b')
		arg = binary_to_a(ap, flags, arg);
	ret = handle_num(arg, flags, format, ret);
	return (ret);
}
