/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:44:33 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/10 17:00:45 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H
# define BUFF_SIZE 8

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_flags
{
	char	*flag;
	int		width;
	int		prec;
	int		size;
	int		type;
	int		percent;
	int		nul;
}					t_flags;
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_strlen(char const *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_atoi(char const *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *lit, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **ap);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_numpower(int number, int power);
char				*ft_allupper(char *str);
char				*ft_alllower(char *str);
char				*ft_unirot(char *str, size_t code);
char				**ft_sortmassiv(char **mass);
size_t				ft_lstsize(t_list *lst);
int					get_next_line(const int fd, char **line);
size_t				ft_printf(char *format, ...);
int					dec_to_octal(int n);
char				*dec_to_hex(int calue, int reg);
int					checker(char *format, int i, va_list ap, t_flags *flags);
void				get_output_string(t_flags *flags, va_list ap);
void				check_flag(char *format, int i, t_flags *flags);
void				check_width(char *format, int i, t_flags *flags);
void				check_precision(char *format, int i, t_flags *flags);
void				check_size(char *format, int i, t_flags *flags);
void				check_type(char *format, int i, t_flags *flags);
void				check_percent(char *format, int i, t_flags *flags);
void				ft_putstr_2(char const *s);
char				*ft_itoa_i(intmax_t n);
uintmax_t			ft_atoi_u(char const *s);
char				*convertor(uintmax_t n, int type);
char				*get_value_to_string(t_flags flags, va_list ap);
void				put_strings(char **result, t_flags flags);
char				*get_flags(t_flags flags, size_t n, char **str, int width);
char				*get_last_symbol(int i);
char				*get_prec(char *str, t_flags flags, int p);
char				*get_sign(char *str, t_flags flags);
char				*ft_itoa_u(uintmax_t n);
char				*get_spec(t_flags flags, char *str);
int					hex_or_oct(int type);
int					is_specifier(char c);
int					is_reading(char c);
char				*get_number(char *str, int start);
char				*str_type(t_flags flags, va_list ap);
char				*signed_type_int(t_flags flags, va_list ap);
char				*unsigned_type_with_size(t_flags flags, va_list ap);
char				*unsigned_type(t_flags flags, va_list ap);
char				*pointer(va_list ap);
void				ft_lstadd_end(t_list **alst, void *data,\
						size_t content_size);
int					ft_atoi_base(char *str, int str_base);
char				*ft_itoa_base(int value, int base);
long long int		ft_atoi_ll(const char *s);
void				ft_free_array(char **array);

#endif
