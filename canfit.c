/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canfit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 13:59:10 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/06 19:50:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			canfit(t_fillit *f, int x, int y, t_element *bloc)
{
	const unsigned short	*m = bloc->masks;

	if (((bloc->height + y) <= (unsigned char)f->grid_size) &&
			((bloc->width + x) <= (unsigned char)f->grid_size) &&
			!((m[0] >> x) & f->bgrid[y]) &&
			!((m[1] >> x) & f->bgrid[y + 1]) &&
			!((m[2] >> x) & f->bgrid[y + 2]) &&
			!((m[3] >> x) & f->bgrid[y + 3]))
		return (1);
	return (0);
}
