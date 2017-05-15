/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:37:33 by sbrochar          #+#    #+#             */
/*   Updated: 2016/04/12 19:37:34 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t		count_words(char const *s, char c)
{
	size_t			ret;
	size_t			i;

	ret = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] == c)
			i += 1;
		if (s[i])
			ret += 1;
		while (s[i] && s[i] != c)
			i += 1;
	}
	return (ret);
}

static size_t		substrlen(char const *s, char c, size_t start)
{
	size_t			i;

	i = 0;
	while (s && s[start] && s[start] != c)
	{
		start += 1;
		i += 1;
	}
	return (i);
}

static void			init_tab(char **tab, char const *s, char c, size_t lentab)
{
	size_t			i;
	size_t			len;
	size_t			start;

	i = 0;
	start = 0;
	while (tab && i < lentab)
	{
		while (s && s[start] && s[start] == c)
			start += 1;
		len = substrlen(s, c, start);
		tab[i] = (char *)ft_memalloc(sizeof(char) * (len + 1));
		tab[i] = ft_strncpy(tab[i], s + start, len);
		start += len;
		i += 1;
	}
}

char				**ft_strsplit(char const *s, char c)
{
	char			**ret;
	size_t			nb_words;

	if (s)
	{
		nb_words = count_words(s, c);
		ret = (char **)ft_memalloc(sizeof(char *) * (nb_words + 1));
		if (ret)
		{
			ret[nb_words] = NULL;
			init_tab(ret, s, c, nb_words);
			return (ret);
		}
	}
	return (NULL);
}
