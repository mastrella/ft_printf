/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:23:27 by mmastrel          #+#    #+#             */
/*   Updated: 2017/04/19 01:41:10 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_p(void *pointer, t_format flags, int ret)
{
	uintmax_t	num;
	int			size;
	char		*hex;

	num = (uintmax_t)(pointer);
	size = ft_uilength(num, 16) + 2;
	ret = print_padding(flags, size, ret, 1);
	ret += write(1, "0x", 2);
	hex = ft_uitoa_base(num, 16, 0);
	ret += write(1, hex, ft_strlen(hex));
	ret = print_padding(flags, size, ret, 0);
	return (ret);
}
