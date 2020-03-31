/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:41:55 by ihwang            #+#    #+#             */
/*   Updated: 2019/10/27 19:42:42 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pt_dst;
	const unsigned char	*pt_src;

	pt_dst = dst;
	pt_src = src;
	while (n-- > 0)
		*(pt_dst++) = *(pt_src++);
	return ((void*)dst);
}
