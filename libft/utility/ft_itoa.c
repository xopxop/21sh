/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:21:14 by dthan             #+#    #+#             */
/*   Updated: 2019/10/30 10:24:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

static int	getsizenumber(unsigned int nb)
{
	unsigned int size;

	size = 0;
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa(int n)
{
	char			*string;
	unsigned int	nbr;
	unsigned int	index;
	unsigned int	size;

	index = 0;
	if (n < 0)
		nbr = (unsigned int)(n * -1);
	else
		nbr = (unsigned int)(n);
	size = (unsigned int)getsizenumber(nbr);
	if (!(string = (char*)malloc(sizeof(char) *
					(size + 1 + (n < 0 ? 1 : 0)))))
		return (NULL);
	if (n < 0 && (string[index] = '-'))
		size++;
	index = size - 1;
	while (nbr >= 10)
	{
		string[index--] = (char)(nbr % 10 + '0');
		nbr /= 10;
	}
	string[index] = (char)(nbr % 10 + '0');
	string[size] = '\0';
	return (string);
}
