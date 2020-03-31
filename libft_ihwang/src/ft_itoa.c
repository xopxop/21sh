/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:57:16 by tango             #+#    #+#             */
/*   Updated: 2020/02/28 00:56:52 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		init_str(char *str, size_t n_size)
{
	size_t		i;

	i = -1;
	while (++i < n_size)
		str[i] = '\0';
}

char			*ft_itoa(int n)
{
	size_t		i;
	size_t		n_size;
	char		*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_size = ft_nbrlen(n);
	str = (char *)malloc(sizeof(char) * (n_size + 1));
	if (str == 0)
		return (0);
	init_str(str, n_size);
	str[n_size] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i += 1;
	}
	while (i < n_size--)
	{
		str[n_size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
