/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_print_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 12:05:49 by sbrochar          #+#    #+#             */
/*   Updated: 2017/06/29 12:24:37 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char				*get_permissions(struct stat *data)
{
	char			*ret;

	ret = (char *)ft_memalloc(sizeof(char) * 11);
	ret[0] = S_ISDIR(data->st_mode) ? 'd' : '-';
	ret[1] = data->st_mode & S_IRUSR ? 'r' : '-';
	ret[2] = data->st_mode & S_IWUSR ? 'w' : '-';
	ret[3] = data->st_mode & S_IXUSR ? 'x' : '-';
	ret[4] = data->st_mode & S_IRGRP ? 'r' : '-';
	ret[5] = data->st_mode & S_IWGRP ? 'w' : '-';
	ret[6] = data->st_mode & S_IXGRP ? 'x' : '-';
	ret[7] = data->st_mode & S_IROTH ? 'r' : '-';
	ret[8] = data->st_mode & S_IWOTH ? 'w' : '-';
	ret[9] = data->st_mode & S_IXOTH ? 'x' : '-';
	return (ret);
}
