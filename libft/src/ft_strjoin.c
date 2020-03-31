/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:56:34 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 00:59:38 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *fresh;

	fresh = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!fresh)
		return (NULL);
	ft_strcpy(fresh, s1);
	fresh = (ft_strcat(fresh, s2));
	return (fresh);
}
