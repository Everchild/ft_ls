/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:37:08 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/11 08:47:52 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			print_long(size_t *col_width, t_node *entry)
{
	struct passwd	*data_usr;
	struct group	*data_grp;
	char			*tmp;
	char			*year;

	data_usr = getpwuid(((t_entry *)entry->content)->data->st_uid);
	data_grp = getgrgid(((t_entry *)entry->content)->data->st_gid);
	tmp = get_permissions(((t_entry *)entry->content)->data);
	ft_printf("%s ", tmp);
	ft_strdel(&tmp);
	ft_printf("%*d ", col_width[0], ((t_entry *)entry->content)->data->st_nlink);
	if (data_usr)
		ft_printf("%-*s ", col_width[1], data_usr->pw_name);
	else
		ft_printf("%-*d ", col_width[1], ((t_entry *)entry->content)->data->st_uid);
	ft_printf("%-*s", col_width[2], data_grp->gr_name);
	ft_printf("%*d ", col_width[3], ((t_entry *)entry->content)->data->st_size);
	if ((time(NULL) - ((t_entry *)entry->content)->data->st_mtime) >= 15552000)
	{
		tmp = ft_strsub(ctime(&(((t_entry *)entry->content)->data->st_mtime)), 4, 7);
		year = ft_strsub(ctime(&(((t_entry *)entry->content)->data->st_mtime)), 19, 5);
		ft_printf("%s%s ", tmp, year);
		ft_strdel(&year);
	}
	else
	{
		tmp = ft_strsub(ctime(&(((t_entry *)entry->content)->data->st_mtime)), 4, 12);
		ft_printf("%s ", tmp);
	}
	ft_strdel(&tmp);
	ft_printf("%s", ((t_entry *)entry->content)->name);
	if ((((t_entry *)entry->content)->data->st_mode & S_IFMT) == S_IFLNK)
	{
		tmp = ft_strnew(BUFF_SIZE);
		if (readlink(((t_entry *)entry->content)->name, tmp, BUFF_SIZE) != -1)
			ft_printf(" -> %s", tmp);
		ft_strdel(&tmp);
	}
	ft_printf("\n");
}

static void			print_reverse(size_t *col_width, t_dblist *dirs, t_opt options, t_dblist *data)
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
		if (options & O_LONG)
			print_long(col_width, cur);
		else
			ft_printf("%s\n", ((t_entry *)cur->content)->name);
		cur = cur->prev;
	}
	ft_memdel((void **)&col_width);
}

static void			print_default(size_t *col_width, t_dblist *dirs, t_opt options, t_dblist *data)
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
				if (((char *)first->content)[0] == '/' && ((char *)first->content)[1] == '\0')
					tmp = ft_strjoin(first->content, ((t_entry *)cur->content)->name);
				else
					tmp = ft_strcjoin(first->content, ((t_entry *)cur->content)->name, '/');
				new_dir = create_node(tmp, ft_strlen(tmp) + 1);
				insert_node(&dirs, new_dir, first);
				ft_strdel(&tmp);
			}
		}
		if (options & O_LONG)
			print_long(col_width, cur);
		else
			ft_printf("%s\n", ((t_entry *)cur->content)->name);
		cur = cur->next;
	}
	ft_memdel((void **)&col_width);
}

static size_t		*min_col_width(t_opt options, t_dblist *data)
{
	size_t			*ret;
	size_t			tmp;
	t_node			*cur;
	
	ret = (size_t *)ft_memalloc(sizeof(size_t) * 4);
	ret[0] = 2;
	ret[1] = 5;
	ret[2] = 5;
	ret[3] = 2;
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
			tmp = ft_strlen((getgrgid(((t_entry *)cur->content)->data->st_gid))->gr_name) + 1;
			ret[2] = tmp > ret[2] ? tmp : ret[2];
			tmp = ft_strlen(ft_itoa(((t_entry *)cur->content)->data->st_size)) + 1;
			ret[3] = tmp > ret[3] ? tmp : ret[3];
			cur = cur->next;
		}
	}
	return (ret);
}

void				print_data(t_dblist *dirs, t_opt options, t_dblist *data, t_bool params)
{
	static t_bool	first_dir = TRUE;

	if (dirs && ft_strcmp(dirs->start->content, ".") && !(first_dir && dirs->start == dirs->end))
		ft_printf("%s:\n", dirs->start->content);
	if (data->start)
	{
		if ((((t_entry *)data->start->content)->isdir && !(((t_entry *)data->start->content)->perms & P_READ)))
			ft_printf("ls: %s: Permission denied\n", dirs->start->content);
		else if (  ((((t_entry *)data->start->content)->perms & P_READ) && (((t_entry *)data->start->content)->perms & P_EXEC)) || ! ((t_entry *)data->start->content)->isdir)
		{
			if (dirs && (options & O_LONG))
				ft_printf("total %d\n", get_total(data));
			if (options & O_REVERSE)
				print_reverse(min_col_width(options, data), dirs, options, data);
			else
				print_default(min_col_width(options, data), dirs, options, data);
		}
	}
	if ((!(dirs) && params) || (dirs && dirs->start != dirs->end))
		ft_printf("\n");
	if (first_dir)
		first_dir = FALSE;
}
