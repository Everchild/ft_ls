/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_type1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:05:37 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/15 16:24:28 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void				treat_percent(t_prf *env, char **result)
{
	(void)env;
	*result = (char *)ft_memalloc(sizeof(char) * 2);
	*(result[0]) = '%';
}

void				treat_char(t_prf *env, char **result)
{
	char			to_format;

	if (env->cur_specs->format == 'c')
	{
		to_format = va_arg(env->args, int);
		*result = (char *)ft_memalloc(sizeof(char) * 2);
		*(result[0]) = to_format;
		if (!to_format)
		{
			env->null_char = TRUE;
			env->len_result++;
		}
	}
	else
	{
		to_format = va_arg(env->args, int);
		*result = ft_itoa(to_format);
	}
}

void				treat_charp(t_prf *env, char **result)
{
	char			*to_format;

	to_format = va_arg(env->args, char *);
	if (to_format)
		*result = ft_strdup(to_format);
	else
		*result = ft_strdup("(null)");
}

void				treat_wchar(t_prf *env, char **result)
{
	wchar_t			to_format;

	to_format = va_arg(env->args, wchar_t);
	*result = ft_wctombc(to_format);
	if (!to_format)
	{
		env->null_char = TRUE;
		env->len_result++;
	}
}

void				treat_wcharp(t_prf *env, char **result)
{
	wchar_t			*to_format;
	char			*tmp;

	to_format = va_arg(env->args, wchar_t *);
	if (!to_format)
		*result = ft_strdup("(null)");
	else
	{
		*result = ft_strnew(ft_wstrlen(to_format));
		while (to_format && *to_format)
		{
			tmp = ft_wctombc(*to_format);
			*result = ft_strcat(*result, tmp);
			ft_strdel(&tmp);
			to_format++;
		}
	}
}
