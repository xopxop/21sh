/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 00:51:15 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/23 01:04:40 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_isext(char *s1, char *s2)
{
	int		len1;
	int		len2;

	len1 = (int)ft_strlen(s1);
	len2 = (int)ft_strlen(s2);
	while (len1-- && len2--)
	{
		if (s1[len1] != s2[len2])
			return (0);
	}
	if (len2 < 0 && len1 >= 0)
		return (1);
	else
		return (0);
}
