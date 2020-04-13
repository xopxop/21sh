/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:58:25 by dthan             #+#    #+#             */
/*   Updated: 2019/10/26 04:02:36 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

char	*ft_strmapi(char const *string, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*newstring;

	index = 0;
	if (!string || !f ||
			!(newstring = ft_memalloc((size_t)ft_strlen((char*)string) + 1)))
		return (NULL);
	while (string[index])
	{
		newstring[index] = f(index, string[index]);
		index++;
	}
	return (newstring);
}
