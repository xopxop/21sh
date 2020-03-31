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

#include "../includes/minishell.h"

void	ft_error_malloc(void)
{
	ft_putstr_fd("Not enough space/cannot allocate memory\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
