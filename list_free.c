/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:06:54 by bfrochot          #+#    #+#             */
/*   Updated: 2017/01/21 19:35:56 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	list_free_inner(t_file *lst)
{
	if (lst->acces)
		free(lst->acces);
	if (lst->nbfconv)
		free(lst->nbfconv);
	if (lst->owner)
		free(lst->owner);
	if (lst->sizeconv)
		free(lst->sizeconv);
	if (lst->name)
		free(lst->name);
	if (lst->path)
		free(lst->path);
	if (lst->group)
		free(lst->group);
}

void	list_free_down(t_file *lst)
{
	t_file *tmp;

	while (lst != NULL)
	{
		list_free_inner(lst);
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
}

void	list_free_up(t_file *lst)
{
	t_file *tmp;

	while (lst != NULL)
	{
		list_free_inner(lst);
		tmp = lst;
		lst = lst->prev;
		free(tmp);
		tmp = NULL;
	}
}

void	list_free(t_file *lst)
{
	if (lst == NULL)
		return ;
	if (lst->next)
		list_free_down(lst);
	else if (lst->prev)
		list_free_up(lst);
}
