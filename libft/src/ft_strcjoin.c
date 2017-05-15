/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:31:17 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:31:18 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strcjoin(char const *s1, char const *s2, char c)
{
	char			*ret;

	if (s1 && s2)
	{
		ret = ft_strjoin(s1, &c);
		ret = ft_strjoin(ret, s2);
		return (ret);
	}
	return (NULL);
}
