/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:32:05 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 00:59:46 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*fresh;
	char		*c_fresh;
	int			i;
	int			len;

	if (s)
	{
		len = ft_strlen(s);
		if ((fresh = (char*)malloc(sizeof(char) * len + 1)))
		{
			c_fresh = fresh;
			i = 0;
			while (i < len)
			{
				*(c_fresh++) = f(i, s[i]);
				i++;
			}
			*c_fresh = '\0';
			return (fresh);
		}
	}
	return (NULL);
}
