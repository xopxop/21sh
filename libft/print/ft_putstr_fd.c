/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:27:03 by dthan             #+#    #+#             */
/*   Updated: 2019/10/26 04:51:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_print.h"

void	ft_putstr_fd(char const *string, int filedescriptor)
{
	while (*string)
	{
		ft_putchar_fd(*string, filedescriptor);
		string++;
	}
}
