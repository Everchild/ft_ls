/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:36:01 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:36:03 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				remove_node(t_dblist **list, t_node *node)
{
	if (list && *list && node)
	{
		if (node->prev)
			node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		if (node == (*list)->start)
			(*list)->start = node->next;
		if (node == (*list)->end)
			(*list)->end = node->prev;
		ft_memdel((void **)&(node->content));
		ft_memdel((void **)&node);
		(*list)->nb_nodes -= 1;
	}
}
