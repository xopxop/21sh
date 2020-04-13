/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:28:03 by dthan             #+#    #+#             */
/*   Updated: 2019/10/30 10:19:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (n-- > 0)
	{
		if (p1[i] != p2[i])
			return ((int)(p1[i] - p2[i]));
		else
			i++;
	}
	return (0);
}
