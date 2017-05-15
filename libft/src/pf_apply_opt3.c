/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_opt3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 19:34:45 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/14 19:37:39 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				opt_on_percent(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	char			to_fill;

	to_fill = ' ';
	if (specs->field_width > 0)
	{
		result = (char *)ft_memalloc(sizeof(char) * (specs->field_width) + 1);
		if (specs->flags & ZERO)
			to_fill = '0';
		ft_memset(result, to_fill, specs->field_width);
		if (specs->flags & MINUS)
			result[0] = '%';
		else
			result[specs->field_width - 1] = '%';
	}
	else
		result = ft_strdup(*orig_s);
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(orig_s);
	ft_strdel(&result);
}

void				opt_on_ptr(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	size_t			len;
	int				orig_len;

	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	ft_memset(result, ' ', len);
	if (specs->flags & MINUS)
		result = ft_strncpy(result, *orig_s, orig_len);
	else
		ft_strncpy(result + (len - orig_len), *orig_s, orig_len);
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(orig_s);
	ft_strdel(&result);
}

void				opt_on_octal(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	size_t			len;
	int				orig_len;

	if (specs->flags & HASHTAG && **orig_s != '0')
		*orig_s = ft_strjoinf("0", *orig_s, 2);
	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (specs->flags & ZERO && !(specs->flags & MINUS))
		ft_memset(result, '0', len);
	else
		ft_memset(result, ' ', len);
	if (specs->flags & MINUS)
		result = ft_strncpy(result, *orig_s, orig_len);
	else
		ft_strncpy(result + (len - orig_len), *orig_s, orig_len);
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(orig_s);
	ft_strdel(&result);
}

void				opt_on_udigit(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	size_t			len;
	int				orig_len;

	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (specs->flags & ZERO && !(specs->flags & MINUS))
		ft_memset(result, '0', len);
	else
		ft_memset(result, ' ', len);
	if (specs->flags & MINUS)
		result = ft_strncpy(result, *orig_s, orig_len);
	else
		ft_strncpy(result + (len - orig_len), *orig_s, orig_len);
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(orig_s);
	ft_strdel(&result);
}
