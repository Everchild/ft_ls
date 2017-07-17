/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_print_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 12:05:49 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/17 17:26:11 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char			*get_permissions(struct stat *data)
{
	char			*ret;

	ret = ft_strdup("---------- ");
	if (S_ISDIR(data->st_mode))
		ret[0] = 'd';
	else if ((S_IFMT & data->st_mode) == S_IFLNK)
		ret[0] = 'l';
	else if ((S_IFMT & data->st_mode) == S_IFIFO)
		ret[0] = 'p';
	else if ((S_IFMT & data->st_mode) == S_IFBLK)
		ret[0] = 'b';
	else if ((S_IFMT & data->st_mode) == S_IFCHR)
		ret[0] = 'c';
	else if ((S_IFMT & data->st_mode) == S_IFSOCK)
		ret[0] = 's';
	ret[1] = data->st_mode & S_IRUSR ? 'r' : ret[1];
	ret[2] = data->st_mode & S_IWUSR ? 'w' : ret[2];
	if ((data->st_mode & S_ISUID) && !(data->st_mode & S_IXUSR))
		ret[3] = 'S';
	else if (data->st_mode & S_ISUID)
		ret[3] = 's';
	else if (data->st_mode & S_IXUSR)
		ret[3] = 'x';
	ret[4] = data->st_mode & S_IRGRP ? 'r' : ret[4];
	ret[5] = data->st_mode & S_IWGRP ? 'w' : ret[5];
	if ((data->st_mode & S_ISGID) && !(data->st_mode & S_IXGRP))
		ret[6] = 'S';
	else if (data->st_mode & S_ISGID)
		ret[6] = 's';
	else if (data->st_mode & S_IXGRP)
		ret[6] = 'x';
	ret[7] = data->st_mode & S_IROTH ? 'r' : ret[7];
	ret[8] = data->st_mode & S_IWOTH ? 'w' : ret[8];
	if (data->st_mode & S_ISVTX && !(data->st_mode & S_IXOTH))
		ret[9] = 'T';
	else if (data->st_mode & S_ISVTX)
		ret[9] = 't';
	else if (data->st_mode & S_IXOTH)
		ret[9] = 'x';
	return (ret);
}

void				print_long(size_t *col_width, t_node *entry)
{
	struct passwd	*data_usr;
	struct group	*data_grp;
	char			*tmp;
	char			*year;

	data_usr = getpwuid(((t_entry *)entry->content)->data->st_uid);
	data_grp = getgrgid(((t_entry *)entry->content)->data->st_gid);
	tmp = get_permissions(((t_entry *)entry->content)->data);
	ft_printf("%s", tmp);
	ft_strdel(&tmp);
	ft_printf("%*d ", col_width[0], ((t_entry *)entry->content)->data->st_nlink);
	if (data_usr)
		ft_printf("%-*s ", col_width[1], data_usr->pw_name);
	else
		ft_printf("%-*d ", col_width[1], ((t_entry *)entry->content)->data->st_uid);
	if (data_grp)
		ft_printf("%-*s", col_width[2], data_grp->gr_name);
	else
		ft_printf("%-*d ", col_width[2], ((t_entry *)entry->content)->data->st_gid);
	if (( ((t_entry *)entry->content)->data->st_mode & S_IFMT) == S_IFCHR)
		ft_printf("%*d, %*d ", col_width[3], major(((t_entry *)entry->content)->data->st_rdev), col_width[4], minor(((t_entry *)entry->content)->data->st_rdev));
	else
		ft_printf("%*d ", col_width[3], ((t_entry *)entry->content)->data->st_size);
	if ((time(NULL) - ((t_entry *)entry->content)->data->st_mtime) >= 15552000)
	{
		tmp = ft_strsub(ctime(&(((t_entry *)entry->content)->data->st_mtime)), 4, 7);
		year = ft_strsub(ctime(&(((t_entry *)entry->content)->data->st_mtime)), 19, 5);
		ft_printf("%s%s ", tmp, year);
		ft_strdel(&year);
	}
	else
	{
		tmp = ft_strsub(ctime(&(((t_entry *)entry->content)->data->st_mtime)), 4, 12);
		ft_printf("%s ", tmp);
	}
	ft_strdel(&tmp);
	ft_printf("%s", ((t_entry *)entry->content)->name);
	if ((((t_entry *)entry->content)->data->st_mode & S_IFMT) == S_IFLNK)
	{
		tmp = ft_strnew(BUFF_SIZE);
		if (readlink(((t_entry *)entry->content)->name, tmp, BUFF_SIZE) != -1)
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
