/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 12:05:49 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/23 09:47:25 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			print_usr_and_grp(size_t *col_width, struct stat *data)
{
	struct passwd	*data_usr;
	struct group	*data_grp;

	data_usr = getpwuid(data->st_uid);
	data_grp = getgrgid(data->st_gid);
	if (data_usr)
		ft_printf("%-*s ", col_width[1], data_usr->pw_name);
	else
		ft_printf("%-*d ", col_width[1], data->st_uid);
	if (data_grp)
		ft_printf("%-*s", col_width[2], data_grp->gr_name);
	else
		ft_printf("%-*d ", col_width[2], data->st_gid);
}

static void			print_time(struct stat *data)
{
	char			*tmp;
	char			*year;

	if ((time(NULL) - data->st_mtime) >= (525600 * 60 / 2))
	{
		tmp = ft_strsub(ctime(&(data->st_mtime)), 4, 7);
		year = ft_strsub(ctime(&(data->st_mtime)), 19, 5);
		ft_printf("%s%s ", tmp, year);
		ft_strdel(&year);
	}
	else
	{
		tmp = ft_strsub(ctime(&(data->st_mtime)), 4, 12);
		ft_printf("%s ", tmp);
	}
	ft_strdel(&tmp);
}

void				print_long(char *path, size_t *col_width, t_node *entry)
{
	char			*tmp;

	tmp = get_permissions(path, ((t_entry *)entry->content)->data);
	ft_printf("%s", tmp);
	ft_strdel(&tmp);
	ft_printf("%*d ", col_width[0], ((t_entry*)entry->content)->data->st_nlink);
	print_usr_and_grp(col_width, ((t_entry *)entry->content)->data);
	if (((((t_entry *)entry->content)->data->st_mode & S_IFMT) == S_IFCHR)
		|| ((((t_entry *)entry->content)->data->st_mode & S_IFMT) == S_IFBLK))
		ft_printf("%*d, %*d ", col_width[3],
			major(((t_entry *)entry->content)->data->st_rdev), col_width[4],
			minor(((t_entry *)entry->content)->data->st_rdev));
	else
		ft_printf("%*d ", col_width[3],
		((t_entry *)entry->content)->data->st_size);
	print_time(((t_entry *)entry->content)->data);
	ft_printf("%s", ((t_entry *)entry->content)->name);
	if ((((t_entry *)entry->content)->data->st_mode & S_IFMT) == S_IFLNK)
	{
		tmp = ft_strnew(BUFF_SIZE);
		if (readlink(path, tmp, BUFF_SIZE) != -1)
			ft_printf(" -> %s", tmp);
		ft_strdel(&tmp);
	}
	ft_printf("\n");
}

int					get_total(t_dblist *data)
{
	int				total;
	t_node			*cur;

	total = 0;
	cur = data->start;
	while (cur)
	{
		total += ((t_entry *)cur->content)->data->st_blocks;
		cur = cur->next;
	}
	return (total);
}
