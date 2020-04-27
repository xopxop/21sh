/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:41:15 by dthan             #+#    #+#             */
/*   Updated: 2019/10/26 04:50:03 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_print.h"

void	ft_putendl_fd(char const *string, int filedescriptor)
{
	ft_putstr_fd(string, filedescriptor);
	ft_putchar_fd('\n', filedescriptor);
}
