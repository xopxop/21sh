/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:04:27 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 01:00:19 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	char	*c_fresh;

	fresh = (char*)malloc(len + 1);
	if (!fresh)
		return (NULL);
	c_fresh = fresh;
	while (len-- > 0)
		*(c_fresh++) = s[start++];
	*c_fresh = '\0';
	return (fresh);
}
