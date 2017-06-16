/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:10:50 by sbrochar          #+#    #+#             */
/*   Updated: 2017/06/05 20:52:53 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <uuid/uuid.h>
# include <dirent.h>
# include <libft.h>
# include <stdio.h>

# define NB_OPT 5

typedef enum		e_opt
{
	NO_OPT = 0,
	O_LONG = 1 << 1,
	O_RECURS = 1 << 2,
	O_ALL = 1 << 3,
	O_REVERSE = 1 << 4,
	O_TIME =  1 << 5
}					t_opt;

typedef struct		s_app_opts
{
	t_opt			flag;
	char			letter;
	char			*word;
}					t_app_optss;

typedef struct		s_entry
{
	char			*name;
	struct stat		*data;
	t_bool			isdir;
}					t_entry;

//le main appelle
t_opt				handle_params(char **params, t_dblist **dirs);
void				ft_ls(t_opt options, t_dblist *dirs);

//handle_params appelle
void				parse_long_opt(t_opt *options, char *flag);
void				parse_short_opt(t_opt *options, char *flag);
void				parse_entry(char *param, t_dblist **dirs, t_dblist **files);
void				handle_files_in_param(t_opt options, t_dblist *files);

//parse_entry appelle
void				register_file_data(char *name, t_dblist **files, struct stat buf);

#endif
