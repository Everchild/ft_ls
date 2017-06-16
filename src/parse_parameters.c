/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:26:13 by sbrochar          #+#    #+#             */
/*   Updated: 2017/06/16 20:28:40 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static t_app_opts		*get_app_opts(void)
{
	static t_app_opts	opts[NB_OPT] = {
	{ O_ALL, 'a', "all" },
	{ O_LONG, 'l', "long" },
	{ O_RECURS, 'R', "recursive" },
	{ O_REVERSE, 'r', "reverse" },
	{ O_TIME, 't', "time" } };

	return (opts);
}

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

static void			parse_entry(char *param, t_dblist **dirs, t_dblist **files)
{
	struct stat		buf;
	t_node			*node;

	node = NULL;
	if (lstat(param, &buf) == -1)
	{
		ft_printf("ft_ls: cannot access ");
		perror(param);
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

t_opt				handle_params(char **params, t_dblist **dirs)
{
	t_opt			options;
	t_dblist		*files;

	options = NO_OPT;
	files = NULL;
	while (*params)
	{
		if ((*params)[0] == '-')
		{
			if ((*params)[1] == '-')
				parse_long_opt(&options, (*params) + 2);
			else
				parse_short_opt(&options, (*params) + 1);
		}
		else
			parse_entry(*params, dirs, &files);
		params++;
	}
	if (!(options & O_INVAL) && !files && !(*dirs))
	{
		*dirs = create_list();
		if (*dirs)
			add_node_end(dirs, create_node(".", 2));
	}
	else if (!(options & O_INVAL) && files)
		handle_files_in_param(options, files);
	return (options);
}
