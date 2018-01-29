/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:07:54 by upopee            #+#    #+#             */
/*   Updated: 2018/01/29 20:28:12 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "buffer_tools.h"
#include "player_behaviour.h"

static void		init_fenv(t_fenv *env)
{
	env->player = UNSET;
	env->char_used = UNSET;
	env->opponent = UNSET;
	env->char_opp = UNSET;
	env->round.playing = 1;
	env->round.direction = UNSET;
	env->heat_map.cells = NULL;
	env->heat_map.size_x = UNSET;
	env->heat_map.size_y = UNSET;
	env->piece_buffer.cells = NULL;
	env->piece_buffer.size_x = UNSET;
	env->piece_buffer.size_y = UNSET;
	env->piece_buffer.offset_x = UNSET;
	env->piece_buffer.offset_y = UNSET;
}

int				main(void)
{
	t_fenv	env;

	init_fenv(&env);
	play_game(&env);
	delete_doublearray(env.heat_map.cells, env.heat_map.size_x);
	delete_doublearray(env.piece_buffer.cells, env.heat_map.size_x);
	return (SUCCESS);
}
