/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:10:50 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/17 11:24:52 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <dirent.h>
# include <unistd.h>
# include <libft.h>

# define NB_OPT 6

typedef enum		e_opt
{
	NO_OPT = 0,
	O_INVAL = 1 << 1,
	O_RECURS = 1 << 2,
	O_ALL = 1 << 3,
	O_REVERSE = 1 << 4,
	O_TIME = 1 << 5,
	O_LONG = 1 << 6,
	O_DEFAULT = 1 << 7
}					t_opt;

typedef struct		s_app_opts
{
	t_opt			flag;
	char			letter;
	char			*word;
}					t_app_opts;

typedef enum		e_perms
{
	P_NONE = 0,
	P_READ = 1 << 1,
	P_EXEC = 1 << 2,
	P_FILE = 1 << 3
}					t_perms;

typedef struct		s_entry
{
	char			*name;
	struct stat		*data;
	t_bool			isdir;
	t_perms			perms;
}					t_entry;

t_app_opts			*get_app_opts(void);
t_opt				handle_params(char **params, t_dblist **dirs);
void				handle_files_in_param(t_opt options, t_dblist *files, t_bool dirs);
void				register_param_data(char *name, t_dblist **files, struct stat buf);

void				ft_ls(t_opt options, t_dblist *dirs);

void				sort_timestamp(t_dblist *list);
void				sort_ascii(t_dblist *list);
void				print_data(t_dblist *dirs, t_opt options, t_dblist *data, t_bool params);
void				print_long(size_t *col_width, t_node *entry);
int					get_total(t_dblist *data);
void				free_data(t_dblist *list);

#endif
