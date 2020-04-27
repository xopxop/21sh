/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:18:57 by dthan             #+#    #+#             */
/*   Updated: 2019/10/28 17:52:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t tlen;

	i = 0;
	j = 0;
	tlen = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (dstsize <= i)
		tlen = j + dstsize;
	else
		tlen = i + j;
	j = 0;
	while (src[j] != '\0' && i + 1 < dstsize)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (tlen);
}
