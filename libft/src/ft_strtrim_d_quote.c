/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_d_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:18:07 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/09 18:20:35 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char			*trimming(char *s)
{
	int len;

	while (ft_is_d_quote(*s++))
		;
	s--;
	len = ft_strlen(s);
	while (len-- > 0)
	{
		if (!ft_is_d_quote(s[len]))
		{
			s[len + 1] = '\0';
			break ;
		}
	}
	return (s);
}

char				*ft_strtrim_d_quote(char const *s)
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
