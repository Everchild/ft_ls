/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:22:58 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/23 11:59:21 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static t_bool		get_dir_permissions(char *dir, t_perms *perms)
{
	struct stat		buf;

	if (lstat(dir, &buf) < 0)
		ft_printf("");
	else
	{
		if (buf.st_mode & S_IXUSR)
			*perms |= P_EXEC;
		if (buf.st_mode & S_IRUSR)
			*perms |= P_READ;
	}
	return ((*perms & P_EXEC) && (*perms & P_READ));
}

static t_bool		register_struct_stat(char *dir, t_entry *entry)
{
	struct stat		buf;
	char			*tmp;

	if (!ft_strcmp(dir, "/"))
		tmp = ft_strjoin(dir, entry->name);
	else
		tmp = ft_strcjoin(dir, entry->name, '/');
	if (lstat(tmp, &buf) == -1)
		return (FALSE);
	entry->data = (struct stat *)ft_memdup(&buf, sizeof(struct stat));
	ft_strdel(&tmp);
	return (TRUE);
}

static void			get_dir_content(t_opt options, char *name,
					t_dblist *content)
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
			if (!register_struct_stat(name, &entry))
				continue ;
			entry.isdir = data->d_type & DT_DIR ? TRUE : FALSE;
			entry.perms = P_READ | P_EXEC;
			node = create_node(&entry, sizeof(t_entry));
			if (node)
				add_node_end(&content, node);
		}
		closedir(dir);
	}
}

static void			init_dir_without_perm(t_dblist *content, char *name,
					t_perms perms)
{
	t_entry			entry;
	t_node			*node;

	entry.name = ft_strdup(name);
	entry.data = NULL;
	entry.isdir = TRUE;
	entry.perms = perms;
	node = create_node(&entry, sizeof(entry));
	if (node)
		add_node_end(&content, node);
}

void				ft_ls(t_opt options, t_dblist *dirs)
{
	t_dblist		*content;
	t_node			*cur;
	t_perms			perms;

	content = create_list();
	while (dirs->start)
	{
		perms = P_NONE;
		cur = dirs->start;
		if (get_dir_permissions(cur->content, &perms))
			get_dir_content(options, cur->content, content);
		else
			init_dir_without_perm(content, cur->content, perms);
		if (options & O_TIME)
			sort_timestamp(content);
		else
			sort_ascii(content);
		print_data(dirs, options, content, FALSE);
		free_data(content);
		clear_list(&content);
		remove_node(&dirs, cur);
	}
}
