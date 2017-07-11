/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_print_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 12:05:49 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/11 08:47:54 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

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

char				*get_permissions(struct stat *data)
{
	char			*ret;

	ret = ft_strdup("----------");
	if (S_ISDIR(data->st_mode))
		ret[0] = 'd';
	else if ((S_IFMT & data->st_mode) == S_IFLNK)
		ret[0] = 'l';
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
