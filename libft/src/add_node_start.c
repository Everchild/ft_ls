/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:41:38 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:41:39 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_node				*add_node_start(t_dblist **list, t_node *node)
{
	if (list && *list && node)
	{
		if (!(*list)->start && !(*list)->end)
		{
			(*list)->start = node;
			(*list)->end = node;
			node->next = NULL;
		}
		else
		{
			node->next = (*list)->end;
			(*list)->start->prev = node;
			(*list)->start = node;
		}
		node->prev = NULL;
		(*list)->nb_nodes += 1;
		return ((*list)->start);
	}
	return (NULL);
}
