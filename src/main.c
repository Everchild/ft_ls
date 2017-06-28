/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:12:03 by sbrochar          #+#    #+#             */
/*   Updated: 2017/06/28 14:03:32 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int					main(int argc, char **argv)
{
	t_opt			options;
	t_dblist		*dirs;
	t_node			*node;

	dirs = NULL;
	node = NULL;
/*	if (argc == 1)
	{
		options = NO_OPT;
		dirs = create_list();
		node = create_node(".", 2);
		if (dirs && node)
			add_node_end(&dirs, node);
	}
	else*/
		options = handle_params(argv + 1, &dirs);
	if (options & O_INVAL)
		ft_printf("ft_ls: illegal option\nusage: ft_ls [-Ralrt] [file ...]\n");
	else if (dirs)
	{
		ft_ls(options, dirs);
		free_list(&dirs);
	}
	(void)argc;
	//	while (1);
	return (0);
}
