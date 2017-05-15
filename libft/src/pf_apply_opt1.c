/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_opt1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:32:03 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/14 19:37:36 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void			zero_on_digit(t_specs *specs, char **orig_s, char **result)
{
	if (specs->flags & ZERO && ((*orig_s = ft_strchr(*result, '+')) != 0)
			&& *result != *orig_s)
	{
		**orig_s = '0';
		**result = '+';
	}
	else if (specs->flags & ZERO && ((*orig_s = ft_strchr(*result, '-')) != 0)
			&& *result != *orig_s)
	{
		**orig_s = '0';
		**result = '-';
	}
	else if (specs->flags & ZERO && ((*orig_s = ft_strchr(*result, ' ')) != 0)
			&& *result != *orig_s && !(specs->flags & MINUS))
	{
		**orig_s = '0';
		**result = ' ';
	}
}

void				opt_on_digit(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;
	int				len;
	int				orig_len;

	if (specs->flags & PLUS && !ft_strchr(*orig_s, '-'))
		*orig_s = ft_strjoinf("+", *orig_s, 2);
	else if (specs->flags & SPACE && !ft_strchr(*orig_s, '-'))
		*orig_s = ft_strjoinf(" ", *orig_s, 2);
	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (specs->flags & ZERO && !(specs->flags & MINUS) && specs->precision < 0)
		ft_memset(result, '0', len);
	else
		ft_memset(result, ' ', len);
	if (specs->flags & MINUS)
		result = ft_strncpy(result, *orig_s, orig_len);
	else
		ft_strncpy(result + (len - orig_len), *orig_s, orig_len);
	ft_strdel(orig_s);
	zero_on_digit(specs, orig_s, &result);
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(&result);
}

static void			wesh_hexa(t_specs *specs, char **orig_s, char **result)
{
	int				len;
	int				orig_len;

	orig_len = ft_strlen(*orig_s);
	len = specs->field_width > orig_len ? specs->field_width : orig_len;
	*result = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (specs->flags & ZERO && !(specs->flags & MINUS) && specs->precision < 0)
		ft_memset(*result, '0', len);
	else
		ft_memset(*result, ' ', len);
	if (specs->flags & MINUS)
		*result = ft_strncpy(*result, *orig_s, orig_len);
	else
		ft_strncpy(*result + (len - orig_len), *orig_s, orig_len);
	if (specs->format == 'X')
		ft_strupper(result);
	ft_strdel(orig_s);
	if (specs->flags & ZERO && (*orig_s = ft_strchr(*result, 'x')) != 0)
	{
		**orig_s = '0';
		(*result)[1] = 'x';
	}
}

void				opt_on_hexa(t_prf *env, t_specs *specs, char **orig_s)
{
	char			*result;

	if (!ft_strcmp(*orig_s, "0") && specs->flags & HASHTAG)
		specs->flags &= ~HASHTAG;
	if (**orig_s && specs->flags & HASHTAG)
		*orig_s = ft_strjoinf("0x", *orig_s, 2);
	wesh_hexa(specs, orig_s, &result);
	buff_handler(&env->buff, FILL, result);
	env->len_result += ft_strlen(result);
	ft_strdel(&result);
}
