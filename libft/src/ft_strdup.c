/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:45:43 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:59:09 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strdup(const char *s)
{
	char			*ret;

	ret = NULL;
	ret = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	ret = ft_strcpy(ret, s);
	return (ret);
}
