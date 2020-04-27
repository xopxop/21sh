/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:11:30 by dthan             #+#    #+#             */
/*   Updated: 2019/10/26 03:53:26 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t pos;
	size_t i;

	if (!*needle)
		return ((char*)haystack);
	pos = 0;
	while (haystack[pos] != '\0' && pos < len)
	{
		if (haystack[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[pos + i] == needle[i]
					&& (pos + i) < len)
				i++;
			if (needle[i] == '\0')
				return ((char*)&haystack[pos]);
		}
		pos++;
	}
	return (0);
}
