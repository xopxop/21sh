/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 14:36:43 by dthan             #+#    #+#             */
/*   Updated: 2020/03/26 14:36:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell_error.h"

void	ft_error_malloc(void)
{
	ft_putstr_fd("Not enough space/cannot allocate memory\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	error_monitor(char *first, char *second, char *third, char *fourth, \
					int ret_value, int exit_value)
{
	if (first)
		ft_putstr_fd(first, STDERR_FILENO);
	if (second)
		ft_putstr_fd(second, STDERR_FILENO);
	if (third)
		ft_putstr_fd(third, STDERR_FILENO);
	if (fourth)
		ft_putstr_fd(fourth, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	if (ret_value == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (exit_value == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
