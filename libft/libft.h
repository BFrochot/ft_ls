/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:57:23 by bfrochot          #+#    #+#             */
/*   Updated: 2017/01/06 17:25:38 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# define BUFF_SIZE 200

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *str);
void			ft_putnbr(int n);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char const *s, int fd);
int				ft_atoi(char *str);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *big, const char *little, size_t len);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnew(size_t size);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_itoa(int n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_bzero(void *s, size_t n);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *neww);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_is_prime(int nb);
int				ft_sqrt(int nb);
void			ft_printmemory(const void *addr, size_t size);
int				ft_recursive_power(int nb, int power);
int				ft_recursive_factorial(int nb);
int				get_next_line(const int fd, char **line);

typedef int		(*t_fun)(va_list a, int b, char c, char **d);

void			ft_error(void);
t_fun			*ft_type(void);
int				ft_fuckit(char c);
int				ft_isokay(char c);
int				conv(int nb, char *net);
int				ft_printf(const char *str, ...);
void			ft_apliopt(char *res, char *str);
int				ft_prec(int i, int k, char c, char **str);
int				ft_moncul(char *opt, char **str, int i);
int				ft_opts(char *opt, char **str, int i);
int				ft_print(char *str, int k, int u);
void			ft_memlcat(char *dst, const char *src, int start, int end);
char			*ft_itoa_base(uintmax_t value, int base, char neg);
int				ft_atoi_base_printf(const char *str, int str_base, int i);
int				ft_s(va_list ap, int k, char c, char **str);
int				ft_p(va_list ap, int k, char c, char **str);
int				ft_d(va_list ap, int k, char c, char **str);
int				ft_i(va_list ap, int k, char c, char **str);
int				ft_o(va_list ap, int k, char c, char **str);
int				ft_u(va_list ap, int k, char c, char **str);
int				ft_x(va_list ap, int k, char c, char **str);
int				ft_c(va_list ap, int k, char c, char **str);
int				ft_israndom(va_list ap, int i, char c, char **str);
int				ft_hastag(int k, int i, int boul, char **str);
int				ft_number(int k, int i, int boul, char **str);
int				ft_minus(int k, int i, int boul, char **str);
int				ft_plus(int k, int i, int boul, char **str);

#endif
