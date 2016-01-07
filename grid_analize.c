/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_analize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 12:25:49 by qloubier          #+#    #+#             */
/*   Updated: 2016/01/07 13:10:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		refresh_minx(t_fillit *f, unsigned char line)
{
	unsigned char	i;

	if (line >= f->grid_size)
		return (0);
	i = 0;
	while ((f->bgrid[line] << (15 - i)) & 32768)
		i++;
	f->minx[line] = i;
	return ((int)i);
}
