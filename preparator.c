/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:26:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/07 14:29:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>

static unsigned char	tetro_width(unsigned short b)
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

static unsigned char	tetro_height(unsigned short b)
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

static unsigned short	revbits(unsigned short b)
{
	unsigned short	x;
	int				p;

	p = 15;
	x = (unsigned short)((b & 1) << 15);
	while ((b >>= 1))
		x |= (unsigned short)((b & 1) << (--p));
	return (x);
}

static void				prepair_elem(char *s, t_element *elem, char letter)
{
	int	p;

	elem->display = binarizator_of_doom(s);
	elem->bin = elem->display;
	elem->height = tetro_height(elem->bin);
	elem->width = tetro_width(elem->bin);
	elem->letter = letter;
	elem->pos = 0;
	elem->bin = revbits(elem->display);
	elem->placed = 0;
	p = 4;
	while (p--)
		elem->masks[p] = (elem->bin << (4 * p)) & 61440;
}

t_fillit				*preparator(t_list *lst)
{
	t_fillit	*x;
	size_t		p;

	if (!(x = (t_fillit*)malloc(sizeof(t_fillit))))
		return (NULL);
	x->elements_count = (unsigned char)ft_lstsize(lst);
	p = 0;
	x->grid_size = (unsigned char)ft_sqrtup(x->elements_count * 4);
	while (lst)
	{
		prepair_elem((char*)lst->content, &x->elems[p],
				(char)((int)p + 'A'));
		++p;
		lst = lst->next;
	}
	grid_reset(x);
	return (x);
}
