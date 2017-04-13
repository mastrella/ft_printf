/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:23:27 by mmastrel          #+#    #+#             */
/*   Updated: 2017/03/18 01:24:13 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	invocate_args(const char *format, va_list *ap, t_format flags, int ret)
{
	if (*format == 'c' || *format == 'C')
		ret = print_c((va_arg(*ap, int)), flags, ret);
	else if (*format == 's' || *format == 'S')
		ret = print_s(va_arg(*ap, char*), flags, ret);
	else if (*format == 'p')
		ret = print_p(va_arg(*ap, void*), flags, ret);
	else if (*format == 'o' || *format == 'O' || *format == 'u' || *format == 'U'
				|| *format == 'x' || *format == 'X' || *format == 'd' || *format == 'D'
				|| *format == 'i' || *format == 'b')
				{
						ret = print_num(format, ap, flags, ret);
				}
	else if (*format == 'n')
		print_n(va_arg(*ap, int*), ret);
	else if (*format == '%')
		ret = print_percent(flags, ret);
	return (ret);
}

int	prepare_n_print(va_list *ap, const char *format, int ret)
{
	static t_format	flags;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			prepare_format(&flags);
			format += observe_format(format, &flags, ap);
			ret = invocate_args(format, ap, flags, ret);
			format++;
		}
		else
		{
			ret += write(1, &(*format), 1);
			format++;
		}
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	ret;

	va_start(ap, format);
	ret = prepare_n_print(&ap, format, 0);
	va_end(ap);
	return (ret);
}
