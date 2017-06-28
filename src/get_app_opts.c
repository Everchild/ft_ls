/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_app_opts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:33:05 by sbrochar          #+#    #+#             */
/*   Updated: 2017/06/28 15:40:59 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_app_opts			*get_app_opts(void)
{
	static t_app_opts	opts[NB_OPT] = {
	{ O_ALL, 'a', "all" },
	{ O_LONG, 'l', "long" },
	{ O_RECURS, 'R', "recursive" },
	{ O_REVERSE, 'r', "reverse" },
	{ O_TIME, 't', "time" },
	{ O_DEFAULT, '1', "default" } };

	return (opts);
}
