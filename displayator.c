/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:53:17 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/20 16:02:48 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	display_tetrominos(t_fillit *x)
{
	t_list	*lst;
	size_t	p;

	p = 0;
	lst = x->lst;
	while (lst)
	{
		ft_putnbr((int)x->elems[p++].bin);
		ft_putchar('\n');
		ft_putendl((char*)lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
}

void		displayator(t_fillit *x)
{
	size_t	p;

	display_tetrominos(x);
	p = 0;
	while (p < x->grid_size)
		ft_putnendl(x->grid[p++], x->grid_size);
}
