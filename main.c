/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:50:23 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/15 19:35:37 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void			lst_callback(size_t p, size_t len, void *content)
{
	(void)len;
	ft_strreplace((char *)content, '#', 'A' + (char)p);
}

int				main(int ac, char **av)
{
	t_list	*lst;
	int		err;

	if (ac == 2)
	{
		err = read_file(av[1], &lst);
		if ((!err) && (lst))
		{
			tetro_cleaner(lst);
			ft_lstforeachi_suffix(lst, &lst_callback);
			ft_lstforeach_suffix(lst, &ft_putendl);
			ft_lstdel(&lst, &ft_lstpulverisator);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("nombre de parametres invalides");
	return (0);
}
