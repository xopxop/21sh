/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_d_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:33:31 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/27 17:16:59 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_check_d_quote(char *str)
{
	int		bal;
	int		i;
	int		flag;

	bal = 0;
	flag = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_is_d_quote(str[i]))
		{
			flag = 1;
			if (bal % 2 == 0)
				bal++;
			else
				bal--;
		}
	}
	if (!bal && flag)
		return (1);
	else
		return (0);
}
