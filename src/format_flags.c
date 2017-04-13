/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 07:25:04 by mmastrel          #+#    #+#             */
/*   Updated: 2017/03/18 01:24:52 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void prepare_format(t_format  *flags)
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
  flags->precision = 0;
  flags->precision_arg = 0;
  flags->precision_value = 0;
}

int observe_prec_width(const char *format, t_format *flags, int i, va_list *ap, int moved)
{
	char  tmp[22];

	ft_bzero(tmp, 22);
	if (*format == '.')
	{
		format++;
		moved++;
		flags->precision = 1;
		if (*format == '*')
		{
			flags->precision_arg = 1;
			flags->precision_value = va_arg(*ap, int);
			format++;
			moved++;
			if (flags->precision_value < 0)
				flags->precision = 0;
		}
		else while (*format >= '0' && *format <= '9')
		{
			tmp[i++] = *format;
			format++;
			moved++;
		}
		i = 0;
		flags->precision_value = ft_atoi(tmp);
		format--;
		moved--;
	}
  else if (*format == '*')
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
/*
 else
 {
   ft_putstr("\e[033Sorry, I don't handle conversion character ");
   ft_putchar(*format + 1);
   ft_putstr("\e[031\n");
   moved++;
 }
*/
	return (moved);
}

int observe_length(const char *format, t_format *flags, va_list *ap, int moved)
{
	if (*format == 'h')
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
	}
	else if (*format == 'l')
	{
		format++;
		if (*format + 1 == 'l')
		{
			flags->ll = 1;
			format++;
			moved++;
		}
		else
			flags->l = 1;
		format--;
	}
	else if (*format == 'j')
		flags->j = 1;
	else if (*format == 'z')
		flags->z = 1;
	else
		moved = observe_prec_width(format, flags, 0, ap, moved);
	return (moved);
}

int observe_flags(const char *format, t_format *flags, va_list *ap, int moved)
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

int observe_format(const char *format, t_format *flags, va_list *ap)
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
/*
   if (*format == '\0')
   {
     ft_putstr("\e[033Error, missing conversion character.\e[031");
     return (0); //end printf function.
   }
*/
    curr_move = observe_flags(format, flags, ap, 0);
    moved += curr_move;
    format += curr_move;
  }
  return (moved);
}
