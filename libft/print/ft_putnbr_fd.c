/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:48:02 by dthan             #+#    #+#             */
/*   Updated: 2019/10/28 17:55:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_print.h"

void	ft_putnbr_fd(int nbr, int filedescriptor)
{
	unsigned int nb;

	if (nbr < 0)
	{
		ft_putchar_fd('-', filedescriptor);
		nb = (unsigned int)(nbr * -1);
	}
	else
		nb = (unsigned int)nbr;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, filedescriptor);
	ft_putchar_fd((nb % 10) + '0', filedescriptor);
}
