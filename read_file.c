/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 09:53:29 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 13:10:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

int				read_file(const char *file, t_list **lst)
{
	int		fd;
	int		ret;
	int		err;
	char	buffer[BUFF_SIZE + 1];

	*lst = NULL;
	err = 0;
	if (!(fd = open(file, O_RDONLY)))
		return (1);
	while ((ret = (int)read(fd, buffer, BUFF_SIZE)))
	{
		if ((ret < 0) && ((err = 1)))
			break ;
		if ((buffer[ret] = '\0') && (ret == 0))
			break ;
		else if (check_line((char *)buffer, ret) == 1)
			ft_lstpush_back(lst, ft_lstnew(buffer, (size_t)ret + 1));
		else if ((err = 1))
			break ;
	}
	close(fd);
	if ((lst) && (ft_lstsize(*lst) > TETRO_MAX) && ((err = 1)))
		ft_lstdel(lst, &ft_lstpulverisator);
	return (err);
}
