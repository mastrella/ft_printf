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

char	*ft_witos(wint_t c)
{
	char	*str;

	str = ft_strnew(4);
	if (c <= 0x7F)
		str[0] = c;
	else if (c <= 0x7FF)
	{
		str[0] = (c >> 6) + 0xc0;
		str[1] = (c & 0x3f) + 0x80;
	}
	else if (c <= 0xFFFF)
	{
		str[0] = (c >> 12) + 0xe0;
		str[1] = ((c >> 6) & 0x3f) + 0x80;
		str[2] = (c & 0x3f) + 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		str[0] = (c >> 18) + 0xf0;
		str[1] = (c >> 12 & 0x3f) + 0x80;
		str[2] = (c >> 6 & 0x3f) + 0x80;
		str[3] = (c & 0x3f) + 0xc80;
	}
	return (str);
}

int print_wide_c(wint_t character, t_format flags, int ret)
{
  char  *str;
  int size;

  if (character == 0)
	  ret += 1;
  size = 1;
  ret = print_padding(flags, size, ret, 1);
  str = ft_witos(character);
  ret += write (1, str, ft_strlen(str));
  ret = print_padding(flags, size, ret, 0);
  return (ret);
}

int print_c(int character, t_format flags, int ret)
{
  int   size;
  char  c;

  c = (char)character;
  size = 1;
  ret = print_padding(flags, size, ret, 1);
  ret += write(1, &c, 1);
  ret = print_padding(flags, size, ret, 0);
  return (ret);
}
