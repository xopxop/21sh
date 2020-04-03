/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 17:49:01 by dthan             #+#    #+#             */
/*   Updated: 2020/04/03 17:49:19 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DQUOTE_H
# define DQUOTE_H

char	*get_input(int level);
int		open_d_quote(char *input, int level);
char	*ft_strjoin_and_free_string2(char *string1, char *string2);
char	*ft_strjoin_and_free_string1(char *string1, char *string2);

#endif
