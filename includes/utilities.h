/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 11:35:45 by dthan             #+#    #+#             */
/*   Updated: 2020/04/13 11:35:48 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

int is_separator_operator(char c);
int	is_open_dquote(char *input, int level);
int	input_contain_dquote(char *input);
int	pre_tokens_contains_separator_operator(char *pre_token);

#endif
