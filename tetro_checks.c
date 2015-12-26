/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 13:08:54 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 13:10:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	count_adj_pos(char *s, size_t p)
{
	size_t	adjacents;

	adjacents = 0;
	if ((p % TETRA_BASE != 0) && (s[p - 1] == '#'))
		adjacents++;
	if ((p % TETRA_BASE != TETRA_BASE - 1) && (s[p + 1] == '#'))
		adjacents++;
	if ((p < TETRA_BASE * (TETRA_HEIGH - 1)) && (s[p + TETRA_BASE] == '#'))
		adjacents++;
	if ((p >= TETRA_BASE) && (s[p - TETRA_BASE] == '#'))
		adjacents++;
	return (adjacents);
}

static int		check_tetrominal(char *s)
{
	size_t	p;
	size_t	adjacents;

	if ((ft_strcount(s, '#') != 4) || (ft_strcount(s, '\n') != 4))
		return (0);
	p = 0;
	adjacents = 0;
	while (s[p] != '\0')
	{
		if (s[p] == '#')
			adjacents += count_adj_pos(s, p);
		p++;
	}
	return (((adjacents == 6) || (adjacents == 8)) ? 1 : 0);
}

static int		check_eols(char *s)
{
	size_t	line;

	line = 1;
	while (line <= TETRA_HEIGH)
	{
		if (s[line * TETRA_BASE - 1] != '\n')
			return (0);
		line++;
	}
	return (1);
}

int				check_line(char *buffer, int len)
{
	if ((len != BUFF_SIZE) && (len != BUFF_SIZE - 1))
		return (0);
	if (len == BUFF_SIZE)
		buffer[BUFF_SIZE - 1] = '\0';
	if ((!ft_stronlystr(buffer, ".#\n")) || (!check_eols(buffer)))
		return (0);
	if (!check_tetrominal(buffer))
		return (0);
	return (1);
}
