/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:58:54 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 00:56:55 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char			conv_to_hex(int nb)
{
	char	ret;

	if (nb == 10)
		ret = 'a';
	else if (nb == 11)
		ret = 'b';
	else if (nb == 12)
		ret = 'c';
	else if (nb == 13)
		ret = 'd';
	else if (nb == 14)
		ret = 'e';
	else if (nb == 15)
		ret = 'f';
	else
		ret = nb + 48;
	return (ret);
}

char				*ft_itoh(int nb)
{
	char			*hex;
	int				i;

	hex = (char*)malloc(sizeof(char) * 11);
	hex = ft_strcpy(hex, "0x00000000");
	i = 10;
	while (nb)
	{
		hex[--i] = conv_to_hex(nb % 16);
		nb /= 16;
	}
	return (hex);
}
