/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:06:25 by bfrochot          #+#    #+#             */
/*   Updated: 2017/01/21 19:35:52 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		ft_listlen(t_file *lst)
{
	int i;

	i = 1;
	while (lst->next)
		lst = lst->next;
	while (lst->prev && ++i)
		lst = lst->prev;
	return (i);
}

void	ft_revlist(t_file *lst)
{
	t_file	*tmp;
	int		i;

	while (lst->next)
		lst = lst->next;
	i = ft_listlen(lst);
	while (i > 0)
	{
		tmp = lst->next;
		lst->next = lst->prev;
		lst->prev = tmp;
		lst = lst->next;
		--i;
	}
}

void	ft_lstsort(t_truc *parse, t_file *lst, int i)
{
	int u;

	u = 0;
	if (parse->flag_t == 0)
		while (u != (i - 1))
		{
			lst = ft_sortbase1(lst);
			u = ft_sortbase2(lst, 0);
		}
	if (parse->flag_t == 1)
		while (u != (i - 1))
		{
			lst = ft_sortt1(lst);
			u = ft_sortt2(lst, 0);
		}
	if (parse->flag_r == 1)
		ft_revlist(lst);
}
