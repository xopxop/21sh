/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:48:34 by tango             #+#    #+#             */
/*   Updated: 2020/03/07 18:52:36 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr_e(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)&haystack[i + j + 1]);
			j++;
		}
		i++;
	}
	return (NULL);
}
