/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:50:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/07 16:51:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int				main(int ac, char **av)
{
	t_list	*lst;

	if (ac == 2)
	{
		if ((!read_file(av[1], &lst)) && (lst))
			trouvator(lst);
		else
			ft_putendl("error");
	}
	else
		ft_putendl("error");
	return (0);
}
