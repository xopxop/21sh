/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 12:28:36 by dthan             #+#    #+#             */
/*   Updated: 2020/02/10 08:53:39 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

/*
** ft_isnan return 1 if not a number
**                 0 if is number
*/

int		ft_isnan(double num)
{
	return (num != num);
}

/*
** ft_isinf return 1 if the number divide 0,
**                 0 if not
*/

int		ft_isinf(double num)
{
	if (num == (10.0 / 0.0) || num == (-10.0 / 0.0))
		return (1);
	return (0);
}

/*
** Return 1 if there is any special case: not a number, positive/ negative
** infinity and the string, "nan" for not a number, "inf" for the 2 later
*/

int		special_case(char **s, double num)
{
	char *new;

	if (ft_isnan(num) || ft_isinf(num))
	{
		new = ft_strnew(3);
		if (ft_isnan(num))
			ft_strcpy(new, "nan");
		else if (ft_isinf(num))
			ft_strcpy(new, "inf");
		*s = new;
		return (1);
	}
	return (0);
}
