/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:36:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/15 21:00:04 by snicolet         ###   ########.fr       */
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
	char	pure[TETRA_BLOCS * 2 + 1];
	size_t	p;
	int		npos;
	size_t	line;
	size_t	lines_count;

	p = 0;
	npos = 1;
	lines_count = ft_strcount(s, '\n');
	while ((s[p] != '\0') && (npos >= 0))
	{
		line = lines_count;
		npos = ft_strchrpos(&s[p + (line * (TETRA_BASE - 1))], '\n');
		while ((line > 0) && (npos >= 0) &&
				(s[p + (size_t)npos] == '.'))
			line--;
		(void)pure;
		p++;
	}
}

void		tetro_cleaner(char *s)
{
	tetroclean_lines(s);
	tetroclean_columns(s);
}
