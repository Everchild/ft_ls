/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:30:37 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/14 14:35:17 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define CHECK_SPACE(x) (x == ' ' || x == '\n' || x == '\t')
#define CHECK_BLANKS(x) (x == '\v' || x == '\f' || x == '\r')

static size_t		count_len(char const *s, size_t *start)
{
	size_t			i;
	size_t			end;
	size_t			size;

	i = ft_strlen(s) - 1;
	end = 0;
	size = ft_strlen(s);
	while (s && s[*start] &&
			(CHECK_SPACE(s[*start]) || CHECK_BLANKS(s[*start])))
		*start += 1;
	while (s && s[i] && CHECK_SPACE(s[i]))
	{
		i -= 1;
		end += 1;
	}
	if ((*start + end) >= size)
		return (0);
	else
		return (size - *start - end);
}

char				*ft_strtrim(char const *s)
{
	size_t			len;
	size_t			start;
	char			*ret;

	if (s)
	{
		start = 0;
		len = count_len(s, &start);
		ret = (char *)ft_memalloc(sizeof(char) * (len + 1));
		if (ret)
		{
			ret = ft_strncpy(ret, &s[start], len);
			return (ret);
		}
		return (NULL);
	}
	return (NULL);
}
