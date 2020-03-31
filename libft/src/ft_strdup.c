/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:51:45 by ihwang            #+#    #+#             */
/*   Updated: 2019/10/27 15:51:04 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pt_dup;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	pt_dup = (char*)malloc(sizeof(char) * i + 1);
	i = -1;
	while (s1[++i])
		pt_dup[i] = s1[i];
	pt_dup[i] = '\0';
	return (pt_dup);
}
