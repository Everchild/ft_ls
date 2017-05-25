/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:12:03 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/25 13:42:20 by sbrochar         ###   ########.fr       */
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
	destroy_env(&env);
//	while (1);
	return (0);
}
