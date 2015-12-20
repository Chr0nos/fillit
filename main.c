/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:50:23 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/20 16:47:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int				main(int ac, char **av)
{
	t_list	*lst;
	int		err;

	if (ac == 2)
	{
		err = read_file(av[1], &lst);
		if ((!err) && (lst))
		{
			trouvator(lst);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("nombre de parametres invalides");
	return (0);
}
