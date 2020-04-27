/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:26:00 by dthan             #+#    #+#             */
/*   Updated: 2019/10/30 10:19:03 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;
	unsigned int		i;

	ptr = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	i = 0;
	while (n--)
	{
		ptr[i] = ptr2[i];
		if (ptr[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
