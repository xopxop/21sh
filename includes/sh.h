/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 14:52:24 by ihwang            #+#    #+#             */
/*   Updated: 2020/08/02 18:04:48 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# define KEY 1
# define VAL 0

# define PARENT 1
# define CHILD 0
# define F_TYPE_MASK 0170000

int						g_status;

void					sig_controller(int option);
char					*get_env(char *name, int keyval);
void					get_prompt(void);

#endif
