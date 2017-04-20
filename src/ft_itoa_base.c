/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:13:55 by mmastrel          #+#    #+#             */
/*   Updated: 2017/04/19 01:30:09 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*fill_value(uintmax_t mod, size_t len, char *hex, int base)
{
	char *value;

	value = ft_strnew(len);
	if (!value)
		return (NULL);
	value[len--] = '\0';
	if (mod == 0)
		value[len] = '0';
	while (mod != 0)
	{
		value[len] = hex[(mod % base)];
		mod = mod / base;
		len--;
	}
	return (value);
}

static int		ft_isnegative(intmax_t mod)
{
	size_t	neg;

	if (mod < 0)
		neg = 1;
	else
		neg = 0;
	return (neg);
}

char			*ft_itoa_base(intmax_t n, int base, int upper)
{
	size_t		len;
	size_t		neg;
	uintmax_t	mod;
	char		*value;
	char		hex[17];

	if (upper == 1)
		ft_strcpy(hex, "0123456789ABCDEF");
	else
		ft_strcpy(hex, "0123456789abcdef");
	neg = ft_isnegative(n);
	mod = n;
	if (n < 0)
		mod = -mod;
	len = ft_ilength(n, base);
	value = fill_value(mod, len, hex, base);
	if (neg == 1)
		value[0] = '-';
	return (value);
}
