/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:07:29 by bfrochot          #+#    #+#             */
/*   Updated: 2017/01/21 19:42:07 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_file	*ft_start(char *path)
{
	struct stat		*buf;
	struct group	*group;
	t_file			*lsd;

	if (!(buf = malloc(sizeof(struct stat))))
		ft_err(-10, 0, NULL);
	if (!(lsd = malloc(sizeof(t_file))))
		ft_err(-10, 0, NULL);
	lsd_null(lsd);
	lsd->name = ft_strdup(path);
	if (lstat(path, buf) == -1)
	{
		free(buf);
		return (lsd);
	}
	group = getgrgid(buf->st_gid);
	ft_elemcreate2(lsd, buf, path, path);
	if (group)
		lsd->group = ft_strdup(group->gr_name);
	free(buf);
	return (lsd);
}

void	ls_ls(t_truc *parse, char *str)
{
	t_file	*lsd;
	char	*time;

	lsd = ft_start(str);
	if (lsd->type == 'l' && parse->flag_l == 1)
	{
		lst_l_prepare(lsd, parse, 0);
		free(lsd->path);
		lsd->path = "";
		linkatt(lsd);
		time = conv_time(lsd->date, parse);
		ft_printf("%s %s %s %s %s %s %s%s%s\n", lsd->acces, lsd->sizeconv,
		lsd->owner, lsd->group, lsd->nbfconv, time, ft_color(lsd, 1),
		lsd->name, ft_color(lsd, 0));
		free(time);
		exit(1);
	}
	list_free(lsd);
	if (parse->flag_rr == 1)
		flag_rr(parse, str);
	else
	{
		ls_core(parse, str, &lsd);
		list_free(lsd);
	}
}

void	ft_initparse(t_truc *parse)
{
	parse->flag_rr = 0;
	parse->flag_r = 0;
	parse->flag_t = 0;
	parse->flag_tt = 0;
	parse->flag_a = 0;
	parse->flag_l = 0;
}

void	parse_flag(char *av, int u, t_truc *parse)
{
	while (av[u])
	{
		parse->flag_rr = ((av[u] == 'R') || parse->flag_rr) ? 1 : 0;
		parse->flag_r = ((av[u] == 'r') || parse->flag_r) ? 1 : 0;
		parse->flag_l = ((av[u] == 'l') || parse->flag_l) ? 1 : 0;
		parse->flag_a = ((av[u] == 'a') || parse->flag_a) ? 1 : 0;
		parse->flag_t = ((av[u] == 't') || parse->flag_t) ? 1 : 0;
		parse->flag_tt = ((av[u] == 'T') || parse->flag_tt) ? 1 : 0;
		if (av[u] != '-' && av[u] != 'R' && av[u] != 'r' &&
			av[u] != 'l' && av[u] != 'a' && av[u] != 't' &&
			av[u] != 'T')
			ft_err(-1, 0, parse);
		++u;
	}
}

int		main(int ac, char **av)
{
	t_truc	*parse;
	int		i;

	i = 0;
	if (!(parse = malloc(sizeof(t_truc))))
		ft_err(-10, 0, NULL);
	ft_initparse(parse);
	while (++i < ac)
	{
		if (av[i][0] == '-')
			parse_flag(av[i], 0, parse);
		else
			break ;
	}
	if (i == ac)
		ls_ls(parse, "./");
	while (i < ac)
	{
		if (ft_strlen(av[i]) == 0)
			ft_err(-666, "", parse);
		ls_ls(parse, av[i]);
		if (i < ac - 1)
			write(1, "\n", 1);
		++i;
	}
}
