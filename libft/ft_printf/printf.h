/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:33:25 by bfrochot          #+#    #+#             */
/*   Updated: 2016/12/09 20:33:26 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "../libft.h"

typedef int	(*t_fun)(va_list a, int b, char c, char **d);

void		ft_error(void);
t_fun		*ft_type(void);
int			ft_fuckit(char c);
int			ft_isokay(char c);
int			conv(int nb, char *net);
int			ft_printf(const char *str, ...);
void		ft_apliopt(char *res, char *str);
int			ft_prec(int i, int k, char c, char **str);
int			ft_moncul(char *opt, char **str, int i);
int			ft_opts(char *opt, char **str, int i);
int			ft_print(char *str, int k, int u);
void		ft_memlcat(char *dst, const char *src, int start, int end);
char		*ft_itoa_base(uintmax_t value, int base, char neg);
int			ft_atoi_base_printf(const char *str, int str_base, int i);
int			ft_s(va_list ap, int k, char c, char **str);
int			ft_p(va_list ap, int k, char c, char **str);
int			ft_d(va_list ap, int k, char c, char **str);
int			ft_i(va_list ap, int k, char c, char **str);
int			ft_o(va_list ap, int k, char c, char **str);
int			ft_u(va_list ap, int k, char c, char **str);
int			ft_x(va_list ap, int k, char c, char **str);
int			ft_c(va_list ap, int k, char c, char **str);
int			ft_israndom(va_list ap, int i, char c, char **str);
int			ft_hastag(int k, int i, int boul, char **str);
int			ft_number(int k, int i, int boul, char **str);
int			ft_minus(int k, int i, int boul, char **str);
int			ft_plus(int k, int i, int boul, char **str);

#endif
