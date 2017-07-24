/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 08:48:09 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/24 09:40:33 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static t_bool		check_links(char *param)
{
	struct stat		buf;

	stat(param, &buf);
	return (S_ISDIR(buf.st_mode));
}

static void			handle_error(char *param, t_dblist **invalid)
{
	t_node			*node;

	node = NULL;
	if (!*invalid)
		*invalid = create_list();
	node = create_node(param, ft_strlen(param) + 1);
	if (*invalid && node)
		add_node_end(invalid, node);
}

static void			handle_links(char *param, t_dblist **dirs, t_dblist **files,
					struct stat buf)
{
	t_node			*node;

	node = NULL;
	if (check_links(param))
	{
		if (!*dirs)
			*dirs = create_list();
		node = create_node(param, ft_strlen(param) + 1);
		if (*dirs && node)
			add_node_end(dirs, node);
	}
	else
		register_param_data(param, files, buf);
}

void				parse_entry(char *param, t_dblist **dirs, t_dblist **files,
					t_dblist **invalid)
{
	struct stat		buf;
	t_node			*node;

	node = NULL;
	if (lstat(param, &buf) == -1)
		handle_error(param, invalid);
	else if ((S_IFMT & buf.st_mode) == S_IFLNK)
		handle_links(param, dirs, files, buf);
	else if (S_ISDIR(buf.st_mode))
	{
		if (!*dirs)
			*dirs = create_list();
		node = create_node(param, ft_strlen(param) + 1);
		if (*dirs && node)
			add_node_end(dirs, node);
	}
	else
		register_param_data(param, files, buf);
}
