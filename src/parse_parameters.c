/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:26:13 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/09 23:01:04 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			parse_long_opt(t_opt *options, char *flag)
{
	t_app_opts		*app_opts;
	int				i;

	app_opts = get_app_opts();
	i = 0;
	while (i < NB_OPT)
	{
		if (!ft_strcmp(flag, app_opts[i].word))
		{
			*options |= app_opts[i].flag;
			break ;
		}
		i++;
	}
	if (i == NB_OPT)
		*options = O_INVAL;
}

static void			parse_short_opt(t_opt *options, char *flag)
{
	t_app_opts		*app_opts;
	int				i;

	app_opts = get_app_opts();
	while (flag && *flag)
	{
		i = 0;
		while (i < NB_OPT)
		{
			if (*flag == app_opts[i].letter)
			{
				*options |= app_opts[i].flag;
				break ;
			}
			i++;
		}
		if (i == NB_OPT)
		{
			*options = O_INVAL;
			break ;
		}
		flag++;
	}
}

static void			parse_entry(char *param, t_dblist **dirs, t_dblist **files, t_dblist **invalid)
{
	struct stat		buf;
	t_node			*node;

	node = NULL;
	if (lstat(param, &buf) == -1)
	{
		if (!*invalid)
			*invalid = create_list();
		node = create_node(param, ft_strlen(param) + 1);
		if (*invalid && node)
			add_node_end(invalid, node);
//		ft_printf("ls: ");
//		perror(param);
	}
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

static void			check_params(t_opt options, t_dblist *invalid, t_dblist *files, t_dblist **dirs)
{
	t_node			*node;

	if (!(options & O_INVAL) && !invalid && !files && !(*dirs))
	{
		*dirs = create_list();
		if (*dirs)
			add_node_end(dirs, create_node(".", 2));
	}
	if (!(options & O_INVAL) && invalid)
	{
		sort_ascii(invalid);
		node = invalid->start;
		while (node)
		{
			ft_printf("ls: ");
			perror(node->content);
			node = node->next;
		}
	}
	if (!(options & O_INVAL) && files)
		handle_files_in_param(options, files, *dirs ? TRUE : FALSE);
}

t_opt				handle_params(char **params, t_dblist **dirs)
{
	t_opt			options;
	t_dblist		*files;
	t_dblist		*invalid;
	t_bool			end_opt;

	options = NO_OPT;
	files = NULL;
	invalid = NULL;
	end_opt = FALSE;
	while (*params)
	{
		if (!end_opt && (*params)[0] == '-')
		{
			if ((*params)[1] == '-' && (*params)[2])
				parse_long_opt(&options, (*params) + 2);
			else if ((*params)[1] == '-' && !(*params)[2])
				end_opt = TRUE;
			else if (!(*params)[1])
				parse_entry(*params, dirs, &files, &invalid);
			else
				parse_short_opt(&options, (*params) + 1);
		}
		else
			parse_entry(*params, dirs, &files, &invalid);
		params++;
	}
	check_params(options, invalid, files, dirs);
	return (options);
}
