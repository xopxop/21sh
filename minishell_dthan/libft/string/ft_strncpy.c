/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:26:05 by dthan             #+#    #+#             */
/*   Updated: 2019/10/17 17:38:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t ct;

	ct = 0;
	while ((src[ct]) && (ct < len))
	{
		dst[ct] = src[ct];
		ct++;
	}
	while (ct < len)
	{
		dst[ct] = '\0';
		ct++;
	}
	return (dst);
}
