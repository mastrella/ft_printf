/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:23:27 by mmastrel          #+#    #+#             */
/*   Updated: 2017/03/18 01:21:43 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int print_percent(t_format flags, int ret)
{
  ret = print_padding(flags, 1, ret, 1);
  ret += write(1, "%", 1);
  ret = print_padding(flags, 1, ret, 0);
  return (ret);
}
