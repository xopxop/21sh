/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_project.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 04:27:40 by dthan             #+#    #+#             */
/*   Updated: 2020/04/02 04:27:41 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# define YES 1
# define NO 0

int		cmd_contains_pipe(char *cmd_input);
void	ft_lststrdel(char ***str);
void	parse_cmd(char *cmd_input, int *ret);

#endif
