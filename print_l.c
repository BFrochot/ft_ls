/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:07:39 by bfrochot          #+#    #+#             */
/*   Updated: 2017/01/21 19:36:11 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_c(t_file *lst, t_truc *parse)
{
	char *time;

	time = conv_time(lst->date, parse);
	while ((lst->major / 256) > 0)
		lst->major = lst->major / 256;
	lst->acces[11] = 0;
	ft_printf("%s %s %s  %s  %2d, %3d%s %s%s%s\n", lst->acces,
		lst->nbfconv, lst->owner,
		lst->group, lst->major, lst->minor, time, ft_color(lst, 1),
		lst->name, ft_color(lst, 0));
	free(time);
}

void	print_l_too_long(t_truc *parse, t_file *lst)
{
	char *time;

	if ((lst->name[0] != '.' || parse->flag_a == 1) && lst->type != 'c')
	{
		if (lst->type == 'l')
			linkatt(lst);
		time = conv_time(lst->date, parse);
		lst->acces[11] = 0;
		ft_printf("%s %s %s  %s  %s%s %s%s%s\n", lst->acces,
			lst->nbfconv, lst->owner,
			lst->group, lst->sizeconv, time, ft_color(lst, 1),
			lst->name, ft_color(lst, 0));
		free(time);
	}
	else if (lst->type == 'c')
		print_c(lst, parse);
}

void	lst_l_prepare(t_file *lst, t_truc *parse, int bool)
{
	lst = group_l(lst, parse);
	lst = owner_l(lst, parse);
	lst = nbf_l(lst, parse);
	lst = size_l(lst, parse);
	if (bool && (ft_listlen(lst) > 2 || parse->flag_a == 1))
		ft_prtot(lst, parse);
}

void	print_l(t_file *lst, t_truc *parse)
{
	if (lst->group)
		lst_l_prepare(lst, parse, 1);
	while (lst->next)
	{
		if (lst->owner == NULL &&
			(lst->name[0] != '.' || parse->flag_a == 1))
			ft_printf("ft_ls: %s: You shall not pass !\n", lst->name);
		else if (lst->owner)
			print_l_too_long(parse, lst);
		lst = lst->next;
	}
	if (lst->owner == NULL &&
		(lst->name[0] != '.' || parse->flag_a == 1))
		ft_printf("ft_ls: %s: You shall not pass !\n", lst->name);
	else if (lst->owner)
		print_l_too_long(parse, lst);
}
