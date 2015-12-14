/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:50:23 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/14 20:57:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#define BUFF_SIZE 21

static int	check_pos(char *s, size_t p)
{
	if ((p > 1) && (s[p - 1] == '#'))
		return (1);
	if (s[p + 1] == '#')
		return (1);
	if ((p < 5) && (s[p + 5] == '#'))
		return (1);
	if ((p > 5) && (s[p - 5] == '#'))
		return (1);
	return (0);
}

static int	check_tetrominal(char *s)
{
	size_t	p;

	if ((ft_strcount(s, '#') != 4) || (ft_strcount(s, '\n') != 4))
		return (0);
	p = 0;
	while (s[p] != '\0')
	{
		if ((s[p] == '#') && (!check_pos(s, p)))
			return (0);
		p++;
	}
	return (1);
}

static int	check_line(char *buffer, int len)
{
	if ((len != 21) && (len != 20))
		return (0);
	if (len == 21)
		buffer[20] = '\0';
	if (!ft_stronlystr(buffer, ".#\n"))
		return (0);
	if (!check_tetrominal(buffer))
		return (0);
	return (1);
}

static int	read_file(const char *file, t_list **lst)
{
	int		fd;
	int		ret;
	int		err;
	char	buffer[BUFF_SIZE + 1];

	*lst = NULL;
	err = 0;
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret < 0)
			break ;
		buffer[ret] = '\0';
		if (ret == 0)
			break ;
		else if (check_line((char *)buffer, ret) == 1)
			ft_lstadd(lst, ft_lstnew(buffer, ret));
		else
		{
			err = 1;
			break ;
		}
	}
	close(fd);
	return (err);
}

int			main(int ac, char **av)
{
	t_list	*lst;
	int		err;

	if (ac == 2)
	{
		err = read_file(av[1], &lst);
		if ((!err) && (lst))
		{
			ft_lstforeach(lst, &ft_putendl);
			//ft_lstforeach_suffix(lst, &ft_memdel);
		}
		else
			ft_putendl("fichier invalide");
	}
	else
		ft_putendl("nombre de parametres invalides");
	return (0);
}
