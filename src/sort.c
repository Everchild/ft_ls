/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:31:09 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/05 10:11:18 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void				sort_ascii(t_dblist *list)
{
	t_bool			issort;
	t_node			*node;

	issort = FALSE;
	while (!issort)
	{
		issort = TRUE;
		node = list->start;
		while (node && node != list->end)
		{
			if (ft_strcmp(((t_entry *)node->content)->name, ((t_entry *)node->next->content)->name) > 0)
			{
				issort = FALSE;
				swap_nodes(&node, &node->next);
			}
			node = node->next;
		}
	}
}
//timestamp incorrect
void				sort_timestamp(t_dblist *list)
{
	t_bool			issort;
	t_node			*node;

	issort = FALSE;
	while (!issort)
	{
		issort = TRUE;
		node = list->start;
		while (node && node != list->end)
		{
			if ((((t_entry *)node->content)->data->st_mtime < ((t_entry *)node->next->content)->data->st_mtime) || (((t_entry *)node->content)->data->st_mtime == ((t_entry *)node->next->content)->data->st_mtime && (ft_strcmp(((t_entry *)node->content)->name, ((t_entry *)node->next->content)->name) > 0)))
			{
				issort = FALSE;
				swap_nodes(&node, &node->next);
			}
			node = node->next;
		}
	}
}
