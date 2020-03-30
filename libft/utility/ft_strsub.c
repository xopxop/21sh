/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:36:03 by dthan             #+#    #+#             */
/*   Updated: 2019/10/26 04:41:15 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

char	*ft_strsub(char const *string, unsigned int start, size_t len)
{
	char *substring;

	if (!string)
		return (NULL);
	if (!(substring = ft_memalloc(len + 1)))
		return (NULL);
	substring = ft_strncpy(substring, (char*)string + start, len);
	return (substring);
}
