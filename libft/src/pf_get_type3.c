/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_type3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:49:29 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/14 18:50:37 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				treat_long_long(t_prf *env, char **result)
{
	long long		to_format;

	to_format = va_arg(env->args, long long);
	*result = ft_itoa(to_format);
}

void				treat_ulong_long(t_prf *env, char **result)
{
	unsigned long long	to_format;

	to_format = va_arg(env->args, unsigned long long);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}

void				treat_intmax_t(t_prf *env, char **result)
{
	intmax_t		to_format;

	to_format = va_arg(env->args, intmax_t);
	*result = ft_itoa(to_format);
}

void				treat_uintmax_t(t_prf *env, char **result)
{
	uintmax_t		to_format;

	to_format = va_arg(env->args, uintmax_t);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}

void				treat_size_t(t_prf *env, char **result)
{
	size_t			to_format;

	to_format = va_arg(env->args, size_t);
	*result = ft_itoa_base(to_format, env->cur_specs->base);
}
