/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 09:53:29 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 13:21:48 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

/*
** return 1 in cases of error
** 0 in case of success
*/

static int		rfi(char *buffer, int ret, t_list **lst)
{
	if (ret < 0)
		return (1);
	if ((buffer[ret] = '\0') && (ret == 0))
		return (0);
	else if (check_line(buffer, ret) == 1)
	{
		ft_lstpush_back(lst, ft_lstnew(buffer, (size_t)ret + 1));
		return (0);
	}
	else
		return (1);
}

int				read_file(const char *file, t_list **lst)
{
	int		fd;
	int		ret;
	int		err;
	int		lret;
	char	buffer[BUFF_SIZE + 1];

	if (!(fd = open(file, O_RDONLY)))
		return (1);
	*lst = NULL;
	err = 0;
	lret = 0;
	while (((ret = (int)read(fd, buffer, BUFF_SIZE))) &&
			(!(err = rfi((char *)buffer, ret, lst))))
	{
		lret = ret;
	}
	close(fd);
	if (lret != 20)
		err = 1;
	if ((lst) && (ft_lstsize(*lst) > TETRO_MAX) && ((err = 1)))
		ft_lstdel(lst, &ft_lstpulverisator);
	return (err);
}
