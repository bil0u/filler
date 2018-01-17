/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_behaviour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:30:04 by upopee            #+#    #+#             */
/*   Updated: 2018/01/17 19:33:04 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "heatmap_tools.h"

static void		get_offset(t_piece *p)
{
	int		i;

	while (p->offset_x < p->size_x)
	{
		i = 0;
		while (i < p->size_y && p->cells[p->offset_x][i] == EMPTY_CELL)
			i++;
		if (i == p->size_y)
			p->offset_x++;
		else
			break ;
	}
	while (p->offset_y < p->size_y)
	{
		i = 0;
		while (i < p->size_x && p->cells[i][p->offset_y] == EMPTY_CELL)
			i++;
		if (i == p->size_x)
			p->offset_y++;
		else
			break ;
	}
}

static int		can_fit_here(t_hmap *m, t_piece *p, int x, int y)
{
	int		i;
	int		j;
	int		yy;

	i = p->offset_x;
	while (i < p->size_x && x < m->size_x)
	{
		j = p->offset_y;
		yy = y;
		while (j < p->size_y && yy < m->size_y)
		{
			if (i == p->offset_x && j == p->offset_y)
				(void)x;
			else if (p->cells[i][j] == PIECE_CHAR && !is_free(m->cells, x, yy))
				return (0)
			yy++;
			j++;
		}
		if (j < p->size_y)
			return (0);
		x++;
		i++;
	}
	return (i < p->size_x ? 0 : 1);
}
