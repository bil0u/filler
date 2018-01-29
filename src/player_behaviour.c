/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_behaviour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:30:04 by upopee            #+#    #+#             */
/*   Updated: 2018/01/29 14:54:33 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "heatmap_tools.h"
#include "vm_io.h"
#include "buffer_tools.h"
#include "debug.h"

static void			get_offset(t_piece *p)
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

static int			can_fit_here(t_fenv *e, int x, int y)
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

static int			score(t_fenv *e, int x, int y)
{
	int		wall;
	int		i;
	int		j;
	int		yy;

	e->tmp_score = 0;
	wall = 0;
	i = e->piece_buffer.offset_x;
	while (i < e->piece_buffer.size_x && x < e->heat_map.size_x)
	{
		j = e->piece_buffer.offset_y;
		yy = y;
		while (j < e->piece_buffer.size_y && yy < e->heat_map.size_y)
		{
			if (e->piece_buffer.cells[i][j++] == PIECE_CHAR)
			{
				if (e->heat_map.cells[x][yy] == HOT_CELL)
					e->tmp_score += HOT_SCORE;
				if (e->heat_map.cells[x][yy] == BORDER_CELL)
					wall++;
			}
			yy++;
		}
		x++;
		i++;
	}
	return (wall && e->tmp_score ? e->tmp_score + WALL_SCORE : e->tmp_score);
}

static void			best_move(t_fenv *e, int *x_best, int *y_best)
{
	int		x;
	int		y;

	e->playing = 0;
	e->score = 0;
	x = 0;
	while (x < e->heat_map.size_x)
	{
		y = 0;
		while (y < e->heat_map.size_y)
		{
			if (can_fit_here(e, x, y))
			{
				if (score(e, x, y) >= e->score)
				{
					e->score = e->tmp_score;
					*x_best = x - e->piece_buffer.offset_x;
					*y_best = y - e->piece_buffer.offset_y;
				}
				e->playing++;
			}
			y++;
		}
		x++;
	}
}


void				play_game(t_fenv *env)
{
	int		x_best;
	int		y_best;
	t_piece	*piece;

	piece = &(env->piece_buffer);
	get_player_data(env);
	while (env->playing)
	{
		x_best = 0;
		y_best = 0;
		get_mapdata(&(env->heat_map), &(env->piece_buffer));
		get_piecedata(&(env->piece_buffer));
		update_heatvalues(&(env->heat_map), env->char_opp);
		get_offset(piece);
		best_move(env, &x_best, &y_best);
		clean_buffer(piece->cells, piece->size_x, piece->size_y);
		ft_printf("%d %d\n", x_best, y_best);
	}
}
