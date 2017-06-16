/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:10:50 by sbrochar          #+#    #+#             */
/*   Updated: 2017/06/16 20:28:45 by sbrochar         ###   ########.fr       */
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
	O_INVAL = 1 << 1,
	O_RECURS = 1 << 2,
	O_ALL = 1 << 3,
	O_REVERSE = 1 << 4,
	O_TIME =  1 << 5,
	O_LONG = 1 << 6
	
}					t_opt;

typedef struct		s_app_opts
{
	t_opt			flag;
	char			letter;
	char			*word;
}					t_app_opts;

typedef struct		s_entry
{
	char			*name;
	struct stat		*data;
	t_bool			isdir;
}					t_entry;

t_opt				handle_params(char **params, t_dblist **dirs);
void				handle_files_in_param(t_opt options, t_dblist *files);
void				register_param_data(char *name, t_dblist **files, struct stat buf);

void				ft_ls(t_opt options, t_dblist *dirs);

void				sort_timestamp(t_dblist *list);
void				sort_ascii(t_dblist *list);
void				print_data(t_dblist *dirs, t_opt options, t_dblist *data);
void				free_data(t_dblist *list);

#endif

/*
main.c :
main

parse_parameters.c :
static get_app_opts
static parse_long_opt
static parse_short_opt
static parse_entry
handle_params

handle_files_in_param.c :
register_param_data
handle_files_in_param

sort.c :
sort_timestamp
sort_ascii

print_data.c :
static print_long_reverse
static print_long
static print_reverse
static print_default
print_data

ft_ls.c :
static register_struct_stat
static get_dir_content
ft_ls

free_data.c :
free_data
*/
