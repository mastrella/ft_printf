/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:23:27 by mmastrel          #+#    #+#             */
/*   Updated: 2017/04/19 01:39:18 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_c(int character, t_format flags, int ret)
{
	int		size;
	char	c;

	c = (char)character;
	size = 1;
	ret = print_padding(flags, size, ret, 1);
	ret += write(1, &c, 1);
	ret = print_padding(flags, size, ret, 0);
	return (ret);
}
