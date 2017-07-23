/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_permissions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 08:34:09 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/23 09:29:14 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			get_type_of_file(char **perms, struct stat *data)
{
	if (S_ISDIR(data->st_mode))
		(*perms)[0] = 'd';
	else if ((S_IFMT & data->st_mode) == S_IFLNK)
		(*perms)[0] = 'l';
	else if ((S_IFMT & data->st_mode) == S_IFIFO)
		(*perms)[0] = 'p';
	else if ((S_IFMT & data->st_mode) == S_IFBLK)
		(*perms)[0] = 'b';
	else if ((S_IFMT & data->st_mode) == S_IFCHR)
		(*perms)[0] = 'c';
	else if ((S_IFMT & data->st_mode) == S_IFSOCK)
		(*perms)[0] = 's';
}

static void			get_usr_perms(char **perms, struct stat *data)
{
	(*perms)[1] = data->st_mode & S_IRUSR ? 'r' : (*perms)[1];
	(*perms)[2] = data->st_mode & S_IWUSR ? 'w' : (*perms)[2];
	if ((data->st_mode & S_ISUID) && !(data->st_mode & S_IXUSR))
		(*perms)[3] = 'S';
	else if (data->st_mode & S_ISUID)
		(*perms)[3] = 's';
	else if (data->st_mode & S_IXUSR)
		(*perms)[3] = 'x';
}

static void			get_grp_perms(char **perms, struct stat *data)
{
	(*perms)[4] = data->st_mode & S_IRGRP ? 'r' : (*perms)[4];
	(*perms)[5] = data->st_mode & S_IWGRP ? 'w' : (*perms)[5];
	if ((data->st_mode & S_ISGID) && !(data->st_mode & S_IXGRP))
		(*perms)[6] = 'S';
	else if (data->st_mode & S_ISGID)
		(*perms)[6] = 's';
	else if (data->st_mode & S_IXGRP)
		(*perms)[6] = 'x';
}

static void			get_oth_perms(char **perms, struct stat *data)
{
	(*perms)[7] = data->st_mode & S_IROTH ? 'r' : (*perms)[7];
	(*perms)[8] = data->st_mode & S_IWOTH ? 'w' : (*perms)[8];
	if (data->st_mode & S_ISVTX && !(data->st_mode & S_IXOTH))
		(*perms)[9] = 'T';
	else if (data->st_mode & S_ISVTX)
		(*perms)[9] = 't';
	else if (data->st_mode & S_IXOTH)
		(*perms)[9] = 'x';
}

char				*get_permissions(char *path, struct stat *data)
{
	char			*ret;
	acl_t			acl;
	acl_entry_t		buf;

	ret = ft_strdup("---------- ");
	get_type_of_file(&ret, data);
	get_usr_perms(&ret, data);
	get_grp_perms(&ret, data);
	get_oth_perms(&ret, data);
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &buf) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	ret[10] = acl ? '+' : ret[10];
	ret[10] = listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0 ? '@' : ret[10];
	return (ret);
}
