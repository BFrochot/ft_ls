/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:23:52 by bfrochot          #+#    #+#             */
/*   Updated: 2017/01/21 19:37:13 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*timef2(char *timec)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = malloc(14)))
		ft_err(-10, 0, NULL);
	tmp[0] = ' ';
	tmp[1] = timec[1];
	tmp[2] = timec[2];
	tmp[3] = timec[3];
	tmp[4] = ' ';
	tmp[5] = timec[8];
	tmp[6] = timec[9];
	tmp[7] = ' ';
	tmp[8] = ' ';
	tmp[9] = timec[17];
	tmp[10] = timec[18];
	tmp[11] = timec[19];
	tmp[12] = timec[20];
	tmp[13] = '\0';
	return (tmp);
}

int		ft_max_size(t_file *lst, int i)
{
	char *str;

	str = ft_itoa(lst->size);
	if ((int)ft_strlen(str) > i)
		i = ft_strlen(str);
	free(str);
	return (i);
}

int		ft_max_nbf(t_file *lst, int i)
{
	char *str;

	str = ft_itoa(lst->nbf);
	if ((int)ft_strlen(str) > i)
		i = ft_strlen(str);
	free(str);
	return (i);
}

t_file	*size_l(t_file *lst, t_truc *parse)
{
	t_file	*sav;
	int		i;
	char	*str;

	i = 0;
	sav = lst;
	while (lst)
	{
		if (parse->flag_a == 1 || lst->name[0] != '.')
			i = ft_max_size(lst, i);
		lst = lst->next;
	}
	lst = sav;
	while (lst)
	{
		if (!(str = malloc(i + 1)))
			ft_err(-10, 0, parse);
		ft_memset(str, ' ', i);
		str[i] = '\0';
		ft_cpdsize(lst, &str);
		lst = lst->next;
	}
	return (sav);
}

t_file	*nbf_l(t_file *lst, t_truc *parse)
{
	t_file	*sav;
	int		i;
	char	*str;

	i = 0;
	sav = lst;
	while (lst)
	{
		if (parse->flag_a == 1 || lst->name[0] != '.')
			i = ft_max_nbf(lst, i);
		lst = lst->next;
	}
	lst = sav;
	while (lst)
	{
		if (!(str = malloc(i + 1)))
			ft_err(-10, 0, parse);
		ft_memset(str, ' ', i);
		str[i] = '\0';
		ft_cpdnbf(lst, &str);
		lst = lst->next;
	}
	return (sav);
}
