/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:05:34 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 01:00:21 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			is_white(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static char			*trimming(char *s)
{
	int len;

	while (is_white(*s++))
		;
	s--;
	len = ft_strlen(s);
	while (len-- > 0)
	{
		if (!is_white(s[len]))
		{
			s[len + 1] = '\0';
			break ;
		}
	}
	return (s);
}

char				*ft_strtrim(char const *s)
{
	char			*copy;
	int				i;
	unsigned long	len;

	s = trimming((char*)s);
	len = ft_strlen(s);
	copy = (char*)malloc(len + 1);
	ft_bzero(copy, len + 1);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	return (copy);
}
