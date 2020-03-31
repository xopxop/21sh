/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:17:42 by dthan             #+#    #+#             */
/*   Updated: 2019/10/19 18:31:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *pd;
	unsigned char *ps;

	pd = (unsigned char*)dst;
	ps = (unsigned char*)src;
	if (ps < pd)
	{
		pd += len;
		ps += len;
		while (len--)
			*--pd = *--ps;
	}
	else
		while (len--)
			*pd++ = *ps++;
	return (dst);
}
