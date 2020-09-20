/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:54:43 by tango             #+#    #+#             */
/*   Updated: 2020/09/21 03:57:25 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char const *s1, char const *s2, size_t n, int *count)
{
	char	*fresh;
	size_t	len_s2;

	fresh = (char*)malloc(ft_strlen(s1) + n + 1);
	if (!fresh)
		return (NULL);
	ft_strcpy(fresh, s1);
	fresh = ft_strncat(fresh, s2, n);
	len_s2 = ft_strlen(s2);
	if (count)
	{
		if (len_s2 > n)
			*count = (int)n;
		else
			*count = (int)len_s2;
	}
	return (fresh);
}
