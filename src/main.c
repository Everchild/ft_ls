/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:12:03 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/27 02:25:08 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			destroy_env(t_env *env)
{
	if (env->files)
		free_list(&env->files);
	if (env->dirs)
		free_list(&env->dirs);
}

static void			init_env(t_env *env)
{
	env->options = NO_OPT;
	env->files = NULL;
	env->dirs = NULL;
}

int					main(int argc, char **argv)
{
	t_env			env;

	init_env(&env);
	if (argc > 1)
		parse_arg(&env, argv + 1);
//	ft_ls(&env);
	int i = 0;
	t_node *entry;
	struct passwd *lol;
	if (env.files)
	{
		entry = env.files->start;
		while (entry)
		{
			ft_printf("test1\n");
			ft_printf("name: %s\n", ((t_entry *)entry->content)->name);
			ft_printf("test2\n");
			lol = getpwuid(((t_entry *)entry->content)->data->st_uid);
			ft_printf("test3\n");
			ft_printf("%11s%11s\n", ((t_entry *)entry->content)->name, lol->pw_name);
			ft_printf("test4\n");
			entry = entry->next;
			ft_printf("test5\n");
			i++;
			ft_printf("test6\n");
		}
	}
	i = 0;
	if (env.dirs)
	{
		entry = env.dirs->start;
		while (entry)
		{
			ft_printf("param #%d: %s\n", i, entry->content);
			entry = entry->next;
			i++;
		}
	}
	destroy_env(&env);
//	while (1);
	return (0);
}
