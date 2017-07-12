/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfunct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:34:09 by bfrochot          #+#    #+#             */
/*   Updated: 2016/12/09 20:34:12 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_fun	*ft_type(void)
{
	static t_fun *fcts = NULL;

	if (fcts == NULL)
	{
		fcts = malloc(sizeof(t_fun *) * 14);
		fcts[0] = ft_s;
		fcts[1] = ft_d;
		fcts[2] = ft_o;
		fcts[3] = ft_u;
		fcts[4] = ft_x;
		fcts[5] = ft_c;
		fcts[6] = ft_i;
		fcts[7] = ft_p;
		fcts[8] = ft_israndom;
	}
	return (fcts);
}
