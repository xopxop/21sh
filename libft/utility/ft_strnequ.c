/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:59:32 by dthan             #+#    #+#             */
/*   Updated: 2019/10/26 04:04:19 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

int	ft_strnequ(char const *string1, char const *string2, size_t maxlen)
{
	if (!string1 || !string2)
		return (0);
	return (ft_strncmp(string1, string2, maxlen) ? 0 : 1);
}
