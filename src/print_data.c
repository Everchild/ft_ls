/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:37:08 by sbrochar          #+#    #+#             */
/*   Updated: 2017/06/16 20:28:34 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			print_default(t_dblist *dirs, t_opt options, t_dblist *data)
{
	t_node			*cur;
	t_node			*new_dir;
	t_node			*first;
	char			*tmp;

	cur = data->start;
	ft_printf("test5\n");
	if (dirs)
		first = dirs->start;
	while (cur)
	{
//	ft_printf("test6\n");
//	ft_printf("%p\n", )
		if ((options & O_RECURS) && S_ISDIR(((t_entry *)cur->content)->data->st_mode))
		{
			tmp = ft_strcjoin(first->content, ((t_entry *)cur->content)->name, '/');
			new_dir = create_node(tmp, ft_strlen(tmp) + 1);
			insert_node(&dirs, new_dir, first);
			ft_strdel(&tmp);
		}
		ft_printf("%s\n", ((t_entry *)cur->content)->name);
		cur = cur->next;
	}
}
//incomplete
void				print_data(t_dblist *dirs, t_opt options, t_dblist *data)
{
			ft_printf("test1\n");
	if (dirs && dirs->nb_nodes > 1)
		ft_printf("%s:\n", dirs->start->content);
			ft_printf("test1\n");
	print_default(dirs, options, data);
}
