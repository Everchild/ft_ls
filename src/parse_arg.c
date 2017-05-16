/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:26:13 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/16 16:47:45 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

//static void			parse_entry(t_env *env, char *arg)
//{
//
//}

static void			parse_opt(t_env *env, char *arg)
{
	while (*arg)
	{
		arg++;
	}
	env->options = NO_OPT;
}

void				parse_arg(t_env *env, char **arg)
{
	while (arg && *arg)
	{
		if (**arg == '-')
		{
			ft_printf("*arg: %s, *arg + 1: %s\n", *arg, *arg + 1);
			parse_opt(env, (*arg) + 1);
		}
//		else
//			parse_entry(env, *arg);
		arg++;
	}
}
