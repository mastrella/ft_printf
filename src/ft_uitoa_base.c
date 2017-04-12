/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:13:55 by mmastrel          #+#    #+#             */
/*   Updated: 2017/03/20 00:50:08 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_uitoa_base(uintmax_t n, int base, int upper)
{
	size_t	len;
	uintmax_t	mod;
	char	*value;
	char  hex[17];

  if (upper == 1)
    ft_strcpy(hex, "0123456789ABCDEF");
	else
		ft_strcpy(hex, "0123456789abcdef");
	mod = n;
	len = ft_ilength(n, base);
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
