/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:33:37 by upopee            #+#    #+#             */
/*   Updated: 2018/01/29 18:06:07 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		is_free(char **c, int x, int y)
{
	return (c[x][y] == EMPTY_CELL
			|| c[x][y] == BORDER_CELL || c[x][y] == HOT_CELL);
}

static void		surround_opponent(t_hmap *hm, int i, int j)
{
	char	**c;

	c = hm->cells;
	if (i - 1 >= 0 && is_free(c, i - 1, j))
		c[i - 1][j] = HOT_CELL;
	if (i + 1 < hm->size_x && is_free(c, i + 1, j))
		c[i + 1][j] = HOT_CELL;
	if (j - 1 >= 0 && is_free(c, i, j - 1))
		c[i][j - 1] = HOT_CELL;
	if (j + 1 < hm->size_y && is_free(c, i, j + 1))
		c[i][j + 1] = HOT_CELL;
	if (i - 1 >= 0 && j - 1 >= 0 && is_free(c, i - 1, j - 1))
		c[i - 1][j - 1] = HOT_CELL;
	if (i - 1 >= 0 && j + 1 < hm->size_y && is_free(c, i - 1, j + 1))
		c[i - 1][j + 1] = HOT_CELL;
	if (i + 1 < hm->size_x && j - 1 >= 0 && is_free(c, i + 1, j - 1))
		c[i + 1][j - 1] = HOT_CELL;
	if (i + 1 < hm->size_x && j + 1 < hm->size_y && is_free(c, i + 1, j + 1))
		c[i + 1][j + 1] = HOT_CELL;
}

void			update_heatvalues(t_hmap *hmap, char char_opp)
{
	int		i;
	int		j;

	i = 0;
	while (i < hmap->size_x)
	{
		j = 0;
		while (j < hmap->size_y)
		{
			if ((i == 0 || i == (hmap->size_x - 1) ||
					j == 0 || j == (hmap->size_y - 1)) &&
					hmap->cells[i][j] == EMPTY_CELL)
				hmap->cells[i][j] = BORDER_CELL;
			if (hmap->cells[i][j] == char_opp)
				surround_opponent(hmap, i, j);
			j++;
		}
		i++;
	}
}

void			get_offset(t_piece *p)
{
	int		i;

	p->offset_x = 0;
	p->offset_y = 0;
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

int				can_fit_here(t_fenv *e, int x, int y)
{
	int		i;
	int		j;
	int		yy;
	int		links;

	links = 0;
	i = e->piece_buffer.offset_x;
	while (i < e->piece_buffer.size_x && x < e->heat_map.size_x)
	{
		j = e->piece_buffer.offset_y;
		yy = y;
		while (j < e->piece_buffer.size_y && yy < e->heat_map.size_y)
		{
			if (e->piece_buffer.cells[i][j] == PIECE_CHAR)
			{
				if (e->heat_map.cells[x][yy] == e->char_used)
					links++;
				else if (e->heat_map.cells[x][yy] == e->char_opp)
					return (0);
			}
			yy++;
			j++;
		}
		if (j < e->piece_buffer.size_y)
			return (0);
		x++;
		i++;
	}
	return ((i == e->piece_buffer.size_x) && (links == 1) ? 1 : 0);
}
