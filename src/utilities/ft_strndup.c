/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:18:18 by dthan             #+#    #+#             */
/*   Updated: 2020/04/06 00:18:19 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strndup(char *str, size_t len)
{
	char *new;
	int i;

	new = ft_strnew(len);
	i = 0;
	while (len > 0)
	{
		new[i] = str[i];
		len--;
		i++;
	}
	new[i] = '\0';
	return (new);
}
