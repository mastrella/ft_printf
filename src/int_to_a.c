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

char	*int_to_a(const char *format, va_list *ap, t_format flags, char *arg)
{
	if (flags.l == 1 || *format == 'D')
		arg = ft_itoa_base(va_arg(*ap, long int), 10, 0);
	else if (flags.hh == 1)
		arg = ft_itoa_base((signed char)(va_arg(*ap, int)), 10, 0);
	else if (flags.h == 1)
		arg = ft_itoa_base((short int)(va_arg(*ap, int)), 10, 0);
	else if (flags.ll == 1)
		arg = ft_itoa_base(va_arg(*ap, long long int), 10, 0);
	else if (flags.j == 1)
		arg = ft_itoa_base(va_arg(*ap, intmax_t), 10, 0);
	else if (flags.z == 1)
		arg = ft_itoa_base(va_arg(*ap, size_t), 10, 0);
	else
		arg = ft_itoa_base(va_arg(*ap, int), 10, 0);
	return (arg);
}

char	*uint_to_a(const char *format, va_list *ap, t_format flags, char *arg)
{
	if (flags.l == 1 || *format == 'U')
		arg = ft_uitoa_base(va_arg(*ap, unsigned long int), 10, 0);
	else if (flags.hh == 1)
		arg = ft_uitoa_base((unsigned char)(va_arg(*ap, int)), 10, 0);
	else if (flags.h == 1)
		arg = ft_uitoa_base((unsigned short int)(va_arg(*ap, int)), 10, 0);
	else if (flags.ll == 1)
		arg = ft_uitoa_base(va_arg(*ap, unsigned long long int), 10, 0);
	else if (flags.j == 1)
		arg = ft_uitoa_base(va_arg(*ap, uintmax_t), 10, 0);
	else if (flags.z == 1)
		arg = ft_uitoa_base(va_arg(*ap, size_t), 10, 0);
	else
		arg = ft_uitoa_base(va_arg(*ap, unsigned int), 10, 0);
	return (arg);
}
