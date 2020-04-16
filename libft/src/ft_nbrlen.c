/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:02:50 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 01:02:21 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned long		ft_nbrlen(int nb)
{
	unsigned long	len;

	len = 0;
	if (!nb)
		return (1);
	else if (nb < 0)
		len++;
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
