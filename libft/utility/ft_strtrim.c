/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:25:48 by dthan             #+#    #+#             */
/*   Updated: 2019/10/31 16:00:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

char	*ft_strtrim(char const *string)
{
	int	stringstart;
	int	stringend;

	stringstart = 0;
	if (!string)
		return (NULL);
	stringend = ft_strlen((char*)string);
	while (ft_isspace(string[stringstart]))
		stringstart++;
	while (ft_isspace(string[stringend - 1]))
		stringend--;
	if (stringend < stringstart)
		stringend = stringstart;
	return (ft_strsub(string, stringstart, stringend - stringstart));
}
