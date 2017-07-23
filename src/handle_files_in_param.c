/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files_in_param.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:50:16 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/23 11:59:39 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void				register_param_data(char *name, t_dblist **files,
					struct stat buf)
{
	t_node			*node;
	t_entry			entry;

	node = NULL;
	entry.name = ft_strdup(name);
	entry.data = (struct stat *)ft_memdup(&buf, sizeof(struct stat));
	entry.isdir = S_ISDIR(buf.st_mode) ? TRUE : FALSE;
	entry.perms = P_NONE;
	if (buf.st_mode & S_IRUSR)
		entry.perms |= P_READ;
	if (buf.st_mode & S_IXUSR)
		entry.perms |= P_EXEC;
	node = create_node(&entry, sizeof(t_entry));
	if (!*files)
		*files = create_list();
	if (*files && node)
		add_node_end(files, node);
}

void				handle_files_in_param(t_opt options, t_dblist *files,
					t_bool dirs)
{
	if (options & O_TIME)
		sort_timestamp(files);
	else
		sort_ascii(files);
	print_data(NULL, options, files, dirs);
	free_data(files);
	free_list(&files);
}
