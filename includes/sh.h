/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 14:52:24 by ihwang            #+#    #+#             */
/*   Updated: 2020/07/30 02:16:37 by ihwang           ###   ########.fr       */
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



// void					print_semicolon_error(char *line);
// void					print_is_dir(char *str);
// void					print_no_cmd(char *str);
// void					print_set_unset(char *str, int opt);
//int						is_eof(char *line);
void					sig_controller(int option);
char					*get_env(char *name, int keyval);
void					get_prompt(void);

#endif
