/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:12:03 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/16 16:47:48 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

//static void			destroy_env(t_env *env)
//{
//
//}

static void			init_env(t_env *env)
{
	env->options = NO_OPT;
}

int					main(int argc, char **argv)
{
	t_env			env;

	init_env(&env);
	if (argc > 1)
		parse_arg(&env, argv + 1);
//	get_data(&env);
//	sort_data(&env);
//	print_data(&env);
//	destroy_env(&env);
	return (0);
}
