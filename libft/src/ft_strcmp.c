/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:01:26 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 00:59:18 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *pt_s1;
	unsigned char *pt_s2;

	pt_s1 = (unsigned char*)s1;
	pt_s2 = (unsigned char*)s2;
	while (*pt_s1 || *pt_s2)
	{
		if (*pt_s1 > *pt_s2)
			return (1);
		else if (*pt_s1 < *pt_s2)
			return (-1);
		pt_s1++;
		pt_s2++;
	}
	return (0);
}
