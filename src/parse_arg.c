/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:26:13 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/27 02:57:23 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static t_args			*get_all_args(void)
{
	static t_args		args[NB_OPT] = {
	{ O_ALL, 'a', "all" },
	{ O_LONG, 'l', "long" },
	{ O_RECURS, 'R', "recursive" },
	{ O_REVERSE, 'r', "reverse" },
	{ O_TIME, 't', "time" } };

	return (args);
}

static void			parse_entry(t_env *env, char *arg)
{
	t_node			*new;
	t_entry			*entry;
	struct stat		buf;

	entry = NULL;
	if (lstat(arg, &buf) == -1)
	{
		ft_printf("ft_ls: cannot access ");
		perror(arg);
	}
	else
	{
		if (S_ISDIR(buf.st_mode))
		{
			if (!env->dirs)
				env->dirs = create_list();
			add_node_end(&env->dirs, create_node(arg, ft_strlen(arg) + 1));
		}
		else
		{
			if (!env->files)
				env->files = create_list();
			entry = (t_entry *)ft_memalloc(sizeof(t_entry));
			entry->name = ft_strdup(arg);
//			entry->data = (struct stat)ft_memdup((void *)&buf, sizeof(struct stat));
			entry->content = NULL;
			new = create_node(entry, sizeof(t_entry *));
			add_node_end(&env->files, new);
		}
//			init_file(env);
	}
}

static void			parse_long_opt(t_env *env, char *arg, t_args *all)
{
	int				i;

	i = 0;
	while (i < NB_OPT)
	{
		if (!ft_strcmp(arg, all[i].word))
		{
			env->options |= all[i].flag;
			break ;
		}
		i++;
	}
}

static void			parse_short_opt(t_env *env, char *arg, t_args *all)
{
	int				i;

	i = 0;
	while (*arg)
	{
		while (i < NB_OPT)
		{
			if (*arg == all[i].letter)
			{
				env->options |= all[i].flag;
				break ;
			}
			i++;
		}
		arg++;
	}
}

void				parse_arg(t_env *env, char **arg)
{
	t_args			*all;

	all = get_all_args();
	while (arg && *arg)
	{
		if (**arg == '-')
		{
			if (*(*arg + 1) == '-')
				parse_long_opt(env, (*arg) + 2, all);
			else
				parse_short_opt(env, (*arg) + 1, all);
		}
		else
			parse_entry(env, *arg);
		arg++;
	}
}
