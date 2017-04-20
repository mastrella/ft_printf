/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 07:25:04 by mmastrel          #+#    #+#             */
/*   Updated: 2017/04/19 06:57:58 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_l(const char *format, t_format *flags, int moved)
{
	format++;
	if (*format == 'l')
	{
		flags->ll = 1;
		format++;
		moved++;
	}
	else
		flags->l = 1;
	format--;
	return (moved);
}

int	check_h(const char *format, t_format *flags, int moved)
{
	format++;
	if (*format == 'h')
	{
		flags->hh = 1;
		format++;
		moved++;
	}
	else
		flags->h = 1;
	format--;
	return (moved);
}

int	observe_length(const char *format, t_format *flags, va_list *ap, int moved)
{
	if (*format == 'h')
		moved = check_h(format, flags, moved);
	else if (*format == 'l')
		moved = check_l(format, flags, moved);
	else if (*format == 'j')
		flags->j = 1;
	else if (*format == 'z')
		flags->z = 1;
	else
		moved = observe_prec(format, flags, ap, moved);
	return (moved);
}

int	observe_flags(const char *format, t_format *flags, va_list *ap, int moved)
{
	if (*format == '#')
		flags->num = 1;
	else if (*format == '0')
		flags->zero = 1;
	else if (*format == '-')
		flags->neg = 1;
	else if (*format == '+')
		flags->plus = 1;
	else if (*format == ' ')
		flags->space = 1;
	else
		moved = observe_length(format, flags, ap, moved);
	moved++;
	return (moved);
}

int	observe_format(const char *format, t_format *flags, va_list *ap)
{
	int	moved;
	int curr_move;

	moved = 0;
	curr_move = 0;
	while (*format != 's' && *format != 'S' && *format != 'p' && *format != 'i'
		&& *format != 'd' && *format != 'D' && *format != 'o' && *format != 'O'
		&& *format != 'u' && *format != 'U' && *format != 'x' && *format != 'X'
		&& *format != 'c' && *format != 'C' && *format != '%' && *format != 'n'
		&& *format != 'b' && *format != '\0')
	{
		curr_move = observe_flags(format, flags, ap, 0);
		moved += curr_move;
		format += curr_move;
	}
	return (moved);
}
