/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:45:37 by sbrochar          #+#    #+#             */
/*   Updated: 2017/06/16 17:51:10 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void				free_data(t_dblist *list)
{
	t_node			*cur;

	cur = list->start;
	while (cur)
	{
		ft_strdel(&(((t_entry *)cur->content)->name));
		if (((t_entry *)cur->content)->data)
			ft_memdel((void **)&(((t_entry *)cur->content)->data));
		cur = cur->next;
	}
}
