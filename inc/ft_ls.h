/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:10:50 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/24 18:01:58 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>

typedef enum		e_opt
{
	NO_OPT = 0,
	LONG = 1 << 1,
	RECURS = 1 << 2,
	HIDDEN = 1 << 3,
	REVERSE = 1 << 4,
	TIME =  1 << 5
}					t_opt;

/*typedef struct		s_data
{
i	
}					t_data;*/

typedef struct		s_env
{
	t_opt			options;
	t_dblist		*files;
	t_dblist		*dirs;
	DIR				*cur_dir;
}					t_env;

void				parse_arg(t_env *env, char **arg);

#endif
