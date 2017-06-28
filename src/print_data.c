/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:37:08 by sbrochar          #+#    #+#             */
/*   Updated: 2017/06/28 21:02:22 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*static void			print_long()
{
	int				total;


	ft_printf("total %d", total);
}*/

static void			print_reverse(t_dblist *dirs, t_opt options, t_dblist *data)
{
	t_node			*cur;
	t_node			*new_dir;
	t_node			*first;
	char			*tmp;

	cur = data->end;
	if (dirs)
		first = dirs->start;
	while (cur)
	{
		if ((options & O_RECURS) && S_ISDIR(((t_entry *)cur->content)->data->st_mode))
		{
			tmp = ft_strcjoin(first->content, ((t_entry *)cur->content)->name, '/');
			new_dir = create_node(tmp, ft_strlen(tmp) + 1);
			insert_node(&dirs, new_dir, first);
			ft_strdel(&tmp);
		}
		ft_printf("%s\n", ((t_entry *)cur->content)->name);
		cur = cur->prev;
	}
}

static void			print_default(t_dblist *dirs, t_opt options, t_dblist *data)
{
	t_node			*cur;
	t_node			*new_dir;
	t_node			*first;
	char			*tmp;

	cur = data->start;
	if (dirs)
		first = dirs->start;
	while (cur)
	{
		if (ft_strcmp(((t_entry *)cur->content)->name, ".") && ft_strcmp(((t_entry *)cur->content)->name, ".."))
		{
			if ((options & O_RECURS) && S_ISDIR(((t_entry *)cur->content)->data->st_mode))
			{
				tmp = ft_strcjoin(first->content, ((t_entry *)cur->content)->name, '/');
				new_dir = create_node(tmp, ft_strlen(tmp) + 1);
				insert_node(&dirs, new_dir, first);
				ft_strdel(&tmp);
			}
		}
		ft_printf("%s\n", ((t_entry *)cur->content)->name);
		cur = cur->next;
	}
}
//incomplete
void				print_data(t_dblist *dirs, t_opt options, t_dblist *data)
{
	static t_bool	first_dir = TRUE;
	if (dirs && ft_strcmp(dirs->start->content, ".") && !(first_dir && dirs->start == dirs->end))
		ft_printf("%s:\n", dirs->start->content);
	if ((options & O_LONG) && (options & O_REVERSE))
		print_reverse(dirs, options, data);
	else if (options & O_LONG)
		print_default(dirs, options, data);
	else if (options & O_REVERSE)
		print_reverse(dirs, options, data);
	else
		print_default(dirs, options, data);
	if (!dirs || (dirs && dirs->start != dirs->end))
		ft_printf("\n");
	if (first_dir)
		first_dir = FALSE;
}
