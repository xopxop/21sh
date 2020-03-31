/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:41:23 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 00:57:34 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*pt_dst;
	const unsigned char	*pt_src;

	pt_dst = dst;
	pt_src = src;
	while (n-- > 0)
	{
		if (*pt_src == c)
		{
			*(pt_dst++) = *pt_src;
			return ((void*)pt_dst);
		}
		*(pt_dst++) = *(pt_src++);
	}
	return (NULL);
}
