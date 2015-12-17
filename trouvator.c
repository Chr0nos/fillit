/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/17 16:58:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		trouvator_engine(t_fillit *x)
{
	(void)x;
}

int				trouvator(t_list *lst)
{
	t_fillit	*fillit;

	fillit = preparator(lst);
	if (!fillit)
		return (-1);
	trouvator_engine(fillit);
	displayator(fillit);
	liberator(fillit);
	return (0);
}
