/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analytics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bilou <Bilou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:20:06 by Bilou             #+#    #+#             */
/*   Updated: 2018/01/29 20:56:48 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_round(t_analytics *a)
{
	a->playing = 0;
	a->score = 0;
	a->x_best = 0;
	a->y_best = 0;
}

int		score(t_fenv *e, int x, int y, int wall)
{
	int		i;
	int		j;
	int		yy;

	e->round.tmp_score = 0;
	i = e->piece_buffer.offset_x;
	while (i++ < e->piece_buffer.size_x && x++ < e->heat_map.size_x)
	{
		j = e->piece_buffer.offset_y;
		yy = y;
		while (j++ < e->piece_buffer.size_y && yy++ < e->heat_map.size_y)
		{
			if (e->piece_buffer.cells[i - 1][j - 1] == PIECE_CHAR)
			{
				if (e->heat_map.cells[x - 1][yy - 1] == HOT_CELL)
					e->round.tmp_score += HOT_SCORE;
				if (e->heat_map.cells[x - 1][yy - 1] == BORDER_CELL)
					wall++;
			}
		}
	}
	e->round.tmp_score += (wall && e->round.tmp_score ? WALL_SCORE : 0);
	return (e->round.tmp_score);
}

void	first_direction(t_fenv *e, t_hmap *m, t_analytics *a)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < m->size_x)
	{
		j = 0;
		while (j++ < m->size_y)
		{
			if (m->cells[i - 1][j - 1] == e->char_used)
			{
				a->player_x = i;
				a->player_y = j;
			}
			else if (m->cells[i - 1][j - 1] == e->char_opp)
			{
				a->opp_x = i;
				a->opp_y = j;
			}
		}
	}
	a->x_direction = a->opp_x - a->player_x < 0 ? -1 : 1;
	a->y_direction = a->opp_y - a->player_y < 0 ? -1 : 1;
	a->direction = 1;
}

void	update_direction(t_fenv *e, t_hmap *m, t_analytics *a)
{
	int		i;
	int		j;

	i = a->x_direction > 0 ? m->size_x - 1 : 0;
	while (0 <= i && i < m->size_x)
	{
		j = a->y_direction > 0 ? m->size_y - 1 : 0;
		while (0 <= j && j < m->size_y)
		{
			if (m->cells[i][j] == e->char_opp)
			{
				a->opp_x = i;
				a->opp_y = j;
			}
			j -= a->y_direction;
		}
		i -= a->x_direction;
	}
	a->x_direction = a->opp_x - a->player_x < 0 ? -1 : 1;
	a->y_direction = a->opp_y - a->player_y < 0 ? -1 : 1;
}
