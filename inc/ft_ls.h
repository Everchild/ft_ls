/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:10:50 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/25 17:53:02 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
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

typedef struct		s_args
{
	t_opt			flag;
	char			letter;
	char			*word;
}					t_args;

typedef struct		s_entry
{
	char			*name;
	struct stat		*data;
	t_dblist		*content; // init seulement si l'entree est un dossier
}					t_entry;

typedef struct		s_env
{
	t_opt			options;
	t_dblist		*files; // struct t_entry -> uniquement des fichiers (parametres)
	// à imprimer dès après le parsing des params
	//à clear juste après
	t_dblist		*dirs; // contient les dossiers en parametre / si pas de param, 1 seul noeud egal a "."
//	DIR				*cur_dir;
}					t_env;

void				parse_arg(t_env *env, char **arg);

#endif
