/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:36:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/17 14:02:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

static void	free_tab(char **tab)
{
	char	**origin;

	origin = tab;
	while (*tab != NULL)
		free(*tab++);
	free(origin);
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

static void	delete_column(char *s, size_t column_id)
{
	ft_memmove(s + column_id,
			s + column_id + 1,
			ft_strlen(s + column_id));
}

static void	tetroclean_columns(char *s, const size_t total_lines)
{
	size_t			line;
	size_t			column;
	size_t			pureline;
	char			**tab;
	char			*retstring;

	tab = ft_strsplit(s, '\n');
	pureline = 0;
	column = TETRA_BASE - 1;
	while (column--)
	{
		line = total_lines;
		while ((line != 0) && ((tab[line - 1])[column] == '.'))
			line--;
		if (line == 0)
			while (line < total_lines)
				delete_column(tab[line++], column);
	}
	retstring = ft_strunsplit(tab, '\n');
	free_tab(tab);
	ft_strcpy(s, retstring);
	free(retstring);
}

void		tetro_cleaner(char *s)
{
	tetroclean_lines(s);
	tetroclean_columns(s, ft_strcount(s, '\n'));
}
