/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 07:25:04 by mmastrel          #+#    #+#             */
/*   Updated: 2017/04/19 06:58:35 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	prepare_format(t_format *flags)
{
	flags->num = 0;
	flags->zero = 0;
	flags->neg = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->l = 0;
	flags->ll = 0;
	flags->j = 0;
	flags->z = 0;
	flags->width = 0;
	flags->width_arg = 0;
	flags->width_value = 0;
	flags->prec = 0;
	flags->prec_arg = 0;
	flags->prec_value = 0;
	return (0);
}

int	observe_width(const char *format, t_format *flags, va_list *ap, int moved)
{
	char	tmp[22];
	int		i;

	i = 0;
	ft_bzero(tmp, 22);
	if (*format == '*')
	{
		flags->width = 1;
		flags->width_arg = 1;
		flags->width_value = va_arg(*ap, int);
	}
	else if (*format >= '0' && *format <= '9')
	{
		flags->width = 1;
		while (*format >= '0' && *format <= '9')
		{
			tmp[i++] = *format;
			format++;
			moved++;
		}
		flags->width_value = ft_atoi(tmp);
		format--;
		moved--;
	}
	return (moved);
}

int	get_prec(const char *format, t_format *flags, va_list *ap, int moved)
{
	char	tmp[22];
	int		i;

	i = 0;
	ft_bzero(tmp, 22);
	if (*format == '*')
	{
		flags->prec_arg = 1;
		flags->prec_value = va_arg(*ap, int);
		format++;
		moved++;
		if (flags->prec_value < 0)
			flags->prec = 0;
	}
	else
	{
		while (*format >= '0' && *format <= '9')
		{
			tmp[i++] = *format;
			format++;
			moved++;
		}
	}
	flags->prec_value = ft_atoi(tmp);
	return (moved);
}

int	observe_prec(const char *format, t_format *flags, va_list *ap, int moved)
{
	if (*format == '.')
	{
		format++;
		moved++;
		flags->prec = 1;
		moved = get_prec(format, flags, ap, moved);
		format--;
		moved--;
	}
	else
		moved = observe_width(format, flags, ap, moved);
	return (moved);
}
