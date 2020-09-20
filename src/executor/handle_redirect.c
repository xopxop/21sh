/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 02:26:01 by tango             #+#    #+#             */
/*   Updated: 2020/08/05 05:41:52 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			handle_redirect(t_exe exe)
{
	t_redirect *traverse;

	traverse = exe.redi;
	while (traverse)
	{
		if (ft_strequ(traverse->redirect_op, ">"))
			redirect_great(traverse);
		else if (ft_strequ(traverse->redirect_op, ">>"))
			redirect_dgreat(traverse);
		else if (ft_strequ(traverse->redirect_op, "<"))
			redirect_less(traverse);
		else if (ft_strequ(traverse->redirect_op, "<<"))
			redirect_dless(&exe);
		else if (ft_strequ(traverse->redirect_op, ">&"))
			redirect_greatand(traverse);
		else if (ft_strequ(traverse->redirect_op, "<&"))
			redirect_lessand(traverse);
		traverse = traverse->next;
	}
}
