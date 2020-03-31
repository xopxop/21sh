/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:48:28 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 01:01:33 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *node;
	t_list *n_node;

	node = *alst;
	while (node)
	{
		n_node = node->next;
		del(node->content, node->content_size);
		free(node);
		node = n_node;
	}
	*alst = NULL;
}
