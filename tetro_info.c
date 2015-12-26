/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:35:01 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 12:35:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned char	tetro_width(unsigned short b)
{
	unsigned char	w;
	unsigned short	bits;

	bits = 34952;
	w = 0;
	while (b & bits)
	{
		bits >>= 1;
		w++;
	}
	return (w);
}

unsigned char	tetro_height(unsigned short b)
{
	unsigned char	h;
	unsigned short	bits;

	h = 0;
	bits = 15;
	while (b & bits)
	{
		bits <<= 4;
		h++;
	}
	return (h);
}
