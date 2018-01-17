/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:19:00 by upopee            #+#    #+#             */
/*   Updated: 2018/01/17 15:08:39 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_heatmap(t_hmap *map, int x, int y)
{
	int		i;

	i = 0;
	if ((map->cells = ft_memalloc(sizeof(*(map->cells)) * x)) == NULL)
		return (FAILURE);
	while (i < x)
	{
		if ((map->cells[i] = ft_memalloc(sizeof(**(map->cells)) * y)) == NULL)
			break ;
		i++;
	}
	map->size_x = i;
	map->size_x = y;
	return (i == x ? SUCCESS : FAILURE);
}

int		init_piecebuffer(t_piece *p, int xmax, int ymax)
{
	int		i;

	i = 0;
	if ((p->cells = ft_memalloc(sizeof(*(p->cells)) * xmax)) == NULL)
		return (FAILURE);
	while (i < xmax)
	{
		if ((p->cells[i] = ft_memalloc(sizeof(**(p->cells)) * ymax)) == NULL)
			break ;
		i++;
	}
	p->size_x = 0;
	p->size_x = 0;
	return (i == xmax ? SUCCESS : FAILURE);
}

int		delete_doublearray(char **cells, int nb_lines)
{
	char	**curr;

	if (cells)
	{
		curr = cells;
		while (nb_lines--)
		{
			if (*curr)
				free(*curr);
			curr++;
		}
		free(cells);
	}
	return (SUCCESS);
}
