/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:31:41 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 15:45:52 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf("coucou %p -- %p\n", av, NULL);
	printf("coucou %p -- %p\n", av, NULL);
	return (0);
}
