/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:37:08 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/04 11:49:49 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			print_long(size_t *col_width, t_node *entry)
{
	struct passwd	*data_usr;
	struct group	*data_grp;
	char			*tmp;
	time_t			last_modif;

	data_usr = getpwuid(((t_entry *)entry->content)->data->st_uid);
	data_grp = getgrgid(((t_entry *)entry->content)->data->st_gid);
	tmp = get_permissions(((t_entry *)entry->content)->data);
	ft_printf("%s ", tmp);
	ft_strdel(&tmp);
	ft_printf("%*d ", col_width[0], ((t_entry *)entry->content)->data->st_nlink);
	ft_printf("%-*s", col_width[1], data_usr->pw_name);
	ft_printf("%*s ", col_width[2], data_grp->gr_name);
	ft_printf("%*d ", col_width[3], ((t_entry *)entry->content)->data->st_size);
	last_modif = time(&(((t_entry *)entry->content)->data->st_mtime));
	tmp = ft_strsub(ctime(&last_modif), 4, 12);
	ft_printf("%s ", tmp);
	ft_strdel(&tmp);
	ft_printf("%s", ((t_entry *)entry->content)->name);
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
		if ((options & O_RECURS) && S_ISDIR(((t_entry *)cur->content)->data->st_mode))
		{
			tmp = ft_strcjoin(first->content, ((t_entry *)cur->content)->name, '/');
			new_dir = create_node(tmp, ft_strlen(tmp) + 1);
			insert_node(&dirs, new_dir, first);
			ft_strdel(&tmp);
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
			tmp = ft_strlen((getpwuid(((t_entry *)cur->content)->data->st_uid))->pw_name) + 1;
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

void				print_data(t_dblist *dirs, t_opt options, t_dblist *data)
{
	static t_bool	first_dir = TRUE;
	int				total;
	t_node			*cur;
	if (dirs && ft_strcmp(dirs->start->content, ".") && !(first_dir && dirs->start == dirs->end))
		ft_printf("%s:\n", dirs->start->content);
	if (dirs && (options & O_LONG))
	{
		total = 0;
		cur = data->start;
		while (cur)
		{
			total += ((t_entry *)cur->content)->data->st_blocks;
			cur = cur->next;
		}
		ft_printf("total %d\n", total);
	}
	if (options & O_REVERSE)
		print_reverse(min_col_width(options, data), dirs, options, data);
	else
		print_default(min_col_width(options, data), dirs, options, data);
	if (!dirs || (dirs && dirs->start != dirs->end))
		ft_printf("\n");
	if (first_dir)
		first_dir = FALSE;
}
