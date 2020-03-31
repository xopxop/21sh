/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:55:44 by dthan             #+#    #+#             */
/*   Updated: 2019/10/26 04:44:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

char	*ft_strjoin(char const *string1, char const *string2)
{
	char	*jointstring;
	size_t	jointstringsize;

	if (string1 && string2)
		jointstringsize = (size_t)(ft_strlen(string1) + ft_strlen(string2));
	else if (string1)
		jointstringsize = (size_t)(ft_strlen(string1));
	else if (string2)
		jointstringsize = (size_t)(ft_strlen(string2));
	else
		return (NULL);
	if (!(jointstring = ft_memalloc(jointstringsize + 1)))
		return (NULL);
	if (string1)
		jointstring = ft_strcpy(jointstring, (char*)string1);
	else if (string2)
		jointstring = ft_strcpy(jointstring, (char*)string2);
	if (string1 && string2)
		jointstring = ft_strcat(jointstring, (char*)string2);
	return (jointstring);
}
