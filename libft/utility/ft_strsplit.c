/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:15:10 by dthan             #+#    #+#             */
/*   Updated: 2019/10/30 10:28:39 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

char	**ft_strsplit(char const *str, char c)
{
	char	**re;
	size_t	checkinsideaword;
	size_t	indexword;
	size_t	indexstring;
	size_t	start;

	if (!str)
		return (NULL);
	if (!(re = (char**)ft_memalloc((ft_ctwords(str, c) + 1) * sizeof(char*))))
		return (NULL);
	indexword = 0;
	checkinsideaword = 0;
	indexstring = -1;
	start = 0;
	while (str[++indexstring])
	{
		if (checkinsideaword && str[indexstring] == c)
			re[indexword++] = ft_strsub(str, start, indexstring - start);
		if (!checkinsideaword && str[indexstring] != c)
			start = indexstring;
		checkinsideaword = (str[indexstring] == c) ? 0 : 1;
	}
	if (checkinsideaword)
		re[indexword] = ft_strsub(str, start, indexstring - start);
	return (re);
}
