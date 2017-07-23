/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_col_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 11:06:17 by sbrochar          #+#    #+#             */
/*   Updated: 2017/07/23 11:57:06 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			idecanymore(size_t **ret, struct stat *data)
{
	size_t			tmp;

	tmp = ft_strlen(ft_itoa(data->st_nlink)) + 1;
	(*ret)[0] = tmp > (*ret)[0] ? tmp : (*ret)[0];
	if (getpwuid(data->st_uid))
		tmp = ft_strlen((getpwuid(data->st_uid))->pw_name) + 1;
	else
		tmp = ft_strlen(ft_itoa(data->st_uid));
	(*ret)[1] = tmp > (*ret)[1] ? tmp : (*ret)[1];
	if (getpwuid(data->st_uid))
		tmp = ft_strlen((getgrgid(data->st_gid))->gr_name) + 1;
	else
		tmp = ft_strlen(ft_itoa(data->st_gid));
	(*ret)[2] = tmp > (*ret)[2] ? tmp : (*ret)[2];
	if ((data->st_mode & S_IFMT) == S_IFCHR)
	{
		tmp = ft_strlen(ft_itoa(minor(data->st_rdev)));
		(*ret)[4] = tmp > (*ret)[4] ? tmp : (*ret)[4];
		tmp = ft_strlen(ft_itoa(major(data->st_rdev)));
	}
	else
		tmp = ft_strlen(ft_itoa(data->st_size)) + 1;
	(*ret)[3] = tmp > (*ret)[3] ? tmp : (*ret)[3];
}

size_t				*min_col_width(t_dblist *data)
{
	size_t			*ret;
	t_node			*cur;

	ret = (size_t *)ft_memalloc(sizeof(size_t) * 5);
	ret[0] = 2;
	ret[1] = 5;
	ret[2] = 5;
	ret[3] = 2;
	ret[4] = 2;
	cur = data->start;
	while (cur)
	{
		idecanymore(&ret, ((t_entry *)cur->content)->data);
		cur = cur->next;
	}
	return (ret);
}
