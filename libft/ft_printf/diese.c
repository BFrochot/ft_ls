/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diese.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:29:44 by bfrochot          #+#    #+#             */
/*   Updated: 2016/12/09 20:29:47 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_2long(int i, char **str)
{
	char *tmp;

	tmp = malloc(i + 3);
	tmp[0] = '0';
	tmp[1] = 'x';
	tmp[2] = '\0';
	ft_strcat(tmp, *str);
	return (tmp);
}

char	*ft_2long2(int k, int i, char **str)
{
	char *tmp;

	tmp = NULL;
	if (k == 1)
		**str = '0';
	else if (k == 0)
	{
		tmp = malloc(i + 2);
		tmp[0] = '0';
		tmp[1] = '\0';
		ft_strcat(tmp, *str);
		if (tmp[i] == ' ')
			tmp[i] = 0;
	}
	else if ((*str)[0] == ' ')
		(*str)[k - 1] = '0';
	return (tmp);
}

int		ft_hastag(int k, int i, int bool, char **str)
{
	char *tmp;

	tmp = NULL;
	while ((*str)[k] == ' ' || (*str)[k] == '0')
		++k;
	if (bool == 1)
		tmp = ft_2long(i, str);
	else
		tmp = ft_2long2(k, i, str);
	if (tmp != NULL)
		free(*str);
	if (tmp != NULL)
		*str = tmp;
	return (ft_strlen(*str));
}
