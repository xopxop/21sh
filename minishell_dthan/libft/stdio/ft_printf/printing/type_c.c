/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:33:24 by dthan             #+#    #+#             */
/*   Updated: 2020/02/10 08:38:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	type_c(t_info *info, va_list arg, size_t *ct)
{
	char	chr;
	char	*str;
	int		null;
	int		null_position;

	null_position = 0;
	chr = va_arg(arg, int);
	str = ft_strnew(1);
	null = (chr == '\0') ? 1 : 0;
	str[0] = chr + null;
	width_ctrl(info, &str);
	*ct = ft_strlen(str);
	if (null)
	{
		while (str[null_position] != chr + null)
			null_position++;
		str[null_position] = 0;
	}
	write(STDOUT, str, *ct);
	free(str);
}
