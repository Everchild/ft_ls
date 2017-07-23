/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:37:08 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/23 11:20:31 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			check_recurs_dir(t_opt options, t_dblist *dirs,
					t_node *entry, t_node *first)
{
	t_node			*new_dir;
	char			*tmp;

	if (dirs)
	{
		if ((options & O_RECURS)
			&& S_ISDIR(((t_entry *)entry->content)->data->st_mode))
		{
			if (((char *)first->content)[0] == '/'
				&& ((char *)first->content)[1] == '\0')
				tmp = ft_strjoin(first->content,
					((t_entry *)entry->content)->name);
			else
				tmp = ft_strcjoin(first->content,
					((t_entry *)entry->content)->name, '/');
			new_dir = create_node(tmp, ft_strlen(tmp) + 1);
			insert_node(&dirs, new_dir, first);
			ft_strdel(&tmp);
		}
	}
}

static void			print_reverse(size_t *col_width, t_dblist *dirs,
					t_opt options, t_dblist *data)
{
	t_node			*cur;
	t_node			*first;
	char			*cur_dir;
	char			*path;

	cur = data->end;
	cur_dir = NULL;
	if (dirs)
	{
		first = dirs->start;
		cur_dir = dirs->start->content;
	}
	while (cur)
	{
		if (ft_strcmp(((t_entry *)cur->content)->name, ".")
			&& ft_strcmp(((t_entry *)cur->content)->name, ".."))
			check_recurs_dir(options, dirs, cur, first);
		path = ft_strcjoin(cur_dir, ((t_entry *)cur->content)->name, '/');
		if (options & O_LONG)
			print_long(path, col_width, cur);
		else
			ft_printf("%s\n", ((t_entry *)cur->content)->name);
		ft_strdel(&path);
		cur = cur->prev;
	}
}

static void			print_default(size_t *col_width, t_dblist *dirs,
					t_opt options, t_dblist *data)
{
	t_node			*cur;
	t_node			*first;
	char			*cur_dir;
	char			*path;

	cur = data->start;
	cur_dir = NULL;
	if (dirs)
	{
		first = dirs->start;
		cur_dir = dirs->start->content;
	}
	while (cur)
	{
		if (ft_strcmp(((t_entry *)cur->content)->name, ".")
			&& ft_strcmp(((t_entry *)cur->content)->name, ".."))
			check_recurs_dir(options, dirs, cur, first);
		path = ft_strcjoin(cur_dir, ((t_entry *)cur->content)->name, '/');
		if (options & O_LONG)
			print_long(path, col_width, cur);
		else
			ft_printf("%s\n", ((t_entry *)cur->content)->name);
		ft_strdel(&path);
		cur = cur->next;
	}
}

static void			handle_print(t_dblist *dirs, t_opt options, t_dblist *data)
{
	size_t			*col_width;

	if (options & O_LONG)
	{
		col_width = min_col_width(data);
		if (dirs)
			ft_printf("total %d\n", get_total(data));
	}
	if (options & O_REVERSE)
		print_reverse(col_width, dirs, options, data);
	else
		print_default(col_width, dirs, options, data);
}

void				print_data(t_dblist *dirs, t_opt options, t_dblist *data,
					t_bool params)
{
	static t_bool	first_dir = TRUE;

	if (dirs && ft_strcmp(dirs->start->content, ".")
		&& !(first_dir && dirs->start == dirs->end))
		ft_printf("%s:\n", dirs->start->content);
	if (data->start)
	{
		if ((((t_entry *)data->start->content)->isdir
			&& !(((t_entry *)data->start->content)->perms & P_READ)))
			ft_printf("ls: %s: Permission denied\n", dirs->start->content);
		else if (((((t_entry *)data->start->content)->perms & P_READ)
				&& (((t_entry *)data->start->content)->perms & P_EXEC))
				|| !((t_entry *)data->start->content)->isdir)
			handle_print(dirs, options, data);
	}
	if ((!(dirs) && params) || (dirs && dirs->start != dirs->end))
		ft_printf("\n");
	first_dir = FALSE;
}
