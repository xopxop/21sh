/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:48:41 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 00:57:39 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *pt_s1;
	unsigned char *pt_s2;

	pt_s1 = (unsigned char*)s1;
	pt_s2 = (unsigned char*)s2;
	if (*pt_s1 == '\0' && *pt_s2 == '\0')
		return (0);
	while (n-- > 0)
	{
		if (*pt_s1 != *pt_s2)
			return (*pt_s1 - *pt_s2);
		pt_s1++;
		pt_s2++;
	}
	return (0);
}
