/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:50:23 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/19 16:33:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void			lst_callback(size_t p, size_t len, void *content)
{
	(void)len;
	tetro_cleaner((char *)content);
	ft_strreplace((char *)content, '#', 'A' + (char)p);
	ft_putendl((char *)content);
	ft_putchar('\n');
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
			ft_lstforeachi_suffix(lst, &lst_callback);
			trouvator(lst);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("nombre de parametres invalides");
	return (0);
}
