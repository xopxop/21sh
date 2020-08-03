/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 14:36:43 by dthan             #+#    #+#             */
/*   Updated: 2020/08/02 17:56:00 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_error.h"

void	ft_error_malloc(void)
{
	ft_putstr_fd("Not enough space/cannot allocate memory\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int		error_monitor(char *first, char *second, char *third, int ret_value)
{
	if (first)
		ft_putstr_fd(first, STDERR_FILENO);
	if (second)
		ft_putstr_fd(second, STDERR_FILENO);
	if (third)
		ft_putstr_fd(third, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	if (ret_value == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
