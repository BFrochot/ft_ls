/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:06:00 by bfrochot          #+#    #+#             */
/*   Updated: 2017/01/21 19:56:37 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_one_file2(t_file *lsd, struct stat *buf, char *path, char *pathnm)
{
	dev_t			toast;
	struct passwd	*test;

	test = getpwuid(buf->st_uid);
	if (test)
		lsd->owner = ft_strdup(test->pw_name);
	lsd->size = buf->st_size;
	lsd->date = buf->st_mtime;
	lsd->nbf = buf->st_nlink;
	lsd->type = type(buf);
	lsd->acces = droit(buf->st_mode, lsd, pathnm);
	lsd->acces[0] = lsd->type;
	lsd->path = ft_strdup(path);
	lsd->total = buf->st_blocks;
	if (lsd->type == 'c')
	{
		toast = buf->st_rdev;
		lsd->minor = toast % 256;
		lsd->major = toast;
	}
}

void	ft_one_file(char *tmp, t_truc *parse)
{
	struct stat		*buf;
	struct group	*group;
	t_file			*lsd;

	if (parse->flag_l == 0 && ft_printf("%s\n", tmp))
		return ;
	if (!(buf = malloc(sizeof(struct stat))))
		ft_err(-10, 0, parse);
	if (!(lsd = malloc(sizeof(t_file))))
		ft_err(-10, 0, parse);
	lsd_null(lsd);
	lsd->name = tmp;
	if (lstat(tmp, buf) == -1)
		free(buf);
	group = getgrgid(buf->st_gid);
	ft_one_file2(lsd, buf, tmp, tmp);
	if (group)
		lsd->group = ft_strdup(group->gr_name);
	if (lsd->group)
		lst_l_prepare(lsd, parse, 1);
	free(buf);
	print_l_too_long(parse, lsd);
	list_free(lsd);
}

int		ft_err(int i, char *tmp, t_truc *parse)
{
	if (i == -666)
		ft_printf("fts_open: No such file or directory\n");
	else if (i == -1)
	{
		ft_printf("Illegal flag.\nusage: ./ls [-rRatTl]\n");
		exit(-1);
	}
	else if (i == -10)
	{
		ft_printf("Allocation error. Bitch.\n");
		exit(-1);
	}
	else if (i == ENOTDIR && tmp[ft_strlen(tmp) - 1] != '/')
		ft_one_file(tmp, parse);
	else
	{
		ft_printf("ft_ls: %s: ", tmp);
		perror(NULL);
		if (errno != 2)
			exit(-1);
	}
	return (1);
}
