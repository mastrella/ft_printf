/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:23:27 by mmastrel          #+#    #+#             */
/*   Updated: 2017/03/18 01:21:43 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int print_s(char *s, t_format flags, int ret)
{
  int size;
  int i;
  char *shortened;

  // if (flags.hh  == 1 || flags.h == 1 || flags.ll == 1 || flags.j == 1 || flags.z == 1)
  // {
  //   // perror("Error: use of \e[033'%s' flag\e[031 with 's' type character [-Werror=format=]", ??presentflag??);
  // }
  i = 0;
  if (!s)
	  s = "(null)";
  size = ft_strlen(s);
  if (flags.precision == 1 && flags.precision_value < size)
  {
	  size = flags.precision_value;
	  shortened = (char*)malloc(sizeof(char) * flags.precision_value + 1);
	  while (flags.precision_value > i)
	  {
		  shortened[i] = s[i];
		  i++;
	  }
	  shortened[i] = '\0';
  }
  else
	  shortened = s;
  if (flags.neg == 0)
  {
    while(flags.width_value-- > size)
      ret += write(1, " ", 1);
  }
    ft_putstr(shortened);
    ret += size;
  if (flags.neg == 1)
  {
    while (flags.width_value-- > size)
      ret += write(1, " ", 1);
  }
  return (ret);
}
