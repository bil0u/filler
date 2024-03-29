/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:33:37 by upopee            #+#    #+#             */
/*   Updated: 2018/02/01 13:15:20 by upopee           ###   ########.fr       */
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

static int		current_pos_valid(t_fenv *e, char p, char m, int *links)
{
	if (p == PIECE_CHAR)
	{
		if (m == e->char_used)
			(*links)++;
		else if (m == e->char_opp)
			return (0);
	}
	return (1);
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
			if (!current_pos_valid(e, e->piece_buffer.cells[i][j],
									e->heat_map.cells[x][yy], &links))
				return (0);
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
