/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:13:55 by mmastrel          #+#    #+#             */
/*   Updated: 2017/03/20 00:50:08 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_isnegative(intmax_t mod)
{
	size_t	neg;

	if (mod < 0)
	{
		neg = 1;
		mod = mod * (-1);
	}
	else
		neg = 0;
	return (neg);
}

char			*ft_itoa_base(intmax_t n, int base, int upper)
{
	size_t	len;
	size_t	neg;
	uintmax_t	mod;
	char	*value;
	char  hex[17];
	
	if (upper == 1)
		ft_strcpy(hex, "0123456789ABCDEF");
	else
		ft_strcpy(hex, "0123456789abcdef");
	neg = ft_isnegative(n);
	mod = n;
	if (n < 0)
		mod = -mod;
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
	if (neg == 1)
		value[len--] = '-';
	return (value);
}



























// static int      compte(unsigned long nbr, int base)
// {
// 	int ret;
//
// 	ret = 0;
// 	while (nbr != 0)
// 	{
// 		nbr /= base;
// 		ret++;
// 	}
// 	return (ret);
// }
//
// char            *ft_itoa_base(unsigned int nbr, int base)
// {
// 	char		*retour;
// 	int		nb;
// 	int		i;
// 	char		tab[17];
//
// 	if (nbr == 0)
// 		return (ft_alloc_str("0"));
// 	ft_strcpy(tab, "0123456789abcdef");
// 	nb = compte(nbr, base);
// 	retour = malloc(nb + 1);
// 	i = 1;
// 	while (nbr != 0)
// 	{
// 		retour[nb - i] = tab[nbr % base];
// 		nbr /= base;
// 		i++;
// 	}
// 	retour[nb] = '\0';
// 	return (retour);
// }
