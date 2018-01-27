/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_behaviour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:30:04 by upopee            #+#    #+#             */
/*   Updated: 2018/01/26 18:32:40 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "heatmap_tools.h"
#include "vm_io.h"
#include "buffer_tools.h"

static void			get_offset(t_piece *p)
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
			if (e->piece_buffer.cells[i][j] == PIECE_CHAR
				&& !is_free(e->heat_map.cells, x, yy))
			{
				if (e->heat_map.cells[x][yy] == e->char_opp)
					return (0);
				links++;
			}
			yy++;
			j++;
		}
		if (j < e->piece_buffer.size_y)
			return (0);
		x++;
		i++;
	}
	return (i < e->piece_buffer.size_x ? 0 : 1);
}

static int			score(t_hmap *m, t_piece *p, int x, int y)
{
	int		score;
	int		wall;
	int		i;
	int		j;
	int		yy;

	score = 0;
	wall = 0;
	i = p->offset_x;
	while (i < p->size_x && x < m->size_x)
	{
		j = p->offset_y;
		yy = y;
		while (j < p->size_y && yy < m->size_y)
		{
			if (p->cells[i][j++] == PIECE_CHAR)
			{
				if (m->cells[x][yy] == HOT_CELL)
					score += HOT_SCORE;
				if (m->cells[x][yy] == BORDER_CELL)
					wall++;
			}
			yy++;
		}
		x++;
		i++;
	}
	return (wall && score ? score + WALL_SCORE : score);
}

static void			best_move(t_fenv *e, int *x_best, int *y_best)
{
	int		x;
	int		y;

	x = 0;
	while (x < e->heat_map.size_x)
	{
		y = 0;
		while (y < e->heat_map.size_y)
		{
			if (can_fit_here(e, x, y))
			{
				if (score(&(e->heat_map), &(e->piece_buffer), x, y) >= e->score)
				{
					e->score = score(&(e->heat_map), &(e->piece_buffer), x, y);
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


void				play_turn(t_fenv *env)
{
	int		x_best;
	int		y_best;
	t_piece	*piece;

	x_best = 0;
	y_best = 0;
	env->score = 0;
	env->playing = 0;
	piece = &(env->piece_buffer);
	get_vm_output(env);
	update_heatvalues(&(env->heat_map), env->char_opp);
	get_offset(piece);
	best_move(env, &x_best, &y_best);
	clean_buffer(piece->cells, piece->size_x, piece->size_y);
	ft_printf("%d %d\n", x_best, y_best);
}
