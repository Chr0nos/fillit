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

	w = 0;
	if (b & 4369)
		++w;
	if (b & 8738)
		++w;
	if (b & 17476)
		++w;
	if (b & 34952)
		++w;
	return (w);
}

unsigned char	tetro_height(unsigned short b)
{
	unsigned char	h;

	h = 0;
	if (b & 15)
		++h;
	if (b & 240)
		++h;
	if (b & 3840)
		++h;
	if (b & 61440)
		++h;
	return (h);
}
