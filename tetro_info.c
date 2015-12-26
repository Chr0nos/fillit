/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:35:01 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 12:27:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetro_width(t_element *t, int line)
{
	char	*s;
	int		p;

	s = t->data[line];
	while ((*s) && (*s == '.'))
		s++;
	p = 0;
	while ((s[p] != '\0') && (s[p] != '.'))
		p++;
	return (p);
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
