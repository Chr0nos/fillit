/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:41:16 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/23 10:32:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <string.h>

void	liberator(t_fillit *x)
{
	size_t	n;
	size_t	p;

	n = x->elements_count;
	while (n--)
	{
		p = 0;
		while (x->elems[n].data[p] != NULL)
			free(x->elems[n].data[p++]);
		free(x->elems[n].data);
	}
	free(x->elems);
	free(x);
}
