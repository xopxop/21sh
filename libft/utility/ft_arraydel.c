/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 06:29:33 by dthan             #+#    #+#             */
/*   Updated: 2020/04/04 06:29:34 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

void	ft_arraydel(char **string_array)
{
	char *ptr;

	while (*string_array)
	{
		ptr = *string_array;
		string_array++;
		free(ptr);
	}
	ptr = *string_array;
	free(ptr);
}
