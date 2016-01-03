/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 11:40:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 11:46:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

t_fillit	*duplicator(t_fillit *f)
{
	t_fillit		*n;
	unsigned int	p;

	if (!(n = ft_memdup(f, sizeof(t_fillit))))
		return (NULL);
	if (!(n->elems = malloc(sizeof(t_element) * f->elements_count)))
	{
		free(n);
		return (NULL);
	}
	p = f->elements_count;
	while (p--)
		n->elems[p] = f->elems[p];
	return (n);
}
