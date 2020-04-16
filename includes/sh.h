/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 14:52:24 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/01 14:52:37 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# define KEY 1
# define VAL 0
# define PARENT 1
# define CHILD 0
# define SET 1
# define UNSET 0
# define F_TYPE_MASK 0170000
# define PRINT 1
# define ER 0

int						g_status;



// void					print_semicolon_error(char *line);
// void					print_is_dir(char *str);
// void					print_no_cmd(char *str);
// void					print_set_unset(char *str, int opt);
int						is_eof(char *line);
// void					ft_pwd(void);
// void					ft_env(void);
void					sig_controller(int option);
char					*get_env(char *name, int keyval);
void					get_prompt(void);

#endif
