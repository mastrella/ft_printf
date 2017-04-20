/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilength.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 22:50:38 by mmastrel          #+#    #+#             */
/*   Updated: 2017/04/19 01:17:37 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_ilength(intmax_t n, int base)
{
	intmax_t	mod;
	int			len;

	mod = n;
	len = 0;
	if (mod <= 0)
		len++;
	while (mod != 0)
	{
		mod = mod / base;
		len++;
	}
	return (len);
}

int	ft_uilength(uintmax_t n, int base)
{
	uintmax_t	mod;
	int			len;

	mod = n;
	len = 0;
	if (mod == 0)
		len++;
	while (mod != 0)
	{
		mod = mod / base;
		len++;
	}
	return (len);
}
