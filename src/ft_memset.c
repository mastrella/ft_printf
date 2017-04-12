/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:18:45 by mmastrel          #+#    #+#             */
/*   Updated: 2017/03/20 00:55:40 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*x;
	size_t			i;

	i = 0;
	if (len == 0)
		return (b);
	x = (unsigned char*)b;
	while (i < len)
	{
		x[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
