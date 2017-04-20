/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:23:27 by mmastrel          #+#    #+#             */
/*   Updated: 2017/04/19 02:55:47 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*shorten(char *s, int size, t_format flags)
{
	int		i;
	char	*shortened;

	i = 0;
	size = flags.prec_value;
	shortened = (char*)malloc(sizeof(char) * flags.prec_value + 1);
	while (flags.prec_value > i)
	{
		shortened[i] = s[i];
		i++;
	}
	shortened[i] = '\0';
	return (shortened);
}

int			print_s(char *s, t_format flags, int ret)
{
	int		size;

	if (!s)
		s = "(null)";
	size = ft_strlen(s);
	if (flags.prec == 1 && flags.prec_value < size)
		s = shorten(s, size, flags);
	size = ft_strlen(s);
	if (flags.neg == 0)
	{
		while (flags.width_value-- > size)
			ret += write(1, " ", 1);
	}
	ft_putstr(s);
	ret += size;
	if (flags.neg == 1)
	{
		while (flags.width_value-- > size)
			ret += write(1, " ", 1);
	}
	return (ret);
}
