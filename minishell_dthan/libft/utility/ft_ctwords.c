/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:23:18 by dthan             #+#    #+#             */
/*   Updated: 2019/10/30 10:23:26 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

int		ft_ctwords(char const *str, char c)
{
	size_t	count;
	int		inside_a_word;

	inside_a_word = 0;
	count = 0;
	while (*str)
	{
		if (!inside_a_word && *str != c)
			count++;
		inside_a_word = (*str == c) ? 0 : 1;
		str++;
	}
	return (count);
}
