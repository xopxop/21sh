/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:56:47 by dthan             #+#    #+#             */
/*   Updated: 2019/10/26 04:00:37 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

char	*ft_strmap(char const *string, char (*f)(char))
{
	char *newstring;
	char *pstring;
	char *pnewstring;

	if (!string || !f ||
			!(newstring = ft_memalloc((size_t)ft_strlen((char*)string) + 1)))
		return (NULL);
	pstring = (char*)string;
	pnewstring = newstring;
	while (*pstring)
		*(pnewstring++) = f(*(pstring++));
	return (newstring);
}
