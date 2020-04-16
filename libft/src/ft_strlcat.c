/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:59:47 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 00:59:40 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	dst_count;

	dst_count = 0;
	while (dst[dst_count] && dst_count < size)
		dst_count += 1;
	dst_len = dst_count;
	while (src[dst_count - dst_len] && dst_count + 1 < size)
	{
		dst[dst_count] = src[dst_count - dst_len];
		dst_count += 1;
	}
	if (dst_len < size)
		dst[dst_count] = '\0';
	return (dst_len + ft_strlen(src));
}
