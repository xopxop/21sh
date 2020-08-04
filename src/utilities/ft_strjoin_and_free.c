/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 08:09:40 by dthan             #+#    #+#             */
/*   Updated: 2020/08/05 05:46:02 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_strjoin_and_free_string2(char *string1, char *string2)
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
	free(string2);
	ft_strdel(&string1);
	return (jointstring);
}

char	*ft_strjoin_and_free_string1(char *string1, char *string2)
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
	free(string1);
	return (jointstring);
}
