/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:11:07 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 01:00:08 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if ((str = (char*)malloc(size + 1)))
	{
		i = 0;
		while (i < size)
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
	return (NULL);
}
