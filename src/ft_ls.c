/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:22:58 by sbrochar          #+#    #+#             */
/*   Updated: 2017/06/28 13:30:22 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			register_struct_stat(t_opt options, char *dir, t_entry *entry)
{
	struct stat		buf;
	char			*tmp;

	if ((options & O_LONG) || (options & O_TIME) || options & O_RECURS)
	{
		tmp = ft_strcjoin(dir, entry->name, '/');
		if (lstat(tmp, &buf) == -1)
			ft_printf("error\n");
		entry->data = (struct stat *)ft_memdup(&buf, sizeof(struct stat));
		ft_strdel(&tmp);
	}
	else
		entry->data = NULL;
}

static void			get_dir_content(t_opt options, char *name, t_dblist *content)
{
	DIR				*dir;
	struct dirent	*data;
	t_node			*node;
	t_entry			entry;

	if ((dir = opendir(name)))
	{
		while ((data = readdir(dir)))
		{
			if (!(options & O_ALL) && data->d_name[0] == '.')
				continue ;
			entry.name = ft_strdup(data->d_name);
			register_struct_stat(options, name, &entry);
			entry.isdir = data->d_type & DT_DIR ? TRUE : FALSE;
			node = create_node(&entry, sizeof(t_entry));
			if (node)
				add_node_end(&content, node);
		}
		closedir(dir);
	}
}

void				ft_ls(t_opt options, t_dblist *dirs)
{
	t_dblist		*content;
	t_node			*cur;

	content = create_list();
	while (dirs->start)
	{
		cur = dirs->start;
		get_dir_content(options, cur->content, content);
		if (options & O_TIME)
			sort_timestamp(content);
		else
			sort_ascii(content);
		print_data(dirs, options, content);
		free_data(content);
		clear_list(&content);
		remove_node(&dirs, cur);
	}
}
