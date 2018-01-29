/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_behaviour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:30:04 by upopee            #+#    #+#             */
/*   Updated: 2018/01/29 20:55:46 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "heatmap_tools.h"
#include "vm_io.h"
#include "buffer_tools.h"
#include "analytics.h"

static void			best_move(t_fenv *e, t_hmap *m, t_piece *p, t_analytics *a)
{
	int		i;
	int		j;

	i = a->x_direction > 0 ? 0 : m->size_x - 1;
	while (0 <= i && i < m->size_x)
	{
		j = a->y_direction > 0 ? 0 : m->size_y - 1;
		while (0 <= j && j < m->size_y)
		{
			if (can_fit_here(e, i, j))
			{
				if (score(e, i, j, 0) >= a->score)
				{
					a->score = a->tmp_score;
					a->x_best = i - p->offset_x;
					a->y_best = j - p->offset_y;
				}
				a->playing++;
			}
			j += a->y_direction;
		}
		i += a->x_direction;
	}
}

void				play_game(t_fenv *env)
{
	t_piece	*piece;

	piece = &(env->piece_buffer);
	get_player_data(env);
	while (env->round.playing)
	{
		init_round(&(env->round));
		get_mapdata(&(env->heat_map), &(env->piece_buffer));
		get_piecedata(&(env->piece_buffer));
		update_heatvalues(&(env->heat_map), env->char_opp);
		get_offset(piece);
		if (env->round.direction == UNSET)
			first_direction(env, &(env->heat_map), &(env->round));
		else
			update_direction(env, &(env->heat_map), &(env->round));
		best_move(env, &(env->heat_map), &(env->piece_buffer), &(env->round));
		clean_buffer(piece->cells, piece->size_x, piece->size_y);
		ft_printf("%d %d\n", env->round.x_best, env->round.y_best);
		env->round.player_x = env->round.x_best + env->piece_buffer.offset_x;
		env->round.player_y = env->round.y_best + env->piece_buffer.offset_y;
	}
}
