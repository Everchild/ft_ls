/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:31:09 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/23 12:17:13 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void				sort_ascii(t_dblist *list)
{
	t_bool			issort;
	t_node			*node;

	issort = FALSE;
	if (list && list->start)
	{
		while (!issort)
		{
			issort = TRUE;
			node = list->start;
			while (((t_entry *)node->content)->data
				&& node && node != list->end)
			{
				if (ft_strcmp(((t_entry *)node->content)->name,
				((t_entry *)node->next->content)->name) > 0)
				{
					issort = FALSE;
					swap_nodes(&node, &node->next);
				}
				node = node->next;
			}
		}
	}
}

static void			check_time(t_node *node, t_bool *issort)
{
	struct stat		*data;

	data = ((t_entry *)node->content)->data;
	if ((data->st_mtime < ((t_entry *)node->next->content)->data->st_mtime)
		|| (data->st_mtime == ((t_entry *)node->next->content)->data->st_mtime
		&& (ft_strcmp(((t_entry *)node->content)->name,
				((t_entry *)node->next->content)->name) > 0)))
	{
		*issort = FALSE;
		swap_nodes(&node, &node->next);
	}
}

void				sort_timestamp(t_dblist *list)
{
	t_bool			issort;
	t_node			*node;

	issort = FALSE;
	if (list && list->start)
	{
		while (!issort && list->start)
		{
			issort = TRUE;
			node = list->start;
			while (((t_entry *)node->content)->data
				&& node && node != list->end)
			{
				check_time(node, &issort);
				node = node->next;
			}
		}
	}
}
