/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:05:21 by bfrochot          #+#    #+#             */
/*   Updated: 2017/01/21 19:35:07 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	type(struct stat *buf)
{
	char ret;

	ret = '-';
	if (S_ISDIR(buf->st_mode) == 1)
		ret = 'd';
	else if (S_ISCHR(buf->st_mode) == 1)
		ret = 'c';
	else if (S_ISBLK(buf->st_mode) == 1)
		ret = 'b';
	else if (S_ISFIFO(buf->st_mode) == 1)
		ret = 'p';
	else if (S_ISLNK(buf->st_mode) == 1)
		ret = 'l';
	else if (S_ISSOCK(buf->st_mode) == 1)
		ret = 's';
	return (ret);
}

int		getacl(char *name)
{
	acl_t		facl;
	acl_entry_t	ae;

	facl = acl_get_link_np(name, ACL_TYPE_EXTENDED);
	if (facl && (acl_get_entry(facl, ACL_FIRST_ENTRY, &ae) == -1))
	{
		acl_free(facl);
		return (0);
	}
	if (facl != NULL)
	{
		acl_free(facl);
		return (1);
	}
	acl_free(facl);
	return (0);
}

char	*droit(int mode, t_file *lsd, char *pathname)
{
	char *str;

	if (!(str = malloc(11)))
		ft_err(-10, 0, NULL);
	str[1] = (mode & S_IRUSR) ? 'r' : '-';
	str[2] = (mode & S_IWUSR) ? 'w' : '-';
	str[3] = (mode & S_IXUSR) ? 'x' : '-';
	if (mode & S_ISUID)
		str[3] = ((mode & S_IXUSR) ? 's' : 'S');
	str[4] = (mode & S_IRGRP) ? 'r' : '-';
	str[5] = (mode & S_IWGRP) ? 'w' : '-';
	str[6] = (mode & S_IXGRP) ? 'x' : '-';
	if (mode & S_ISGID)
		str[6] = ((mode & S_IXGRP) ? 's' : 'S');
	str[7] = (mode & S_IROTH) ? 'r' : '-';
	str[8] = (mode & S_IWOTH) ? 'w' : '-';
	str[9] = (mode & S_IXOTH) ? 'x' : '-';
	if (mode & S_ISVTX)
		str[9] = ((str[9] == '-') ? 'T' : 't');
	if ((lsd->type != 'l' && listxattr(pathname, NULL, 0, 0) > 0) ||
		(lsd->type == 'l' && listxattr(pathname, NULL, 0, XATTR_NOFOLLOW) > 0))
		str[10] = '@';
	else
		str[10] = (getacl(pathname)) ? '+' : ' ';
	return (str);
}

char	*ft_color(t_file *lsd, int i)
{
	if (i == 1)
	{
		if (lsd->type == 'd')
			return ("\e[0;36m");
		if (lsd->type == 'c')
			return ("\e[7;33m");
		if (lsd->type == 'b')
			return ("\e[0;32m");
		if (lsd->type == 'p')
			return ("\e[1;33m");
		if (lsd->type == 'l')
			return ("\e[0;35m");
		if (lsd->type == 's')
			return ("\e[0;32m");
	}
	return ("\e[0m");
}

void	lsd_null(t_file *lsd)
{
	lsd->acces = NULL;
	lsd->type = 0;
	lsd->nbf = 0;
	lsd->nbfconv = NULL;
	lsd->owner = NULL;
	lsd->total = 0;
	lsd->group = NULL;
	lsd->size = 0;
	lsd->sizeconv = NULL;
	lsd->name = NULL;
	lsd->date = 0;
	lsd->path = NULL;
	lsd->major = 0;
	lsd->minor = 0;
	lsd->prev = NULL;
	lsd->next = NULL;
}
