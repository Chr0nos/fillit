/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:26:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 15:52:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>

/*
** revert bits order
*/

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
	elem->display = binarizator_of_doom(s);
	elem->bin = elem->display;
	elem->height = tetro_height(elem->bin);
	elem->width = tetro_width(elem->bin);
	elem->letter = letter;
	elem->pos = 0;
	elem->bin = revbits(elem->display);
	elem->placed = 0;
}

static void				prepair_map(t_fillit *f)
{
	unsigned int	p;

	p = 0;
	while (p < f->elements_count)
	{
		f->map[p] = (char)p;
		p++;
	}
	while (p < 26)
		f->map[p++] = -1;
}

t_fillit				*preparator(t_list *lst)
{
	t_fillit	*x;
	size_t		p;

	if (!(x = (t_fillit*)malloc(sizeof(t_fillit))))
		return (NULL);
	x->elements_count = (unsigned int)ft_lstsize(lst);
	x->elems = (t_element*)malloc(sizeof(t_element) * x->elements_count);
	if ((!(p = 0)) && (!x->elems))
	{
		free(x);
		return (NULL);
	}
	prepair_map(x);
	x->grid_size = (unsigned int)ft_sqrtup((int)x->elements_count * 4);
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
