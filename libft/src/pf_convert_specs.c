/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_specs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 13:42:36 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/14 19:49:04 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_options	*get_all_formats(void)
{
	static t_options	ret[F_COUNT] = {
	{ F_PERCENT, "%", &opt_on_percent },
	{ F_STRING, "s", &opt_on_string },
	{ F_WSTRING, "S", &opt_on_wstring },
	{ F_PTR, "p", &opt_on_ptr },
	{ F_DIGIT, "dDi", &opt_on_digit },
	{ F_OCTAL, "oO", &opt_on_octal },
	{ F_UDIGIT, "uU", &opt_on_udigit },
	{ F_HEXA, "xX", &opt_on_hexa },
	{ F_CHAR, "c", &opt_on_char },
	{ F_WCHAR, "C", &opt_on_wchar }
	};

	return (ret);
}

static t_conversion	*get_all_funcs(void)
{
	static t_conversion	ret[C_COUNT] = {
	{ C_PERCENT, "%", &treat_percent },
	{ C_CHAR, "chhdhhi", &treat_char },
	{ C_CHARP, "s", &treat_charp },
	{ C_UCHAR, "hhuhhohhxhhX", &treat_uchar },
	{ C_WCHAR, "lcChChhCllCjCzC", &treat_wchar },
	{ C_WCHARP, "lsShShhSllSjSzS", &treat_wcharp },
	{ C_PTR, "phhphplpllpjpzp", &treat_ptr },
	{ C_SHORT, "hdhi", &treat_short },
	{ C_USHORT, "huhohxhX", &treat_ushort },
	{ C_INT, "di", &treat_int },
	{ C_UINT, "ouxX", &treat_uint },
	{ C_LONG, "ldliDhDhhDlDllDjDzD", &treat_long },
	{ C_ULONG, "luUloOlxlXihUhhUlUllUjUzUhOhhOlOllOjOzO", &treat_ulong },
	{ C_LONG_LONG, "lldlli", &treat_long_long },
	{ C_ULONG_LONG, "llullollxllX", &treat_ulong_long },
	{ C_INTMAX_T, "zdzijdji", &treat_intmax_t },
	{ C_UINTMAX_T, "jujojxjX", &treat_uintmax_t },
	{ C_SIZE_T, "zdzizuzozxzX", &treat_size_t }
	};

	return (ret);
}

static t_bool		find_type(t_prf *env, t_conversion *f)
{
	int				i;
	char			*ptr;

	ptr = NULL;
	i = 0;
	while (i < C_COUNT)
	{
		if ((ptr = ft_strstr(f[i].conv_list, env->cur_specs->conversion)))
		{
			if (!(ptr - 1 && (*(ptr - 1) == 'h' || *(ptr - 1) == 'l'
				|| *(ptr - 1) == 'j' || *(ptr - 1) == 'z')))
			{
				f[i].treat_type(env, &env->cur_specs->result);
				break ;
			}
		}
		i++;
	}
	if (ptr)
		return (TRUE);
	return (FALSE);
}

t_bool				convert_specs(t_prf *env)
{
	t_conversion	*all_formats;

	all_formats = get_all_funcs();
	if (!*(env->cur_specs->conversion))
		return (FALSE);
	else
		return (find_type(env, all_formats));
}

void				apply_opt(t_prf *env)
{
	t_options		*options;
	int				i;

	options = get_all_formats();
	i = 0;
	while (i < F_COUNT)
	{
		if (ft_strchr(options[i].formats, env->cur_specs->format))
		{
			options[i].apply_opt(env, env->cur_specs, &env->cur_specs->result);
			break ;
		}
		i++;
	}
}
