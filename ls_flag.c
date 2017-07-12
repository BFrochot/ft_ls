/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:12:51 by mleclair          #+#    #+#             */
/*   Updated: 2017/01/21 19:39:34 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	flag_r2(DIR *dir, char *pathname, t_truc *parse)
{
	closedir(dir);
	write(1, "\n", 1);
	ft_printf("%s:\n", pathname);
	flag_rr(parse, pathname);
}

void	flag_rr(t_truc *parse, char *path)
{
	char	*pathname;
	t_file	*lsd;
	t_file	*sav;
	DIR		*dir;

	lsd = NULL;
	ls_core(parse, path, &lsd);
	sav = lsd;
	while (lsd && lsd->name)
	{
		if ((lsd->name[0] != '.' || lsd->name[1] != 0) && (lsd->name[1] != '.'
			|| lsd->name[2] != 0) && (lsd->name[0] != '.' || parse->flag_a))
		{
			pathname = ft_pathname(path, lsd->name);
			if (lsd->type != 'l' && (dir = opendir(pathname)))
				flag_r2(dir, pathname, parse);
			else if (errno == 13)
				ft_printf("\n%s:\nft_ls: %s: Permission denied\n",
				pathname, lsd->name);
			free(pathname);
		}
		lsd = lsd->next;
	}
	list_free(sav);
}
