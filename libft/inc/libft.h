/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:42:35 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/15 16:18:32 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <inttypes.h>
# include <wchar.h>

void				buff_handler(char **buff, int action, char *s);

# define BUFF_SIZE 1024
# define FLUSH 1
# define FILL 2

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

/*
** libprint
*/

# define PRF_LEN_MAX_CONV 3
# define ALL_FORMATS "sSpdDioOuUxXcC%"
# define ALL_MODIFIERS "hljz"

typedef enum		e_format
{
	F_PERCENT,
	F_STRING,
	F_WSTRING,
	F_PTR,
	F_DIGIT,
	F_OCTAL,
	F_UDIGIT,
	F_HEXA,
	F_CHAR,
	F_WCHAR,
	F_COUNT
}					t_format;

typedef enum		e_all_conv
{
	C_PERCENT,
	C_CHAR,
	C_CHARP,
	C_UCHAR,
	C_WCHAR,
	C_WCHARP,
	C_PTR,
	C_SHORT,
	C_USHORT,
	C_INT,
	C_UINT,
	C_LONG,
	C_ULONG,
	C_LONG_LONG,
	C_ULONG_LONG,
	C_INTMAX_T,
	C_UINTMAX_T,
	C_SIZE_T,
	C_COUNT
}					t_all_conv;

typedef enum		e_flag
{
	NO_FLAG = 0,
	HASHTAG = 1 << 1,
	ZERO = 1 << 2,
	MINUS = 1 << 3,
	PLUS = 1 << 4,
	SPACE = 1 << 5
}					t_flag;

typedef struct		s_specs
{
	t_flag			flags;
	int				field_width;
	int				precision;
	char			conversion[PRF_LEN_MAX_CONV + 1];
	char			format;
	char			*result;
	unsigned char	base;
}					t_specs;

typedef struct		s_prf
{
	const char		*format;
	size_t			index;
	va_list			args;
	char			*buff;
	size_t			len_result;
	t_bool			null_char;
	t_bool			unifail;
	t_specs			*cur_specs;
}					t_prf;

typedef struct		s_options
{
	t_format		format;
	char			*formats;
	void			(*apply_opt)(t_prf *, t_specs *, char **);
}					t_options;

typedef struct		s_conversion
{
	t_all_conv		conv;
	char			*conv_list;
	void			(*treat_type)(t_prf *, char **);
}					t_conversion;

int					ft_printf(const char *format, ...);
void				get_flag(t_prf *env, t_specs *specs);
void				get_field_width(t_prf *env, t_specs *specs);
void				get_precision(t_prf *env, t_specs *specs);
void				get_conversion(t_prf *env, t_specs *specs);
void				formating_string(t_prf *env);
t_bool				convert_specs(t_prf *env);
void				apply_precision(t_specs *specs, char **result);
void				apply_opt(t_prf *env);
void				treat_percent(t_prf *env, char **result);
void				treat_char(t_prf *env, char **result);
void				treat_charp(t_prf *env, char **result);
void				treat_uchar(t_prf *env, char **result);
void				treat_wchar(t_prf *env, char **result);
void				treat_wcharp(t_prf *env, char **result);
void				treat_ptr(t_prf *env, char **result);
void				treat_short(t_prf *env, char **result);
void				treat_ushort(t_prf *env, char **result);
void				treat_int(t_prf *env, char **result);
void				treat_uint(t_prf *env, char **result);
void				treat_long(t_prf *env, char **result);
void				treat_ulong(t_prf *env, char **result);
void				treat_long_long(t_prf *env, char **result);
void				treat_ulong_long(t_prf *env, char **result);
void				treat_intmax_t(t_prf *env, char **result);
void				treat_uintmax_t(t_prf *env, char **result);
void				treat_size_t(t_prf *env, char **result);
void				opt_on_percent(t_prf *env, t_specs *specs, char **result);
void				opt_on_string(t_prf *env, t_specs *specs, char **result);
void				opt_on_wstring(t_prf *env, t_specs *specs, char **result);
void				opt_on_ptr(t_prf *env, t_specs *specs, char **result);
void				opt_on_digit(t_prf *env, t_specs *specs, char **result);
void				opt_on_octal(t_prf *env, t_specs *specs, char **result);
void				opt_on_udigit(t_prf *env, t_specs *specs, char **result);
void				opt_on_hexa(t_prf *env, t_specs *specs, char **result);
void				opt_on_char(t_prf *env, t_specs *specs, char **result);
void				opt_on_wchar(t_prf *env, t_specs *specs, char **result);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** liblist
*/

typedef struct		s_node
{
	void			*content;
	size_t			size;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_dblist
{
	t_node			*start;
	t_node			*end;
	size_t			nb_nodes;
}					t_dblist;

t_dblist			*create_list(void);
t_node				*create_node(void *content, size_t size);
t_node				*add_node_end(t_dblist **list, t_node *node);
t_node				*add_node_start(t_dblist **list, t_node *node);
void				swap_nodes(t_dblist **list, t_node **n1, t_node **n2);
void				remove_node(t_dblist **list, t_node *node);
void				free_list(t_dblist **list);
t_node				*iter_list(t_dblist **list, int (*f)(t_node *));

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** libmem
*/

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memdup(const void *s, size_t n);
void				*ft_realloc(void *ptr, size_t size);

/*
** libstr
*/

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_strpos(char *s, char c);
int					ft_strnpos(char *s, char c, size_t n);
char				*ft_strcjoin(char const *s1, char const *s2, char c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
void				ft_strrev(char **s);
char				*ft_itoa_base(unsigned long long n, unsigned char base);
void				ft_strupper(char **s);
char				*ft_strjoinf(char *s1, char *s2, int which);
char				*ft_wctombc(wchar_t c);
size_t				ft_wstrlen(const wchar_t *s);

/*
** libtab
*/

char				**ft_tabdup(const char **tab);

/*
** libmath
*/

unsigned long long	ft_abs(long long n);
long int			ft_pow(int n, int pow);

/*
** others
*/

void				ft_exit(char *str, int status);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** gnl
*/

# define GNL_FIRST_CALL -3
# define GNL_BUF_HAS_DATA -2
# define GNL_READ_ERROR -1
# define GNL_END_OF_FILE 0
# define GNL_BUF_HAS_LINE 1

int					get_next_line(const int fd, char **line);

typedef struct		s_gnl
{
	int				fd;
	size_t			size;
	int				ret;
}					t_gnl;

#endif
