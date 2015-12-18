/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:26:33 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/18 13:34:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_fillit	*preparator(t_list *lst)
{
	t_fillit	*x;
	size_t		p;
	char		*s;

	if (!(x = (t_fillit*)malloc(sizeof(t_fillit))))
		return (NULL);
	x->lst = lst;
	x->elements_count = ft_lstsize(lst);
	x->elems = (t_element*)malloc(sizeof(t_element) * x->elements_count);
	x->grid_size = x->elements_count / 2;
	if ((!(p = 0)) && (!x->elems))
	{
		free(x);
		return (NULL);
	}
	while (lst)
	{
		s = (char*)lst->content;
		x->elems[p].height = ft_strcount(s, '\n');
		x->elems[p].width = ft_strsublen(s, '\n');
		x->elems[p++].data = ft_strsplit(s, '\n');
		lst = lst->next;
	}
	grid_reset(x);
	return (x);
}