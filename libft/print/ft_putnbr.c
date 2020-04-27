/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:10:07 by dthan             #+#    #+#             */
/*   Updated: 2019/10/28 17:54:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_print.h"

void	ft_putnbr(int nbr)
{
	unsigned int nb;

	if (nbr < 0)
	{
		ft_putchar('-');
		nb = (unsigned int)(nbr * -1);
	}
	else
		nb = (unsigned int)nbr;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((char)(nb % 10) + '0');
}
