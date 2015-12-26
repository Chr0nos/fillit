/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:26:33 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 13:35:02 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void	prepair_elem(char *s, t_element *elem, char letter)
{
	elem->bin = binarizator_of_doom(s);
	elem->height = tetro_height(elem->bin);
	elem->width = tetro_width(elem->bin);
	elem->letter = letter;
	elem->pos = 0;
}

t_fillit	*preparator(t_list *lst)
{
	t_fillit	*x;
	size_t		p;
	char		*s;

	if (!(x = (t_fillit*)malloc(sizeof(t_fillit))))
		return (NULL);
	x->elements_count = (unsigned int)ft_lstsize(lst);
	x->elems = (t_element*)malloc(sizeof(t_element) * x->elements_count);
	if ((!(p = 0)) && (!x->elems))
	{
		free(x);
		return (NULL);
	}
	x->grid_size = (unsigned int)ft_sqrtup((int)x->elements_count * 4);
	while (lst)
	{
		s = (char*)lst->content;
		prepair_elem((char*)lst->content, &x->elems[p],
				(char)((int)p + 'A'));
		++p;
		lst = lst->next;
	}
	grid_reset(x);
	return (x);
}
