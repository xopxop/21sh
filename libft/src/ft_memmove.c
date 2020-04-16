/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:53:41 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 00:57:51 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pt_result;
	unsigned char		*pt_dst;
	const unsigned char	*pt_src;

	pt_dst = dst;
	pt_src = src;
	pt_result = pt_dst;
	if (pt_dst > pt_src)
	{
		pt_dst = pt_dst + len - 1;
		pt_src = pt_src + len - 1;
		while (len-- > 0)
			*(pt_dst--) = *(pt_src--);
	}
	else
	{
		while (len-- > 0)
			*(pt_dst++) = *(pt_src++);
	}
	return ((void*)pt_result);
}
