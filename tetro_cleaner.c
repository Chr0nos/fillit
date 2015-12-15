/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:36:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/15 22:17:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	ft_strnonly(char *s, size_t n, char c)
{
	while ((*s) && (n--))
		if (*(s++) != c)
			return (0);
	return (1);
}

static void	tetroclean_lines(char *s)
{
	char	pure[BUFF_SIZE];
	char	*origin;

	origin = s;
	ft_memset((void*)pure, '\0', BUFF_SIZE);
	while (*s)
	{
		if (!ft_strnonly(s, TETRA_BASE - 1, '.'))
			ft_strncat(pure, s, TETRA_BASE);
		s += TETRA_BASE;
	}
	ft_strcpy(origin, pure);
}

static void	tetroclean_columns(char *s)
{
	size_t	p;
	size_t	line;
	size_t	lines_count;
	size_t	width;

	width = TETRA_BASE;
	p = width - 1;
	lines_count = ft_strcount(s, '\n');
	while (p)
	{
		line = 0;
		while ((line < lines_count) && (s[p + (line * width)] == '.'))
			line++;
		if (line == lines_count)
		{
			ft_putstr("kill column ! ");
			ft_putnbr((int)p);
			ft_putchar('\n');
		}
		p--;
	}
}

void		tetro_cleaner(char *s)
{
	tetroclean_lines(s);
	tetroclean_columns(s);
}
