/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:37:08 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/18 16:25:59 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static size_t		*min_col_width(t_opt options, t_dblist *data)
{
	size_t			*ret;
	size_t			tmp;
	t_node			*cur;
	
	ret = (size_t *)ft_memalloc(sizeof(size_t) * 5);
	ret[0] = 2;
	ret[1] = 5;
	ret[2] = 5;
	ret[3] = 2;
	ret[4] = 2;
	if (options & O_LONG)
	{
		cur = data->start;
		while (cur)
		{
			tmp = ft_strlen(ft_itoa(((t_entry *)cur->content)->data->st_nlink)) + 1;
			ret[0] = tmp > ret[0] ? tmp : ret[0];
			if (getpwuid(((t_entry *)cur->content)->data->st_uid))
				tmp = ft_strlen((getpwuid(((t_entry *)cur->content)->data->st_uid))->pw_name) + 1;
			else
				tmp = ft_strlen(ft_itoa(((t_entry *)cur->content)->data->st_uid));
			ret[1] = tmp > ret[1] ? tmp : ret[1];
			if (getpwuid(((t_entry *)cur->content)->data->st_uid))
				tmp = ft_strlen((getgrgid(((t_entry *)cur->content)->data->st_gid))->gr_name) + 1;
			else
				tmp = ft_strlen(ft_itoa(((t_entry *)cur->content)->data->st_gid));
			ret[2] = tmp > ret[2] ? tmp : ret[2];
			if ((((t_entry *)cur->content)->data->st_mode & S_IFMT) == S_IFCHR)
			{
				tmp = ft_strlen(ft_itoa(minor(((t_entry *)cur->content)->data->st_rdev)));
				ret[4] = tmp > ret[4] ? tmp : ret[4];
				tmp = ft_strlen(ft_itoa(major(((t_entry *)cur->content)->data->st_rdev)));
			}
			else
				tmp = ft_strlen(ft_itoa(((t_entry *)cur->content)->data->st_size)) + 1;
			ret[3] = tmp > ret[3] ? tmp : ret[3];
			cur = cur->next;
		}
	}
	return (ret);
}

static void			print_reverse(size_t *col_width, t_dblist *dirs, t_opt options, t_dblist *data)
{
	t_node			*cur;
	t_node			*new_dir;
	t_node			*first;
	char			*tmp;
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
		if (ft_strcmp(((t_entry *)cur->content)->name, ".") && ft_strcmp(((t_entry *)cur->content)->name, ".."))
		{
			if ((options & O_RECURS) && S_ISDIR(((t_entry *)cur->content)->data->st_mode))
			{
				if (((char *)first->content)[0] == '/' && ((char *)first->content)[1] == '\0')
					tmp = ft_strjoin(first->content, ((t_entry *)cur->content)->name);
				else
					tmp = ft_strcjoin(first->content, ((t_entry *)cur->content)->name, '/');
				new_dir = create_node(tmp, ft_strlen(tmp) + 1);
				insert_node(&dirs, new_dir, first);
				ft_strdel(&tmp);
			}
		}
		path = ft_strcjoin(cur_dir, ((t_entry *)cur->content)->name, '/');
		if (options & O_LONG)
			print_long(path, col_width, cur);
		else
			ft_printf("%s\n", ((t_entry *)cur->content)->name);
		ft_strdel(&path);
		cur = cur->prev;
	}
}

static void			print_default(size_t *col_width, t_dblist *dirs, t_opt options, t_dblist *data)
{
	t_node			*cur;
	t_node			*new_dir;
	t_node			*first;
	char			*tmp;
	char			*cur_dir;
	char			*path;

	cur = data->start;
	if (dirs)
	{
		first = dirs->start;
		cur_dir = dirs->start->content;
	}
	while (cur)
	{
		if (ft_strcmp(((t_entry *)cur->content)->name, ".") && ft_strcmp(((t_entry *)cur->content)->name, ".."))
		{
			if ((options & O_RECURS) && S_ISDIR(((t_entry *)cur->content)->data->st_mode))
			{
				if (((char *)first->content)[0] == '/' && ((char *)first->content)[1] == '\0')
					tmp = ft_strjoin(first->content, ((t_entry *)cur->content)->name);
				else
					tmp = ft_strcjoin(first->content, ((t_entry *)cur->content)->name, '/');
				new_dir = create_node(tmp, ft_strlen(tmp) + 1);
				insert_node(&dirs, new_dir, first);
				ft_strdel(&tmp);
			}
		}
		path = ft_strcjoin(cur_dir, ((t_entry *)cur->content)->name, '/');
		if (options & O_LONG)
			print_long(path, col_width, cur);
		else
			ft_printf("%s\n", ((t_entry *)cur->content)->name);
		ft_strdel(&path);
		cur = cur->next;
	}
}

void				print_data(t_dblist *dirs, t_opt options, t_dblist *data, t_bool params)
{
	static t_bool	first_dir = TRUE;
	size_t			*col_width;

	if (dirs && ft_strcmp(dirs->start->content, ".") && !(first_dir && dirs->start == dirs->end))
		ft_printf("%s:\n", dirs->start->content);
	if (data->start)
	{
		if ((((t_entry *)data->start->content)->isdir && !(((t_entry *)data->start->content)->perms & P_READ)))
			ft_printf("ls: %s: Permission denied\n", dirs->start->content);
		else if (((((t_entry *)data->start->content)->perms & P_READ) && (((t_entry *)data->start->content)->perms & P_EXEC)) || ! ((t_entry *)data->start->content)->isdir)
		{
			if (options & O_LONG)
			{
				col_width = min_col_width(options, data);
				if (dirs)
					ft_printf("total %d\n", get_total(data));
			}
			if (options & O_REVERSE)
				print_reverse(col_width, dirs, options, data);
			else
				print_default(col_width, dirs, options, data);
		}
	}
	if ((!(dirs) && params) || (dirs && dirs->start != dirs->end))
		ft_printf("\n");
	if (first_dir)
		first_dir = FALSE;
}
