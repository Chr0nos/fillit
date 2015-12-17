/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/17 15:05:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		trouvator(t_list *lst)
{
	t_fillit	*fillit;

	fillit = preparator(lst);
	if (!fillit)
		return (-1);
	liberator(fillit);
	return (0);
}
